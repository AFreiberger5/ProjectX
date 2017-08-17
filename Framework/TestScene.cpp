#include "TestScene.h"
#include "System.h"
#include "Entity.h"
#include "Player.h"
#include "Font.h"
#include "Texture.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Animation.h"
#include "UI.h"
#include "Level.h"
#define CREATE_SPRITE_FROM_SHEET(SHEET, X, Y, W, H) new Sprite(SHEET, X * W, Y * H, W, H)

TestScene::TestScene(System* _pSystem)
	: Scene(_pSystem)
{
}

TestScene::~TestScene()
{
}

void TestScene::update(Uint32 _dt)
{
	m_pSpace1->GetBounds().y += _dt / 4;
	m_pSpace2->GetBounds().y += _dt / 4;

	if (m_pSpace1->GetBounds().y >= 600) {
		m_pSpace1->GetBounds().y = m_pSpace2->GetBounds().y - 1024;
	}

	if (m_pSpace2->GetBounds().y >= 600) {
		m_pSpace2->GetBounds().y = m_pSpace1->GetBounds().y - 1024;
	}

	Scene::update(_dt);
}

void TestScene::render(Renderer* _pRenderer)
{
	Scene::render(_pRenderer);
}

void TestScene::load(Renderer* _pRenderer)
{
	m_pFont = new Font(getAssetPath("Fonts/comic.ttf").c_str(), 12);

#pragma region A.BLomenkamp
	Texture* pSpace = new Texture(_pRenderer, getAssetPath("Images/Space1.png").c_str());


	SDL_Rect boundsBack1;
	boundsBack1.w = 800;
	boundsBack1.h = 1024;
	boundsBack1.x = 0;
	boundsBack1.y = -424;

	SDL_Rect boundsBack2;
	boundsBack2.w = 800;
	boundsBack2.h = 1024;
	boundsBack2.x = 0;
	boundsBack2.y = -1448;

	

	AddEntity(m_pSpace1 = new Level("BackG1", pSpace, boundsBack1));
	AddEntity(m_pSpace2 = new Level("BackG1", pSpace, boundsBack2));


#pragma endregion
		
		m_pUI = new UI();

	SDL_Color col;
	col.a = 255;
	col.r = 255;
	col.g = 255;
	col.b = 255;
	Label* pLabel = new Label(m_pFont, "Hello World", col);
	pLabel->m_bounds.x = 5;
	pLabel->m_bounds.y = 15;

	m_pUI->Add(pLabel);
}

void TestScene::unload()
{
	SAFE_DELETE(m_pSpace1);

	SAFE_DELETE(m_pSpace2);

	SAFE_DELETE(m_pFont);
}
