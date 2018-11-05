/**
 * Bibliotecas necessárias.
 */

// Inclui as bibliotecas necessárias.
#include <math.h>
#include <stdio.h>
#include <string.h>

// Inclui a FreeGLUT.
#include <GL/glut.h>

// Inclui bibliotecas personalizadas.
#include "glutcolor.h"
#include "glutobject.h"
#include "glutpalette.h"
#include "glutpoint.h"

// Inclui o arquivo .h desta biblioteca.
#include "glutdraw.h"



/**
 * Atribuição das variáveis globais.
 */

// Variável global usada apenas neste código.
// Ela não é compartilhada fora dele.
Palette *drPalette;



/**
 * Define a paleta a ser usada pelas funções.
 */

void drSetPalette(Palette *palette) {
	drPalette = palette;
}



/**
 * Desenha um ponto colorido com o tamanho informado.
 */

Object* drPoint(int color, Point *point) {
	// Inicia o algoritmo para desenhar uma forma
	// de acordo com a constante informada.
	glBegin(GL_POINTS);

	// Busca a cor na paleta.
	Color *cl = plGetColor(drPalette, color);

	// Define a cor da forma.
	glColor3f(clGetRed(cl), clGetGreen(cl), clGetBlue(cl));
	
	// Desenha a forma nas suas coordenadas.
	glVertex2d(ptGetX(point), ptGetY(point));

	// Instancia um novo objeto para este desenho.
	Object *pt = obCreate();

	// Adiciona a coordenada no objeto.
	obAdd(pt, point);
	
	// Finaliza o algoritmo.
 	glEnd();

    // Retorna o objeto deste desenho.
    return pt;
}

Object* drPoint(int color, Point *point, double size) {
	// Define o diâmetro do ponto.
	glPointSize(size);

	return drPoint(color, point);
}

Object* drPoint(int color, double x, double y) {
	// Instancia um novo ponto.
	Point *point = ptCreate(x, y);

	return drPoint(color, point);
}

Object* drPoint(int color, double x, double y, double size) {
	// Define o diâmetro do ponto.
	glPointSize(size);
	
	return drPoint(color, x, y);
}



/**
 * Desenha uma linha colorida simples.
 */

Object* drLine(int color, Point *point1, Point *point2) {
	// Inicia o algoritmo para desenhar uma forma
	// de acordo com a constante informada.
	glBegin(GL_LINES);

	// Busca a cor na paleta.
	Color *cl = plGetColor(drPalette, color);

	// Define a cor da forma.
	glColor3f(clGetRed(cl), clGetGreen(cl), clGetBlue(cl));
	
	// Desenha a forma nas suas coordenadas.
	glVertex2d(ptGetX(point1), ptGetY(point1));
	glVertex2d(ptGetX(point2), ptGetY(point2));

	// Instancia um novo objeto para este desenho.
	Object *line = obCreate();

	// Adiciona a coordenada no objeto.
	obAdd(line, point1);
	obAdd(line, point2);
	
	// Finaliza o algoritmo.
 	glEnd();

    // Retorna o objeto deste desenho.
    return line;
}

Object* drLine(int color, Point *point1, Point *point2, double width) {
	// Define a largura da linha.
	glLineWidth(width);

	return drLine(color, point1, point2);
}

Object* drLine(int color, double x1, double y1, double x2, double y2) {
	// Instancia dois novo pontos.
	Point *point1 = ptCreate(x1, y1);
	Point *point2 = ptCreate(x2, y2);

	return drLine(color, point1, point2);
}

Object* drLine(int color, double x1, double y1, double x2, double y2, double width) {
	// Define a largura da linha.
	glLineWidth(width);

	return drLine(color, x1, y1, x2, y2);
}



/**
 * Desenha linhas coloridas interligando todas as coordenadas,
 * uma após a outra, em sequência.
 */

Object* drStrip(int color, Point *points[], int coordLength) {
	// Inicia o algoritmo para desenhar uma forma
	// de acordo com a constante informada.
	glBegin(GL_LINE_STRIP);

	// Busca a cor na paleta.
	Color *cl = plGetColor(drPalette, color);

	// Define a cor da forma.
	glColor3f(clGetRed(cl), clGetGreen(cl), clGetBlue(cl));

	// Instancia um novo objeto para este desenho.
	Object *strip = obCreate();
	
	// Desenha a forma nas suas coordenadas.
	for (int i = 0; i < coordLength; i++) {
		glVertex2d(ptGetX(points[i]), ptGetY(points[i]));

        // Adiciona a coordenada no objeto.
        obAdd(strip, points[i]);
	}
	
	// Finaliza o algoritmo.
 	glEnd();

    // Retorna o objeto deste desenho.
    return strip;
}

Object* drStrip(int color, Point *points[], double width, int coordLength) {
	// Define a largura da linha.
	glLineWidth(width);
	
	return drStrip(color, points, coordLength);
}

Object* drStrip(int color, double coordinates[], int coordLength) {
	// Divide a quantidade de coordenadas para corresponder a quantidade de pontos.
	coordLength /= 2;

	// Instancia um novo vetor de pontos.
	Point *points[coordLength];

	// Atribui as coordenadas a cada ponto do vetor;
	for (int i = 0; i < coordLength; i++)
		points[i] = ptCreate(coordinates[i * 2], coordinates[(i * 2) + 1]);

	return drStrip(color, points, coordLength);
}

Object* drStrip(int color, double coordinates[], double width, int coordLength) {
	// Define a largura da linha.
	glLineWidth(width);
	
	return drStrip(color, coordinates, coordLength);
}



/**
 * Desenha linhas coloridas interligando todas as coordenadas,
 * interligando, também, a última coordenada com a primeira.
 */

Object* drLoop(int color, Point *points[], int coordLength) {
	// Inicia o algoritmo para desenhar uma forma
	// de acordo com a constante informada.
	glBegin(GL_LINE_LOOP);

	// Busca a cor na paleta.
	Color *cl = plGetColor(drPalette, color);

	// Define a cor da forma.
	glColor3f(clGetRed(cl), clGetGreen(cl), clGetBlue(cl));

	// Instancia um novo objeto para este desenho.
	Object *loop = obCreate();
	
	// Desenha a forma nas suas coordenadas.
	for (int i = 0; i < coordLength; i++) {
		glVertex2d(ptGetX(points[i]), ptGetY(points[i]));

        // Adiciona a coordenada no objeto.
        obAdd(loop, points[i]);
	}
	
	// Finaliza o algoritmo.
 	glEnd();

    // Retorna o objeto deste desenho.
    return loop;
}

Object* drLoop(int color, Point *points[], double width, int coordLength) {
	// Define a largura da linha.
	glLineWidth(width);
	
	return drLoop(color, points, coordLength);
}

Object* drLoop(int color, double coordinates[], int coordLength) {
	// Divide a quantidade de coordenadas para corresponder a quantidade de pontos.
	coordLength /= 2;

	// Instancia um novo vetor de pontos.
	Point *points[coordLength];

	// Atribui as coordenadas a cada ponto do vetor;
	for (int i = 0; i < coordLength; i++)
		points[i] = ptCreate(coordinates[i * 2], coordinates[(i * 2) + 1]);

	return drLoop(color, points, coordLength);
}

Object* drLoop(int color, double coordinates[], double width, int coordLength) {
	// Define a largura da linha.
	glLineWidth(width);
	
	return drLoop(color, coordinates, coordLength);
}



/**
 * Desenha uma circunferência colorida.
 */

Object* drRim(int color, Point *point, double ray, int resolution) {
	// Inicia o algoritmo para desenhar uma forma
	// de acordo com a constante informada.
    glBegin(GL_LINE_LOOP);

	// Busca a cor na paleta.
	Color *cl = plGetColor(drPalette, color);

	// Define a cor da forma.
	glColor3f(clGetRed(cl), clGetGreen(cl), clGetBlue(cl));

	// Instancia um novo objeto para este desenho.
	Object *rim = obCreate();
	
	// Desenha a forma nas suas coordenadas.
	for (int i = 0; i < resolution; i++) {
		// Calcula o ângulo entre os segmentos.
		double theta = 2.0 * M_PI * (double) i / (double) resolution;

		// Instancia um novo ponto para esta coordenada do círculo.
		Point *coord = ptCreate(ray * cos(theta) + ptGetX(point), ray * sin(theta) + ptGetY(point));
        
        // Desenha o círculo.
        glVertex2f(ptGetX(coord), ptGetY(coord));

        // Adiciona a coordenada no objeto.
        obAdd(rim, coord);
    }
    
	// Finaliza o algoritmo.
    glEnd();

    // Retorna o objeto deste desenho.
    return rim;
}

Object* drRim(int color, Point *point, double ray, int resolution, double width) {
	// Define a largura da linha.
	glLineWidth(width);

	return drRim(color, point, ray, resolution);
}

Object* drRim(int color, double x, double y, double ray, int resolution) {
	// Instancia um novo ponto.
	Point *point = ptCreate(x, y);

	return drRim(color, point, ray, resolution);
}

Object* drRim(int color, double x, double y, double ray, int resolution, double width) {
	// Define a largura da linha.
	glLineWidth(width);

	return drRim(color, x, y, ray, resolution);
}



/**
 * Desenha um triângulo colorido.
 */

Object* drTriangle(int color, Point *point1, Point *point2, Point *point3) {
	// Inicia o algoritmo para desenhar uma forma
	// de acordo com a constante informada.
	glBegin(GL_TRIANGLES);

	// Busca a cor na paleta.
	Color *cl = plGetColor(drPalette, color);

	// Define a cor da forma.
	glColor3f(clGetRed(cl), clGetGreen(cl), clGetBlue(cl));
	
	// Desenha a forma nas suas coordenadas.
	glVertex2d(ptGetX(point1), ptGetY(point1));
	glVertex2d(ptGetX(point2), ptGetY(point2));
	glVertex2d(ptGetX(point3), ptGetY(point3));

	// Instancia um novo objeto para este desenho.
	Object *triangle = obCreate();

    // Adiciona as coordenadas no objeto.
    obAdd(triangle, point1);
    obAdd(triangle, point2);
    obAdd(triangle, point3);
	
	// Finaliza o algoritmo.
	glEnd();

    // Retorna o objeto deste desenho.
    return triangle;
}

Object* drTriangle(int color, double x1, double y1, double x2, double y2, double x3, double y3) {
	// Instancia três novo pontos.
	Point *point1 = ptCreate(x1, y1);
	Point *point2 = ptCreate(x2, y2);
	Point *point3 = ptCreate(x3, y3);

	return drTriangle(color, point1, point2, point3);
}



/**
 * Desenha um polígono colorido de 4 coordenadas.
 */

Object* drSquad(int color, Point *point, double width, double height) {
	// Inicia o algoritmo para desenhar uma forma
	// de acordo com a constante informada.
	glBegin(GL_QUADS);

	// Busca a cor na paleta.
	Color *cl = plGetColor(drPalette, color);

	// Define a cor da forma.
	glColor3f(clGetRed(cl), clGetGreen(cl), clGetBlue(cl));

	// Instancia os outros pontos.
	Point *point2 = ptCreate(ptGetX(point) + width, ptGetY(point));
	Point *point3 = ptCreate(ptGetX(point) + width, ptGetY(point) + height);
	Point *point4 = ptCreate(ptGetX(point), ptGetY(point) + height);

	// Desenha a forma nas suas coordenadas.
	glVertex2d(ptGetX(point), ptGetY(point));
	glVertex2d(ptGetX(point2), ptGetY(point2));
	glVertex2d(ptGetX(point3), ptGetY(point3));
	glVertex2d(ptGetX(point4), ptGetY(point4));

	// Instancia um novo objeto para este desenho.
	Object *squad = obCreate();

    // Adiciona as coordenadas no objeto.
    obAdd(squad, point);
    obAdd(squad, point2);
    obAdd(squad, point3);
    obAdd(squad, point4);
	
	// Finaliza o algoritmo.
	glEnd();

    // Retorna o objeto deste desenho.
    return squad;
}

Object* drSquad(int color, double x, double y, double width, double height) {
	// Instancia um novo ponto.
	Point *point = ptCreate(x, y);

	return drSquad(color, point, width, height);
}



/**
 * Desenha um polígono colorido de vários lados.
 */

Object* drPoly(int color, Point *points[], int coordLength) {
	// Inicia o algoritmo para desenhar uma forma
	// de acordo com a constante informada.
	glBegin(GL_POLYGON);

	// Busca a cor na paleta.
	Color *cl = plGetColor(drPalette, color);

	// Define a cor da forma.
	glColor3f(clGetRed(cl), clGetGreen(cl), clGetBlue(cl));

	// Instancia um novo objeto para este desenho.
	Object *poly = obCreate();
	
	// Desenha a forma nas suas coordenadas.
	for (int i = 0; i < coordLength; i++) {
		glVertex2d(ptGetX(points[i]), ptGetY(points[i]));

        // Adiciona a coordenada no objeto.
        obAdd(poly, points[i]);
	}
	
	// Finaliza o algoritmo.
	glEnd();

    // Retorna o objeto deste desenho.
    return poly;
}

Object* drPoly(int color, double coordinates[], int coordLength) {
	// Divide a quantidade de coordenadas para corresponder a quantidade de pontos.
	coordLength /= 2;

	// Instancia um novo vetor de pontos.
	Point *points[coordLength];

	// Atribui as coordenadas a cada ponto do vetor;
	for (int i = 0; i < coordLength; i++)
		points[i] = ptCreate(coordinates[i * 2], coordinates[(i * 2) + 1]);

	return drPoly(color, points, coordLength);
}



/**
 * Desenha um círculo colorido.
 * 
 * Retirado de: https://stackoverflow.com/questions/22444450/drawing-circle-with-opengl
 */

Object* drCircle(int color, Point *point, double ray, int resolution) {
	// Inicia o algoritmo para desenhar uma forma
	// de acordo com a constante informada.
    glBegin(GL_POLYGON);

	// Busca a cor na paleta.
	Color *cl = plGetColor(drPalette, color);

	// Define a cor da forma.
	glColor3f(clGetRed(cl), clGetGreen(cl), clGetBlue(cl));

	// Instancia um novo objeto para este desenho.
	Object *circle = obCreate();
	
	// Desenha a forma nas suas coordenadas.
	for (int i = 0; i < resolution; i++) {
		// Calcula o ângulo entre os segmentos.
		double theta = 2.0 * M_PI * (double) i / (double) resolution;

		// Instancia um novo ponto para esta coordenada do círculo.
		Point *coord = ptCreate(ray * cos(theta) + ptGetX(point), ray * sin(theta) + ptGetY(point));
        
        // Desenha o círculo.
        glVertex2f(ptGetX(coord), ptGetY(coord));

        // Adiciona a coordenada no objeto.
        obAdd(circle, coord);
    }
    
	// Finaliza o algoritmo.
    glEnd();

    // Retorna o objeto deste desenho.
    return circle;
}

Object* drCircle(int color, double x, double y, double ray, int resolution) {
	// Instancia um novo ponto.
	Point *point = ptCreate(x, y);

	return drCircle(color, point, ray, resolution);
}



/**
 * Renderiza um texto na tela.
 * A fonte padrão, caso não seja informada,
 * é GLUT_BITMAP_HELVETICA_18
 */

Object* drText(int color, Point *point, char *str, void *font) {
	// Busca a cor na paleta.
	Color *cl = plGetColor(drPalette, color);

	// Define a cor da forma.
	glColor3f(clGetRed(cl), clGetGreen(cl), clGetBlue(cl));

	// Inicia a matriz de coordenadas do texto.
	glPushMatrix();

	// Instancia um novo objeto para este desenho.
	Object *text = obCreate();

    // Adiciona a coordenada no objeto.
    obAdd(text, point);

    // Define a posição do texto.
	glRasterPos2f(ptGetX(point), ptGetY(point));

	// Insere o texto na tela, caractere a caractere.
	while (*str)
		glutBitmapCharacter(font, *str++);

	// Finaliza a matriz de coordenadas.
	glPopMatrix();

    // Retorna o objeto deste desenho.
    return text;
}

Object* drText(int color, double x, double y, char *str, void *font) {
	// Instancia um novo ponto.
	Point *point = ptCreate(x, y);

	return drText(color, point, str, font);
}

Object* drText(int color, Point *point, char *str, void *font, bool rightJustify) {
	// Possui o tamanho da cadeia de caracteres.
    // Esta variável só será usada se o texto for alinhado a direita.
    double sum = 0;

    // Caso deve alinhar a direita
    if (rightJustify) {
    	// Cria uma nova cadeia de caracteres a partir do tamanho da original.
	    char *_str = (char*) malloc(strlen(str));

	    // Copia a string original para a criada acima.
	    strcpy(_str, str);

	    // Desconta a largura do primeiro caractere.
	    sum -= (double) glutBitmapWidth(font, *_str++);

	    // Calcula a largura do resto do texto.
	    while (*_str)
	    	sum += (double) glutBitmapWidth(font, *_str++);
	}

	// Altera o valor de X da coordenada
	// considerando o deslocamento para a esquerda.
	ptSetX(point, ptGetX(point) - sum);

	return drText(color, point, str, font);
}

Object* drText(int color, double x, double y, char *str, void *font, bool rightJustify) {
	// Instancia um novo ponto.
	Point *point = ptCreate(x, y);

	return drText(color, point, str, font, rightJustify);
}

Object* drText(int color, Point *point, char *str) {
	return drText(color, point, str, GLUT_BITMAP_HELVETICA_18);
}

Object* drText(int color, double x, double y, char *str) {
	return drText(color, x, y, str, GLUT_BITMAP_HELVETICA_18);
}

Object* drText(int color, Point *point, char *str, bool rightJustify) {
	return drText(color, point, str, GLUT_BITMAP_HELVETICA_18, rightJustify);
}

Object* drText(int color, double x, double y, char *str, bool rightJustify) {
	return drText(color, x, y, str, GLUT_BITMAP_HELVETICA_18, rightJustify);
}