#include <iostream>
using namespace std;
#include "Trabalho.h"
#include <windows.h>



int main() {

    srand(time(NULL));
    defaultOptions d;
    features f;
    mob m;
    urso u;
    treante t;
    boss b;
    ladino l;
    mimico mi;
    heroAction h;
    setlocale(LC_ALL, "Portuguese");

    option(d);
    //inicia um novo jogo automatico caso o usuario nao tenha salvo nenhum jogo anteriormente.
    if(!d.save)
    {
        intro();
        doFeatures(f, d);

    }
    while (d.live) 
    {
        //Personagem inicia na taberna
        d.pos[1] = 1;

        if(d.pos[1])
        {
            taberna(d, f);
        }
        cout << "\nSAIU";
        system("pause");
    }
    return 0;
}