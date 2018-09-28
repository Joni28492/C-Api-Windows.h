#include <stdio.h>
#include "funciones.h"


int main(){
	int resultado = 0;
	obtenerPc();
	obtenerUsuario();
	obtenerDirectorio();

	moverseADirectorio("c:\\users");

	//esperarMilisegundos(3000);

	obtenerDirectorio();

	obtenerTiempoEncendido();
	//esperarMilisegundos(5000);
	obtenerTiempoEncendido();

	resultado = mostrarMensaje("Ventana sin icono", "Ventana genérica", MB_OK, NULL);//MB_RETRYCANCEL
	//printf("%d \n",resultado);
	//resultado 1

	resultado = mostrarMensaje("Ventana con icono exclamación", "Aqui va con icono de exclamación", MB_OK, MB_ICONWARNING);
	//printf("%d \n", resultado);
	//resultado 1

	resultado = mostrarMensaje("Ventana con icono de error grave", "¡Error grave! ¿Desea salir del programa?", MB_YESNOCANCEL, MB_ICONERROR);
	//resultado 6(si), 7(no)

	Beep(440, 1000);
	Sleep(500);
	Beep(428, 1000);
	Sleep(500);
	Beep(748, 1000);
	return 0;
}