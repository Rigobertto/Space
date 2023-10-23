
#ifndef _SPACE_FUNDO_H_
#define _SPACE_FUNDO_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Fundo : public Object
{
private:
    float xB;                       // posi��o horizontal dos sprites
    Image* imgB;                       // imagem de fundo traseira    

    Sprite* backgB1;                   // pano de fundo din�mico (traseiro 1)
    Sprite* backgB2;                   // pano de fundo din�mico (traseiro 2)

    Color color;                        // cor do pano de fundo
    float speed = 0;

public:
    Fundo(float speed, Color tint, string src); // construtor
    ~Fundo();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif