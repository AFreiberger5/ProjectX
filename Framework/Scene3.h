#pragma once
#include "Timer.h"
#include "Scene.h"
#include "Projectile.h"

class Font;
class Level;
class System;

class Scene3 : public Scene
{

public:
	Scene3(System* _pSystem);
	virtual ~Scene3();

	virtual void update(Uint32 _dt) override;
	virtual void render(Renderer* _pRenderer) override;

	virtual void load(Renderer* _pRenderer) override;
	virtual void unload() override;

protected:
	Font* m_pFont;
	Level* m_pSpace1;
	Level* m_pSpace2;
	SDL_Rect boundsBack1;
	SDL_Rect boundsBack2;



};