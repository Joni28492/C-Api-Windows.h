#include<stdio.h>
#include "funcionesapi.h"



int main(int argc, char** argv){
	
	
	int resultado=0;
	char cadenaTiempo[500]="Tiempo de encendido: ";
	char *ptrTiempo=&cadenaTiempo[0];
	char cadenaUsuario[50]="aaa";
	char *ptrUsuario=&cadenaUsuario[0];
	
	char cadenaPc[256]="P";
	char *ptrPc=&cadenaPc[0];
	
	char cadenaDir[512]="";
	char *ptrDir=&cadenaDir;
	
	//1-Obtener en un método toda la información posible acerca de la sesión 
	//en la que se encuentra el usuario,
	// escuchándose un sonido informativo y un mensaje de ok
	
	obtenerInfo(ptrTiempo,ptrUsuario,ptrPc,ptrDir);
	//mostrarMensaje("Tiempo de encendido",  obtenerTiempoEncendido(ptrTiempo), MB_OK, MB_ICONINFORMATION);
	
	
	
	
	
	//2-Copiar un archivo con información relativa a los procesos activos del sistema obtenido
	// desde línea de comandos desde Mis documentos hasta una carpeta hija "Procesos"
	// de la carpeta en la que se encuentra el proyecto de C programado.
	
	//crear directorio
	crearDirectorio();
	//copiamos de un directorio a otro
	copiarDirectorio();
	
	
	//3-Eliminar el archivo creado en la ruta del origen si en un mensaje de pregunta se confirma 
	//que se desea eliminar. En caso contrario mostrar otro mensaje que indique que no se ha eliminado.
	
	eliminarFichero();
	
	//4-Mostrar un mensaje de error advirtiendo que tras un minuto se apagará el equipo. Si se confirma 
	//la afirmación se llevará a cabo la espera del tiempo y el intento de apagado. En caso contrario se
	// esperará 10 segundos y se mostrará nuevamente el mensaje. Si tras 3 repeticiones del mensaje, la 
	//respuesta sigue siendo negativa, se mostrará un nuevo mensaje de ayuda de windows así como un triple sonido.
	 cerrarSesion();
	
	return 0;
}