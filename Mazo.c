#include "Mazo.h"

bool isEmpty(struct StackNode* stack){
    return stack == NULL;
}

StackNode* newNode(Carta carta){
    struct StackNode* nodonext = malloc(sizeof (struct StackNode));
    nodonext->carta = carta;
    nodonext->next = NULL;
    return nodonext;
}

bool push(struct StackNode** root, Carta carta) {
    struct StackNode *stackNode = newNode(carta);
    stackNode->next = *root;
    *root = stackNode;
    return true;
}

Carta pop(struct StackNode** root){
    if (isEmpty(*root)){
        Carta fallo;
        fallo.palo = FALLO;
        return fallo;
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    Carta popped = temp->carta;
    free(temp);
    return popped;
}