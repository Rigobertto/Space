

#ifndef _SPACE_PLAYER_H_
#define _SPACE_PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                        // objetos do jogo
#include "Sprite.h"                        // desenho de sprites
#include "Vector.h"                        // representação de vetores
#include "Particles.h"                    // sistema de partículas

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite * sprite;                    // sprite do objeto
    Particles * tail;                   // calda do jogador

public:
    Vector * speed;                     // velocidade e direção

    Player();                           // construtor
    ~Player();                          // destrutor
    
    void Move(Vector && v);             // movimenta jogador
    void Update();                      // atualização
    void Draw();                        // desenho
}; 
// ---------------------------------------------------------------------------------

#endif