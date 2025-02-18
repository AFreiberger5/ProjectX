#include "Player.h"
#include <iostream>
#include "System.h"
#include "Enemy.h"
#include "Scene2.h"
#include "TestScene.h"




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
}

void Player::OnCollision(Entity * _other)
{
	if (Enemy* eny = dynamic_cast<Enemy*>(_other))
	{
		m_Lose = true;
		m_currentScene->LoadLose(m_Lose);
		m_currentScene->RemoveEntity(this, true);

	}
}
