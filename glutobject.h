/**
 * Garante que a biblioteca seja chamada uma única vez.
 */

#ifndef _GLUTOBJECT_H
#define _GLUTOBJECT_H



/**
 * Bilbiotecas necessárias.
 */

// Inclui bibliotecas personalizadas.
#include "glutpoint.h"



/**
 * Protótipo da estrutura de um objeto.
 */

typedef struct coord Coord;

typedef struct coord* Object;



/**
 * Protótipos das funções da biblioteca.
 */

Object* obCreate();

void obDestroy(Object *object);

int obAdd(Object *object, Point *point);

int obRemove(Object *object, int id);

int obCoordLength(Object *object);

Point* obGetCoordPoint(Coord *coord);

Point* obGetFirstPoint(Object *object);

Coord* obGetNextCoord(Coord *coord);

Point* obGetPoint(Object *object, int id);

Object* obRefresh(Object *object, double x, double y);

bool obCrash(Object *object1, Object *object2);



/**
 * A condição envolve todo o código.
 */

#endif