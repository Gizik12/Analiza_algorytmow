#include <iostream>
#include "movieChest.h"

using namespace std;

//scalanie,quicksort,i cos
//(problemy dodawajnie tytułów z , w nazwie )
int main()
{
    int amount_of_data = 1000000; //Ustawiamy ile danych ma wczytac program
    MovieChest tab(amount_of_data); //Konstruktor naszego pojemnika na dane
    tab.loadData(amount_of_data); //Wczytanie danych z pliku do tablicy
    return 0;
}