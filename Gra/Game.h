#pragma once
#include "Board.h"
#include "AI.h"

class UGame
{
public:
    UGame(UBoard* Plansza, UArtificialIntelligence* AI);

    void Uruchom();

private:
    void RysujPlansze();
    void ObsluzRuchGracza();
    void ObsluzRuchAI();

    UBoard* GraPlansza;
    UArtificialIntelligence* GraAI;
};
