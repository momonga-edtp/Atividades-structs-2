#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[40];
    char autor[30];
    int ano;
    int disponivel;
} Livro;

Livro *buscarPorTitulo(Livro v[], int n, char titulo[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].titulo, titulo) == 0) {
            return &v[i];
        }
    }
    return NULL;
}

void emprestar(Livro *l) {
    l->disponivel = 0;
}

int main() {
    Livro acervo[3] = {
        {"Estruturas de Dados", "Autor A", 2018, 1},
        {"Algoritmos em C",     "Autor B", 2020, 1},
        {"Redes de Computadores", "Autor C", 2015, 1},
    };
    Livro *l;

    l = buscarPorTitulo(acervo, 3, "Algoritmos em C");
    if (l != NULL) {
        printf("Encontrado: %s (%d) - disponivel: %d\n", l->titulo, l->ano, l->disponivel);
        emprestar(l);
        printf("Apos emprestimo - disponivel: %d\n", l->disponivel);
    }

    l = buscarPorTitulo(acervo, 3, "Livro Inexistente");
    if (l == NULL) {
        printf("Livro nao encontrado\n");
    }
    return 0;
}