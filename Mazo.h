#ifndef BLACK_JACK_MAZO_H
#define BLACK_JACK_MAZO_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef enum tipopalo {
    DIAMANTES,
    PICAS,
    CORAZONES,
    TREBOLES,
    FALLO
}tipopalo;

typedef struct Carta{
    tipopalo palo;
    unsigned int numero;
    unsigned int valor;
}Carta;

typedef struct StackNode {
    Carta carta;
    struct StackNode* next;
}StackNode;

StackNode* newNode(Carta carta);
bool isEmpty (struct StackNode* stack);
bool push(struct StackNode** stack , Carta carta);
Carta pop(struct StackNode** root);

#endif