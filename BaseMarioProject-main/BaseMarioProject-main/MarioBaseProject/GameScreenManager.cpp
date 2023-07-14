#include "GameScreenManager.h"
#include "GameScreen.h"
#include "GameScreenLevel1.h"

GameScreenLevel1* tempScreen;

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
	m_renderer = renderer;
	m_current_screen = nullptr;

	ChangeScreen(startScreen);
}

GameScreenManager::~GameScreenManager()
{
	delete m_current_screen;
	m_renderer = nullptr;
}

void GameScreenManager::ChangeScreen(SCREENS new_screen)
{
	//clear up the old screen
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}
	switch (new_screen)
	{
	case SCREEN_LEVEL1:
		tempScreen = new GameScreenLevel1(m_renderer);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
	default:;
	}
}

void GameScreenManager::Render()
{
	m_current_screen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);
}