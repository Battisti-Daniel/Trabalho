#include <iostream>
using namespace std;
#include "Trabalho.h"
#include <windows.h>



int main() {

    srand(time(NULL));
    defaultOptions d;
    features f;
    mob m;
    treante t;
    boss b;
    ladino l;
    mimico mi;
    heroAction h;
    urso u;
    setlocale(LC_ALL, "Portuguese");
    while (!d.start)
    {
        option(d);
    }

    //inicia um novo jogo automatico caso o usuario nao tenha salvo nenhum jogo anteriormente.
    if (!d.save)
    {
        intro();
        doFeatures(f, d);

    }
    while (d.live)
    {
        acao(d, f, h, l, u, t, mi, b);
        avanca(d);

    }
    return 0;
}
