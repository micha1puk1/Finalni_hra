#include <iostream>
using namespace std;

int main() {

  int pocetpostav = 4;
  string postava[pocetpostav] = {"Revizor", "Bezdomovec", "Černý pasažér", "Ajťák"};
  int cislopostavy;

  cout <<"Vybete si postavu:";

 do {
     cout << "\n1. Revizor";
     cout << "\n2. Bezdomovec";
     cout << "\n3. Černý pasažér";
     cout << "\n4. Ajťák";
     cout << "\nČíslo postavy: ";
     cin >> cislopostavy;
 }while (cislopostavy <= 0 || cislopostavy > 4);

  cout << endl << postava[cislopostavy-1];










}