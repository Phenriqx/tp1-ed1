#include <stdio.h>

#include "formula.h"

int main() {
    char arq[MAX];
    int n, m;

    printf("Insira o nome do arquivo: ");
    scanf("%s", arq);

    FILE* file = fopen(arq, "r");
    if (!file) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    fscanf(file, "%d %d", &n, &m);
    Formula* formula = criaFormula(n, m);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        fscanf(file, "%d %d %d", &a, &b, &c); 
        adicionaClausula(formula, i, a, b, c);
    }

    imprimeFormula(formula);
    return 0;
}
