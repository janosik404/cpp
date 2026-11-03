#include <iostream>
#include "zespolona.h"
using namespace std;




int main(int argc, char const *argv[])
{
    //operatory na wbudowanych

    zespolona obwodA;
    zespolona obwodB("obwodB", 12, 5);
    cout << obwodA.toString() << endl;
    cout << obwodB.toString() << endl;

    zespolona wynik = obwodA + obwodB;
    cout << wynik.toString() << endl;
    
    
    zespolona wynik2 = 12.1 + obwodB;
    cout << wynik2.toString();
cout << "wypisania za pomoca <<" <<endl;
    cout << wynik2 << endl;

    if(wynik2 == obwodB)
        cout << "wunik2 jest rowny obwodB";
    else
        cout << "wunik2 nie jest rowny obwodB";

    obwodA = wynik2;

 if(wynik2 == obwodA)
        cout << "wunik2 jest rowny obwodA";
    else
        cout << "wunik2 nie jest rowny obwodA";


    cout << endl << endl;

    int liczba1 , liczba2;

    liczba1 = 10;
    liczba2 = 12;

    int wynikl = liczba1 + liczba2;
    liczba1++;
    ++liczba1;

cout << wynikl << endl;

    if (liczba1 > liczba2)
        cout << "liczba1 jest wieksza od liczba2";


    return 0;
}
