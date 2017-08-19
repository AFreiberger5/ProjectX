#pragma once
#include "Timer.h"
#include "Scene.h"

class Font;
class System;

class Scene1 : public Scene
{

public:
	Scene1(System* _pSystem);
	virtual ~Scene1();

	virtual void update(Uint32 _dt) override;
	virtual void render(Renderer* _pRenderer) override;

	virtual void load(Renderer* _pRenderer) override;
	virtual void unload() override;

protected:
	Font* m_pFont;

};