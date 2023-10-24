/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#ifndef _LIFE_BAR_H_
#define _LIFE_BAR_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------
// Constantes Globais

// ---------------------------------------------------------------------------------

class LifeBar : public Object
{
private:
    Sprite* spriteA = nullptr;         // sprite do player indo para esquerda
    Sprite* spriteB = nullptr;         // sprite do player indo para direita
    Sprite* spriteC = nullptr;         // sprite do player indo para cima
    Sprite* spriteD = nullptr;         // sprite do player indo para baixo
    Sprite* spriteE = nullptr;         // sprite do player indo para baixo
    Sprite* spriteF = nullptr;         // sprite do player indo para baixo


public:
    static int life;

    LifeBar();                           // construtor
    ~LifeBar();                          // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif