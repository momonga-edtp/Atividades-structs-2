#include <stdio.h>

typedef struct {
    char nome[30];
    float notas[3];
} Aluno;

float media(Aluno a) {
    return (a.notas[0] + a.notas[1] + a.notas[2]) / 3.0f;
}

void imprimirBoletim(Aluno turma[], int n) {
    float somaTurma = 0;
    for (int i = 0; i < n; i++) {
        float med = media(turma[i]);
        printf("%s: %.1f\n", turma[i].nome, med);
        somaTurma += med;
    }
    printf("Media da turma: %.1f\n", somaTurma / n);
}

int main() {
    Aluno turma[4] = {
        {"Ana",   {8.0f, 7.5f, 9.0f}},
        {"Bruno", {5.0f, 6.0f, 4.0f}},
        {"Carla", {9.5f, 8.5f, 10.0f}},
        {"Diego", {6.0f, 6.5f, 7.0f}},
    };

    imprimirBoletim(turma, 4);
    return 0;
}