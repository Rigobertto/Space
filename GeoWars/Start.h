
#ifndef _SPACE_START_H_
#define _SPACE_START_H_

// ------------------------------------------------------------------------------
// Inclusões

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
    Hud* hud = nullptr;            // painel de informações
    bool viewBBox = false;          // visualização das bouding boxes

public:
    static Scene* scene;           // cena do jogo
    static bool viewHUD;            // visualização do painel
    static Player* player;         // nave controlada pela jogador

    void Init();                    // inicialização do nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finalização do nível
};

// -----------------------------------------------------------------------------

#endif