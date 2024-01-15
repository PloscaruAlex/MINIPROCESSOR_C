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

    printf("%d ", N);
    for(int i = 0; i < N; ++i){
        if(Op[i] == 0){
            printf("+ ");
        }
        if(Op[i] == 1){
            printf("- ");
        }
        if(Op[i] == 2){
            printf("* ");
        }
        if(Op[i] == 3){
            printf("/ ");
        }
    }
    printf("%d\n", dim);

    return 0;
}