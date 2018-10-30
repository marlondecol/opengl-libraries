/**
 * Bibliotecas necessárias.
 */

// Inclui as bibliotecas necessárias.
#include <string.h>

// Inclui a FreeGLUT.
#include <GL/glut.h>

// Inclui bibliotecas personalizadas.
#include "glutcolor.h"
#include "glutpalette.h"

// Inclui o arquivo .h deste arquivo.
#include "glutdefpalette.h"



/**
 * Cria uma nova paleta de cores preenchida com valores predefinidos.
 */

Palette* plGetDefaultPalette() {
	// Cores disponíveis na paleta.
	GLfloat glPalette[][3] = {
		{0.0f, 0.0f, 0.0f}, // #000000
		{1.0f, 0.0f, 0.0f}, // #ff0000
		{1.0f, 1.0f, 0.0f}, // #ffff00
		{0.0f, 1.0f, 0.0f}, // #00ff00
		{0.0f, 1.0f, 1.0f}, // #00ffff
		{0.0f, 0.0f, 1.0f}, // #0000ff
		{1.0f, 0.0f, 1.0f}, // #ff00ff
		{1.0f, 1.0f, 1.0f}, // #ffffff
		{0.5f, 0.0f, 1.0f}, // #7f00ff
		{0.25f, 0.0f, 0.5f}, // #3f007f
		{0.816f, 0.668f, 0.0f}, // #d1ab00
		{0.25f, 0.25f, 0.25f}, // #3f3f3f
		{0.46f, 0.6f, 0.61f}, // #779a9c
		{1.0f, 0.94f, 0.84f}, // #ffefd9
		{1.0f, 0.5f, 0.0f}, // #ff7f00
		{0.75f, 0.0f, 0.0f}, // #bf0000
		{0.45f, 0.75f, 0.0f}, // #72bf00
		{0.5f, 0.5f, 0.5f}, // #7f7f7f
		{0.125f, 0.125f, 0.125f} // #1f1f1f
	};

	// Nomes relativos às cores listadas acima.
	char glPaletteNames[][20] = {
		"Preto",
		"Vermelho",
		"Amarelo",
		"Verde",
		"Ciano",
		"Azul",
		"Rosa",
		"Branco",
		"Violeta",
		"Purpura",
		"Dourado",
		"Cinza",
		"Cinza azulado",
		"Areia",
		"Laranja",
		"Escarlate",
		"Verde grama",
		"Cinza claro",
		"Cinza escuro"
	};

	int paletteSize = sizeof(glPalette) / sizeof(glPalette[0]);
	int paletteNamesSize = sizeof(glPaletteNames) / sizeof(glPaletteNames[0]) / sizeof(char);

	Palette *palette = plCreate();

	if (paletteSize == paletteNamesSize && paletteSize > 0)
		for (int i = 0; i < paletteSize; i++)
			plAdd(palette, clCreate(glPalette[i][0], glPalette[i][1], glPalette[i][2], glPaletteNames[i]));

	return palette;
}