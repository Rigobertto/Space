
#include "Resources.h"
#include "Space.h"
#include "Engine.h"    
#include "Magenta.h"
#include "Blue.h"    
#include "Green.h"
#include "Orange.h"
#include "Delay.h"
#include "Start.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;
#include <iostream>

using namespace std;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe



Scene * Start::scene = nullptr;
bool   Start::viewHUD = false;

// ------------------------------------------------------------------------------

void Start::Init()
{

    Start::Size(1920, 1200);
    backg = new Background("Resources/background/Space.png");
    // cria gerenciador de cena
    scene = new Scene();

    // cria o painel de informações
    hud = new Hud();

    // adiciona objetos na cena (sem colisão)
    scene->Add(player, STATIC);
    scene->Add(new Magenta(player), STATIC);
    scene->Add(new Blue(player), STATIC);
    scene->Add(new Green(player), STATIC);
    scene->Add(new Orange(player), STATIC);
    scene->Add(new Delay(), STATIC);

    // ----------------------
    // inicializa a viewport
    // ----------------------
    
    // calcula posição para manter viewport centralizada
    float difx = (game->Width() - window->Width()) / 2.0f;
    float dify = (game->Height() - window->Height()) / 2.0f;

    // inicializa viewport para o centro do mundo
    viewport.left = 0.0f + difx;
    viewport.right = viewport.left + window->Width();
    viewport.top = 0.0f + dify;
    viewport.bottom = viewport.top + window->Height();
}

// ------------------------------------------------------------------------------

void Start::Update()
{
    scene->Update();
    scene->CollisionDetection();

    // ativa ou desativa a bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;

    // ativa ou desativa o heads up display
    if (window->KeyPress('H'))
        viewHUD = !viewHUD;

    // --------------------
    // atualiza a viewport
    // --------------------

    viewport.left = player->X() - window->CenterX();
    viewport.right = player->X() + window->CenterX();
    viewport.top = player->Y() - window->CenterY();
    viewport.bottom = player->Y() + window->CenterY();

    if (viewport.left < 0)
    {
        viewport.left = 0;
        viewport.right = window->Width();
    }
    else if (viewport.right > game->Width())
    {
        viewport.left = game->Width() - window->Width();
        viewport.right = game->Width();
    }

    if (viewport.top < 0)
    {
        viewport.top = 0;
        viewport.bottom = window->Height();
    }
    else if (viewport.bottom > game->Height())
    {
        viewport.top = game->Height() - window->Height();
        viewport.bottom = game->Height();
    }

}

// ------------------------------------------------------------------------------

void Start::Draw()
{
    // desenha pano de fundo
    backg->Draw(viewport);

    // desenha a cena
    scene->Draw();

    // desenha painel de informações
    if (viewHUD)
        hud->Draw();

    // desenha bounding box
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Start::Finalize()
{
    scene->Remove(player, MOVING);

    delete player;
    delete hud;
    delete scene;
    delete backg;
}

// ------------------------------------------------------------------------------
