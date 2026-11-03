#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[30];
    Data data;
} Evento;

int dataMaior(Data d1, Data d2) {
    if (d1.ano > d2.ano) return 1;
    if (d1.ano < d2.ano) return 0;
    if (d1.mes > d2.mes) return 1;
    if (d1.mes < d2.mes) return 0;
    if (d1.dia > d2.dia) return 1;
    return 0;
}

Evento *eventoMaisRecente(Evento v[], int n) {
    Evento *maisRecente = &v[0];
    for (int i = 1; i < n; i++) {
        if (dataMaior(v[i].data, maisRecente->data)) {
            maisRecente = &v[i];
        }
    }
    return maisRecente;
}

int main() {
    Evento agenda[4] = {
        {"Reuniao de projeto",   {10, 3, 2026}},
        {"Entrega do TCC",       {21, 9, 2026}},
        {"Seminario de pesquisa",{5, 9, 2026}},
        {"Banca",                {2, 12, 2025}},
    };
    Evento *e;

    e = eventoMaisRecente(agenda, 4);
    printf("Mais recente: %s (%d/%d/%d)\n", e->nome, e->data.dia, e->data.mes, e->data.ano);
    return 0;
}