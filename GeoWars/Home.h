#ifndef _SPACE_HOME_H_
#define _SPACE_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Item.h"
#include "Mouse.h"
#include "Scene.h"
#include "Fundo.h"

// ------------------------------------------------------------------------------

enum MenuID { PLAY, ABOUT, EXIT };

class Home : public Game
{
private:
    static const int MaxItens = 3;

    Sprite* logo = nullptr;
    Mouse* mouse = nullptr;         // objeto mouse
    Fundo* background = nullptr;
    Item* menu[MaxItens] = { 0, 0, 0};    // itens do menu

public:
    static Scene* scene;           // cena do n�vel

    void Init();                    // inicia n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza n�vel
};

// -----------------------------------------------------------------------------

#endif