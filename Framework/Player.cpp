#include "Player.h"
#include <iostream>
#include "System.h"
#include "Enemy.h"

System s;

Player::Player(const char* _name,
	IRenderable* _pRenderable,
	SDL_Rect _bounds,
	EntityFlags _flags)
	: Entity(_name, _pRenderable, _bounds, (EntityFlags)(_flags | EntityFlags::SHOULD_UPDATE))
{
}

Player::~Player()
{
}

void Player::Update(Uint32 _dt)
{
	// steuerung
	// ggf. physik
	// ..

	// spieler in bounds halten


	if (GetBounds().x < m_allowBounds.x)
	{
		GetBounds().x = m_allowBounds.x;
	}

	if (GetBounds().y < m_allowBounds.y)
	{
		GetBounds().y = m_allowBounds.y;
	}

	if ((GetBounds().x + GetBounds().w) > (m_allowBounds.x + m_allowBounds.w))
	{
		GetBounds().x = m_allowBounds.x + m_allowBounds.w - GetBounds().w;
	}

	if ((GetBounds().y + GetBounds().h) > (m_allowBounds.y + m_allowBounds.h))
	{
		GetBounds().y = m_allowBounds.y + m_allowBounds.h - GetBounds().h;
	}

	// Temporäre Verlustbedingugn

	/*if (GetBounds().x <= 400 && GetBounds().y <= 400)
	{
		if (!LoseTriggered)
		{
			LoseTriggered = true;

			s.clean();

			std::cout << " KAFFE KEVIN ANGRY!!!" << std::endl;
		}
		
		

		

		

	}*/


}

void Player::OnCollision(Entity * _other)
{
	if (Enemy* eny = dynamic_cast<Enemy*>(_other))
	{
		m_currentScene->RemoveEntity(this);


	}
}
