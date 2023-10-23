

#ifndef _SPACE_H_
#define _SPACE_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

enum Ids
{
    PLAYER, MISSILE, WALLHIT, BLUE, GREEN, MAGENTA, ORANGE,
    THEME, START, FIRE, EXPLODE, HITWALL, EXPLOSION, AUDIOMENU
};

// ------------------------------------------------------------------------------


// ------------------------------------------------------------------------------

class Space : public Game
{
private:
    //static Game* level;            // nível atual do jogo

public:
    static Game* level;            // nível atual do jogo
    static Audio * audio;           // sitema de áudio
    static bool viewBBox;

    static bool gameover;
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização

    template<class T>
    static void NextLevel()         // muda para próximo nível do jogo
    {
        if (level)
        {
            level->Finalize();
            delete level;
            level = new T();
            level->Init();
        }
    };
};

// ---------------------------------------------------------------------------------

#endif