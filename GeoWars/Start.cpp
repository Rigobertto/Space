
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
Image* Start::blue = nullptr;
Image* Start::green = nullptr;
Image* Start::magenta = nullptr;
Image* Start::orange = nullptr;
LifeBar* Start::lifeBar = nullptr;
// ------------------------------------------------------------------------------

void Start::Init()
{

    Start::Size(1920, 1200);
    // carrega imagens das geometrias
    blue = new Image("Resources/Blue.png");
    green = new Image("Resources/Green.png");
    magenta = new Image("Resources/Magenta.png");
    orange = new Image("Resources/Orange.png");

    // carrega/incializa objetos
    backg = new Background("Resources/background/Space.png");
    player = new Player();
    player->MoveTo((game->CenterX()/2), (game->CenterY() / 2));
    scene = new Scene();
    hud = new Hud();
    lifeBar = new LifeBar();

    // adiciona objetos na cena
    scene->Add(player, MOVING);
    scene->Add(lifeBar, MOVING);
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
    // sai com o pressionamento da tecla ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena e calcula colisões
    scene->Update();
    scene->CollisionDetection();

    // ---------------------------------------------------
    // atualiza a viewport
    // ---------------------------------------------------

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

    // ---------------------------------------------------

    // atualiza o painel de informações
    hud->Update();

    // ativa ou desativa o heads up display
    if (window->KeyPress('H'))
        viewHUD = !viewHUD;

}

// ------------------------------------------------------------------------------

void Start::Draw()
{
    // desenha pano de fundo
    backg->Draw(viewport);

    // desenha a cena
    scene->Draw();

    // desenha o painel de informações
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

    //delete player;
    delete hud;
    delete scene;
    delete backg;

    delete blue;
    delete green;
    delete magenta;
    delete orange;
}

// ------------------------------------------------------------------------------
