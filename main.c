#include "Mazo.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

StackNode* crearMazo(StackNode *stack){
    int numbers[52];
    for (int i = 0; i < 52; i++) {
        numbers[i] = i + 1;
    }
    shuffle(numbers, 52);

    Carta *n_carta;
    for (int i = 1; i < 52; ++i) {
        n_carta = malloc(sizeof (struct Carta));
        if(numbers[i] <= 13){
            n_carta->palo = CORAZONES;
            n_carta->numero = numbers[i];
            n_carta->valor = numbers[i] > 10 ? 10 : numbers[i];
        }else if(numbers[i] <= 26){
            n_carta->palo = TREBOLES;
            n_carta->numero = numbers[i]-13;
            n_carta->valor = numbers[i]-13 > 10 ? 10 : numbers[i]-13;
        }else if(numbers[i] <= 39){
            n_carta->palo = PICAS;
            n_carta->numero = numbers[i]-13*2;
            n_carta->valor = numbers[i]-13*2 > 10 ? 10 : numbers[i]-13*2;
        }else if (numbers[i] > 39){
            n_carta->palo = DIAMANTES;
            n_carta->numero = numbers[i] - 13 * 3;
            n_carta->valor = numbers[i] - 13 * 3 > 10 ? 10 : numbers[i] - 13 * 3;
        }
        push(&stack , *n_carta);
    }
    return stack;
}

void imprimirCartas(Carta a[2] , int n){
    printf("***********************************************\n");
    for (int i = 0; i < n; ++i) {
        if(a[i].numero == 11){
            printf("La J de ");
        } else if(a[i].numero == 12){
            printf("La Q de ");
        } else if (a[i].numero == 13){
            printf("El K de ");
        } else{
            printf("El %d de " , a[i].numero);
        }
        switch (a[i].palo) {
            case 0:
                printf("Diamantes ");
                break;
            case 1:
                printf("Picas ");
                break;
            case 2:
                printf("Corazones ");
                break;
            case 3:
                printf("Treboles ");
                break;
            case 4:
                break;
        }
        printf("de valor %d \n" , a[i].valor);
    }
    printf("***********************************************\n");
}

int resultado(int player , int crupiere) {
    if (player > 21 || player < crupiere) {
        printf("PERDEDOR\n");
        return -1;
    } else if (player > crupiere) {
        printf("GANADOR\n");
        return 1;
    } else{
        printf("EMPATE\n");
        return 0;
    }
}

int main() {
    srand(time(NULL));
    StackNode* stack;
    bool fin = false;
    Carta jugador[2];
    Carta crupiere[2];

    int p = 0;
    int *perdidas = &p;
    while (!fin){
        char sino = 'A';
        stack = crearMazo(stack);
        jugador[0] = pop(&stack);
        jugador[1] = pop(&stack);
        printf("-----------------------------------------------\n");
        printf("Eres un acabao , aqui estan tus cartas:\n");
        imprimirCartas(jugador , 2);
        crupiere[0] = pop(&stack);
        crupiere[1] = pop(&stack);
        printf("Cartas del crupiere:\n");
        imprimirCartas(crupiere , 2);
        printf("-----------------------------------------------\n");
        *perdidas += resultado(jugador[0].valor+jugador[1].valor , crupiere[0].valor+crupiere[0].valor);
        printf("-----------------------------------------------\n");
        printf("Otra ronda , y/n?\n");
        scanf("%s" , &sino);
        if(sino == 'y' || sino == 'Y'){
            printf("A perder pasta gilipollas\n\n\n\n\n");
        }else
            fin = true;
    }
    printf("A ver si quedaches en positivo ou negativo %d" , *perdidas);
}