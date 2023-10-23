
#ifndef _SPACE_DELAY_H_
#define _SPACE_DELAY_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Sprite.h"
#include "Timer.h"

// --------------------------------------------------------------------------------

class Delay : public Object
{
private:
    Sprite * logo;          // logotipo do jogo
    Timer timer;            // medidor de tempo
    bool notPlayed;         // intro não tocada ainda

public:
    Delay();                // construtor
    ~Delay();               // destrutor

    void Update();          // atualização
    void Draw();            // desenho
};

// ------------------------------------------------------------------------------

#endif
