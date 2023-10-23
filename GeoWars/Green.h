

#ifndef _SPACE_GREEN_H_
#define _SPACE_GREEN_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Green : public Object
{
private:
    Sprite * sprite;                    // sprite do objeto
    Vector * speed;                     // velocidade e direção
    Player * player;                    // ponteiro para jogador
    int distance;                       // mantém distância do jogador
    
public:
    Green(Player * p);                  // construtor
    ~Green();                           // destrutor
    
    void OnCollision(Object* obj);      // resolução da colisão
    void Update();                      // atualização
    void Draw();                        // desenho
}; 

// ---------------------------------------------------------------------------------

inline void Green::Draw()
{ sprite->Draw(x, y, Layer::LOWER, scale, rotation); }

// ---------------------------------------------------------------------------------


#endif