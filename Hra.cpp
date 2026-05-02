#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void vyberPostav() {
    cout <<"\nVybete si postavu:";
    cout << "\n1. Revizor";
    cout << "\n2. Bezdomovec";
    cout << "\n3. Černý pasažér";
    cout << "\n4. Ajťák";
    cout << "\nČíslo postavy: ";
}

void revizorInfo() {
    cout << "Popis postavy Revizor";
}
void bezdomovecInfo() {
    cout << "Popis postavy Bezdomovec";
}
void cernypasazerInfo() {
    cout << "Popis postavy Cernypasazer";
}

void ajtakInfo() {
    cout << "Popis postavy Ajtak";
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
            case 1: revizorInfo(); break;
            case 2: bezdomovecInfo(); break;
            case 3: cernypasazerInfo(); break;
            case 4: ajtakInfo(); break;
            default: cout << "ERROR";
        }

        do {
            cout << "\nChcete vybrat tuto postavu (a/n): ";
            cin  >> vyberanone;
        }while ((vyberanone != 'a') && (vyberanone != 'n'));

    }while (vyberanone == 'n');





    statistikaVagon(zivoty, zivotymax, energie, energiemax, penize, vagon);
    jidelniVagon(zivoty,penize,energie);
    statistikaVagon(zivoty, zivotymax, energie, energiemax, penize, vagon);
    cout << "\nKonec";

}