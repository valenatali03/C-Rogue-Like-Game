# Proyecto en C con PDCurses

Este proyecto es un programa en C que utiliza la biblioteca PDCurses para crear un videojuego como rogue/nethack. El entorno de desarrollo utilizado es Windows con MSYS2 y el compilador MinGW64.

## Requisitos

- **Windows**
- **MSYS2 con MinGW64** instalado
- **PDCurses** (instalado en MSYS2)

## Instalación

1. Instala [MSYS2](https://www.msys2.org/) siguiendo las instrucciones en su sitio web.
2. Abre la terminal de MSYS2 y actualiza los paquetes:

   ```bash
   pacman -Syu

3. Instala el compilador MinGW64 y PDCurses
   ```bash
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-pdcurses
   
## Compilación
1. Compila con el siguiente comando:
   ```bash
   gcc -o main main.c -I/mingw64/include/pdcurses -L/mingw64/lib -lpdcurses

2. Ejecuta con:
   ```bash
   ./main


