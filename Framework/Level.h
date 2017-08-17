#pragma once

#include "Entity.h"

#pragma region A.Blomenlamp

class Level : public Entity
{

public:
	Level(
		const char* _name,
		IRenderable* _pRenderable,
		SDL_Rect _bounds,
		EntityFlags _flags = EntityFlags::NONE);
	~Level();

	virtual void Update(Uint32 _dt) override;
	SDL_Rect m_allowBounds;

//const char* m_name;
//EntityFlags m_flags;
//IRenderable* m_pRenderable;
//SDL_Rect m_bounds;
};

#pragma endregion