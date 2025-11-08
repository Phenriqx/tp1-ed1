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

    formula->clausulas = (Clausula*) malloc(m * sizeof(Clausula));
    if (!formula->clausulas) 
        return NULL;

    formula->n = n;
    formula->m = m;

    return formula;
}

void destroiFormula(Formula** f) {
    if ((*f)->clausulas) {
        free((*f)->clausulas);
        (*f)->clausulas = NULL;
    }

    free(*f);
    *f = NULL;
}

void adicionaClausula(Formula *f, int i, int a, int b, int c) {
    if (!f)
        return;

    // n variaveis  (n v n+1 v n+2 ... v nx)

    for(int i = 0; i < f->m; i++){

        for(int j = 0; j < f->n; j++){

            if(f->clausulas[i].val[j] < 0){

                f->clausulas[i].valorLogico[j] = 0;


            }else{
                
                f->clausulas[i].valorLogico[j] = 1; 


            }

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

    if(f->m == n){

        return verificaClausula;

    }


    return solucaoFormula(f, n + 1, vet);
    


}

int verificaClausula(Clausula *c, Formula *f, int *vet) {
    

    for(int i = 0; i < 3; i++){

        if(c->valorLogico[i] == 0){
            vet[i] = !vet[i];
        }


    }

    return vet[0] | vet[1] | vet[2];



}

//  111
//  110

int *proxVeri(int *vet){

        for(int j = 3; j >0; j-- ){

            vet[j] = !vet[j];

            if(vet[j] == 0){
                return vet;
            }


        }
}