#include <iostream>
#include <time.h> // wenerowanie ziarna funkcji losujacej i pomiaru czasu
using namespace std;

// funkcja ktora wypelni tablice przekazana w parametrze losowymi wartosciami
// wejscie: tablica, rozmiar tablicy
// wyjscie; brak
void losowanieTab(int tab[], int rozmiarTab){ //void losowanieTab(int *tab, int rozmiar) {}
    srand(time(NULL)); //zainicjowanie funkcji losujacej
    for (int i = 0; i < rozmiarTab; i++)
        tab[i] = rand()%rozmiarTab;
}

// funkcja ktora wypisze na ekranie pierwsze 100 wartosci z tablicy przekazanej w parametrze
// wejscie :tab, rozmiar tab
// wyjscie: brak
void wypiszTab(int tab[], int rozmiar){
    for ( int i = 0 ; i < rozmiar; i++){
        if(i > 99){
            cout << "BREAK";
            break;
        }
        cout << tab[i] << " ";
    }
    cout << endl;
}

//funkcja wyswietwa into o czsie operacji wyliczajac go jako roznice pomiedzy czasStart i czasStop przekazane w parametrze
//wejscie clock_t szasStart, clock_t czasStop
//wyjscie brak
void czasOperacji(clock_t czasStart, clock_t czasStop){
    clock_t czas = czasStop - czasStart;
    cout << "zajelo to " << czas << " cykli czyli " << ((float)czas)/CLOCKS_PER_SEC << " sekund" << endl;
}
//sortowanie bombelkowe sortuje tab podana w parametrze metoda bombelkowa
// wejscie; tab, rozmiar tab
///wyjscie; brak
void sortowanieBabelkowe(int tab[], int rozmiar){
    for ( int i = 0; i < rozmiar; i++)
      for (int j = 0 ; j < rozmiar-1; j++)
        if (tab[j] > tab[j+1])
            swap(tab[j], tab[j+1]);
}

//sortowanie przez wybor
//sortuje tab podana w parametrze metoda przez wybor 0(n^2)
// wejscie; tablica, rozmiar tab
// wyjscei; brak
void sortWybor(int tab[], int rozmiar){

    for(int j = 0; j < rozmiar; j++){
        int pozMin = j;
        int min = tab[j];
        for ( int i = j; i < rozmiar; i++){
            if(tab[i] < min){
                pozMin = i;
                min = tab[i];
            }
        }
        if(j != pozMin)
        swap(tab[j], tab[pozMin]);
}
}

//sortowanie przez wstawianie(praca wlasna pls nie ufac)
// takie jak prestawianie kart by byly pokolei
// wejscie; tab i rozmiar tab
//wyjscie; nie
void sortInsert(int tab[], int rozmiar){
    for(int i = 1; i < rozmiar; i++)
    for (int j = 0; j < rozmiar; j++)
        if(tab[i] < tab[j])
            swap(tab[i], tab[j]);
}

int main(int argc, char const *argv[])
{
    cout << "START" << endl;
    const int n = 100;
    int tab[n];
    clock_t czasStart, czasStop;

    int rozmiarTab = 100;
    cout << "podaj rozmiar tablicy: ";
    cin >> rozmiarTab;
    int *tablica = new int[rozmiarTab]; // tablica tworzona dynamicznie, jej rozmiar jest znany dopiero po urochomieniu programu

    czasStart = clock();
    losowanieTab(tablica, rozmiarTab);
    czasStop = clock();
    wypiszTab(tablica, rozmiarTab);
    czasOperacji(czasStart, czasStop);
//babbelkowanie

    czasStart = clock();
    sortowanieBabelkowe(tablica, rozmiarTab);
    czasStop = clock();
    wypiszTab(tablica, rozmiarTab);
    czasOperacji(czasStart, czasStop);
//wybor
    losowanieTab(tablica, rozmiarTab);
    czasStart = clock();
    sortWybor(tablica, rozmiarTab);
    czasStop = clock();
    wypiszTab(tablica, rozmiarTab);
    czasOperacji(czasStart, czasStop);
//wstawnianie
    losowanieTab(tablica, rozmiarTab);
    czasStart = clock();
    sortInsert(tablica, rozmiarTab);
    czasStop = clock();
    wypiszTab(tablica, rozmiarTab);
    czasOperacji(czasStart, czasStop);



    return 0;
}