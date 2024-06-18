#pragma once
#include <cstdint>

class UBoard;

class UArtificialIntelligence
{
public:
    UArtificialIntelligence(uint32_t Glebokosc);

    void RuchAI(UBoard* Plansza);

    int32_t MiniMax(UBoard* Plansza, uint32_t Glebokosc, bool bMaksymalizujacyWynik, int32_t Alfa, int32_t Beta);

    uint32_t GetNajlepszyWiersz() const { return NajlepszyWiersz; }

    uint32_t GetNajlepszaKolumna() const { return NajlepszaKolumna; }

private:
    uint32_t NajlepszyWiersz;

    uint32_t NajlepszaKolumna;

    uint32_t Glebokosc;
};
