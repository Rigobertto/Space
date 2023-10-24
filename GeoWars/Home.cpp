
#include "Engine.h"
#include "Space.h"
#include "Home.h"
#include "Start.h"
//#include "GameOver.h"
#include "Fundo.h"
#include "About.h"

// ------------------------------------------------------------------------------

Scene* Home::scene = nullptr;

void Home::Init()
{

    scene = new Scene();

    string src = "Resources/background/teladefundo.png";
    background = new Fundo(50, Color{ 1,1,1,1 }, src);
    scene->Add(background, STATIC);

    logo = new Sprite("Resources/botoes/logo.png");

    // cria objeto mouse
    mouse = new Mouse();
    scene->Add(mouse, MOVING);

    // cria itens de menu - float posX, float posY, float largura, float altura, int colunas, int quantidade, uint menuId, string imgFile
    menu[0] = new Item(window->CenterX(), 300, 260, 130, 1, 2, PLAY, "Resources/botoes/start.png");
    menu[1] = new Item(window->CenterX(), 420, 260, 130, 1, 2, ABOUT, "Resources/botoes/aboutb.png");
    menu[2] = new Item(window->CenterX(), 540, 260, 130, 1, 2, EXIT, "Resources/botoes/exit.png");

    // adiciona itens na cena
    for (int i = 0; i < MaxItens; ++i)
        scene->Add(menu[i], STATIC);

    Space::audio->Play(AUDIOMENU, true);
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    
    scene->Update();

    // fecha a janela ao pressionar ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza objeto mouse
    mouse->Update();

    if (window->KeyDown('N')) {
        Space::NextLevel<Start>();
    }

    // destaca item selecionado
    for (int i = 0; i < (MaxItens); i++)
    {
        if (scene->Collision(mouse, menu[i]))
        {
            menu[i]->Select();

            if (mouse->Clicked())
            {
                switch (menu[i]->Type())
                {
                case PLAY:
                    //Space::audio->Stop(MENU);
                    Space::NextLevel<Start>();
                    break;
                case ABOUT: Space::NextLevel<About>(); break;
                case EXIT: window->Close(); break;
                }
                break;
            }
        }
        else
        {
            menu[i]->UnSelect();
        }

        menu[i]->Update();
    }

}

// ------------------------------------------------------------------------------

void Home::Draw()
{

    logo->Draw(window->CenterX(), 150, Layer::FRONT);

    // desenha itens do menu
    scene->Draw();

    if (Space::viewBBox)
        scene->DrawBBox();

}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete background;
    delete mouse;
}

// ------------------------------------------------------------------------------