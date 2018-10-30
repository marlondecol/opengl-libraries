/**
 * Bibliotecas.
 */

// Inclui as bibliotecas necessárias.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Inclui o arquivo .h desta biblioteca.
#include "glutpoint.h"



/**
 * Definição da estrutura de um ponto.
 */

struct point {
	double x;
	double y;
};



/**
 * Instancia um ponto e atribui suas coordenadas.
 */

Point* ptCreate(double x, double y) {
	Point *point = (Point*) malloc(sizeof(Point));

	if (point != NULL) {
		point->x = x;
		point->y = y;
	}

	return point;
}



/**
 * Destrói a instância do ponto informado.
 */

void ptDestroy(Point *point) {
	free(point);
}



/**
 * Obtêm as coordenadas do ponto informado.
 */

void ptGet(Point *point, double *x, double *y) {
	*x = point->x;
	*y = point->y;
}



/**
 * Obtém apenas a coordenada X do ponto informado.
 */

double ptGetX(Point *point) {
	return point->x;
}



/**
 * Obtém apenas a coordenada X do ponto informado.
 */

double ptGetY(Point *point) {
	return point->y;
}



/**
 * Atribui coordenadas à um ponto.
 */

void ptSet(Point *point, double x, double y) {
	point->x = x;
	point->y = y;
}



/**
 * Atribui a coordenada X à um ponto.
 */

void ptSetX(Point *point, double x) {
	point->x = x;
}



/**
 * Atribui a coordenada Y à um ponto.
 */

void ptSetY(Point *point, double y) {
	point->y = y;
}



/**
 * Calcula a distância entre dois pontos.
 */

double ptDistance(Point *pointA, Point *pointB) {
	double dx = pointA->x - pointB->x;
	double dy = pointA->y - pointB->y;

	return sqrt(dx * dx + dy * dy);
}



/**
 * Imprime no terminal as coordenadas do ponto informado.
 */

void ptPrint(Point *point) {
	ptPrint(point, 5);
}



/**
 * Imprime no terminal as coordenadas do ponto informado, usando
 * valores com uma quantidade de casas decimais informadas manualmente.
 */

void ptPrint(Point *point, int precision) {
	printf("x: %*.*lf   y: %*.*lf\n", precision + 7, precision, point->x, precision + 7, precision, point->y);
}