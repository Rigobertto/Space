/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     01 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Player do jogo PacMan
//
**********************************************************************************/

#ifndef _LIFE_BAR_H_
#define _LIFE_BAR_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
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

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif