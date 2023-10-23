

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
    //static Game* level;            // n�vel atual do jogo

public:
    static Game* level;            // n�vel atual do jogo
    static Audio * audio;           // sitema de �udio
    static bool viewBBox;

    static bool gameover;
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o

    template<class T>
    static void NextLevel()         // muda para pr�ximo n�vel do jogo
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