#include "Character.h"
#include "Texture2D.h"
#include "constants.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
{
	m_renderer = renderer;
	m_position = start_position;
	m_facing_direction = FACING_RIGHT;
	m_moving_right = false;
	m_moving_left = false;
	m_can_jump = true;
	m_jumping = false;
	m_jump_force = 20.0f;

	m_texture = new Texture2D(m_renderer);

	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << "Failed to load Character texture!" << std::endl;
	}
}

Character :: ~Character()
{
	m_renderer = nullptr;
}

void Character :: Render()
{
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
}

void Character::Update(float deltaTime, SDL_Event e)
{
	//deal with jumping first
	if (m_jumping)
	{
		//adjust position
		m_position.y -= m_jump_force * deltaTime;

		//reduce jump force
		m_jump_force -= GRAVITY * deltaTime;

		//is jump force 0?
		if (m_jump_force <= 0.0f)
			m_jumping = false;
	}

	switch (e.type)
	{

	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = true;
			MoveLeft(deltaTime);
			break;
		case SDLK_RIGHT:
			m_moving_right = true;
			MoveRight(deltaTime);
			break;
		case SDLK_UP:
			if (m_can_jump)
			{
				Jump();
			}
		}
		break;

	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = false;
			break;
		case SDLK_RIGHT:
			m_moving_right = false;
			break;
		}
		break;

	}	
	AddGravity(deltaTime);
}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D Character :: GetPosition()
{
	return m_position;
}

void Character::MoveLeft(float deltaTime)
{
	if (m_moving_left == true)
	{
		m_facing_direction = FACING_LEFT;
		m_position.x -= MOVEMENTSPEED * deltaTime;
	}
}
void Character::MoveRight(float deltaTime)
{
	if (m_moving_right == true)
	{
		m_facing_direction = FACING_RIGHT;
		m_position.x += MOVEMENTSPEED * deltaTime;
	}
}

void Character::AddGravity(float deltaTime)
{
	if (m_position.y + 64 <= SCREEN_HEIGHT)
	{
		m_position.y += GRAVITY * deltaTime;
	}
	else
	{
		m_can_jump = true;
	}
}

void Character::Jump()
{
	//JUMP
	m_jump_force = INITIAL_JUMP_FORCE;
	m_jumping = true;
	m_can_jump = false;
}



