#include <iostream>
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

    cout << "\n==== Jídelní vagón ====";
    cout << "\nVítejte v jídelním voze. \nZde si můžete koupit jídlo a pití a také i jiné věci.";
    cout << "\n\nAKTUÁLNÍ NABÍDKA";
    cout << "\n1. Kolalokova limonáda      +1 život               65 Peněz";
    cout << "\n2. Šumavský bochník         +3 energie             50 Peněz";
    cout << "\n3. Výherní los              až 1 000 000 peněz     45 Peněz";
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
                    cout << "\nMINISTERSTVO FINANCÍ VARUJE: Účastí na hazardní hře může vzniknout závislost.";
                    //random +/- peníze


            }


    }


}





int main() {
    SetConsoleOutputCP(CP_UTF8);

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