#pragma once
#include <cstdint>
#include <vector>

enum ETurn
{
    Gracz,
    AI
};

enum ESymbol
{
    Brak,
    Krzyzyk,
    Kolko
};

enum EGameState
{
    Trwa,
    GraczWygrywa,
    AIWygrywa,
    Remis
};

class UBoard
{
public:
    UBoard() {};

    UBoard(uint32_t Rozmiar, uint32_t WarunekWygranej, char SymbolGracza);

    void UmiescSymbol(uint32_t Wiersz, uint32_t Kolumna, ESymbol Symbol);

    void UsunSymbol(uint32_t Wiersz, uint32_t Kolumna);

    void ResetujPlansze();

    ESymbol SprawdzSymbol(uint32_t Wiersz, uint32_t Kolumna) const;

    bool CzyPoleZajete(uint32_t Wiersz, uint32_t Kolumna) const;

    bool CzyPlanszaPelna() const;

    void ZmienKolej();

    EGameState SprawdzStanGry();

    size_t GetRozmiar() const { return Rozmiar; }

    uint32_t GetWarunekWygranej() const { return WarunekWygranej; }

    ETurn GetKolej() const { return Kolej; }

    ESymbol GetSymbolGracza() const { return SymbolGracza; }

    ESymbol GetSymbolAI() const { return SymbolAI; }

private:
    uint32_t Rozmiar;

    uint32_t WarunekWygranej;

    ETurn Kolej;

    ESymbol SymbolGracza;

    ESymbol SymbolAI;

    EGameState StanGry;

    std::vector<std::vector<ESymbol>> Pola;
};
