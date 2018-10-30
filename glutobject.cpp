/**
 * Bibliotecas.
 */

// Inclui as bibliotecas necessárias.
#include <stdio.h>
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
 * Obtém um ponto informando diretamente um ponteiro para uma coordenada.
 */

Point* obGetCoordPoint(Coord *coord) {
	if (coord == NULL)
		return NULL;

	return coord->point;
}



Point* obGetFirstPoint(Object *object) {
	if (object == NULL)
		return NULL;

	Coord *coord = *object;

	return coord->point;
}



/**
 * Obtém a próxima coordenada de uma informada.
 */

Coord* obGetNextCoord(Coord *coord) {
	if (coord == NULL)
		return NULL;

	return coord->next;
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
 * Atualiza as coordenadas de um objeto, dados seus deslocamentos.
 */

Object* obRefresh(Object *object, double x, double y) {
	if (object == NULL)
		return NULL;

	Coord *coord = *object;

	while (coord != NULL) {
		ptSet(coord->point, ptGetX(coord->point) + x, ptGetY(coord->point) + y);
		coord = coord->next;
	}

	return object;
}



/**
 * Verifica se dois retângulos drSquad() estão colidindo um no outro.
 */

bool obCrash(Object *object1, Object *object2) {
	// Verifica se os objetos existem.
	if (object1 == NULL || object2 == NULL)
		return false;

	// Cria um ponteiro para a primeira coordenada
	// registrada de cada objeto, onde, no caso
	// dos quadrados desenhados pela função drSquad(),
	// é o canto inferior esquerdo.
	Coord *coord1 = *object1;
	Coord *coord2 = *object2;

	// Instancia uma variável para cada coordenada dos pontos
	// inferior esquerdo e superior direito de cada objeto.
	double ax1, ax2, bx1, bx2;
	double ay1, ay2, by1, by2;

	// Define as coordenadas nas variáveis correspondentes
	// ao ponto inferior esquerdo de cada objeto.
	ptGet(obGetCoordPoint(coord1), &ax1, &ay1);
	ptGet(obGetCoordPoint(coord2), &bx1, &by1);

	// Define as coordenadas dos dois ponteiros como sendo
	// o canto superior direito de cada objeto.
	coord1 = obGetNextCoord(obGetNextCoord(coord1));
	coord2 = obGetNextCoord(obGetNextCoord(coord2));

	// Define as coordenadas nas variáveis correspondentes
	// ao ponto superior direito de cada objeto.
	ptGet(obGetCoordPoint(coord1), &ax2, &ay2);
	ptGet(obGetCoordPoint(coord2), &bx2, &by2);

	// Verifica se os objetos não estão sobrepostos.
	// Partindo disto, retorna o contrário, ou seja,
	// se estão sobrespostos, o retorno será verdadeiro.
	// Torna-se mais fácil a implementação desta forma,
	// visto que deveriam ser feitas mais operações lógicas
	// para verificar se está havendo sobreposição.
	return !((ax1 >= bx2 || ax2 <= bx1) || (ay1 >= by2 || ay2 <= by1));
}