#pragma once

#ifndef GAMESCREENLEVEL1_H
#define GAMESCREENLEVEL1_H

#include "GameScreen.h"
#include "Commons.h"

class Texture2D;

class GameScreenLevel1 : GameScreen
{
	private:
		Texture2D* m_background_texture;

		bool SetUpLevel1();

	public:
		GameScreenLevel1(SDL_Renderer* renderer);
		~GameScreenLevel1();

		void Render() override;
		void Update(float deltaTime, SDL_Event e) override;

};

#endif 
