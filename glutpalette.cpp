/**
 * Bibliotecas.
 */

// Inclui as bibliotecas necessárias.
#include <stdlib.h>

// Inclui a FreeGLUT.
#include <GL/glut.h>

// Inclui bibliotecas personalizadas.
#include "glutcolor.h"

// Inclui o arquivo .h deste arquivo.
#include "glutpalette.h"



/**
 * Definição da estrutura de uma paleta.
 */

struct mix {
	int id;
	Color *color;
	Mix *next;
};



/**
 * Cria uma nova paleta de cores.
 */

Palette* plCreate() {
	Palette *palette = (Palette*) malloc(sizeof(Palette));

	if (palette != NULL)
		*palette = NULL;

	return palette;
}



/**
 * Destrói a instância da paleta informada.
 */

void plDestroy(Palette *palette) {
	if (palette != NULL) {
		Mix *mix;

		while ((*palette) != NULL) {
			mix = *palette;
			*palette = (*palette)->next;

			free(mix);
		}

		free(palette);
	}
}



/**
 * Insere uma cor na paleta.
 */

int plAdd(Palette *palette, Color *color) {
	if (palette == NULL)
		return 0;

	Mix *mix = (Mix*) malloc(sizeof(Mix));

	if (mix == NULL)
		return 0;

	mix->id = plSize(palette);
	mix->color = color;
	mix->next = NULL;

	if ((*palette) == NULL)
		*palette = mix;
	else {
		Mix *aux = *palette;

		while (aux->next != NULL)
			aux = aux->next;

		aux->next = mix;
	}

	return 1;
}



/**
 * Remove uma cor da paleta informando o atributo "id" do elemento.
 */

int plRemove(Palette *palette, int id) {
	if (palette == NULL)
		return 0;

	Mix *prev;
	Mix *mix = *palette;

	while (mix != NULL && mix->id != id) {
		prev = mix;
		mix = mix->next;
	}

	if (mix == NULL)
		return 0;

	if (mix == *palette)
		*palette = mix->next;
	else
		prev->next = mix->next;

	free(mix);

	return 1;
}



/**
 * Obtém o tamanho da paleta de cores informada.
 */

int plSize(Palette *palette) {
	if (palette == NULL)
		return 0;

	int size = 0;

	Mix *mix = *palette;

	while (mix != NULL) {
		size++;
		mix = mix->next;
	}

	return size;
}



/**
 * Obtém uma cor da paleta informando o atributo "id" do elemento.
 */

Color* plGetColor(Palette *palette, int id) {
	if (palette == NULL)
		return NULL;

	Mix *mix = *palette;

	while (mix != NULL && mix->id != id)
		mix = mix->next;

	if (mix == NULL)
		return NULL;

	return mix->color;
}