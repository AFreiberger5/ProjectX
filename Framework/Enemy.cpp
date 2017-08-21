#include "Enemy.h"
#include "TestScene.h"
#include "Renderer.h"
#include "Scene.h"
#include "System.h"
#include <iostream>

class Scene;

Enemy::Enemy(
	const char* _name,
	IRenderable* _pRenderable,
	SDL_Rect _bounds,
	Uint32 _flags)
	:Entity(_name, _pRenderable, _bounds, (EntityFlags)_flags)
{
}

Enemy::~Enemy()
{
}

void Enemy::Render(Renderer* _pRenderer, SDL_Point _offset)
{
	SDL_Rect bounds = SDL_Rect(m_bounds);
	bounds.x -= _offset.x;
	bounds.y += _offset.y;
	_pRenderer->Draw(m_pRenderable, bounds);
}

void Enemy::Update(Uint32 _dt)
{
	if (m_name == "Pit")
		m_bounds.y += _dt / RandomI(4, 15);

	else if (m_name == "Kevin1")
		m_bounds.y += _dt / RandomI(4, 15);

	else if (m_name == "Kevin2")
	{
		m_bounds.x += _dt / RandomI(4, 15);
		m_bounds.y += _dt / RandomI(4, 15);
	}

	else if (m_name == "Kevin3")
	{
		m_bounds.y -= _dt / RandomI(4, 15);
		m_bounds.x += _dt / RandomI(4, 15);
	}
	else if (m_name == "Mattis1")
	{
		m_bounds.y += _dt / RandomI(1, 12);
		m_bounds.x += _dt / RandomI(1, 12);
	}
	else if (m_name == "Mattis2")
		m_bounds.y += _dt / RandomI(4, 15);
	else if (m_name == "Mattis3")
		m_bounds.x -= _dt / RandomI(4, 15);
	else if (m_name == "Andre")
	{
		m_bounds.y += _dt / RandomI(4, 15);
		m_bounds.x += _dt / RandomI(4, 15);
	}

	//not optimal but to prevent all the entities from not getting deleted I kinda fixed it with this
	if ((GetBounds().y <= -1000) | (GetBounds().x <= -1000) | (GetBounds().x >= 1000) | (GetBounds().y >= 1000))
		m_currentScene->RemoveEntity(this, true);

}

void Enemy::OnCollision(Entity* _other)
{
	if (Projectile* pro = dynamic_cast<Projectile*>(_other))
	{
		m_currentScene->RemoveEntity(this, true);

	// tried stuff like this but we couldn't find a good way to remove the projectile when it collides with the first enemy
	//_other->m_currentScene->RemoveEntity(this, true);		
	}
}

bool Enemy::HasFlag(EntityFlags _flag)
{
	return m_flags & _flag;
}