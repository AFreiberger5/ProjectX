#include "Level.h"



Level::Level(
	const char* _name,
	IRenderable* _pRenderable,
	SDL_Rect _bounds,
	EntityFlags _flags)
	:Entity (_name, _pRenderable,_bounds, EntityFlags (_flags |EntityFlags::SHOULD_UPDATE))
{
}

Level::~Level()
{
}

void Level::Update(Uint32 _dt)
{
}