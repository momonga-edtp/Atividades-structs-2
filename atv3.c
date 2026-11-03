#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Ponto;

typedef struct {
    Ponto a;
    Ponto b;
} Retangulo;

int area(Retangulo r) {
    return abs(r.b.x - r.a.x) * abs(r.b.y - r.a.y);
}

int perimetro(Retangulo r) {
    return 2 * (abs(r.b.x - r.a.x) + abs(r.b.y - r.a.y));
}

void deslocar(Retangulo *r, int dx, int dy) {
    r->a.x += dx;
    r->a.y += dy;
    r->b.x += dx;
    r->b.y += dy;
}

int main() {
    Retangulo ret = {{2, 3}, {10, 7}};

    printf("Area: %d\n", area(ret));
    printf("Perimetro: %d\n", perimetro(ret));
    deslocar(&ret, 5, -1);
    printf("Novo a: (%d, %d)\n", ret.a.x, ret.a.y);
    printf("Novo b: (%d, %d)\n", ret.b.x, ret.b.y);
    printf("Area depois: %d\n", area(ret));
    return 0;
}