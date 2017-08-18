#include "Enemy.h"
#include "TestScene.h"
#include "Renderer.h"
#include "Scene.h"
#include <iostream>






class Scene;



Enemy::Enemy(
	const char* _name,
	IRenderable* _pRenderable,
	SDL_Rect _bounds,
	Uint32 _flags)
	:Entity(_name, _pRenderable, _bounds, (EntityFlags)_flags)
{
	/*m_name = _name;
	m_pSprite = _pSprite;
	m_bounds = _bounds;
	m_flags = _flags;
	*/
	

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
	
	if (m_bounds.x < 200 && m_name == "Kevin")
		m_bounds.x += _dt / 2;

	else if (m_bounds.x < 200)
		m_bounds.x += _dt/3;

	if (m_bounds.x >= 200)
		m_bounds.y -= _dt;



}

void Enemy::OnCollision(Entity * _other)
{
	

	if (Projectile* pro = dynamic_cast<Projectile*>(_other))
	{
		m_currentScene->RemoveEntity(this);

		
	}
}



bool Enemy::HasFlag(EntityFlags _flag)
{
	return m_flags & _flag;
}

