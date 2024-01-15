#include <stdio.h>
#define LENBINAR 32

/* doua functii diferite pt transformarea in baza doi
una pt numerele de tip int si una pt numerele de tip short */

void transformareBinar(unsigned int n, int *v){
    int contor = LENBINAR - 1;
    while(n){
        v[contor] = n % 2;
        n /= 2;
        contor--;
    }
}

void transformareBinarS(unsigned short n, int *v){
    int contor = 15;
    while(n){
        v[contor] = n % 2;
        n /= 2;
        contor--;
    }
}

/* o functie care returneaza valoarea in baza 10 a unui numar
in baza 2 scris intr-un vector, dar la un anumit indice din acel vector
pentru a putea folosi functia pentru dimensiuni diferite ale operanzilor
*/

int Decimal(int dim, int *v, int indice){
    int contor = 1, n = 0;
    for(int i = 0; i < dim - 1; ++i){
        contor *= 2;
    }

    for(int i = 0; i < dim; ++i, contor /= 2){
        n += contor * v[indice + i];
    }
    return n;
}

int main(){
    unsigned int instructiune;
    int instrucBinar[LENBINAR] = {0};
    int Op[8] = {0}, contorOp = 0;
    scanf("%u", &instructiune);

    transformareBinar(instructiune, instrucBinar);

    int N = 0;
    for(int i = 0, contor = 4; i < 3; ++i, contor /= 2){
        N += contor * instrucBinar[i];
    }
    N++;

    for(int i = 3; i < 2 * N + 3; i = i + 2){
        int a = instrucBinar[i];
        int b = instrucBinar[i + 1];
        Op[contorOp] = 2 * a + b;
        contorOp++;
    }

    int dim = 0;
    for(int i = 2 * N + 3, contor = 8; i < 2 * N + 7; ++i, contor /= 2){
        dim += contor * instrucBinar[i];
    }
    dim++;

    /* calculul numarului de instruciuni necesare
    pentru un anumit numar de variabile de tip short 
    si citirea instructiunilor intr-un vector */
    int nrInstrucPentruOperanzi = ((N + 1) * dim) / 16;
    if(((N + 1) * dim) % 16 != 0){
        nrInstrucPentruOperanzi++;
    }

    unsigned short instrucOperanzi[9] = {0};
    for(int i = 0; i < nrInstrucPentruOperanzi; ++i){
        scanf("%hu", &instrucOperanzi[i]);
    }

    /* transformarea instructiunilor in binar, apoi in decimal,
    cu dimensiunea corespunzatoare 
    fiecare instructiune a fost stocata pe cate un rand al unei matrici */
    int operanziBinar[9][16];
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 16; ++j){
            operanziBinar[i][j] = 0;
        }
    }

    for(int i = 0; i < nrInstrucPentruOperanzi; ++i){
        transformareBinarS(instrucOperanzi[i], operanziBinar[i]);
    }

    int operanzi[9] = {0};
    int indexOp = 0;
    for(int i = 0; i < nrInstrucPentruOperanzi; ++i){
        for(int j = 0; j < 16 / dim; ++j){
            operanzi[indexOp] = Decimal(dim, operanziBinar[i], j * dim);
            indexOp++;
        }
    }

    //calculul rezultatului, fara ordinea corecta a operatiilor
    int rezultat = operanzi[0];
    for(int i = 0; i < N; ++i){
        if(Op[i] == 0){
            rezultat += operanzi[i + 1];
        }
        if(Op[i] == 1){
            rezultat -= operanzi[i + 1];
        }
        if(Op[i] == 2){
            rezultat *= operanzi[i + 1];
        }
        if(Op[i] == 3){
            rezultat /= operanzi[i + 1];
        }
    }
    printf("%d\n", rezultat);

    return 0;
}