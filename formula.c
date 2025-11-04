#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "formula.h"

struct clausula {
    int val[3];
    bool valorLogico[3];
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
