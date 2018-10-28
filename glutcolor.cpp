/**
 * Bibliotecas.
 */

// Inclui as bibliotecas necessárias.
#include <stdlib.h>
#include <string.h>

// Inclui a FreeGLUT.
#include <GL/glut.h>

// Inclui o arquivo .h deste arquivo.
#include "glutcolor.h"



/**
 * Definição da estrutura de uma cor.
 */

struct color {
	GLfloat red, green, blue;
	char name[20];
};



/**
 * Instancia uma nova cor e define seus atributos.
 */

Color* clCreate(GLfloat red, GLfloat green, GLfloat blue, char *name) {
	Color *color = (Color*) malloc(sizeof(Color));

	if (color != NULL) {
		color->red = red;
		color->green = green;
		color->blue = blue;

		strcpy(color->name, name);
	}

	return color;
}



/**
 * Destrói a instância da cor informada.
 */

void clDestroy(Color *color) {
	free(color);
}



/**
 * Obtém todos os atributos da cor informada.
 */

void clGet(Color *color, GLfloat *red, GLfloat *green, GLfloat *blue, char *name) {
	*red = color->red;
	*green = color->green;
	*blue = color->blue;

	strcpy(name, color->name);
}



/**
 * Obtém apenas o tom de vermelho da cor informada.
 */

GLfloat clGetRed(Color *color) {
	return color->red;
}



/**
 * Obtém apenas o tom de verde da cor informada.
 */

GLfloat clGetGreen(Color *color) {
	return color->green;
}



/**
 * Obtém apenas o tom de azul da cor informada.
 */

GLfloat clGetBlue(Color *color) {
	return color->blue;
}



/**
 * Obtém apenas o nome da cor informada.
 */

char* clGetName(Color *color) {
	return color->name;
}



/**
 * Define ou redefine os atributos da cor informada.
 */

void clSet(Color *color, GLfloat red, GLfloat green, GLfloat blue, char *name) {
	color->red = red;
	color->green = green;
	color->blue = blue;

	strcpy(color->name, name);
}