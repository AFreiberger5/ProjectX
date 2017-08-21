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
		m_bounds.y += _dt / 8;

	else if (m_name == "Kevin1")
		m_bounds.y += _dt / 2;

	else if (m_name == "Kevin2")
	{
		m_bounds.x += _dt / 3;
		m_bounds.y += _dt / 3;
	}

	else if (m_name == "Kevin3")
	{
		m_bounds.y -= _dt / 2;
		m_bounds.x += _dt / 2;
	}
	else if (m_name == "Mattis1")
	{
		m_bounds.y += _dt / 4;
		m_bounds.x += _dt / 2;
	}
	else if (m_name == "Mattis2")
		m_bounds.y += _dt / 5;
	else if (m_name == "Mattis3")
		m_bounds.x -= _dt / 2;

	


}

void Enemy::OnCollision(Entity* _other)
{
	

	if (Projectile* pro = dynamic_cast<Projectile*>(_other))
	{
		m_currentScene->RemoveEntity(this,true);
		
		
	}
}



bool Enemy::HasFlag(EntityFlags _flag)
{
	return m_flags & _flag;
}

