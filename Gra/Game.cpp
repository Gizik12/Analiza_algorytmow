#include <iostream>
#include "Game.h"

UGame::UGame(UBoard* Plansza, UArtificialIntelligence* AI)
{
    this->GraPlansza = Plansza;
    this->GraAI = AI;
}

void UGame::Uruchom()
{
    int stan = 0;
    std::cout << "Plansza:" << std::endl;
    RysujPlansze();
    while (GraPlansza->SprawdzStanGry() == EGameState::Trwa)
    {
        if (GraPlansza->GetKolej() == ETurn::Gracz)
        {
            ObsluzRuchGracza();
            std::cout << "Twoj ruch:"<< std::endl;
            RysujPlansze();

        }
        else
        {
            ObsluzRuchAI();
            std::cout << "Ruch AI:"<< std::endl;
            RysujPlansze();
        }
    }

    RysujPlansze();
    EGameState StanGry = GraPlansza->SprawdzStanGry();
    if (StanGry == EGameState::GraczWygrywa)
    {
        std::cout << "Gracz wygral!\n";
    }
    else if (StanGry == EGameState::AIWygrywa)
    {
        std::cout << "AI wygral!\n";
    }
    else
    {
        std::cout << "Remis!\n";
    }
}

void UGame::RysujPlansze()
{
    for (uint32_t Wiersz = 0; Wiersz < GraPlansza->GetRozmiar(); ++Wiersz)
    {
        for (uint32_t Kolumna = 0; Kolumna < GraPlansza->GetRozmiar(); ++Kolumna)
        {
            ESymbol Symbol = GraPlansza->SprawdzSymbol(Wiersz, Kolumna);
            if (Symbol == ESymbol::Krzyzyk)
            {
                std::cout << " X ";
            }
            else if (Symbol == ESymbol::Kolko)
            {
                std::cout << " O ";
            }
            else
            {
                std::cout << " . ";
            }

            if (Kolumna < GraPlansza->GetRozmiar() - 1)
            {
                std::cout << "|";
            }
        }
        std::cout << "\n";

        if (Wiersz < GraPlansza->GetRozmiar() - 1)
        {
            for (uint32_t Kolumna = 0; Kolumna < GraPlansza->GetRozmiar(); ++Kolumna)
            {
                std::cout << "---";
                if (Kolumna < GraPlansza->GetRozmiar() - 1)
                {
                    std::cout << "+";
                }
            }
            std::cout << "\n";
        }
    }
}

void UGame::ObsluzRuchGracza()
{
    uint32_t Wiersz, Kolumna;
    do
    {
        std::cout << "Podaj wiersz i kolumne (0-" << GraPlansza->GetRozmiar() - 1 << "): ";
        std::cin >> Wiersz >> Kolumna;
    } while (Wiersz >= GraPlansza->GetRozmiar() || Kolumna >= GraPlansza->GetRozmiar() || GraPlansza->CzyPoleZajete(Wiersz, Kolumna));

    GraPlansza->UmiescSymbol(Wiersz, Kolumna, GraPlansza->GetSymbolGracza());
    GraPlansza->ZmienKolej();
}

void UGame::ObsluzRuchAI()
{
    GraAI->RuchAI(GraPlansza);
    GraPlansza->UmiescSymbol(GraAI->GetNajlepszyWiersz(), GraAI->GetNajlepszaKolumna(), GraPlansza->GetSymbolAI());
    GraPlansza->ZmienKolej();
}
