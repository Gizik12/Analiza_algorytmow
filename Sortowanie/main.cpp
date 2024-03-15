#include <iostream>
#include "movieChest.h"

using namespace std;

//scalanie,quicksort,i cos
//(problemy dodawajnie tytułów z , w nazwie )
int main()
{
    int amount_of_data = 100; // Ustawiamy ile danych ma wczytac program
    MovieChest tab(amount_of_data); // Konstruktor naszego pojemnika na dane
    tab.loadData(amount_of_data); // Wczytanie danych z pliku do tablicy
    tab.showMovie();
    // Zwolnienie pamięci zaalokowanej dla obiektów Movie
    for (size_t i = 0; i < tab.getSize(); ++i)
    {
        delete tab.getMovie(i);
    }
    return 0;
} 