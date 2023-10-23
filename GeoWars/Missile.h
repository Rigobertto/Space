

#ifndef _SPACE_MISSILE_H_
#define _SPACE_MISSILE_H_

// --------------------------------------------------------------------------------

#include "Vector.h"
#include "Object.h"
#include "Sprite.h"
#include "Player.h" 

// --------------------------------------------------------------------------------

class Missile : public Object
{
private:
    const float MaxDistance = 4406; // distância máxima para o jogador
    const float BaseVolume = 0.8f;  // volume base para explosão

    static Player* & player;        // referência para o player
    Sprite * sprite;                // sprite do míssil
    Vector speed;                   // velocidade do míssil    
    
public:
    Missile();                      // construtor
    ~Missile();                     // destrutor

    Vector& Speed();                // retona vetor velocidade
    void Update();                  // atualização
    void Draw();                    // desenho
}; 

// ------------------------------------------------------------------------------

inline Vector& Missile::Speed()
{ return speed; }

inline void Missile::Draw()
{ sprite->Draw(x, y, Layer::UPPER, scale, rotation); }

// ------------------------------------------------------------------------------

#endif