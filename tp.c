#include <stdio.h>

#include "formula.h"

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    Formula *formula = criaFormula(n, m);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c); 
        adicionaClausula(formula, i, a, b, c);
    }

    imprimeFormula(formula);
    return 0;
}