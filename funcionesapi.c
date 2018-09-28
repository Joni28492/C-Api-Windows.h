#include "funcionesapi.h"


	//1-Obtener en un método toda la información posible acerca de la sesión 
	//en la que se encuentra el usuario,
	// escuchándose un sonido informativo y un mensaje de ok
	
/**
* Metodo de muestra de mensajes al usuario
* @param char *titulo titulo de la ventana
* @param char *texto mensaje de la ventana
* @param int tipo codigo de los botones a mostrar en la ventana
* @param int icono icono mostrado en la ventana
*/
int mostrarMensaje(char* titulo, char* texto, int tipo, int icono) {
	return MessageBox(NULL, texto, titulo, tipo | icono);
}
	
/**
* Metodo que obtiene el usuario de sesión utilizado en el sistema.
* Se muestran los bytes utilizados para poder manejar espacios de memoria.
*/
void obtenerUsuario(char* ptrUsuario) {
	//char usuario[250];
	int numBytes = 0;
	int resultado = 0;

	numBytes = 250;
	resultado = GetUserName(ptrUsuario, &numBytes);

	/*if(resultado!=0){
		
		resultado = mostrarMensaje("Usuario", ptrUsuario, MB_OK, MB_ICONINFORMATION);
		
		//printf("El usuario es: %s\n", usuario);
		//printf("Se usaron %d bytes\n", numBytes);
	}
	else{
		
		resultado = mostrarMensaje("Error", "no hay ningun usuario", MB_OK, MB_ICONWARNING);
		//printf("Fallo al obtener el usuario\n");
		//printf("Se usaron %d bytes\n", numBytes);
	}*/

}

/**
* Metodo que obtiene el nombre del equipo.
* Se muestran los bytes utilizados para poder manejar espacios de memoria.
*/
void obtenerPc(char* ptrPc) {
	//char nombrepc[250];
	int numBytes = 0;
	int resultado = 0;

	numBytes = 250;
	resultado = GetComputerName(ptrPc, &numBytes);
	
	/*if(resultado!=0){
		
		resultado = mostrarMensaje("Nombre PC", ptrPc, MB_OK, MB_ICONINFORMATION);
		//printf("El pc es: %s\n", nombrepc);
		//printf("Se usaron %d bytes\n", numBytes);
	}
	else{
		resultado = mostrarMensaje("Error", "no hay ningun PC", MB_OK, MB_ICONWARNING);
		//printf("Fallo al obtener el pc\n");
		//printf("Se usaron %d bytes\n", numBytes);
	}*/

}

/**
* Metodo que obtiene el directorio en el que nos encontramos trabajando.
* Se muestran los bytes utilizados para poder manejar espacios de memoria.
*/
void obtenerDirectorio(char* ptrDir) {
	//char directorio[500];
	int numBytes = 0;
	int resultado = 0;

	numBytes = 500;
	resultado = GetCurrentDirectory(&numBytes, ptrDir);

	if(resultado!=0){
		resultado = mostrarMensaje("Directorio",  ptrDir, MB_OK, MB_ICONINFORMATION);
		//printf("El directorio es: %s\n", directorio);
		//printf("Se usaron %d bytes\n", numBytes);
	}
	else{
		
		resultado = mostrarMensaje("Error", "no hay ningun directorio", MB_OK, MB_ICONWARNING);
		//printf("Fallo al obtener el directorio\n");
		//printf("Se usaron %d bytes\n", numBytes);
	}
}

/**
* Metodo que obtiene el tiempo que se enceuntra arrancado el sistema operativo
* y la sesión.
* Se calcula a partir de los milisegundos los minutos y segundos para un mejor
* visionado.
*/
void obtenerTiempoEncendido(char* ptrTiempo) {
	int tiempoMs = 0;
	int segundos = 0;
	int minutos = 0;
	int horas = 0;
	int resultado=0;
	char* ptrHoras=&horas;
	

	tiempoMs = GetTickCount();

	tiempoMs = tiempoMs / 1000;

	horas = (tiempoMs / 3600);
	tiempoMs -= (horas * 3600);

	minutos = (tiempoMs / 60);
	tiempoMs -= (minutos * 60);

	segundos = tiempoMs;

	*ptrHoras+=48;
	
	//printf("Tiempo encendido: %d horas %d minutos %d segundos\n", horas, minutos, segundos);
	
	strcat(ptrTiempo, ptrHoras);
	resultado = mostrarMensaje("Directorio", ptrTiempo, MB_OK, MB_ICONINFORMATION);
	
}

/**
*Metodo que muestra la info del usario, equipo, directorio y tiempo de encendido mediante una ventana
*por ahora solo se muestran usuario y pc
*NOTA: hay que modificar el for con el numBytes para que no afecte el numero de caracteres
*/

void obtenerInfo(char* ptrTiempo, char* ptrUsuario, char* ptrPc,char* ptrDir){
	
	int resultado=0;
	char datos[500];
	char *ptrDatos=&datos[0];

	
	obtenerUsuario(ptrUsuario);
	
	
	int i=0;
	for(i=500;i<508;i++){
		
		*ptrDatos = *ptrUsuario;
		ptrUsuario++;
		ptrDatos++;
		
		
	}
	
	obtenerPc(ptrPc);
	
	*(ptrDatos-1)='\n';
	//ptrDatos-=2;



	for(i=550;i<557;i++){
		
		*ptrDatos = *ptrPc;
		
		printf("ptrpg %c %p \n", *ptrPc, ptrPc);
		ptrPc++;
		ptrDatos++;
		
		
	}
	
	

	
	
	
	
	
	ptrDatos=&datos[0];
	
	
	
	
	resultado = mostrarMensaje("Datos", ptrDatos, MB_OK, MB_ICONINFORMATION);
	
	
	/*
	//Estas en vantanas separadas y descomentando en la propia funcion
	obtenerUsuario(ptrUsuario);
	obtenerPc(ptrPc);
	obtenerDirectorio(ptrDir);
	obtenerTiempoEncendido(ptrTiempo);
	*/
	
	Beep(440,1000);
	
	
	
}

/**
*crea un directorio en la ruta especificada
*y muestra una ventana de que se ha creado correctamente
*/
void crearDirectorio(){
	
	int resultado=0;
	
	resultado=CreateDirectory("C:\\cygwin\\home\\usuario\\APIS\\directoriocreado",0);
	if(resultado){
		 MessageBox(NULL, "Directorio creado correctamente", "crear directorio", MB_OK | MB_ICONINFORMATION);
	}
}
/**
*crea una copia del fichero especificado en la ruta especificada
*y muestra una ventana de que se hacopiado correctamente
*/
void copiarDirectorio(){
	
	int resultado=0;
	
	resultado=CopyFile("C:\\Users\\usuario\\Documents\\procesos.txt","C:\\cygwin\\home\\usuario\\APIS\\directoriocreado\\procesos(copia).txt",0);
	if(resultado){
		 MessageBox(NULL, "Archivo copiado correctamente", "copiar archivo", MB_OK | MB_ICONINFORMATION);
	}
	
	
	
	
}
/**
*elimina el fichero especificado
*y muestra una ventana para confirmar si desea eliminarlo
*/
void eliminarFichero(){
	
	int resultado=0;
	
	resultado= MessageBox(NULL, "Desea eliminar el archivo", "Eliminar archivo archivo", MB_YESNOCANCEL | MB_ICONQUESTION);
	
	switch(resultado){
		
		case 6:
			DeleteFile("C:\\cygwin\\home\\usuario\\APIS\\directoriocreado\\procesos(copia).txt");
			break;
			
		case 7:
			 MessageBox(NULL, "Tu archivo no se borrara", "No eliminado", MB_OK | MB_ICONINFORMATION);
			break;
			
			
		default:
			 MessageBox(NULL, "Laoperacion ha sido cancelada", "Cancelado", MB_OK | MB_ICONINFORMATION);
			break;
	
	
	
		
	}
	
	
	
	
}
/**
*muestra un mensaje de que el equipo se apagara en un minuto
*se muestra un mensaje 3 veces para confirmar el apagado
*emite 3 pitidos
*descomentar exit windows para que el programa cierre la sesion
*/

void cerrarSesion(){
	int resultado=0;
	int contador=0;
	
		resultado=MessageBox(NULL, "en 1:00 min se apagara tu equipo\n desea apagarlo?", "apagando equipo", MB_YESNO | MB_ICONQUESTION);
	Sleep(10000);
	contador++;
	while(contador<=3){
		
		if(resultado==7 && contador<=3){
			resultado=MessageBox(NULL, "10seg", "apagando equipo", MB_YESNO | MB_ICONQUESTION);
			Sleep(10000);
			contador++;
		}
		if(resultado==6){
			contador=4;
		}
	
	}
	Sleep(30000);
	
	resultado=MessageBox(NULL, "ordenador apagado", "apagando equipo", MB_OK | MB_ICONINFORMATION);
	//descomentar para cerrar sesion
	
	Beep(440, 1000);
	Beep(440, 1000);
	Beep(440, 1000);
	//ExitWindows(0,0);
	
}