#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <stdlib.h>
#include<time.h>

struct defaultOptions
{
    int pos = 0, dia = 0;
    int rlucky = 2, mortes = 0, moedas = 120, taberneirocount = 0;
    int weapon = 0,exppoints = 1000, healfix = 0;
    bool start = false, live = true, save = false, ladina = true, taberneiro = false, going = false, taberneirof = false, ladinaf = false;
    string classe;
    int ursos = 10, treantes = 5, mimicos = 2, boss = 1;
};

void lobby()
{
    system("cls");
    ifstream lobbytext;
    string phrase;
    lobbytext.open("lobby.txt");
    while (lobbytext.eof() == false)
    {
        getline(lobbytext, phrase);
        cout << phrase << "\n";
    }
    lobbytext.close();
}

int option(defaultOptions& d)
{
    int value = 0;
    while (value < 1 or value > 4)
    {
        lobby();
        cin >> value;
    }

    switch (value)
    {

    case 4:
    {
        exit(0);
        break;
    }

    case 3:
    {
        system("cls");
        ifstream creditos;
        string phrase;
        creditos.open("creditos.txt");
        while (creditos.eof() == false)
        {
            getline(creditos, phrase);
            cout << phrase << "\n";
        }
        system("pause");
        creditos.close();
        break;
    }
    case 2:
        do {
            system("cls");
            ifstream textoptions;
            string phrase;
            textoptions.open("options.txt");
            while (textoptions.eof() == false)
            {
                getline(textoptions, phrase);
                cout << phrase << "\n";
            }
            cin >> value;
            textoptions.close();
        } while (value < 1 or value > 2);
        if (value == 1)
        {
            do {
                system("cls");
                ifstream sortype;
                string phrase;
                sortype.open("sortype.txt");
                while (sortype.eof() == false)
                {
                    getline(sortype, phrase);
                    cout << phrase << "\n";
                }

                cin >> d.rlucky;
                sortype.close();
            } while (d.rlucky < 1 or d.rlucky > 3);
        }
        break;

    case 1:
        d.start = true;
        break;

    default:
        option(d);
    }
}

struct features
{
    int hp = 0, luck = 0, str = 0, inte = 0, classe;
    string name;
};

void doFeatures(features& f, defaultOptions& d)
{
    system("cls");
    int confirm = 0;
    cout << "Qual ?? mesmo o seu nome? \n";
    cout << "Seu nome: ";
    cin >> f.name;
    do
    {
        system("cls");
        cout << "Entendo, seu nome ?? " << f.name << " isso mesmo? \n\n";
        cout << "1 - Acenar com a cabe??a que sim \t 2 - Tentar lembrar do nome \n";
        cin >> confirm;
        if (confirm == 2)
        {
            system("cls");
            cout << "Seu nome: ";
            cin >> f.name;
        }
    } while (confirm != 1);
    do {
        system("cls");
        cout << "Escolha sua classe \n\n";
        cout << "1 - Guerreiro \t 2 - Mago \t 3 - Arqueiro \t \n";
        cin >> f.classe;

    } while (f.classe < 1 or f.classe > 3);
    if (f.classe == 1)
    {
        d.classe = "Guerreiro";
    }
    else if (f.classe == 2)
    {
        d.classe = "Mago";
    }
    else if (f.classe == 3)
    {
        d.classe = "Arqueiro";
    }
    system("cls");
    cout << "Voc?? foi cadastrado na cidade Albadram com sucesso " << f.name << " , caso tenha problemas venha me ver!\n";
    system("pause");
    system("cls");
    f.hp = 100;
    f.luck = 0;
    f.inte = 0;
    f.str = 0;
    d.healfix = f.hp;
}

void intro()
{
    system("cls");
    ifstream intro;
    string phrase;
    int currentLine = 0;
    intro.open("intro.txt");
    while (!intro.eof()) {
        getline(intro, phrase);
        cout << phrase << "\n";
        system("pause");
        system("cls");
    }
    intro.close();
}

void showFeatures(features f, defaultOptions d)
{
    system("cls");
    cout << "Suas caracteristicas s??o. \n";
    cout << "Hp: " << f.hp << "\n";
    cout << "Sorte: " << f.luck << "\n";
    cout << "For??a: " << f.str << "\n";
    cout << "inteligencia: " << f.inte << "\n";
    cout << "Voc?? ?? da classe: " << d.classe << "\n";
    cout << "Voc?? tem " << d.moedas << " moedas\n";
    system("pause");
}

void changeFeatures(features& f, defaultOptions &d)
{
    system("cls");
    int change = 0, quant = 0;
    do
    {
        cout << "Voc?? deseja ver seus atributos? \n";
        cout << "1 - Sim \t 2 - N??o \n";
        cin >> change;
        system("cls");
    } while (change < 1 or change > 2);
    if (change == 1)
    {
        change = 0;
        cout << "Voc?? tem no total " << d.exppoints << " pontos de experi??ncia \n";
        system("pause");
        system("cls");
        if (d.exppoints <= 0)
        {
            cout << "Voc?? n??o tem pontos para atribuir \n";
            system("pause");
            system("cls");
        }
        else
        {
            while (d.exppoints > 0)
            {
                cout << "Qual caracteristicas gostaria de aumentar? \n";
                cout << "1 - Vida \n2 - Sorte \n3 - For??a \n4 - Inteligencia \nPontos restantes: " << d.exppoints << "\n";
                cin >> change;
                switch (change)
                {
                case 1:
                {
                    cout << "Quantos pontos gostaria de atribuir? \n";
                    cin >> quant;
                    while (d.exppoints < quant)
                    {
                        system("cls");
                        cout << "Insira um valor v??lido\nQuantos pontos gostaria de atribuir\nHP+";
                        cout << "\nPontos disponiveis: " << d.exppoints << "\n";
                        cin >> quant;
                    }
                    d.exppoints -= quant;
                    f.hp += quant;
                    d.healfix += quant;
                    break;
                }
                case 2:
                {
                    cout << "Quantos pontos gostaria de atribuir? \n";
                    cin >> quant;
                    while (d.exppoints < quant)
                    {
                        system("cls");
                        cout << "Insira um valor v??lido\nQuantos pontos gostaria de atribuir\nSORTE+";
                        cout << "\nPontos disponiveis: " << d.exppoints << "\n";
                        cin >> quant;
                    }
                    d.exppoints -= quant;
                    f.luck += quant;
                    break;
                }
                case 3:
                {
                    cout << "Quantos pontos gostaria de atribuir? \n";
                    cin >> quant;
                    while (d.exppoints < quant)
                    {
                        system("cls");
                        cout << "Insira um valor v??lido\nQuantos pontos gostaria de atribuir\nFOR??A+";
                        cout << "\nPontos disponiveis: " << d.exppoints << "\n";
                        cin >> quant;
                    }
                    d.exppoints -= quant;
                    f.str += quant;
                    break;
                }
                case 4:
                {
                    cout << "Quantos pontos gostaria de atribuir? \n";
                    cin >> quant;
                    while (d.exppoints < quant)
                    {
                        system("cls");
                        cout << "Insira um valor v??lido\nQuantos pontos gostaria de atribuir\nINTELIGENCIA+";
                        cout << "\nPontos disponiveis: " << d.exppoints << "\n";
                        cin >> quant;
                    }
                    d.exppoints -= quant;
                    f.inte += quant;
                    break;
                }
                }
                system("cls");
            }
        }
    }
}

struct mob
{
    int attack, mp, hp;
    bool block;
};

struct heroAction
{
    defaultOptions d;
    int attack = 17 + d.weapon, mp, spell;
    bool block, turn;
};

struct urso
{
    int hp = 100;
    int attack = 3;
    int mp = 10;
    bool block = false;
};

struct treante
{
    int hp = 150;
    int attack = 15;
    int mp = 30;
    bool block = false;
};

struct mimico
{
    int hp = 700;
    int attack = 10;
    int mp = 0;
    bool block = false;
};

struct boss
{
    int hp = 500;
    int attack = 35;
    int mp = 30;
    bool block = false;
};

struct ladino
{
    int hp = 30;
    int attack = 15;
    int mp = 10;
    bool block = false;
};

void lutaUrso(urso u, features& f, heroAction h, defaultOptions &d)
{
    if (d.ursos > 1)
    {
        while (u.hp > 0 or f.hp > 0)
        {
            system("cls");
            int choice = 0;
            int pass = 0;
            int echoice = 0;
            h.block = false;

            do
            {
                system("cls");
                cout << "Seu turno, oque deseja fazer? \n";
                cout << "1 - Atacar \t 2 - Defender \n";
                cin >> choice;
            } while (choice < 1 or choice > 2);
            switch (choice)
            {
            case 1:
            {
                switch (f.classe)
                {
                case 1:
                {
                    cout << "Voc?? desfere um poderoso golpe de espada\n";
                    if (u.block == true)
                    {
                        cout << "O inimigo se defendeu do ataque\n";
                    }
                    else
                    {
                        u.hp -= h.attack + rand() % 20 + f.str;
                    }
                    cout << "Vida atual do inimigo " << u.hp << "\n";
                }
                break;
                case 2:
                {
                    cout << "Voc?? desfere um poderoso golpe de bola de fogo\n";
                    if (u.block == true)
                    {
                        cout << "O inimigo se defendeu do ataque\n";
                    }
                    else
                    {
                        u.hp -= h.attack + rand() % 20 + f.inte;
                    }
                    cout << "Vida atual do inimigo " << u.hp << "\n";
                    break;
                }
                case 3:
                {
                    cout << "Voc?? desfere uma poderosa flechada\n";
                    if (u.block == true)
                    {
                        cout << "O inimigo se defendeu do ataque\n";
                    }
                    else
                    {
                        u.hp -= h.attack + rand() % 20 + f.luck;
                    }
                    cout << "Vida atual do inimigo " << u.hp << "\n";
                    break;
                }
                }
            }
            case 2:
            {
                pass = d.rlucky + rand() % 10;
                if (pass <= 6 and choice == 2)
                {
                    h.block = true;
                }
                break;
            }
            }
            u.block = false;

            if (u.hp <= 0)
            {
                int golpe = 0;
                system("cls");
                cout << "O Urso foi derrotado \n";
                do
                {
                    system("cls");
                    cout << "Voc?? deseja dar o golpe de misericordia? \n";
                    cout << "1 - Sim \t 2 - N??o \n";
                    cin >> golpe;
                } while (golpe < 1 or golpe > 2);
                if (golpe == 1)
                {
                    system("cls");
                    cout << "experiencia obtida: 2\n";
                    d.exppoints += 2;
                    d.mortes += 1;
                    d.ursos -= 1;
                }
                break;
            }

            echoice = rand() % 1;
            switch (echoice)
            {
            case 0:
            {
                cout << "\nO Urso ataca com suas garras \n";
                if (h.block == true)
                {
                    cout << "Voc?? bloqueou com sucesso. \n";
                }
                else
                {
                    cout << "Voce sofreu o ataque \n";
                    f.hp -= (u.attack + d.rlucky + rand() % 5);
                }
                cout << "Sua vida atual ?? " << f.hp << "\n";
                break;
            }
            case 1:
            {
                u.block = true;
                break;
            }

            }
            system("pause");

            if (f.hp <= 0)
            {
                system("cls");
                cout << "Voc?? morreu! \n";
                system("pause");
                d.live = false;
                exit(0);
            }
        }
    }
    else if (d.ursos < 1)
        system("pause");
}
void lutaTreante(treante t, features& f, heroAction h, defaultOptions &d)
{
    while (t.hp > 0 or f.hp > 0)
    {
        system("cls");
        int choice = 0;
        int pass = 0;
        int echoice = 0;
        h.block = false;

        do
        {
            system("cls");
            cout << "Seu turno, oque deseja fazer? \n";
            cout << "1 - Atacar \t 2 - Defender \n";
            cin >> choice;
        } while (choice < 1 or choice > 2);
        switch (choice)
        {
        case 1:
        {
            switch (f.classe)
            {
            case 1:
            {
                cout << "Voc?? desfere um poderoso golpe de espada\n";
                if (t.block == true)
                {
                    cout << "O inimigo se defendeu do ataque\n";
                }
                else
                {
                    t.hp -= h.attack + rand() % 20 + f.str;
                }
                cout << "Vida atual do inimigo " << t.hp << "\n";
            }
            break;
            case 2:
            {
                cout << "Voc?? desfere um poderoso golpe de bola de fogo\n";
                if (t.block == true)
                {
                    cout << "O inimigo se defendeu do ataque\n";
                }
                else
                {
                    t.hp -= h.attack + rand() % 20 + f.inte;
                }
                cout << "Vida atual do inimigo " << t.hp << "\n";
                break;
            }
            case 3:
            {
                cout << "Voc?? desfere uma poderosa flechada\n";
                if (t.block == true)
                {
                    cout << "O inimigo se defendeu do ataque\n";
                }
                else
                {
                    t.hp -= h.attack + rand() % 20 + f.luck;
                }
                cout << "Vida atual do inimigo " << t.hp << "\n";
                break;
            }
            }
        }
        case 2:
        {
            pass = d.rlucky + rand() % 10;
            if (pass <= 6 and choice == 2)
            {
                h.block = true;
            }
            break;
        }
        }
        t.block = false;

        if (t.hp <= 0)
        {
            int golpe = 0;
            system("cls");
            cout << "O Treante foi derrotado \n";
            do
            {
                system("cls");
                cout << "Voc?? deseja dar o golpe de misericordia? \n";
                cout << "1 - Sim \t 2 - N??o \n";
                cin >> golpe;
            } while (golpe < 1 or golpe > 2);
            if (golpe == 1)
            {
                system("cls");
                cout << "experiencia obtida: 5\n";
                d.exppoints += 5;
                d.mortes += 1;
                d.treantes -= 1;
            }
            break;
        }

        echoice = rand() % 1;
        switch (echoice)
        {
        case 0:
        {
            cout << "\nO Treante ataca com suas videiras \n";
            if (h.block == true)
            {
                cout << "Voc?? bloqueou com sucesso. \n";
            }
            else
            {
                cout << "Voce sofreu o ataque \n";
                f.hp -= (t.attack + d.rlucky + rand() % 5);
            }
            cout << "Sua vida atual ?? " << f.hp << "\n";
            break;
        }
        case 1:
        {
            t.block = true;
            break;
        }

        }
        system("pause");

        if (f.hp <= 0)
        {
            system("cls");
            cout << "Voc?? morreu! \n";
            system("pause");
            d.live = false;
            exit(0);
        }
    }
    system("pause");
}
void lutaMimico(mimico m, features& f, heroAction h, defaultOptions &d)
{
    int count = 0;
    while (m.hp > 0 or f.hp > 0)
    {
        count += 1;
        system("cls");
        int choice = 0;
        int pass = 0;
        h.block = false;
        if (count >= 5)
        {
            m.hp += 50;
            cout << "O Mimico se regenera 50 pontos de vida, sua vida atual ?? de " << m.hp << "\n\n";
            system("pause");
            count = 0;
        }
        do
        {
            system("cls");
            cout << "Seu turno, oque deseja fazer? \n";
            cout << "1 - Atacar \t 2 - Defender \n";
            cin >> choice;
        } while (choice < 1 or choice > 2);
        switch (choice)
        {
        case 1:
        {
            switch (f.classe)
            {
            case 1:
            {
                cout << "Voc?? desfere um poderoso golpe de espada\n";
                if (m.block == true)
                {
                    cout << "O inimigo se defendeu do ataque\n";
                }
                else
                {
                    m.hp -= h.attack + rand() % 20 + f.str;
                }
                cout << "Vida atual do inimigo " << m.hp << "\n";
            }
            break;
            case 2:
            {
                cout << "Voc?? desfere um poderoso golpe de bola de fogo\n";
                if (m.block == true)
                {
                    cout << "O inimigo se defendeu do ataque\n";
                }
                else
                {
                    m.hp -= h.attack + rand() % 20 + f.inte;
                }
                cout << "Vida atual do inimigo " << m.hp << "\n";
                break;
            }
            case 3:
            {
                cout << "Voc?? desfere uma poderosa flechada\n";
                if (m.block == true)
                {
                    cout << "O inimigo se defendeu do ataque\n";
                }
                else
                {
                    m.hp -= h.attack + rand() % 20 + f.luck;
                }
                cout << "Vida atual do inimigo " << m.hp << "\n";
                break;
            }
            }
        }
        case 2:
        {
            pass = d.rlucky + rand() % 10;
            if (pass <= 6 and choice == 2)
            {
                cout << "Voc?? se defende, porem o mimico n??o demonstra agressividade";
                h.block = true;
                system("pause");
            }
            break;
        }
        }
        m.block = false;

        if (m.hp <= 0)
        {
            int golpe = 0;
            system("cls");
            cout << "O Mimico foi derrotado \n";
            do
            {
                system("cls");
                cout << "Voc?? deseja dar o golpe de misericordia? \n";
                cout << "1 - Sim \t 2 - N??o \n";
                cin >> golpe;
            } while (golpe < 1 or golpe > 2);
            if (golpe == 1)
            {
                system("cls");
                cout << "experiencia obtida: 10\n";
                d.exppoints += 10;
                d.mortes += 1;
                d.mimicos -= 1;
            }
            break;
        }

        if (f.hp <= 0)
        {
            system("cls");
            cout << "Voc?? morreu! \n";
            system("pause");
            d.live = false;
            exit(0);
        }
        system("pause");
    }
}
void lutaBoss(boss b, features& f, heroAction h, defaultOptions &d)
{
    {
        while (b.hp > 0 or f.hp > 0)
        {
            system("cls");
            int choice = 0;
            int pass = 0;
            int echoice = 0;
            h.block = false;

            do
            {
                system("cls");
                cout << "Seu turno, oque deseja fazer? \n";
                cout << "1 - Atacar \t 2 - Defender \n";
                cin >> choice;
            } while (choice < 1 or choice > 2);
            switch (choice)
            {
            case 1:
            {
                switch (f.classe)
                {
                case 1:
                {
                    cout << "Voc?? desfere um poderoso golpe de espada\n";
                    if (b.block == true)
                    {
                        cout << "O inimigo se defendeu do ataque\n";
                    }
                    else
                    {
                        b.hp -= h.attack + rand() % 20 + f.str;;
                    }
                    cout << "Vida atual do inimigo " << b.hp << "\n";
                }
                break;
                case 2:
                {
                    cout << "Voc?? desfere um poderoso golpe de bola de fogo\n";
                    if (b.block == true)
                    {
                        cout << "O inimigo se defendeu do ataque\n";
                    }
                    else
                    {
                        b.hp -= h.attack + rand() % 20 + f.inte;
                    }
                    cout << "Vida atual do inimigo " << b.hp << "\n";
                    break;
                }
                case 3:
                {
                    cout << "Voc?? desfere uma poderosa flechada\n";
                    if (b.block == true)
                    {
                        cout << "O inimigo se defendeu do ataque\n";
                    }
                    else
                    {
                        b.hp -= h.attack + rand() % 20 + f.luck;
                    }
                    cout << "Vida atual do inimigo " << b.hp << "\n";
                    break;
                }
                }
            }
            case 2:
            {
                pass = d.rlucky + rand() % 10;
                if (pass <= 6 and choice == 2)
                {
                    h.block = true;
                }
                break;
            }
            }
            b.block = false;

            if (b.hp <= 0)
            {
                int golpe = 0;
                system("cls");
                cout << "O Boss foi derrotado \n";
                do
                {
                    system("cls");
                    cout << "Voc?? deseja dar o golpe de misericordia? \n";
                    cout << "1 - Sim \t 2 - N??o \n";
                    cin >> golpe;
                } while (golpe < 1 or golpe > 2);
                if (golpe == 1)
                {
                    system("cls");
                    cout << "Voc?? obteve o chifre do diabo, parece interessante mostrar isso ao taberneiro \n";
                    cout << "experiencia obtida: 50\n";
                    d.exppoints += 50;
                    d.mortes += 1;
                    d.boss -= 1;
                }
                else
                {
                    cout << "Voc?? poupou a vida do diabo, espero que n??o se arrependa dessa deciss??o \n";
                    d.boss -= 1;
                }
                break;
            }

            echoice = rand() % 1;
            switch (echoice)
            {
            case 0:
            {
                cout << "\nO Diabo ataca com sua espada \n";
                if (h.block == true)
                {
                    cout << "Voc?? bloqueou com sucesso. \n";
                }
                else
                {
                    cout << "Voce sofreu o ataque \n";
                    f.hp -= (b.attack + d.rlucky + rand() % 5);
                }
                cout << "Sua vida atual ?? " << f.hp << "\n";
                break;
            }
            case 1:
            {
                b.block = true;
                break;
            }

            }
            system("pause");

            if (f.hp <= 0)
            {
                system("cls");
                cout << "Voc?? morreu! \n";
                system("pause");
                d.live = false;
                exit(0);
            }
        }
        system("pause");
    }
}
void lutaLadino(ladino l, features& f, heroAction h, defaultOptions &d)
{
    while (l.hp > 0 or f.hp > 0)
    {
        system("cls");
        int choice = 0;
        int pass = 0;
        int echoice = 0;
        int golpe = 0;
        h.block = false;

        do
        {
            system("cls");
            cout << "Seu turno, oque deseja fazer? \n";
            cout << "1 - Atacar \t 2 - Defender \n";
            cin >> choice;
        } while (choice < 1 or choice > 2);
        switch (choice)
        {
        case 1:
        {
            switch (f.classe)
            {
                case 1:
                {
                    cout << "Voc?? desfere um poderoso golpe de espada\n";
                    if (l.block == true)
                    {
                        cout << "O inimigo se defendeu do ataque\n";
                    }
                    else
                    {
                        l.hp -= h.attack + rand() % 20 + f.str;
                    }
                    cout << "Vida atual do inimigo " << l.hp << "\n";
                    break;
                }
                case 2:
                {
                    cout << "Voc?? desfere um poderoso golpe de bola de fogo\n";
                    if (l.block == true)
                    {
                        cout << "O inimigo se defendeu do ataque\n";
                    }
                    else
                    {
                        l.hp -= h.attack + rand() % 20 + f.inte;
                    }
                    cout << "Vida atual do inimigo " << l.hp << "\n";
                    break;
                }
                case 3:
                {
                    cout << "Voc?? desfere uma poderosa flechada\n";
                    if (l.block == true)
                    {
                        cout << "O inimigo se defendeu do ataque\n";
                    }
                    else
                    {
                        l.hp -= h.attack + rand() % 20 + f.luck;
                    }
                    cout << "Vida atual do inimigo " << l.hp << "\n";
                    break;
                }
            }
        }
            case 2:
            {
                pass = d.rlucky + rand() % 10;
                if (pass <= 6 and choice == 2)
                {
                    h.block = true;
                }
                break;
            }
        }
        l.block = false;

        if (l.hp <= 0)
        {
            system("cls");
            cout << "O Ladino foi derrotado \n";
            do
            {
                system("cls");
                cout << "Voc?? deseja dar o golpe de misericordia? \n";
                cout << "1 - Sim \t 2 - N??o \n";
                cin >> golpe;
            } while (golpe < 1 or golpe > 2);
            if (golpe == 1)
            {
                system("cls");
                cout << "experiencia obtida: 2, gold obtido 2\n";
                d.mortes += 1;
                d.exppoints += 2;
                d.boss -= 1;
                d.moedas += 2;
            }
            else 
            {
                system("cls");
                cout << "experiencia obtida: 2\n";
                cout << "O ladino volta para se recuperar!\n";
                d.exppoints += 2;
            }
            break;
        }

        echoice = rand() % 1;
        switch (echoice)
        {
        case 0:
        {
            cout << "\nO Ladino ataca com suas adagas\n";
            if (h.block == true)
            {
                cout << "Voc?? bloqueou com sucesso. \n";
            }
            else
            {
                cout << "Voce sofreu o ataque \n";
                f.hp -= (l.attack + d.rlucky + rand() % 5);
            }
            cout << "Sua vida atual ?? " << f.hp << "\n";
            break;
        }
        case 1:
        {
            l.block = true;
            break;
        }

        }
        system("pause");

        if (f.hp <= 0)
        {
            system("cls");
            cout << "Voc?? morreu! \n";
            system("pause");
            d.live = false;
            exit(0);
        }
    }
    system("pause");
}

void save(defaultOptions& d, features& f)
{
}

void load(defaultOptions& d, features& f)
{
}

void taberna(defaultOptions& d, features& f)
{
    int choice = 0;
    while (choice != 5)
    {
        do
        {
            system("cls");
            cout << "Bem vindo a taberna aventureiro, como podemos te ajudar?\n";
            ifstream taberna;
            string phrase;
            int currentLine = 0;
            taberna.open("taberna.txt");
            while (!taberna.eof()) {
                getline(taberna, phrase);
                cout << phrase << "\n";
            }
            taberna.close();
            cout << "Voc?? tem " << d.moedas << " moedas.\n";
            cin >> choice;
        } while (choice < 1 or choice > 5);
        switch (choice)
        {
        case 1:
        {
            if (d.moedas < 3)
            {
                system("cls");
                cout << "Voc?? n??o tem dinheiro o suficiente";
                system("pause");
            }
            else
            {
                system("cls");
                d.moedas -= 3;
                cout << "Voce perdeu 3 moedas, agora voc?? tem o total de " << d.moedas <<"\n";
                d.taberneirocount += 1;
                system("pause");
                if (d.taberneirocount >= 3)
                {
                    int choice = 0;
                    if (!d.taberneirof and !d.taberneiro)
                    {
                        do
                        {
                            system("cls");
                            cout << "O taberneiro fica muito feliz que voc?? j?? virou cliente, ent??o ele pede se voc?? quer se associar a taberna\n";
                            cout << "1 - Sim \t 2 - N??o\n";
                            cin >> choice;
                        } while (choice < 1 or choice > 2);
                        if (choice == 2)
                        {
                            d.taberneirof = true;
                        }
                        else if (choice == 1)
                        {
                            cout << "Parabens voc?? se associou a taberna!\n";
                            d.taberneiro = true;
                            system("pause");
                        }
                    }

                }
            }
            break;
        }
        case 2:
        {
            int x = rand() % 3;
            switch (x)
            {
            case 0:
            {
                system("cls");
                cout << "Voc?? desabafa seus problemas com o taberneiro, porem ele parece ocupado.\n";
                system("pause");
                break;
            }
            case 1:
            {
                system("cls");
                cout << "Voc?? conversa com a linda esposa do taberneiro, mas nada acontece!\n";
                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                cout << "Voc?? perde horas conversando com o taberneiro e quando v?? j?? ?? hora de ir para casa e perde 1 ponto de experiencia \n";
                system("pause");
                if (d.exppoints > 0)
                {
                    d.exppoints -= 1;
                }
                system("cls");
                cout << "Atualmene voc?? tem " << d.exppoints << " pontos de experiencia\n";
                system("pause");
                break;
            }
            }
            break;
        }
        case 3:
        {
            if (d.ladina and !d.ladinaf)
            {
                int choice = 0;
                do
                {
                    system("cls");
                    ifstream ladina;
                    string phrase;
                    int currentLine = 0;
                    ladina.open("ladina.txt");
                    while (!ladina.eof()) {
                        getline(ladina, phrase);
                        cout << phrase << "\n";
                    }
                    ladina.close();
                    cout << "1 - Aceita \t 2 - Recusar\n";
                    cin >> choice;
                } while (choice < 1 or choice > 2);
                switch (choice)
                {
                case 1:
                {
                    if (d.moedas >= 20 and d.ladina and !d.ladinaf)
                    {
                        system("cls");
                        cout << "Voc?? perdeu 20 moedas\n";
                        d.moedas -= 20;
                        d.ladina = false;
                        system("pause");
                    }
                    else if (d.moedas < 20 and d.ladina and !d.ladinaf)
                    {
                        cout << "Voc?? n??o tem moedas o suficiente, tente novamente outro dia\n";
                        system("pause");
                    }
                    break;
                }
                case 2:
                {
                    system("cls");
                    d.ladinaf = true;
                    cout << "A jovem mo??a sai da mesa murmurando alguma coisa que voc?? n??o entende\n";
                    break;
                }
                }
            }
            else if (d.ladinaf or !d.ladina)
            {
                system("cls");
                cout << "Voc?? senta na mesa, porem ninguem vem falar com voc??.\n";
                system("pause");
            }
            system("cls");
            break;
        }
        case 4:
        {
            changeFeatures(f,d);
            showFeatures(f, d);
            break;
        }
        }
    }
}

void avanca(defaultOptions& d)
{
    int choice = 0;
    do
    {
        cout << "Voc?? deseja avan??ar ou retroceder?\n";
        cout << "1 - Avan??ar \t 2 - Retroceder\n";
        cin >> choice;
        system("cls");
    } while (choice < 1 or choice > 2);

    if (d.pos == 0 and choice == 2)
    {
        cout << "Voc?? n??o pode passar dos port??es da cidade\n";
        system("pause");
        system("cls");
        do
        {
            cout << "Voc?? deseja avan??a?\n";
            cout << "1 - Sim \t 2 - N??o\n";
            cin >> choice;
            system("cls");
        } while (choice != 1);
    }

    else if(d.pos == 8 and choice == 1)
    {
        cout << "Voc?? n??o pode passar pelo castelo do rei\n";
        system("pause");
        system("cls");
    }

    else if (choice == 1)
    {
        d.pos += +1;
        choice = 0;
        d.going = true;
    }
    else if (choice == 2)
    {
        d.pos -= 1;
        choice = 0;
        d.going = false;
    }
}

void mercador(defaultOptions& d)
{
    system("cls");
    if (d.moedas < 30)
    {
        cout << "N??o converso com pessoas pobres, volte quando tiver dinheiro\n";
        system("pause");
        system("cls");
    }
    else if (d.moedas >= 30 and !d.taberneiro)
    {
        int choice = 0;
        while (choice != 4)
        {
            system("pause");
            system("cls");
            do
            {
                system("cls");
                cout << "Seja bem vindo a minha loja, fique a vontade para conhecer e caso queira comprar algo ?? s?? me chamar.\n";
                cout << "ITENS A VENDA:\n";
                cout << "1 - Espada de A??o 30g\n2 - Arco de Treante 30g\n3 - Tomo Amplificador 30g\n4 - Sair \nGold dispon??vel: " << d.moedas << "\n";
                cin >> choice;
            } while (choice < 1 or choice > 4);
            switch (choice)
            {
            case 1:
            {
                if (d.classe == "Arqueiro" or d.classe == "Mago")
                {
                    cout << "Voc?? n??o deveria comprar isso\n";
                }
                else if (d.classe == "Guerreiro" and d.moedas >= 30)
                {
                    cout << "Voc?? acabou de adquirir uma Espada de A??o\n";
                    d.moedas -= 30;
                    d.weapon = 30;
                }
                else if (d.moedas < 30)
                {
                    system("cls");
                    cout << "Voc?? ainda n??o tem dinheiro suficiente para comprar esse artefato\n";
                }
                break;
            }
            case 2:
            {
                if (d.classe == "Guerreiro" or d.classe == "Mago")
                {
                    cout << "Voc?? n??o deveria comprar isso\n";
                }
                else if (d.classe == "Arqueiro" and d.moedas >= 30)
                {
                    cout << "Voc?? acabou de adquirir um Arco de Treante\n";
                    d.moedas -= 30;
                    d.weapon = 30;
                }
                else if (d.moedas < 30)
                {
                    system("cls");
                    cout << "Voc?? ainda n??o tem dinheiro suficiente para comprar esse artefato\n";
                }
                break;
            }
            case 3:
            {
                if (d.classe == "Guerreiro" or d.classe == "Arqueiro")
                {
                    cout << "Voc?? n??o deveria comprar isso\n";
                }
                else if (d.classe == "Mago" and d.moedas >= 30)
                {
                    cout << "Voc?? acabou de adquirir um Tomo Amplificador\n";
                    d.moedas -= 30;
                    d.weapon = 30;
                }
                else if (d.moedas < 30)
                {
                    system("cls");
                    cout << "Voc?? ainda n??o tem dinheiro suficiente para comprar esse artefato\n";
                }
                break;
            }
            case 4:
            {
                system("cls");
                cout << "Volte quando quiser\n";
                system("pause");
            }
            break;
            }
        }
    }
    else if (d.moedas >= 30 and d.taberneiro)
    {
        int choice = 0;
        while (choice != 5)
        {
            do
            {
                cout << "Seja bem vindo a minha loja, fique a vontade para conhecer e caso queira comprar algo ?? s?? me chamar.\n";
                cout << "ITENS A VENDA:\n";
                cout << "1 - Espada de A??o 30g\n2 - Arco de Treante 30g\n3 - Tomo Amplificador 30g\n4 - Anel do poder (overpower) 100g \n5 - Sair \nGold dispon??vel: " <<d.moedas<<"\n";
                cin >> choice;
            } while (choice < 1 or choice > 5);
            switch (choice)
            {
                case 1:
                {
                    if (d.classe == "Arqueiro" or d.classe == "Mago")
                    {
                        system("cls");
                        cout << "Voc?? n??o deveria comprar isso\n";
                    }
                    else if (d.classe == "Guerreiro" and d.moedas >= 30)
                    {
                        system("cls");
                        cout << "Voc?? acabou de adquirir uma Espada de A??o\n";
                        d.moedas -= 30;
                        d.weapon = 30;
                    }
                    else if (d.moedas < 30)
                    {
                        system("cls");
                        cout << "Voc?? ainda n??o tem dinheiro suficiente para comprar esse artefato\n";
                    }
                    break;
                }
                case 2:
                {
                    if (d.classe == "Guerreiro" or d.classe == "Mago")
                    {
                        system("cls");
                        cout << "Voc?? n??o deveria comprar isso\n";
                    }
                    else if (d.classe == "Arqueiro" and d.moedas >= 30)
                    {
                        system("cls");
                        cout << "Voc?? acabou de adquirir um Arco de Treante\n";
                        d.moedas -= 30;
                        d.weapon = 30;
                    }
                    else if (d.moedas < 30)
                    {
                        system("cls");
                        cout << "Voc?? ainda n??o tem dinheiro suficiente para comprar esse artefato\n";
                    }
                    break;
                }
                case 3:
                {
                    if (d.classe == "Guerreiro" or d.classe == "Arqueiro")
                    {
                        system("cls");
                        cout << "Voc?? n??o deveria comprar isso\n";
                    }
                    else if (d.classe == "Mago" and d.moedas >= 30)
                    {
                        system("cls");
                        cout << "Voc?? acabou de adquirir um Tomo Amplificador\n";
                        d.moedas -= 30;
                        d.weapon = 30;
                    }
                    else if (d.moedas < 30)
                    {
                        system("cls");
                        cout << "Voc?? ainda n??o tem dinheiro suficiente para comprar esse artefato\n";
                    }
                    break;
                }
                case 4:
                {
                    if (d.moedas >= 100)
                    {
                        system("cls");
                        cout << "Parabens voc?? acabou de adquirir um Anel do Poder\n";
                        d.moedas -= 100;
                        d.weapon += 50;

                    }
                    else if (d.moedas < 30)
                    {
                        system("cls");
                        cout << "Voc?? ainda n??o tem dinheiro suficiente para comprar esse artefato\n";
                    }
                    break;
                }
                case 5:
                {
                    cout << "Volte quando quiser";
                    break;
                }
            }
            system("pause");
            system("cls");
        }
    }
}

void arena(defaultOptions& d, features f, ladino l, heroAction h)
{
    int choice = 0;
    if (d.ladina)
    {
        while (choice != 2)
        {
            do
            {
                system("cls");
                cout << "Voc?? adentrou a Arena!\nO que deseja fazer?\n";
                cout << "1 - Treinar \t 2 - Sair\n";
                cin >> choice;
            } while (choice < 1 or choice > 2);
            if (choice == 1)
            {
                lutaLadino(l, f, h, d);
            }
            system("cls");
        }
    }
    else if (!d.ladina)
    {
        while (choice != 3)
        {
            do
            {
                system("cls");
                cout << "Voc?? adentrou a Arena!\nO que deseja fazer?\n";
                cout << "1 - Treinar \t 2 - curar \t 3 - Sair\n";
                cin >> choice;
            } while (choice < 1 or choice > 3);
            switch (choice)
            {
            case 1:
            {
                lutaLadino(l, f, h, d);
                break;
            }
            case 2:
            {
                cout << "Voc?? foi curado\n";
                system("pause");
                f.hp = d.healfix;
                break;

            }
            system("cls");
            }
        }
    }
}

void acao(defaultOptions &d, features &f, heroAction h, ladino l, urso u, treante t, mimico mi, boss b)
{
    int pass = 0;
    system("cls");
    switch (d.pos)
    {
        case 0:
        {
            cout << "Voc?? esta no centro da cidade\n";
            break;
        }
        case 1:
        {
            do
            {
                cout << "Voc?? se encontra na taberna\nDeseja entrar?\n";
                cout << "1 - Sim \t 2 - N??o\n";
                    cin >> pass;
            } while (pass < 1 or pass > 2);
            if (pass == 1)
            {
                taberna(d, f);
            }
            break;
        }
        case 2:
        {
            do
            {
                cout << "Voc?? se encontra na loja de armas\nDeseja entrar?\n";
                cout << "1 - Sim \t 2 - N??o\n";
                    cin >> pass;
            } while (pass < 1 or pass > 2);
            if (pass == 1)
            {
                mercador(d);
            }
            break;
        }
        case 3:
        {
            do
            {
                cout << "Voc?? se encontra na arena\nDeseja entrar?\n";
                cout << "1 - Sim \t 2 - N??o\n";
                cin >> pass;
            } while (pass < 1 or pass > 2);
            if (pass == 1) 
            {
                arena(d,f,l,h);
            }
            break;
        }
        case 4:
        {
            cout << "Voc?? esta nos port??es para a floresta.\n";
            break;
        }   
        case 5:
        {
            if(d.ursos >= 1)
            {
             cout << "Voc?? se encontra na floresta 1\n";
             system("pause");
             system("cls");
             cout << "De repente surge um Urso de sua caverna\n";
             system("pause");
             system("cls");
             lutaUrso(u,f,h,d);
            }
            else if(d.ursos < 1)
            {
                system("cls");
                cout << "Voc?? se encontra na floresta 1\n";
                cout << "Parece que voc?? eliminou todos os inimigos desse mapa\n";
                system("pause");
                system("cls");
            }
            break;
        }
        case 6: 
        {
            if (d.treantes >= 1)
            {
                cout << "Voc?? se encontra na floresta 2\n";
                system("pause");
                system("cls");
                cout << "De repente voc?? percebe que uma arvore come??a a te encarar\n";
                system("pause");
                system("cls");
                cout << "E de repente surge um treante\n";
                system("pause");
                system("cls");
                lutaTreante(t, f, h, d);
            }
            else if (d.treantes < 1)
            {
                system("cls");
                cout << "Parece que voc?? eliminou todos os inimigos desse mapa\n";
                system("pause");
                system("cls");
            }
            break;
        }
        case 7: 
        {
            if (d.mimicos >= 1)
            {
                int choice = 0;
                do
                {
                    cout << "Voc?? adentra no castelo do rei negro\n";
                    system("pause");
                    system("cls");
                    cout << "De repente voc?? percebe um bau no canto da sala\n";
                    cout << "1 - Abrir o Bau \t 2 - Passar\n";
                    cin >> choice;
                } while (choice < 1 or choice > 2);
                if(choice == 1)
                {
                    system("cls");
                    lutaMimico(mi, f, h, d);
                }
               
            }
            else if (d.mimicos < 1)
            {
                system("cls");
                cout << "Parece que voc?? eliminou todos os inimigos desse mapa\n";
                system("pause");
                system("cls");
            }
            break;
        }
        case 8: 
        {
            if (d.boss >= 1)
            {
                cout << "Chegou no hall da sala do rei \n";
                system("pause");
                system("cls");
                cout << "De repente ele levanta e a batalha inicia\n";
                system("pause");
                system("cls");
                lutaBoss(b, f, h, d);
            }
            else if (d.boss < 1)
            {
                system("cls");
                cout << "Parece que voc?? eliminou todos os inimigos desse mapa\n";
                system("pause");
                system("cls");
            }
            break;
        }
    }
}
