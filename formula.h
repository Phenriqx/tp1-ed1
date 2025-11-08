#ifndef FORMULA_H
#define FORMULA_H

#define MAX 64

typedef struct clausula Clausula;
typedef struct formula Formula;

Formula* criaFormula(int n, int m);
void destroiFormula(Formula **f);
void adicionaClausula(Formula *f, int i, int a, int b, int c);
void imprimeFormula(Formula *f);
int solucaoFormula(Formula *f, int n); // deve usar recursion
int verificaClausula(Clausula *c);
int[3] proxVeri(int vet[3]);

#endif