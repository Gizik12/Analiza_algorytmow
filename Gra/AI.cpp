#include "AI.h"
#include "Board.h"

UArtificialIntelligence::UArtificialIntelligence(uint32_t Glebokosc)
{
    this->Glebokosc = Glebokosc;
    this->NajlepszyWiersz = -1;
    this->NajlepszaKolumna = -1;
}

void UArtificialIntelligence::RuchAI(UBoard* Plansza)
{
    int32_t NajlepszyWynik = INT32_MIN;
    NajlepszyWiersz = -1;
    NajlepszaKolumna = -1;

    for (uint32_t Wiersz = 0; Wiersz < Plansza->GetRozmiar(); Wiersz++)
    {
        for (uint32_t Kolumna = 0; Kolumna < Plansza->GetRozmiar(); Kolumna++)
        {
            if (!Plansza->CzyPoleZajete(Wiersz, Kolumna))
            {
                Plansza->UmiescSymbol(Wiersz, Kolumna, Plansza->GetSymbolAI());
                int32_t ObecnyWynik = MiniMax(Plansza, Glebokosc - 1, false, INT32_MIN, INT32_MAX);
                Plansza->UsunSymbol(Wiersz, Kolumna);

                if (ObecnyWynik > NajlepszyWynik)
                {
                    NajlepszyWiersz = Wiersz;
                    NajlepszaKolumna = Kolumna;
                    NajlepszyWynik = ObecnyWynik;
                }
            }
        }
    }

    if (NajlepszyWiersz != -1 && NajlepszaKolumna != -1)
    {
        Plansza->UmiescSymbol(NajlepszyWiersz, NajlepszaKolumna, Plansza->GetSymbolAI());
    }
}

int32_t UArtificialIntelligence::MiniMax(UBoard* Plansza, uint32_t Glebokosc, bool bMaksymalizujacyWynik, int32_t Alfa, int32_t Beta)
{
    EGameState ObecnyStanGry = Plansza->SprawdzStanGry();
    if (ObecnyStanGry == EGameState::GraczWygrywa || ObecnyStanGry == EGameState::AIWygrywa || Plansza->CzyPlanszaPelna() || Glebokosc == 0)
    {
        switch (ObecnyStanGry)
        {
        case EGameState::GraczWygrywa:
            return -1;

        case EGameState::AIWygrywa:
            return 1;

        case EGameState::Trwa:
        case EGameState::Remis:
            return 0;
        }
    }

    if (bMaksymalizujacyWynik)
    {
        int32_t Max = INT32_MIN;

        for (uint32_t Wiersz = 0; Wiersz < Plansza->GetRozmiar(); Wiersz++)
        {
            for (uint32_t Kolumna = 0; Kolumna < Plansza->GetRozmiar(); Kolumna++)
            {
                if (!Plansza->CzyPoleZajete(Wiersz, Kolumna))
                {
                    Plansza->UmiescSymbol(Wiersz, Kolumna, Plansza->GetSymbolAI());
                    int32_t Wynik = MiniMax(Plansza, Glebokosc - 1, false, Alfa, Beta);
                    Plansza->UsunSymbol(Wiersz, Kolumna);
                    Max = std::max(Max, Wynik);
                    Alfa = std::max(Alfa, Max);

                    if (Beta <= Alfa)
                    {
                        break;
                    }
                }
            }
            if (Beta <= Alfa)
            {
                break;
            }
        }
        return Max;
    }
    else
    {
        int32_t Min = INT32_MAX;

        for (uint32_t Wiersz = 0; Wiersz < Plansza->GetRozmiar(); Wiersz++)
        {
            for (uint32_t Kolumna = 0; Kolumna < Plansza->GetRozmiar(); Kolumna++)
            {
                if (!Plansza->CzyPoleZajete(Wiersz, Kolumna))
                {
                    Plansza->UmiescSymbol(Wiersz, Kolumna, Plansza->GetSymbolGracza());
                    int32_t Wynik = MiniMax(Plansza, Glebokosc - 1, true, Alfa, Beta);
                    Plansza->UsunSymbol(Wiersz, Kolumna);
                    Min = std::min(Min, Wynik);
                    Beta = std::min(Beta, Min);

                    if (Beta <= Alfa)
                    {
                        break;
                    }
                }
            }
            if (Beta <= Alfa)
            {
                break;
            }
        }
        return Min;
    }
}
