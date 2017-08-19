#pragma once

#include "Entity.h"

class Player : public Entity
{

public:
	Player(
		const char* _name,
		IRenderable* _pRenderable,
		SDL_Rect _bounds,
		EntityFlags _flags = EntityFlags::NONE);
	~Player();

	virtual void Update(Uint32 _dt) override;
	virtual void OnCollision(Entity* _other) override;

	SDL_Rect m_allowBounds;
	bool LoseTriggered = false;

};