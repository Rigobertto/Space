
#include "Engine.h"
#include "GameOver.h"
#include "Space.h"
#include "Home.h"
#include "Fundo.h"
#include "Scene.h"
#include "Animation.h"
#include "Start.h"

// ----------------------------------------------------------------------
Scene* GameOver::scene = nullptr;

void GameOver::Init()
{
    scene = new Scene();
    gameover = new Sprite("Resources/botoes/gameover.png");

    string src = "Resources/background/theend.png";
    background = new Fundo(0, Color{ 1,1,1,1 }, src);
    scene->Add(background, STATIC);


    // cria objeto mouse
    mouse = new Mouse();
    scene->Add(mouse, MOVING);

    // cria itens de menu - float posX, float posY, float largura, float altura, int colunas, int quantidade, uint menuId, string imgFile
    menu[0] = new Item(window->CenterX(), 450, 260, 130, 1, 2, PLAYAGAIN, "Resources/botoes/playagain.png");
    menu[1] = new Item(window->CenterX(), 580, 260, 130, 1, 2, HOME, "Resources/botoes/home.png");

    // adiciona itens na cena
    for (int i = 0; i < MaxItens; ++i)
        scene->Add(menu[i], STATIC);
}

// ----------------------------------------------------------------------

void GameOver::Update()
{

    scene->Update();

    // fecha a janela ao pressionar ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza objeto mouse
    mouse->Update();

    // destaca item selecionado
    for (int i = 0; i < MaxItens; i++)
    {
        if (scene->Collision(mouse, menu[i]))
        {
            menu[i]->Select();

            if (mouse->Clicked())
            {
                switch (menu[i]->Type())
                {
                case PLAYAGAIN:
                    //Space::audio->Stop(THEME);
                    //Start::player->Reset();
                    Space::NextLevel<Start>();

                    break;
                case HOME:
                    
                    Space::audio->Stop(AUDIOMENU);
                   // Start::player->Reset();
                    Space::NextLevel<Home>();
                    break;
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

// ----------------------------------------------------------------------

void GameOver::Draw()
{
    gameover->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
    scene->Draw();

    if (Space::viewBBox)
        scene->DrawBBox();
}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
    delete background;
    delete mouse;
    delete gameover;
}

// ----------------------------------------------------------------------

