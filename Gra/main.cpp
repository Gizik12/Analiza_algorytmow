#include <iostream>
#include <limits>

#include "Board.h"
#include "AI.h"
#include "Game.h"

int main()
{
    setlocale(LC_ALL, "pl_PL");

    uint32_t Rozmiar, WarunekWygranej, Glebokosc;
    char SymbolGracza;

    do
    {
        std::cout << "Podaj rozmiar planszy: ";
        std::cin >> Rozmiar;
    } while (Rozmiar <= 0 || Rozmiar > UINT32_MAX);

    do
    {
        std::cout << "Podaj liczbe symboli potrzebnych do wygrania: ";
        std::cin >> WarunekWygranej;
    } while (WarunekWygranej <= 0 || WarunekWygranej > Rozmiar);

    do
    {
        std::cout << "Podaj glebokosc liczenia wariantow/rekurencji: ";
        std::cin >> Glebokosc;
    } while (Glebokosc <= 0 || Glebokosc > Rozmiar);

    do
    {
        std::cout << "Wybierz symbol (x/o) (x - zaczyna): ";
        std::cin >> SymbolGracza;
    } while (SymbolGracza != 'x' && SymbolGracza != 'o');

    UBoard Plansza(Rozmiar, WarunekWygranej, SymbolGracza);
    UArtificialIntelligence AI(Glebokosc);

    UGame* NowaGra = new UGame(&Plansza, &AI);
    NowaGra->Uruchom();

    delete NowaGra;
    return 0;
}
