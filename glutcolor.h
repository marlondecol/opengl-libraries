/**
 * Garante que a biblioteca seja chamada uma única vez.
 */

#ifndef _GLUTCOLOR_H
#define _GLUTCOLOR_H



/**
 * Protótipo da estrutura de uma cor.
 */

typedef struct color Color;



/**
 * Protótipos das funções da biblioteca.
 */

Color* clCreate(GLfloat red, GLfloat green, GLfloat blue, char *name);

void clDestroy(Color *color);

void clGet(Color *color, GLfloat *red, GLfloat *green, GLfloat *blue, char **name);

GLfloat clGetRed(Color *color);

GLfloat clGetGreen(Color *color);

GLfloat clGetBlue(Color *color);

char* clGetName(Color *color);

void clSet(Color *color, GLfloat red, GLfloat green, GLfloat blue, char *name);



/**
 * A condição envolve todo o código.
 */

#endif