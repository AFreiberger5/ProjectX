#pragma once
#include "Entity.h"
#include <typeinfo>
#include "Scene.h"

class Renderer;
class Texture;
class IRenderable;

class Enemy : public Entity
{
public:
	Enemy(
		const char* _name,
		IRenderable* _pRenderable,
		SDL_Rect _bounds,
		Uint32 _flags = EntityFlags::NONE);
	~Enemy();

	virtual void Render(Renderer* _pRenderer, SDL_Point _offset) override;
	virtual void Update(Uint32 _dt) override;

	virtual void OnCollision(Entity* _other) override;

	bool HasFlag(EntityFlags _flag);
};