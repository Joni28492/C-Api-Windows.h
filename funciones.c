
#include "funciones.h"

/**
* Metodo que obtiene el usuario de sesión utilizado en el sistema.
* Se muestran los bytes utilizados para poder manejar espacios de memoria.
*/
void obtenerUsuario() {
	char usuario[250];
	int numBytes = 0;
	int resultado = 0;

	numBytes = 250;
	resultado = GetUserName(usuario, &numBytes);

	if(resultado!=0){
		printf("El usuario es: %s\n", usuario);
		printf("Se usaron %d bytes\n", numBytes);
	}
	else{
		printf("Fallo al obtener el usuario\n");
		printf("Se usaron %d bytes\n", numBytes);
	}

}

/**
* Metodo que obtiene el nombre del equipo.
* Se muestran los bytes utilizados para poder manejar espacios de memoria.
*/
void obtenerPc() {
	char nombrepc[250];
	int numBytes = 0;
	int resultado = 0;

	numBytes = 250;
	resultado = GetComputerName(nombrepc, &numBytes);

	if(resultado!=0){
		printf("El pc es: %s\n", nombrepc);
		printf("Se usaron %d bytes\n", numBytes);
	}
	else{
		printf("Fallo al obtener el pc\n");
		printf("Se usaron %d bytes\n", numBytes);
	}

}

/**
* Metodo que obtiene el directorio en el que nos encontramos trabajando.
* Se muestran los bytes utilizados para poder manejar espacios de memoria.
*/
void obtenerDirectorio() {
	char directorio[500];
	int numBytes = 0;
	int resultado = 0;

	numBytes = 500;
	resultado = GetCurrentDirectory(&numBytes,directorio);

	if(resultado!=0){
		printf("El directorio es: %s\n", directorio);
		printf("Se usaron %d bytes\n", numBytes);
	}
	else{
		printf("Fallo al obtener el directorio\n");
		printf("Se usaron %d bytes\n", numBytes);
	}
}

/**
* Metodo que obtiene el tiempo que se enceuntra arrancado el sistema operativo
* y la sesión.
* Se calcula a partir de los milisegundos los minutos y segundos para un mejor
* visionado.
*/
void obtenerTiempoEncendido() {
	int tiempoMs = 0;
	int segundos = 0;
	int minutos = 0;
	int horas = 0;

	tiempoMs = GetTickCount();

	tiempoMs = tiempoMs / 1000;

	horas = (tiempoMs / 3600);
	tiempoMs -= (horas * 3600);

	minutos = (tiempoMs / 60);
	tiempoMs -= (minutos * 60);

	segundos = tiempoMs;

	printf("Tiempo encendido: %d horas %d minutos %d segundos\n", horas, minutos, segundos);

}

/**
* Metodo que cambia el directorio en el que nos encontramos trabajando.
* @param char* directorio puntero con la nueva dirección a la que debemos apuntar.
*/
void moverseADirectorio(char* directorio) {
	int resultado = 0;
	resultado = SetCurrentDirectory(directorio);
	if (resultado != 0) {
		printf("Movido ok al directorio: %s\n", directorio);
	}
	else {
		printf("Fallo al moverse al directorio\n");
	}
}

/**
* Metodo que pausa la ejecución de código. Por ejemplo para la ejecución de otros
* procesos o elementos del proyecto.
* @param int milisegundos milisegundos que se desea que el código quede pausado.
*/
void esperarMilisegundos(int milisegundos) {
	printf("Esperando %d milisegundos\n", milisegundos);
	Sleep(milisegundos);
	printf("Espera finalizada\n");
}

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