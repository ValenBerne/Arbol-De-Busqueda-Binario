#include    "abb.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define ERROR -1
#define EXITO 0

int comparador_pruebas(void* uno, void* dos){
    if(!uno || !dos)
        return 0;

    if(uno>dos)
        return 1;

    if(uno<dos)
        return -1;

    return 0;/*
    if((int)uno  ==  (int)dos){
        return 0;
    }
    else if((int)uno <   (int)dos){
        return 1;
    }
    else if((int)dos >   (int)uno){
        return -1;
    }*/
}

void destructor_pruebas(void* destruido){
    if(!destruido)
        return;
    free(destruido);
}

void pruebas_con_NULL(){
    abb_t* arbol = arbol_crear(comparador_pruebas, destructor_pruebas);

    printf("\nPruebas con NULL:\n\n");

    printf("Insertar un elemento NULL devuelve error: %s\n", (arbol_insertar(arbol, NULL))==ERROR?"ATR SALIO BIEN":"AL LOBBY");
    printf("Borrar un elemento NULL devuelve error: %s\n", (arbol_borrar(arbol, NULL))==ERROR?"ATR SALIO BIEN":"AL LOBBY");
    printf("Buscar un elemento NULL devuelve NULL: %s\n", (arbol_buscar(arbol, NULL))==NULL?"ATR SALIO BIEN":"AL LOBBY");
    printf("Ver la raiz de un arbol NULL devuelve NULL: %s\n", (arbol_raiz(NULL))==NULL?"ATR SALIO BIEN":"AL LOBBY");
    printf("Ver ver si esta vacio un arbol NULL devuelve NULL: %s\n", (arbol_vacio(NULL))==true?"ATR SALIO BIEN":"AL LOBBY");

    arbol_destruir(arbol);
}

void pruebas_iteradores() {
    abb_t *arbol = arbol_crear(comparar_cosas, destructor_de_cosas);

    cosa_t *c1 = crear_cosa(1);
    cosa_t *c2 = crear_cosa(2);
    cosa_t *c3 = crear_cosa(3);
    cosa_t *c4 = crear_cosa(4);
    cosa_t *c5 = crear_cosa(5);
    cosa_t *c6 = crear_cosa(6);
    cosa_t *c7 = crear_cosa(7);
    arbol_insertar(arbol, c4);
    arbol_insertar(arbol, c2);
    arbol_insertar(arbol, c6);
    arbol_insertar(arbol, c1);
    arbol_insertar(arbol, c3);
    arbol_insertar(arbol, c5);
    arbol_insertar(arbol, c7);

    printf("\n\n\nPruebas con iteradores:\n\n");

    cosa_t *elementos[10];

    printf("Recorrido inorden (deberian salir en orden 1 2 3 4 5 6 7): ");
    int cantidad = arbol_recorrido_inorden(arbol, (void **) elementos, 10);
    for (int i = 0; i < cantidad; i++)
        printf("%i ", elementos[i]->clave);
    printf("\n");

    printf("Recorrido preorder (deberian salir en orden 4 2 1 3 6 5 7): ");
    cantidad = arbol_recorrido_preorden(arbol, (void **) elementos, 10);
    for (int i = 0; i < cantidad; i++)
        printf("%i ", elementos[i]->clave);
    printf("\n");

    printf("Recorrido postorden (deberian salir en orden  1 3 2 5 7 6 4): ");
    cantidad = arbol_recorrido_postorden(arbol, (void **) elementos, 10);
    for (int i = 0; i < cantidad; i++)
        printf("%i ", elementos[i]->clave);
    printf("\n");

    arbol_destruir(arbol);
}

void pruebas_varias(){
    abb_t *arbol = arbol_crear(comparar_cosas, destructor_de_cosas);

    cosa_t *c1 = crear_cosa(1);
    cosa_t *c2 = crear_cosa(2);
    cosa_t *c3 = crear_cosa(3);
    cosa_t *c4 = crear_cosa(4);
    cosa_t *c5 = crear_cosa(5);
    cosa_t *c6 = crear_cosa(6);
    cosa_t *c7 = crear_cosa(7);
    cosa_t *auxiliar = crear_cosa(0);
    arbol_insertar(arbol, c4);
    arbol_insertar(arbol, c2);
    arbol_insertar(arbol, c6);
    arbol_insertar(arbol, c1);
    arbol_insertar(arbol, c3);
    arbol_insertar(arbol, c5);
    arbol_insertar(arbol, c7);

    printf("\n\n\nPruebas Varias:\n\n");

    auxiliar->clave = 4;
    printf("Borro la raiz (4): %s\n", (arbol_borrar(arbol, auxiliar))==0?"SI":"NO");

    printf("El nodo raiz deberia ser 3: %s\n", ((cosa_t*)arbol_raiz(arbol))->clave==3?"SI":"NO");

    auxiliar->clave = 2;
    printf("Busco el elemento 2: %s\n", ((cosa_t*)arbol_buscar(arbol, auxiliar))->clave==2?"No existe! (Good)":"NO pasas");

    auxiliar->clave = 2;
    printf("Borro nodo con un hijo (2): %s\n", (arbol_borrar(arbol, auxiliar))==0?"SI":"NO");

    auxiliar->clave = 1;
    printf("Borro nodo hoja (1): %s\n", (arbol_borrar(arbol, auxiliar))==0?"SI":"NO");

    auxiliar->clave = 6;
    printf("Borro nodo con dos hijos (6): %s\n", (arbol_borrar(arbol, auxiliar))==0?"SI":"NO");


    auxiliar->clave = 3;
    printf("Busco el elemento (3): %s\n", ((cosa_t*)arbol_buscar(arbol, auxiliar))->clave==3?"SI":"NO");

    arbol_destruir(arbol);
}

int pruebas_mias(){
    pruebas_con_NULL();
    pruebas_iteradores();
    pruebas_varias();
}