

#ifndef _SPACE_ORANGE_H_
#define _SPACE_ORANGE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Orange : public Object
{
private:
    Sprite * sprite;                    // sprite do objeto
    Vector * speed;                     // velocidade e dire��o
    Player * player;                    // ponteiro para jogador
    Particles * tail;                   // calda da nave laranja
    float multiplier;                   // multiplicador da velocidade
    
public:
    Orange(Player * p);                 // construtor
    ~Orange();                          // destrutor
    
    void OnCollision(Object* obj);      // resolu��o da colis�o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
}; 

// ---------------------------------------------------------------------------------


#endif