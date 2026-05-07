#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void vyberPostav() {
    cout <<"\nVybete si postavu:";
    cout << "\n1. Revizor";
    cout << "\n2. Bezdomovec";
    cout << "\n3. Černý pasažér";
    cout << "\n4. Ajťák";
    cout << "\nČíslo postavy: ";
}

void revizor(char moznost,int velikostUtoku0,int velikostUtoku1, int &uderP) {
    int vyber;

    switch (moznost) {
        case 'i':
            cout << "Popis postavy Revizor";
            break;
        case 's':
            cout << "\n1. Úder pokutou      Utok " << velikostUtoku0 << " - " << velikostUtoku1;
            cout << "\n2. Nedělat nic";
            cout << "\nVyberte akci(1-2): ";
            cin >> vyber;
            switch (vyber) {
                case 1:
                    uderP = random(velikostUtoku0,velikostUtoku1);
                    break;

            }


    }
}
void bezdomovec(char moznost) {
    switch (moznost) {
        case 'i':
            cout << "Popis postavy Bezdomovec";
            break;
    }
}
void cernypasazer(char moznost) {
    switch (moznost) {
        case 'i':
            cout << "Popis postavy Černý pasažér";
            break;
    }
}

void ajtak(char moznost) {
    switch (moznost) {
        case 'i':
            cout << "Popis postavy Ajťák";
            break;
    }
}

void postava(int cislopostavy, char moznost, int velikostUtoku0, int velikostUtoku1, int &uder) {
    int uderP = 0;
    switch (cislopostavy) {
        case 1:
            revizor(moznost, velikostUtoku0, velikostUtoku1, uderP);
    }

    uder = uderP;
}


void statistikaVagon(int zivoty, int zivotymax, int energie, int energiemax, int penize, int vagon) {
    cout << "\n-----------------------";
    cout <<"\nVAGÓN " << vagon << " ÚSPĚŠNĚ ZDOLÁN";
    cout << "\n-----------------------";

    cout << "\nŽivoty:       " << zivoty << "/" << zivotymax;
    cout << "\nEnergie:      " << energie << "/" << energiemax;
    cout << "\nPeníze:       " << penize;
    cout << "\nJdete do dalšího vagónu(a): ";
    string odpoved;
    cin >> odpoved;
}

void jidelniVagon(int &zivoty, int &penize, int &energie) {
    char vyberanone;
    int vybernakupu;
    int pocitadloSymboly[3] = {0,0,0};
    int random;

    cout << "\n==== Jídelní vagón ====";
    cout << "\nVítejte v jídelním voze. \nZde si můžete koupit jídlo a pití a také i jiné věci.";
    cout << "\n\nAKTUÁLNÍ NABÍDKA";
    cout << "\n1. Kolalokova limonáda      +1 život               65 Peněz";
    cout << "\n2. Šumavský bochník         +3 energie             50 Peněz";
    cout << "\n3. Stírací los              až 1 000 000 peněz     45 Peněz";
    do {
        cout << "\nKoupíte si něco(a/n): ";
        cin  >> vyberanone;
    }while ((vyberanone != 'a') && (vyberanone != 'n'));

    switch (vyberanone) {
        case 'a':
            cout << "\nCo si koupíte(1-3): ";
            cin >> vybernakupu;
            switch (vybernakupu) {
                case 1:
                    cout << "\n-65 peněz";
                    cout << "\nKolalokova limonáda vás vždy osvěží. \n+1 život";
                    zivoty++;
                    penize-=65;
                    break;
                case 2:
                    cout << "-50 peněz";
                    cout << "\nKdo by čekal že šumava bude mít takto veliké energetické výdaje. \n+3 energie";
                    energie+= 3;
                    penize-= 50;
                    break;
                case 3:
                    cout << "-45 peněz";
                    cout << "\n\nMINISTERSTVO FINANCÍ VARUJE: Účastí na hazardní hře může vzniknout závislost.";
                    cout << "\n\n#   #   #           20 penez";
                    cout <<   "\n2x  *               40 penez";
                    cout <<   "\n*   *   *           80 penez";
                    cout <<   "\n2x  $              200 penez";
                    cout <<   "\n$   $   $    1 000 000 penez";
                    cout << "\n\nSetřít los?(a): ";
                    cin >> vyberanone;
                    cout << "\n=========\n";
                    for (int i = 0; i < 3; i++) {
                        random = rand() % 100;
                        if (random <= 40) {
                            cout << "#   ";
                            pocitadloSymboly[0]++;
                        } else if (random <= 80) {
                            cout << "*   ";
                            pocitadloSymboly[1]++;
                        } else if (random > 80) {
                            cout << "$   ";
                            pocitadloSymboly[2]++;
                        }
                    }
                    cout << "\n=========\n";

                    if (pocitadloSymboly[0] == 3) {
                        cout << "\nVýhra";
                        cout << "\n+20 peněz";
                        penize+=20;
                    } else if (pocitadloSymboly[1] == 2) {
                        cout << "\nVýhra";
                        cout << "\n+40 peněz";
                        penize+=40;
                    } else if (pocitadloSymboly[1] == 3) {
                        cout << "\nVýhra";
                        cout << "\n+80 peněz";
                        penize+=80;
                    } else if (pocitadloSymboly[2] == 2) {
                        cout << "\nVýhra";
                        cout << "\n+200 peněz";
                        penize+=200;
                    } else if (pocitadloSymboly[2] == 3) {
                        cout << "\nGratulujeme vyhráli jste hlavní výhru!";
                        cout << "\n+1 000 000 peněz";
                        penize+=1000000;
                    } else {
                        cout << "\nŽádná výhra, možná příště budete mít více štěstí.";
                    }

            }


    }


}

void MBezdomovec(char moznost,int &zivotyM, string &MJmeno) {
    switch (moznost) {
        case 'i':
            zivotyM = 10;
            MJmeno = "Bezdomovec";
            break;
        case 's':
            cout << "Souboj .....";
            break;
    }


}

void Monstrum1(char moznost,int &zivotyM, string &MJmeno) {
    switch (moznost) {
        case 'i':
            zivotyM = 50;
            MJmeno = "Monstrum1";
            break;
        case 's':
            cout << "Souboj .....";
            break;
    }


}





void souboj(int cislopostavy, int &zivoty,int &energie, int velikostUtoku0,int velikostUtoku1, int monstrum1, int monstrum2 = 0, int monstrum3 = 0) {
    string MJmeno1;
    string MJmeno2;
    string MJmeno3;
    int tah = 0;
    int zivotyM1 = 0;
    int zivotyM2 = 0;
    int zivotyM3 = 0;

    switch (monstrum1) {
        case 1:
            MBezdomovec('i', zivotyM1, MJmeno1);
            break;
        case 2:
            Monstrum1('i', zivotyM1, MJmeno1);
            break;
    }
    switch (monstrum2) {
        case 1:
            MBezdomovec('i', zivotyM2, MJmeno2);
            break;
        case 2:
            Monstrum1('i', zivotyM2, MJmeno2);
            break;
    }
    switch (monstrum3) {
        case 1:
            MBezdomovec('i', zivotyM3, MJmeno3);
            break;
        case 2:
            Monstrum1('i', zivotyM3, MJmeno3);
            break;
    }

    cout << "\n     Souboj"
         << "\n----------------"
         << "\nVy versus " << MJmeno1;
    if (monstrum2 != 0) {
        cout << ", " << MJmeno2;
    }
    if (monstrum3 != 0) {
        cout << ", " << MJmeno3;
    }
    int uder = 0;
    if (monstrum1 <= 1) {
        cout << "\nZačínáte Vy:";
        cout << "\nVaše životy:     "<< zivoty;
        cout << "\nVase energie:    "<< energie;

        cout << "\n\n" << MJmeno1 << "  Životy: " << zivotyM1;
        if (monstrum2 != 0) {
            cout << "\n" << MJmeno2 << "  Životy: " << zivotyM2;
        }
        if (monstrum3 != 0) {
            cout << "\n" << MJmeno3 << "  Životy: " << zivotyM3;
        }

        cout << "\nJste na tahu";
        cout << "Možnosti útoku";
        postava(cislopostavy,'s', velikostUtoku0, velikostUtoku1,uder);

    }


}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    int pocetpostav = 4;
    string postava[pocetpostav] = {"Revizor", "Bezdomovec", "Černý pasažér", "Ajťák"};
    int cislopostavy;
    char vyberanone;

    int vagon = 15;
    int zivoty = 5;
    int zivotymax = 5;
    int energie = 10;
    int energiemax = 10;
    int penize = 100;

    int velikostUtoku[2];
    int uder;

    cout << "Právě se nacházíte ve vlaku v posledním vagónu. \nVaše mise je se dostat do prvního vagonu. \nPotom přelézt do lokomotivy. \nZneškodnit strojvedoucího a ovládnout celý vlak.\n";

    do {
        vyberPostav();
        cin >> cislopostavy;
        while (cislopostavy <= 0 || cislopostavy > 4){
            cout << "\nNEPLATNÝ ÚDAJ\n";
            vyberPostav();
            cin >> cislopostavy;
        }

        cout << endl << postava[cislopostavy-1]<<endl;
        switch (cislopostavy) {
            case 1: revizor('i',0,0,uder);
                velikostUtoku[0] = 2;
                velikostUtoku[1] = 6;
                break;

            case 2: bezdomovec('i'); break;
            case 3: cernypasazer('i'); break;
            case 4: ajtak('i'); break;
            default: cout << "ERROR";
        }

        do {
            cout << "\nChcete vybrat tuto postavu (a/n): ";
            cin  >> vyberanone;
        }while ((vyberanone != 'a') && (vyberanone != 'n'));

    }while (vyberanone == 'n');

    cout << cislopostavy;
    souboj(cislopostavy,zivoty, energie,velikostUtoku[0],velikostUtoku[1], 1,1,1);

    statistikaVagon(zivoty, zivotymax, energie, energiemax, penize, vagon);
    jidelniVagon(zivoty,penize,energie);
    statistikaVagon(zivoty, zivotymax, energie, energiemax, penize, vagon);
    cout << "\nKonec";

}