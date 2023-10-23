
#include "Engine.h"
#include "About.h"
#include "Space.h"
#include "Home.h"
#include "Background.h"
#include "Scene.h"
#include "Animation.h"
#include <iostream>
#include <string>

// ----------------------------------------------------------------------
Scene* About::scene = nullptr;

void About::Init()
{
    scene = new Scene();

    string src = "Resources/background/about.png";
    background = new Fundo(0, Color{ 1,1,1,1 }, src);
    scene->Add(background, STATIC);

    // cria objeto mouse
    mouse = new Mouse();
    scene->Add(mouse, MOVING);

    // cria itens de menu - float posX, float posY, float largura, float altura, int colunas, int quantidade, uint menuId, string imgFile

    menu[0] = new Item(100, 50, 124, 29, 1, 2, VOLTAR, "Resources/botoes/back.png");

    menu[1] = new Item(window->CenterX(), 450, 102, 25, 1, 2, HOMER, "");

    // adiciona itens na cena
    for (int i = 0; i < MaxItens; ++i)
        scene->Add(menu[i], STATIC);


}

// ----------------------------------------------------------------------

void About::Update()
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
                case VOLTAR:

                    Space::NextLevel<Home>();

                    break;
                case HOMER:

                    //Space::audio->Stop(MENU);
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

void About::Draw()
{
    Color vermelho(0.97f, 0.47f, 0.36f, 1.0f);
    Color creme(0.94f, 0.91f, 0.76f, 1.0f);


    scene->Draw();

    if (Space::viewBBox)
        scene->DrawBBox();
}

// ----------------------------------------------------------------------

void About::Finalize()
{
    delete background;
    delete mouse;
}

// ----------------------------------------------------------------------

