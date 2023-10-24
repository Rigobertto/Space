/**********************************************************************************
// Player (Código Fonte)
//
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#include "Player.h"
#include "Engine.h"
#include "Home.h"
#include "LifeBar.h"

// ---------------------------------------------------------------------------------
int LifeBar::life = 0;
LifeBar::LifeBar()
{
    spriteA = new Sprite("Resources/game/life5.png");
    spriteB = new Sprite("Resources/game/life4.png");
    spriteC = new Sprite("Resources/game/life3.png");
    spriteD = new Sprite("Resources/game/life2.png");
    spriteE = new Sprite("Resources/game/life1.png");
    spriteF = new Sprite("Resources/game/life0.png");

    MoveTo(window->CenterX(), window->CenterY());
    type = 23;

    life = 5;
}

// ---------------------------------------------------------------------------------

LifeBar::~LifeBar()
{
    delete spriteA;
    delete spriteB;
    delete spriteC;
    delete spriteD;
    delete spriteE;
    delete spriteF;
}

void LifeBar::Update()
{
    switch (life)
    {
    case 5:  spriteA->Draw(window->Width() - spriteA->Width() * 2, spriteA->Height() + 20, Layer::UPPER, 3.0f); break;
    case 4:  spriteB->Draw(window->Width() - spriteA->Width() * 2, spriteA->Height() + 20, Layer::UPPER, 3.0f); break;
    case 3:  spriteC->Draw(window->Width() - spriteA->Width() * 2, spriteA->Height() + 20, Layer::UPPER, 3.0f); break;
    case 2:  spriteD->Draw(window->Width() - spriteA->Width() * 2, spriteA->Height() + 20, Layer::UPPER, 3.0f); break;
    case 1:  spriteE->Draw(window->Width() - spriteA->Width() * 2, spriteA->Height() + 20, Layer::UPPER, 3.0f); break;
    case 0:  spriteF->Draw(window->Width() - spriteA->Width() * 2, spriteA->Height() + 20, Layer::UPPER, 3.0f); break;
    }
}

// ---------------------------------------------------------------------------------

void LifeBar::Draw()
{

}