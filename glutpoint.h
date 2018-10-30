/**
 * Garante que a biblioteca seja chamada uma única vez.
 */

#ifndef _GLUTPOINT_H
#define _GLUTPOINT_H



/**
 * Protótipo da estrutura de um ponto.
 */

typedef struct point Point;



/**
 * Protótipos das funções da biblioteca.
 */

Point* ptCreate(double x, double y);

void ptDestroy(Point *point);

void ptGet(Point *point, double *x, double *y);

double ptGetX(Point *point);

double ptGetY(Point *point);

void ptSet(Point *point, double x, double y);

void ptSetX(Point *point, double x);

void ptSetY(Point *point, double y);

double ptDistance(Point *pointA, Point *pointB);

void ptPrint(Point *point);

void ptPrint(Point *point, int precision);



/**
 * A condição envolve todo o código.
 */

#endif