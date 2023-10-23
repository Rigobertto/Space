/**********************************************************************************
// Green (Arquivo de Cabe�alho)
//
// Cria��o:     15 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Objeto faz uma fuga suavizada
//revisado
**********************************************************************************/

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
    Sprite* sprite;                            // sprite do objeto
    Player* player;                            // ponteiro para jogador
    Vector speed;                               // velocidade e dire��o
    int distance;                               // dist�ncia do jogador

public:
    Green(float pX, float pY, Player* p);      // construtor
    ~Green();                                   // destrutor

    void OnCollision(Object* obj);              // resolu��o da colis�o
    void Update();                              // atualiza��o
    void Draw();                                // desenho
};

// ---------------------------------------------------------------------------------

inline void Green::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------


#endif