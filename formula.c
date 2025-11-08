#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "formula.h"

char intToChar(int v);

struct clausula {
    int val[3];  //1 2 3
    int valorLogico[3]; // 
};  

struct formula {
    Clausula* clausulas;
    int n, m;
};  

Formula* criaFormula(int n, int m) {
    Formula* formula = (Formula*) malloc(sizeof(Formula));
    if (!formula) {
        printf("Erro de alocação\n");
        return NULL;
    }

    formula->clausulas = malloc(m * sizeof(Clausula));
    if (!formula->clausulas) 
        return NULL;

    formula->n = n;
    formula->m = m;

    return formula;
}

void destroiFormula(Formula* f) {
    if (f->clausulas) {
        free(f->clausulas);
        f->clausulas = NULL;
    }

    free (f);
    f = NULL;
}

void adicionaClausula(Formula *f, int r, int *vetAdd) {
    if (!f)
        return;

    // n variaveis  (n v n+1 v n+2 ... v nx)


    for(int i = 0; i < f->n; i++){
        f->clausulas[r].val[i] = vetAdd[i];


    }


    for(int i = 0; i < f->n; i++){

        if(f->clausulas[r].val[i] < 0){

            f->clausulas[r].valorLogico[i] = 0;


        }else{
                
            f->clausulas[r].valorLogico[i] = 1; 


        }

    }

    
}

void imprimeFormula(Formula *f) {
    for (int i = 0; i < f->m; i++) {
        printf("( ");
        for (int j = 0; j < f->n; j++) {
            if (f->clausulas[i].val[j] > 0)
                printf("%c ", intToChar(f->clausulas[i].val[j]));
            else 
                printf("~%c ", intToChar(f->clausulas[i].val[j] * -1));
            if (j < f->n - 1)
                printf(" V ");
        }
        printf(" )");
        if (i < f->m - 1)
            printf(" ∧ ");
    }

    printf("\n");
}

char intToChar(int v) {
    return v + 'a' - 1;
}
// (a v ~b v ~c ) ^ (a v b v c)


//    -1 2 3
//     1 1 1       

int solucaoFormula(Formula *f, int n, int *vet){

    for(int i = 0; i < pow(2, f->n); i++){
        int saida = verificaCada(f, n, vet);

        if(saida == 1){
            printf("\nDeu certo %d %d %d\n", vet[0], vet[1], vet[2]);
            return 1;
            i = 8;

        }else{

            proxVeri(f, vet);

        }


    }
    
    return 0;


}

int verificaCada(Formula *f, int n, int *vet){
    if(f->m == n){

        return verificaClausula(f->clausulas[n], f, vet);


    }


    int saida = verificaCada(f, n + 1, vet);

    if(saida == 0){
        return 0;
    }else{
        return verificaClausula(f->clausulas[n], f, vet);
    }


}

int verificaClausula(Clausula c, Formula *f, int *vet) {
    
    int *vetClone = malloc(f->n * sizeof(int));


    for(int i = 0; i < f->n; i++){

        vetClone[i] = vet[i];

        if(c.valorLogico[i] == 0){
            vetClone[i] = !vetClone[i];
        }


    }
    int result = vetClone[0] | vetClone[1] | vetClone[2];

    free(vetClone);

    return result;

}

//  111
//  110

void proxVeri(Formula *f, int *vet){

        for(int j = (f->n -1); j >=0; j--){

            vet[j] = !vet[j];

            if(vet[j] == 0){
                break;
            }


        }
}