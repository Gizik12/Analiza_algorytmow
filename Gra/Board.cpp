#include "Board.h"

UBoard::UBoard(uint32_t Rozmiar, uint32_t WarunekWygranej, char SymbolGracza)
{
    this->Rozmiar = Rozmiar;
    this->WarunekWygranej = WarunekWygranej;
    switch (SymbolGracza)
    {
    case 'x':
        this->SymbolGracza = ESymbol::Krzyzyk;
        this->SymbolAI = ESymbol::Kolko;
        this->Kolej = ETurn::Gracz;
        break;

    case 'o':
        this->SymbolGracza = ESymbol::Kolko;
        this->SymbolAI = ESymbol::Krzyzyk;
        this->Kolej = ETurn::AI;
        break;

    default:
        break;
    }
    this->StanGry = EGameState::Trwa;
    this->Pola = std::vector<std::vector<ESymbol>>(Rozmiar, std::vector<ESymbol>(Rozmiar, ESymbol::Brak));
}

void UBoard::UmiescSymbol(uint32_t Wiersz, uint32_t Kolumna, ESymbol Symbol)
{
    Pola[Wiersz][Kolumna] = Symbol;
}

void UBoard::UsunSymbol(uint32_t Wiersz, uint32_t Kolumna)
{
    Pola[Wiersz][Kolumna] = ESymbol::Brak;
}

void UBoard::ResetujPlansze()
{
    for (uint32_t Wiersz = 0; Wiersz < Rozmiar; Wiersz++)
    {
        for (uint32_t Kolumna = 0; Kolumna < Rozmiar; Kolumna++)
        {
            Pola[Wiersz][Kolumna] = ESymbol::Brak;
        }
    }
}

ESymbol UBoard::SprawdzSymbol(uint32_t Wiersz, uint32_t Kolumna) const
{
    return Pola[Wiersz][Kolumna];
}

bool UBoard::CzyPoleZajete(uint32_t Wiersz, uint32_t Kolumna) const
{
    return Pola[Wiersz][Kolumna] != ESymbol::Brak;
}

bool UBoard::CzyPlanszaPelna() const
{
    for (uint32_t Wiersz = 0; Wiersz < Rozmiar; Wiersz++)
    {
        for (uint32_t Kolumna = 0; Kolumna < Rozmiar; Kolumna++)
        {
            if (Pola[Wiersz][Kolumna] == ESymbol::Brak)
            {
                return false;
            }
        }
    }
    return true;
}

void UBoard::ZmienKolej()
{
    Kolej = (Kolej == ETurn::Gracz) ? ETurn::AI : ETurn::Gracz;
}

EGameState UBoard::SprawdzStanGry()
{
    // Sprawdź wygrane wiersze
    for (uint32_t Wiersz = 0; Wiersz < Rozmiar; Wiersz++)
    {
        uint32_t LiczbaSymboli = 1;
        for (uint32_t Kolumna = 1; Kolumna < Rozmiar; Kolumna++)
        {
            if (Pola[Wiersz][Kolumna] != ESymbol::Brak &&
                Pola[Wiersz][Kolumna] == Pola[Wiersz][Kolumna - 1])
            {
                LiczbaSymboli++;
                if (LiczbaSymboli >= WarunekWygranej)
                {
                    return (Pola[Wiersz][Kolumna] == SymbolGracza) ? EGameState::GraczWygrywa : EGameState::AIWygrywa;
                }
            }
            else
            {
                LiczbaSymboli = 1;
            }
        }
    }

    // Sprawdź wygrane kolumny
    for (uint32_t Kolumna = 0; Kolumna < Rozmiar; Kolumna++)
    {
        uint32_t LiczbaSymboli = 1;
        for (uint32_t Wiersz = 1; Wiersz < Rozmiar; Wiersz++)
        {
            if (Pola[Wiersz][Kolumna] != ESymbol::Brak &&
                Pola[Wiersz][Kolumna] == Pola[Wiersz - 1][Kolumna])
            {
                LiczbaSymboli++;
                if (LiczbaSymboli >= WarunekWygranej)
                {
                    return (Pola[Wiersz][Kolumna] == SymbolGracza) ? EGameState::GraczWygrywa : EGameState::AIWygrywa;
                }
            }
            else
            {
                LiczbaSymboli = 1;
            }
        }
    }

    // Sprawdź wygrane przekątne
    for (uint32_t StartWiersz = 0; StartWiersz < Rozmiar - WarunekWygranej + 1; StartWiersz++)
    {
        for (uint32_t StartKolumna = 0; StartKolumna < Rozmiar - WarunekWygranej + 1; StartKolumna++)
        {
            uint32_t LiczbaSymboli = 1;
            for (uint32_t Offset = 1; Offset < WarunekWygranej; Offset++)
            {
                if (Pola[StartWiersz + Offset][StartKolumna + Offset] != ESymbol::Brak &&
                    Pola[StartWiersz + Offset][StartKolumna + Offset] == Pola[StartWiersz + Offset - 1][StartKolumna + Offset - 1])
                {
                    LiczbaSymboli++;
                    if (LiczbaSymboli >= WarunekWygranej)
                    {
                        return (Pola[StartWiersz + Offset][StartKolumna + Offset] == SymbolGracza) ? EGameState::GraczWygrywa : EGameState::AIWygrywa;
                    }
                }
                else
                {
                    LiczbaSymboli = 1;
                }
            }
        }
    }

    for (uint32_t StartWiersz = 0; StartWiersz < Rozmiar - WarunekWygranej + 1; StartWiersz++)
    {
        for (uint32_t StartKolumna = WarunekWygranej - 1; StartKolumna < Rozmiar; StartKolumna++)
        {
            uint32_t LiczbaSymboli = 1;
            for (uint32_t Offset = 1; Offset < WarunekWygranej; Offset++)
            {
                if (Pola[StartWiersz + Offset][StartKolumna - Offset] != ESymbol::Brak &&
                    Pola[StartWiersz + Offset][StartKolumna - Offset] == Pola[StartWiersz + Offset - 1][StartKolumna - Offset + 1])
                {
                    LiczbaSymboli++;
                    if (LiczbaSymboli >= WarunekWygranej)
                    {
                        return (Pola[StartWiersz + Offset][StartKolumna - Offset] == SymbolGracza) ? EGameState::GraczWygrywa : EGameState::AIWygrywa;
                    }
                }
                else
                {
                    LiczbaSymboli = 1;
                }
            }
        }
    }

    if (CzyPlanszaPelna())
    {
        return EGameState::Remis;
    }

    return EGameState::Trwa;
}
