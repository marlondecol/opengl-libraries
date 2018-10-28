/**
 * Garante que a biblioteca seja chamada uma única vez.
 */

#ifndef _GLUTPALETTE_H
#define _GLUTPALETTE_H



/**
 * Bilbiotecas necessárias.
 */

// Inclui bibliotecas personalizadas.
#include "glutcolor.h"



/**
 * Protótipo da estrutura de uma cor.
 */

typedef struct mix Mix;

typedef struct mix* Palette;



/**
 * Protótipos das funções da biblioteca.
 */

Palette* plCreate();

void plDestroy(Palette *palette);

int plAdd(Palette *palette, Color *color);

int plRemove(Palette *palette, int id);

int plSize(Palette *palette);

Color* plGetColor(Palette *palette, int id);



/**
 * A condição envolve todo o código.
 */

#endif