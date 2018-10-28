/**
 * Garante que a biblioteca seja chamada uma única vez.
 */

#ifndef _GLUTDRAW_H
#define _GLUTDRAW_H



/**
 * Bibliotecas necessárias.
 */

// Inclui bibliotecas personalizadas.
#include "glutobject.h"
#include "glutpalette.h"
#include "glutpoint.h"



/**
 * Protótipos das funções da biblioteca.
 */

void drSetPalette(Palette *palette);

Object* drPoint(int color, Point *point);
Object* drPoint(int color, Point *point, double size);
Object* drPoint(int color, double x, double y);
Object* drPoint(int color, double x, double y, double size);

Object* drLine(int color, Point *point1, Point *point2);
Object* drLine(int color, Point *point1, Point *point2, double width);
Object* drLine(int color, double x1, double y1, double x2, double y2);
Object* drLine(int color, double x1, double y1, double x2, double y2, double width);

Object* drStrip(int color, Point *points[], int coordLength);
Object* drStrip(int color, Point *points[], double width, int coordLength);
Object* drStrip(int color, double coordinates[], int coordLength);
Object* drStrip(int color, double coordinates[], double width, int coordLength);

Object* drLoop(int color, Point *points[], int coordLength);
Object* drLoop(int color, Point *points[], double width, int coordLength);
Object* drLoop(int color, double coordinates[], int coordLength);
Object* drLoop(int color, double coordinates[], double width, int coordLength);

Object* drRim(int color, Point *point, double ray, int resolution);
Object* drRim(int color, Point *point, double ray, int resolution, double width);
Object* drRim(int color, double x, double y, double ray, int resolution);
Object* drRim(int color, double x, double y, double ray, int resolution, double width);

Object* drTriangle(int color, Point *points[], int coordLength);
Object* drTriangle(int color, double coordinates[], int coordLength);

Object* drSquad(int color, Point *point, double width, double height);
Object* drSquad(int color, double x, double y, double width, double height);

Object* drPoly(int color, Point *points[], int coordLength);
Object* drPoly(int color, double coordinates[], int coordLength);

Object* drCircle(int color, Point *point, double ray, int resolution);
Object* drCircle(int color, double x, double y, double ray, int resolution);

Object* drText(int color, Point *point, char *str);
Object* drText(int color, double x, double y, char *str);



/**
 * A condição envolve todo o código.
 */

#endif