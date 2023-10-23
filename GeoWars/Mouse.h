
#ifndef _SPACE_MOUSE_H_
#define _SPACE_MOUSE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"        
#include "Types.h" 
#include "Item.h"

// ---------------------------------------------------------------------------------

class Mouse : public Object
{
public:
    Mouse();            // construtor
    ~Mouse();           // destrutor

    bool Clicked();     // click do mouse
    void Update();      // atualiza��o do objeto
    void Draw();        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif