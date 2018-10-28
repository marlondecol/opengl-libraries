/**
 * Bibliotecas.
 */

// Inclui as bibliotecas necessárias.
#include <stdlib.h>

// Inclui a FreeGLUT.
#include <GL/glut.h>

// Inclui bibliotecas personalizadas.
#include "glutpoint.h"

// Inclui o arquivo .h deste arquivo.
#include "glutobject.h"



/**
 * Definição da estrutura de um objeto.
 */

struct coord {
	int id;
	Point *point;
	Coord *next;
};



/**
 * Cria um novo objeto.
 */

Object* obCreate() {
	Object *object = (Object*) malloc(sizeof(Object));

	if (object != NULL)
		*object = NULL;

	return object;
}



/**
 * Destrói a instância do objeto informada.
 */

void obDestroy(Object *object) {
	if (object != NULL) {
		Coord *coord;

		while ((*object) != NULL) {
			coord = *object;
			*object = (*object)->next;

			free(coord);
		}

		free(object);
	}
}



/**
 * Insere uma coordenada no objeto.
 */

int obAdd(Object *object, Point *point) {
	if (object == NULL)
		return 0;

	Coord *coord = (Coord*) malloc(sizeof(Coord));

	if (coord == NULL)
		return 0;

	coord->id = obCoordLength(object);
	coord->point = point;
	coord->next = NULL;

	if ((*object) == NULL)
		*object = coord;
	else {
		Coord *aux = *object;

		while (aux->next != NULL)
			aux = aux->next;

		aux->next = coord;
	}

	return 1;
}



/**
 * Remove uma coordenada do objeto informando o atributo "id" do elemento.
 */

int obRemove(Object *object, int id) {
	if (object == NULL)
		return 0;

	Coord *prev;
	Coord *coord = *object;

	while (coord != NULL && coord->id != id) {
		prev = coord;
		coord = coord->next;
	}

	if (coord == NULL)
		return 0;

	if (coord == *object)
		*object = coord->next;
	else
		prev->next = coord->next;

	free(coord);

	return 1;
}



/**
 * Obtém a quantidade de coordenadas do objeto informado.
 */

int obCoordLength(Object *object) {
	if (object == NULL)
		return 0;

	int size = 0;

	Coord *coord = *object;

	while (coord != NULL) {
		size++;
		coord = coord->next;
	}

	return size;
}



/**
 * Obtém uma coordenadas do objeto informando o atributo "id" do elemento.
 */

Point* obGetPoint(Object *object, int id) {
	if (object == NULL)
		return NULL;

	Coord *coord = *object;

	while (coord != NULL && coord->id != id)
		coord = coord->next;

	if (coord == NULL)
		return NULL;

	return coord->point;
}



/**
 * Verifica se dois objetos estão colidindo um no outro.
 */

int obCrash(Object *object1, Object *object2) {

}