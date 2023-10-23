/**********************************************************************************
// WaveG (C�digo Fonte)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Cria uma onda de inimigos Green
//
**********************************************************************************/

#include "WaveG.h"
#include "Start.h"
#include "Space.h"
#include "Green.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveG::WaveG() : secs(10.0f, 15.0f)
{
    // atraso para a pr�xima onda 
    delay = secs.Rand();
}

// ------------------------------------------------------------------------------

WaveG::~WaveG()
{

}

// -------------------------------------------------------------------------------

void WaveG::Update()
{
    // contador de inimigos
    static uint counter = 8;

    // se passou o tempo de atraso
    if (timer.Elapsed(delay) && Hud::greens < 16)
    {
        if (counter > 0)
        {
            // toca som de nova onda
            Space::audio->Play(GREEN);

            // adiciona nova inimigo
            Start::scene->Add(new Green(50, 50, Start::player), MOVING);
            Start::scene->Add(new Green(game->Width() - 50, 50, Start::player), MOVING);
            Start::scene->Add(new Green(game->Width() - 50, game->Height() - 50, Start::player), MOVING);
            Start::scene->Add(new Green(50, game->Height() - 50, Start::player), MOVING);

            delay = 0.450f;
            timer.Start();
            --counter;
        }
        else
        {
            // nova onda
            counter = 8;
            delay = secs.Rand();
            timer.Start();
        }
    }
}

// -------------------------------------------------------------------------------

void WaveG::Draw()
{

}

// -------------------------------------------------------------------------------
