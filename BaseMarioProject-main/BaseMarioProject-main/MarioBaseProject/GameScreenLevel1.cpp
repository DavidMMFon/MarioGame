#include "GameScreenLevel1.h"

#include "Texture2D.h"
#include <iostream>
using namespace std;

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel1();
}

GameScreenLevel1::~GameScreenLevel1() 
{
	delete m_background_texture;
	m_background_texture = nullptr;
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{

}
void GameScreenLevel1::Render()
{
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);

}

bool GameScreenLevel1::SetUpLevel1()
{
	//load texture
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/test.bmp"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
}


