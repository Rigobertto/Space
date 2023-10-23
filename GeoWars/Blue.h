

#ifndef _SPACE_BLUE_H_
#define _SPACE_BLUE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Blue : public Object
{
private:
    Sprite * sprite;                    // sprite do objeto
    Vector * speed;                     // velocidade e dire��o
    Player * player;                    // ponteiro para jogador
    float factor;                       // fator de escala
    
public:
    Blue(Player * p);                   // construtor
    ~Blue();                            // destrutor
    
    void OnCollision(Object* obj);      // resolu��o da colis�o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
}; 

// ---------------------------------------------------------------------------------

inline void Blue::Draw()
{ sprite->Draw(x, y, Layer::LOWER, scale, rotation); }

// ---------------------------------------------------------------------------------


#endif