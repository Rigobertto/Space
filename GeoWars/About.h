
#ifndef _SPACE_ABOUT_H_
#define _SPACE_ABOUT_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Fundo.h"
#include "Scene.h"
#include "TileSet.h"
#include "Animation.h"
#include "Item.h"
#include "Mouse.h"

// ------------------------------------------------------------------------------

enum MenuAbout { VOLTAR, HOMER };

class About : public Game
{
private:
    static const int MaxItens = 2;

    Mouse* mouse = nullptr;
    Fundo* background = nullptr;
    Item* menu[MaxItens] = { 0, 0 };

public:
    static Scene* scene;

    void Init();                    // inicializa��o do n�vel
    void Update();                  // l�gica da tela de fim
    void Draw();                    // desenho da tela
    void Finalize();                // finaliza��o do n�vel
};

// ------------------------------------------------------------------------------

#endif