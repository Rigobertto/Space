/**********************************************************************************
// Delay (C�digo Fonte)
//
// Cria��o:     02 Ago 2019
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Sincroniza uma a��o
//
**********************************************************************************/

#include "Delay.h"
#include "Space.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

Delay::Delay()
{
    logo = new Sprite("Resources/Logo.png");
    timer.Start();
    notPlayed = true;
}

// ------------------------------------------------------------------------------

Delay::~Delay()
{
    delete logo;
}

// -------------------------------------------------------------------------------

void Delay::Update()
{
    if (notPlayed && timer.Elapsed(2.0f))
    {
        // toca �udio de introdu��o
        Space::audio->Play(START);
        notPlayed = false;
    }

    if (timer.Elapsed(6.0f))
    {
        // toca m�sica do jogo
        Space::audio->Play(THEME, true);
        Space::viewHUD = true;
        Space::scene->Delete();
    }
}

// -------------------------------------------------------------------------------

void Delay::Draw()
{
    logo->Draw(game->viewport.left + window->CenterX() , game->viewport.top + window->CenterY(), Layer::FRONT);
}

// -------------------------------------------------------------------------------
