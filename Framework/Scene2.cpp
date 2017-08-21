#include "Scene2.h"
#include "TestScene.h"
#include "Scene1.h"
#include "System.h"
#include "Entity.h"
#include "Font.h"
#include "Texture.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Animation.h"
#include "UI.h"
#include "Level.h"
#define CREATE_SPRITE_FROM_SHEET(SHEET, X, Y, W, H) new Sprite(SHEET, X * W, Y * H, W, H)
#include <iostream>

UIElement* pLabelLoose;
UIElement* pLabelRetry;
UIElement* pLabelQuit;




Scene2::Scene2(System* _pSystem)
	: Scene(_pSystem)
{

}

Scene2::~Scene2()
{

}

void Scene2::update(Uint32 _dt)
{

#pragma region Backgroundmovement
	m_pSpace1->GetBounds().y += _dt / 4;
	m_pSpace2->GetBounds().y += _dt / 4;

	if (m_pSpace1->GetBounds().y >= 600) {
		m_pSpace1->GetBounds().y = m_pSpace2->GetBounds().y - 1024;
	}

	if (m_pSpace2->GetBounds().y >= 600) {
		m_pSpace2->GetBounds().y = m_pSpace1->GetBounds().y - 1024;
	}
#pragma endregion

#pragma region Controlls
	Scene::update(_dt);

	if (m_pSystem->IsKeyPressed(Key::RETURN))
	{
		TestScene* _x = new TestScene(m_pSystem);
		m_pSystem->changeScene(_x);

	}

	if (m_pSystem->IsKeyPressed(Key::ESC))
	{
		m_pSystem->clean();
	}

#pragma endregion
}

void Scene2::render(Renderer* _pRenderer)
{
	Scene::render(_pRenderer);
}

void Scene2::load(Renderer* _pRenderer)
{
	m_pFont = new Font(getAssetPath("Fonts/comic.ttf").c_str(), 16);

#pragma region LevelSection
	Texture* pSpace = new Texture(_pRenderer, getAssetPath("Images/space.png").c_str());
	
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
	col.g = 0;
	col.b = 0;

	SDL_Color col2;
	col2.a = 255;
	col2.r = 255;
	col2.g = 255;
	col2.b = 0;

	Label* pLabelLoose = new Label(m_pFont, "GAME OVER", col);
	pLabelLoose->AutoCalcBounds = false;
	pLabelLoose->m_bounds.x = 200;
	pLabelLoose->m_bounds.y = 0;
	pLabelLoose->m_bounds.w = 400;
	pLabelLoose->m_bounds.h = 300;

	Label* pLabelRetry = new Label(m_pFont, "Press [Enter] to Retry", col2);
	pLabelRetry->AutoCalcBounds = false;
	pLabelRetry->m_bounds.x = 100;
	pLabelRetry->m_bounds.y = 300;
	pLabelRetry->m_bounds.w = 600;
	pLabelRetry->m_bounds.h = 100;

	Label* pLabelQuit = new Label(m_pFont, "Press [ESC] to Quit", col2);
	pLabelQuit->AutoCalcBounds = false;
	pLabelQuit->m_bounds.x = 100;
	pLabelQuit->m_bounds.y = 400;
	pLabelQuit->m_bounds.w = 600;
	pLabelQuit->m_bounds.h = 100;


	m_pUI->Add(pLabelLoose);
	m_pUI->Add(pLabelRetry);
	m_pUI->Add(pLabelQuit);

}

void Scene2::unload()
{
	SAFE_DELETE(m_pSpace1);
	SAFE_DELETE(m_pSpace2);
	SAFE_DELETE(m_pUI);
	SAFE_DELETE(m_pFont);
}
