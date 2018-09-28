#ifndef FUNCIONESAPI__H
#define FUNCIONESAPI__H

#include <windows.h>
#include <stdio.h>
#include <string.h>


void obtenerUsuario(char* ptrUsuario);
void obtenerPc(char* ptrPc);
void obtenerDirectorio(char* ptrDir);
void obtenerTiempoEncendido(char* ptrTiempo);
int mostrarMensaje(char* titulo, char* texto, int tipo, int icono);
void obtenerInfo(char* ptrTiempo, char* ptrUsuario,char* ptrPc,char* ptrDir);
void crearDirectorio();
void copiarDirectorio();
void eliminarFichero();
void cerrarSesion();

#endif