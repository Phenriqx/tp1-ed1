#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "formula.h"

char intToChar(int v);

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
