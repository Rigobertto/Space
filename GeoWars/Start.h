
#ifndef _SPACE_START_H_
#define _SPACE_START_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Audio.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

class Start : public Game
{
private:
    Background* backg = nullptr;   // pano de fundo
    Hud* hud = nullptr;            // painel de informa��es
    bool viewBBox = false;          // visualiza��o das bouding boxes

public:
    static Scene* scene;           // cena do jogo
    static bool viewHUD;            // visualiza��o do painel
    static Player* player;         // nave controlada pela jogador

    void Init();                    // inicializa��o do n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif