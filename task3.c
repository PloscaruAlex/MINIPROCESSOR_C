#include <stdio.h>
#define LENBINAR 32

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

    int nrInstrucPentruOperanzi = ((N + 1) * dim) / 16;
    if(((N + 1) * dim) % 16 != 0){
        nrInstrucPentruOperanzi++;
    }

    unsigned short instrucOperanzi[9] = {0};
    for(int i = 0; i < nrInstrucPentruOperanzi; ++i){
        scanf("%hu", &instrucOperanzi[i]);
    }

    /* instructiunile au fost transformate in binar si inlantuite 
    intr-un singur vector, pentru a putea lucra cu o dimensiune
    "ciudata" a operanzilor */
    int operanziBinar[144] = {0};
    for(int i = 0; i < nrInstrucPentruOperanzi; ++i){
        transformareBinarS(instrucOperanzi[i], operanziBinar + 16 * i);
    }

    int operanzi[9] = {0};
    int indexOp = 0;
    for(int i = 0; i < N + 1; ++i){
        operanzi[indexOp] = Decimal(dim, operanziBinar, dim * i);
        indexOp++;
    }

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