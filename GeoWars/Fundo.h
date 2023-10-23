
#ifndef _SPACE_FUNDO_H_
#define _SPACE_FUNDO_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

class Fundo : public Object
{
private:
    float xB;                       // posição horizontal dos sprites
    Image* imgB;                       // imagem de fundo traseira    

    Sprite* backgB1;                   // pano de fundo dinâmico (traseiro 1)
    Sprite* backgB2;                   // pano de fundo dinâmico (traseiro 2)

    Color color;                        // cor do pano de fundo
    float speed = 0;

public:
    Fundo(float speed, Color tint, string src); // construtor
    ~Fundo();                      // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif