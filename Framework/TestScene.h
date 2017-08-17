#pragma once

#include "Scene.h"

class Font;
class Texture;
class Level;

class TestScene : public Scene
{

public:
	TestScene(System* _pSystem);
	virtual ~TestScene();

	virtual void update(Uint32 _dt) override;
	virtual void render(Renderer* _pRenderer) override;

	virtual void load(Renderer* _pRenderer) override;
	virtual void unload() override;

protected:
	Font* m_pFont;
	Level* m_pSpace1;
	Level*  m_pSpace2;
};