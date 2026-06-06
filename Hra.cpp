#include <iostream>
#include <ctime>
#include <locale>
#include <limits>
#include <chrono>
#include <thread>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif


using namespace std;

int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

bool overVstup() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}

void statistika(int &zivoty, int &zivotymax, int &energie, int &energiemax, int &penize, int &velikostUtoku0, int velikostUtoku1){
    cout << "\nŽivoty:          " << zivoty << "/" << zivotymax;
    cout << "\nEnergie:         " << energie << "/" << energiemax;
    cout << "\nVelikost útoku:  " << velikostUtoku0 << "-" << velikostUtoku1;
    cout << "\nPeníze:          " << penize;

}

void vyberPostav() {
    cout <<"\nVybete si postavu:";
    cout << "\n1. Revizor";
    cout << "\n2. Bezdomovec";
    cout << "\n3. Černý pasažér";
    cout << "\n4. Ajťák";
    cout << "\nČíslo postavy: ";
}

void revizorInfo(int &zivoty, int &zivotymax, int &energie, int &energiemax, int &penize, int &velikostUtoku0, int &velikostUtoku1) {
    cout << "\nJeho rajón je metro, ale nevadí mu dávat pokuty ani ve vlaku!\n";
    zivoty = 30;
    zivotymax = 35;
    energie = 6;
    energiemax = 18;
    penize = 95;
    velikostUtoku0 = 3;
    velikostUtoku1 = 9;

    statistika(zivoty,zivotymax,energie,energiemax,penize,velikostUtoku0,velikostUtoku1);

}
void revizorSouboj(int velikostUtoku0,int velikostUtoku1, int &uderP, int &energie) {
    int vyber;

            cout << "\n   MMOŽNOST                                      CENA         ÚDER";
            cout << "\n1. Úder                                                       " << velikostUtoku0 << " - " << velikostUtoku1;
            cout << "\n2. Udělit pokutu za nevhodné chování ve voze     5 Energie    " << velikostUtoku1 - 1;
            cout << "\n3. Nedělat nic";
            do {
            cout << "\nVyberte akci(číslo): ";
                cin >> vyber;
            }while ((overVstup()==true)||(vyber < 1 || vyber > 3));

            while ((vyber > 3 || vyber < 1) || ((vyber == 2) && (energie < 5))) {
                if ((vyber == 2) && (energie < 5)) {
                    cout << "Máš málo energie na tuto možnost";
                } else {
                    cout << "Špatně zadané číslo";
                }
                do {
                    cout << "\nVyberte jinou akci(číslo): ";
                    cin >> vyber;
                }while ((overVstup()==true)||(vyber < 1 || vyber > 3));
            }
            switch (vyber) {
                case 1:
                    uderP = random(velikostUtoku0,velikostUtoku1);
                    break;
                case 2:
                    uderP = velikostUtoku1 -1;
                    energie-= 5;
                    break;
                case 3:
                    break;

            }
}
void bezdomovecInfo() {
    cout << "Popis postavy Bezdomovec";
}
void bezdomovecSouboj() {

}
void cernypasazerInfo() {
    cout << "Popis postavy Černý pasažér";
}
void cernypasazerSouboj() {

}
void ajtakInfo() {
    cout << "Popis postavy Ajťák";
}
void ajtakSouboj() {

}
void postava(int cislopostavy, char moznost, int &velikostUtoku0, int &velikostUtoku1, int &uder,int &energie) {
    int uderP = 0;
    switch (cislopostavy) {
        case 1:
            revizorSouboj(velikostUtoku0, velikostUtoku1, uderP, energie);
    }

    uder = uderP;
}

void statistikaVagon(int zivoty, int zivotymax, int energie, int energiemax, int penize, int &vagon, int velikostUtoku0, int velikostUtoku1) {

    cout << "\n-----------------------";
    cout <<"\nVAGÓN " << vagon << " ÚSPĚŠNĚ ZDOLÁN";
    cout << "\n-----------------------";

    statistika(zivoty,zivotymax,energie,energiemax,penize,velikostUtoku0,velikostUtoku1);
    cout << "\nJdete do dalšího vagónu(a): ";
    string odpoved;
    cin >> odpoved;
    vagon--;
    cout << "\n=============== VAGÓN " << vagon << " ===============\n";
}

void jidelniVagon(int &zivoty, int &penize, int &energie, int &zivotymax, int &energiemax) {
    char vyberanone;
    int vybernakupu;
    int pocitadloSymboly[3] = {0,0,0};
    int random;


        cout << "\n==== Jídelní vagón ====";
        cout << "\nVítejte v jídelním voze. \nZde si můžete koupit jídlo a pití a také i jiné věci.";
    do {
        cout << "\nVaše peníze: " << penize;
        cout << "\n\nAKTUÁLNÍ NABÍDKA\n";

        cout << "\n1. Kolalokova limonáda      +10 životů             65 Peněz";
        if ((penize < 65)||(zivotymax <= zivoty)) {
            cout << " - Není dostupné";
        }

        cout << "\n2. Šumavský bochník         +3 energie             50 Peněz";
        if (penize < 50 || energie >= energiemax) {
            cout << " - Není dostupné";
        }

        cout << "\n3. Stírací los              až 1 000 000 peněz     45 Peněz";
        if (penize < 45) {
            cout << " - Není dostupné";
        }

        if (penize < 45) {
            cout << "\nStav vašeho účtu je velmi špatný - Nemáte na nic peníze";
        }
        do {
            cout << "\nKoupíte si něco(a/n): ";
            cin  >> vyberanone;
        }while ((overVstup() == true)||((vyberanone != 'a') && (vyberanone != 'n')));

        switch (vyberanone) {
            case 'a':
                do {
                    cout << "\nCo si koupíte(1-3): ";
                    cin >> vybernakupu;
                }while ((overVstup() == true)||((vybernakupu < 1) || (vybernakupu > 3)));
                switch (vybernakupu) {
                    case 1:
                        if ((penize >= 65) && (zivoty + 10 <= zivotymax)) {
                            cout << "\n-65 peněz";
                            cout << "\nKolalokova limonáda vás vždy osvěží. \n+10 životů";
                            zivoty+=10;
                            penize-=65;
                        } else if (penize < 65) {
                            cout << "\nMate nedostatek peněz";
                        } else if (zivoty >= zivotymax){
                            cout <<"\nMáte už maximální počet životů";
                        } else if (zivotymax -zivoty < 10) {
                            cout << "\n-65 peněz";
                            cout << "\nKolalokova limonáda vás vždy osvěží.\n+" << zivotymax-zivoty  << " životů";
                            zivoty+= zivotymax-zivoty;
                            penize-=65;
                        }

                        break;
                    case 2:
                        if ((penize >= 50)&&(energie < energiemax)) {
                            cout << "-50 peněz";
                            cout << "\nKdo by čekal že šumava bude mít takto veliké energetické výdaje.";
                            if (energie+3>energiemax) {
                                cout << "\n+" << energiemax - energie << "energie";
                                energie = energiemax;
                            }else {
                                energie+= 3;
                                cout << "+3 energie";
                            }

                            penize-= 50;
                        }else if (energie>=energiemax) {
                            cout << "\nMáte už maxilmální počet energie";
                        } else {
                            cout << "\nMate nedostatek peněz";
                        }


                        break;
                    case 3:
                        if (penize >= 45) {
                            for (int i = 0; i < 3; i++) {
                                pocitadloSymboly[i] = 0;
                            }
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
                        } else {
                            cout << "\nMate nedostatek peněz";
                        }

                }
                do {
                    cout << "\nChcete ještě nakoupit(a/n): "; cin >> vyberanone;
                }while ((overVstup() == true)||((vyberanone != 'n')&&(vyberanone != 'a')));
        }
    }while (vyberanone == 'a');
}

void MBezdomovecInfo(int &zivotyM, string &MJmeno) {
    zivotyM = 10;
    MJmeno = "Bezdomovec";
}

void MBezdomovecSouboj(int &uder) {
    cout << "\nZabiju tě";
    uder = random(1,10);
}
void krysaInfo(int &zivotyM, string &MJmeno) {
    zivotyM = 13;
    MJmeno = "Nádražní krysa";
}
void krysaSouboj(int &uder) {
    cout << "\nZhebni!";
    uder = random(3,6);
}

void kapsarInofo(int &zivotyM, string &MJmeno) {
    zivotyM = 8;
    MJmeno = "Kapsář";
}

void kapsarSouboj(int &uder, int &penize) {
    cout << "\nHele tamhle letí ledadlo.";
    uder = random(3,5);
    if (penize > 0) {
        cout << "\nČmajz!";
        int kradez = random(6,20);
        while (kradez > penize) {
            kradez--;
        }
        cout << "\n-" << kradez << " peněz";
        penize -= kradez;
    }
}

void souboj(int &energiemax,int &zivotymax ,int &penize, int cislopostavy, int &zivoty,int &energie, int velikostUtoku0,int velikostUtoku1, int monstrum1, int monstrum2 = 0, int monstrum3 = 0) {
    string MJmeno1;
    string MJmeno2;
    string MJmeno3;
    int tah = 0;
    int zivotyM1 = 0;
    int zivotyM2 = 0;
    int zivotyM3 = 0;

    int pocetB = 0;
    int pocetK = 0;
    int pocetKsr = 0;

    if (monstrum1 == 1) {pocetB++;}else if (monstrum1 == 2) {pocetK++;}else if (monstrum1 == 3) {pocetKsr++;}
    if (monstrum2 == 1) {pocetB++;}else if (monstrum2 == 2) {pocetK++;}else if (monstrum2 == 3) {pocetKsr++;}
    if (monstrum3 == 1) {pocetB++;}else if (monstrum3 == 2) {pocetK++;}else if (monstrum3 == 3) {pocetKsr++;}


    switch (monstrum1) {
        case 1:
            MBezdomovecInfo(zivotyM1, MJmeno1);
            if (pocetB > 1) {
                MJmeno1 += " 1";
            }
            break;
        case 2:
            krysaInfo(zivotyM1, MJmeno1);
            if (pocetK > 1) {
                MJmeno1 += " 1";
            }
            break;
        case 3:
            kapsarInofo(zivotyM1, MJmeno1);
            if (pocetKsr > 1) {
                MJmeno1 += " 1";
            }
            break;
    }
    switch (monstrum2) {
        case 1:
            MBezdomovecInfo(zivotyM2, MJmeno2);
            if (pocetB > 1) {
                MJmeno2 += " 2";
            }
            break;
        case 2:
            krysaInfo(zivotyM2, MJmeno2);
            if (pocetK > 1) {
                MJmeno2 += " 2";
            }
            break;
        case 3:
            kapsarInofo(zivotyM2, MJmeno2);
            if (pocetKsr > 1) {
                MJmeno2 += " 2";
            }
            break;
    }
    switch (monstrum3) {
        case 1:
            MBezdomovecInfo(zivotyM3, MJmeno3);
            if (pocetB>2) {
                MJmeno3 += " 3";
            }
            break;
        case 2:
            krysaInfo(zivotyM3, MJmeno3);
            if (pocetK>2) {
                MJmeno3 += " 3";
            }
            break;
        case 3:
            kapsarInofo(zivotyM3, MJmeno3);
            if (pocetKsr > 1) {
                MJmeno3 += " 3";
            }
            break;
    }

    cout << "\n     Souboj"
         << "\n=================\n"
         << "\nVy versus " << MJmeno1;
    if (monstrum2 != 0) {
        cout << ", " << MJmeno2;
    }
    if (monstrum3 != 0) {
        cout << ", " << MJmeno3;
    }
    cout << "\n\n--------------------------\n";
    cout  << MJmeno1 << "  Životy: " << zivotyM1;
    if (monstrum2 != 0) {
        cout << "\n" << MJmeno2 << "  Životy: " << zivotyM2;
    }
    if (monstrum3 != 0) {
        cout << "\n" << MJmeno3 << "  Životy: " << zivotyM3;
    }

    int uder = 0;

    cout << "\n--------------------------\n";
    while (zivoty > 0 && (zivotyM1 > 0 || zivotyM2 > 0 || zivotyM3 > 0)) {
        if (monstrum1 <= 3) {
            cout << "\nJste na tahu:";
            cout << "\n\nVaše životy:     "<< zivoty;
            cout << "\nVaše energie:    "<< energie;
            cout << "\nVaše peníze:     "<< penize;


            int nakoho;

            if ((monstrum2 == 0) && (monstrum3 == 0)) {
                cout << "\n\nVáš nepřítel\n";
                if (zivotyM1 > 0) {
                    cout << MJmeno1 << "   Životy: " << zivotyM1 << "\n";
                } else {
                    cout <<  MJmeno1 << "   Mrtvý\n";
                }
                nakoho = 1;
                cout << "\nZaútočit...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');


            } else {
                cout << "\n\nVaši nepřátelé\n";
                if (zivotyM1 > 0) {
                    cout << "1. " << MJmeno1 << "   Životy: " << zivotyM1 << "\n";
                } else {
                    cout << "1. " << MJmeno1 << "   Mrtvý\n";
                }
                if (zivotyM2 > 0) {
                    cout << "2. " << MJmeno2 << "   Životy: " << zivotyM2 << "\n";
                } else if (monstrum2 != 0) {
                    cout << "2. " << MJmeno2 << "   Mrtvý\n";
                }
                if (zivotyM3 > 0) {
                    cout << "3. " << MJmeno3 << "   Životy: " << zivotyM3 << "\n";
                } else if (monstrum3 != 0) {
                    cout << "3. " << MJmeno3 << "   Mrtvý\n";
                }

                do {
                    cout << "Na koho zaútočíte(číslo): ";
                    cin >> nakoho;
                }while ((overVstup() == true)||(nakoho < 1 || nakoho > 3));
                while (((nakoho == 1) && (zivotyM1 <= 0)) || ((nakoho == 2) && (zivotyM2 <= 0)) || ((nakoho == 3) && (zivotyM3 <= 0))) {
                    cout << "\nTento nepřítel už je mrtvý.";
                    do {
                        cout << "\nNa koho zaútočíte(číslo): ";
                        cin >> nakoho;
                    }while ((overVstup() == true)||(nakoho < 1 || nakoho > 3));
                }
            }

            postava(cislopostavy,'s', velikostUtoku0, velikostUtoku1,uder, energie);
            switch (nakoho) {
                case 1:
                    zivotyM1 -= uder;
                    cout << endl << MJmeno1 << " -" << uder << " životů";
                    break;
                case 2:
                    zivotyM2 -= uder;
                    cout << endl << MJmeno2 << " -" << uder << " životů";
                    break;
                case 3:
                    zivotyM3 -= uder;
                    cout << endl << MJmeno3 << " -" << uder << " životů";
                    break;
                default:
                    cout << "ERROR";
            }

        }
        this_thread::sleep_for(chrono::seconds(1));
        if ((zivotyM1 > 0)||(zivotyM2 > 0)||(zivotyM3 > 0)) {
            cout << "\n\n--------------------------";
        }
        // tah monster
        if (zivotyM1 > 0) {
            cout << "\nNa tahu je " << MJmeno1;
            switch (monstrum1) {
                case 1:
                    MBezdomovecSouboj(uder);
                    break;
                case 2:
                    krysaSouboj(uder);
                    break;
                case 3:
                    kapsarSouboj(uder, penize);
                    break;
            }
            zivoty -= uder;
            cout << "\nVy -" << uder << " životů";
            uder = 0;

        }

        if (zivotyM2 > 0) {
            cout << "\nNa tahu je " << MJmeno2;
            switch (monstrum2) {
                case 1:
                    MBezdomovecSouboj(uder);
                    break;
                case 2:
                    krysaSouboj(uder);
                    break;
                case 3:
                    kapsarSouboj(uder, penize);
                    break;
            }
            zivoty -= uder;
            cout << "\nVy -" << uder << " životů";
            uder = 0;

        }

        if (zivotyM3 > 0) {
            cout << "\nNa tahu je " << MJmeno3;
            switch (monstrum3) {
                case 1:
                    MBezdomovecSouboj(uder);
                    break;
                case 2:
                    krysaSouboj(uder);
                    break;
                case 3:
                    kapsarSouboj(uder, penize);
                    break;
            }
            zivoty -= uder;
            cout << "\nVy -" << uder << " životů";
            uder = 0;

        }
        if ((zivotyM1 > 0)||(zivotyM2 > 0)||(zivotyM3 > 0)) {
            cout << "\n--------------------------\n";
        }
        cout << "\nPokračovat...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cout << "\n================================";
    if (zivoty > 0) {

        if (monstrum1 != 0) {
            if (zivotyM1 > 0) {
                cout <<endl << MJmeno1 << "   Životy: " << zivotyM1 << "\n";
            } else {
                cout << endl << MJmeno1 << "   Mrtvý\n";
                cout << "Prohledávání... ";
                if (random(0,1) == 1) {
                    int nalez = random(10,36);
                    cout << "\n+ " << nalez <<" Peněz" << endl;
                    penize += nalez;
                }else {
                    cout << "\nNic jsi nenašel\n";
                }
            }
        }

        if (monstrum2 != 0) {
            if (zivotyM2 > 0) {
                cout << MJmeno2 << "   Životy: " << zivotyM2 << "\n";
            } else if (monstrum2 != 0) {
                cout << MJmeno2 << "   Mrtvý\n";
                cout << "Prohledávání... ";
                if (random(0,1) == 1) {
                    int nalez = random(10,36);
                    cout << "\n+ " << nalez <<" Peněz" << endl;
                    penize += nalez;
                }else {
                    cout << "\nNic jsi nenašel\n";
                }
            }
        }
        if (zivotyM3 != 0) {
            if (zivotyM3 > 0) {
                cout << MJmeno3 << "   Životy: " << zivotyM3 << "\n";
            } else if (monstrum3 != 0) {
                cout << MJmeno3 << "   Mrtvý\n";
                cout << "Prohledávání... ";
                if (random(0,1) == 1) {
                    int nalez = random(10,36);
                    cout << "\n+ " << nalez <<" Peněz" << endl;
                    penize += nalez;
                }else {
                    cout << "\nNic jsi nenašel\n";
                }
            }
        }

        cout << "\nTento souboj jsi vyhrál!";
        if (random(0,1) == 1) {
             cout << "\nTento souboj tě hodně naučil a zlepšil tvé dovednosti."
                  << "\n+2 maximální život";
            zivotymax+=2;

        }
        if (random(0,1) == 1) {
            cout << "\n\nCo tě nezabije, to tě posílí."
                 << "\n+1 maximální energie";
            energie++;

        }
    } else {
        cout << "\n\nTento souboj se ti nepodařil, nepřítel byl silnější než ty.";
        zivoty=0;
    }

}




int main() {

    srand(time(NULL));
    std::locale::global(std::locale(""));
    std::cout.imbue(std::locale());

    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    int pocetpostav = 4;
    string postava[pocetpostav] = {"Revizor", "Bezdomovec", "Černý pasažér", "Ajťák"};
    int cislopostavy;
    char vyberanone;

    int vagon = 15;
    int zivoty = 200;
    int zivotymax = 20;
    int energie = 10;
    int energiemax = 10;
    int penize = 100;

    int velikostUtoku[2];
    int uder;

    cout << "\n==== MISE: SOUPRAVA ====\n";
    cout << "\nNastoupíte do vlaku, protože jste si koupil místenku jdete ke svému sedadlu.\n"
         << "Na vašem sedadle leží dopis.\n"
         << "Přečíst dopis... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    cout << ".------------------------------------------.\n"
         << "|                                          |\n"
         << "|   Byl jste vybrán jako agent na tajnou   |\n"
         << "|   MISI: SOUPRAVA.                        |\n"
         << "|                                          |\n"
         << "|   Váš cíl je dostat se do lokomotivy     |\n"
         << "|   tohoto vlaku a zabít strojvedoucího.   |\n"
         << "|   Nebude to jednoduché, protože jste     |\n"
         << "|   v posledním vagónu této soupravy       |\n"
         << "|   Budete muset zneškodnit několik        |\n"
         << "|   nepřátel a postupovat vagón po vagónu  |\n"
         << "|   až k lokomotivě.                       |\n"
         << "|                                          |\n"
         << "|   Tajná vlaková agentura                 |\n"
         << "|                                          |\n"
         << " ------------------------------------------ \n";
    cout << "\nPokračovat... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do {
        vyberPostav();
        cin >> cislopostavy;
        while ((overVstup() == true)||(cislopostavy <= 0 || cislopostavy > 4)){
            cout << "\nNEPLATNÝ ÚDAJ\n";
            vyberPostav();
            cin >> cislopostavy;
        }

        cout << endl << postava[cislopostavy-1]<<endl;
        switch (cislopostavy) {
            case 1: revizorInfo(zivoty,zivotymax,energie,energiemax,penize,velikostUtoku[0],velikostUtoku[1]);

                break;
            case 2: bezdomovecInfo(); break;
            case 3: cernypasazerInfo(); break;
            case 4: ajtakInfo(); break;
            default: cout << "ERROR";
        }

        do {
            cout << "\nChcete vybrat tuto postavu (a/n): ";
            cin  >> vyberanone;
        }while ((overVstup() == true)||((vyberanone != 'a') && (vyberanone != 'n')));

    }while (vyberanone == 'n');

    cout << "\nVaše postava: " << postava[cislopostavy-1];

    cout << "\nAktuálně se nacházíte ve vagónu: " << vagon;
    cout << "\n\nV každém vagónu se mužou nacházet vaši nepřátelé.\n"
         << "Zrovna teď se před vámi objevil váš nepřítel. Váš úkol je ho teď zneškodnit.\n";
    cout << "Zneškodnit nepřítele...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    souboj(energiemax,zivotymax,penize ,cislopostavy, zivoty,energie,velikostUtoku[0], velikostUtoku[1],2,0,0);


    if (zivoty <= 0) {
        cout << "\n\nDosažený Vagón:  " << vagon << endl;
        statistika(zivoty,zivotymax,energie,energiemax,penize, velikostUtoku[0],velikostUtoku[1]);
        cout << "\n\nKonec...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0;
    }

        statistikaVagon(zivoty, zivotymax, energie, energiemax, penize, vagon,velikostUtoku[0],velikostUtoku[1]);


        jidelniVagon(zivoty,penize,energie, zivotymax, energiemax);
        statistikaVagon(zivoty, zivotymax, energie, energiemax, penize, vagon,velikostUtoku[0],velikostUtoku[1]);



    cout << "\nKonec";

}