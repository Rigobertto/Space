
#ifndef _SPACE_GAMEOVER_H_
#define _SPACE_GAMEOVER_H_

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

enum MenuGameOver { PLAYAGAIN, HOME };

class GameOver : public Game
{
private:
    static const int MaxItens = 2;

    Mouse* mouse = nullptr;         // objeto mouse
    Sprite* gameover = nullptr;       // pano de fundo
    Fundo* background = nullptr;
    Item* menu[MaxItens] = { 0, 0 };

public:
    static Scene* scene;

    void Init();                    // inicialização do nível
    void Update();                  // lógica da tela de fim
    void Draw();                    // desenho da tela
    void Finalize();                // finalização do nível
};

// ------------------------------------------------------------------------------

#endif