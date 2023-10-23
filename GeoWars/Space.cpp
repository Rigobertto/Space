
#include "Resources.h"
#include "Space.h"
#include "Engine.h"    
#include "Magenta.h"
#include "Blue.h"    
#include "Green.h"
#include "Orange.h"
#include "Delay.h"
#include "Start.h"
#include "Home.h"
#include "About.h"

// ------------------------------------------------------------------------------

Game* Space::level = nullptr;
Audio* Space::audio = nullptr;
Player* Start::player = nullptr;
bool Space::viewBBox = false;
bool Space::gameover = false;

// ------------------------------------------------------------------------------

void Space::Init() 
{
    // cria sistema de áudio
    audio = new Audio();
    audio->Add(AUDIOMENU, "Resources/audios/Valley-of-Bowser.wav");
    audio->Add(THEME, "Resources/audios/stranger-things.wav");
    audio->Add(FIRE, "Resources/Fire.wav");
    audio->Add(HITWALL, "Resources/Hitwall.wav");
    audio->Add(EXPLODE, "Resources/Explode.wav");
    audio->Add(START, "Resources/Start.wav");

    // ajusta volumes
    audio->Volume(FIRE, 0.2f);
    audio->Volume(START, 0.8f);

    Start::player  = new Player();


    level = new Home();
   // level->Size(1920, 1200);
    level->Init();
}

// ------------------------------------------------------------------------------

void Space::Update()
{
    // sai com o pressionamento da tecla ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    if (gameover)
    {
        Space::NextLevel<Start>();
        gameover = false;
    }

    // habilita/desabilita visualização da bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;
    // atualiza cena e calcula colisões
    level->Update();
    
} 

// ------------------------------------------------------------------------------

void Space::Draw()
{

    level->Draw();
   
}

// ------------------------------------------------------------------------------

void Space::Finalize()
{
    level->Finalize();

    //delete player;
    delete audio;
    delete level;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // cria motor do jogo
    Engine * engine = new Engine();

    // configura motor
    //engine->window->Mode(WINDOWED);
    //engine->window->Size(1152, 648);
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 640);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Space");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    engine->window->HideCursor(true);
    //engine->graphics->VSync(true);

    // cria o jogo
    Game * game = new Space();

    // configura o jogo
    game->Size(1920, 1200);
    
    // inicia execução
    engine->Start(game);

    // destrói motor e encerra jogo
    delete engine;
    return 0;
}

// ----------------------------------------------------------------------------