#ifndef FUNCIONES__H
#define FUNCIONES__H

#include <windows.h>
#include <stdio.h>

void obtenerUsuario();
void obtenerPc();
void obtenerDirectorio();
void obtenerTiempoEncendido();

void moverseADirectorio(char* directorio);

void esperarMilisegundos(int milisegundos);

int mostrarMensaje(char* titulo, char* texto, int tipo, int icono);

#endif