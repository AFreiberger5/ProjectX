#include "Scene3.h"
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

UIElement* pLabelWinKev;
UIElement* pLabelWin;
UIElement* pLabelQuitWin;
UIElement* pLabelRetryWin;


Scene3::Scene3(System* _pSystem)
	: Scene(_pSystem)
{
}

Scene3::~Scene3()
{
}

void Scene3::update(Uint32 _dt)
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

void Scene3::render(Renderer* _pRenderer)
{
	Scene::render(_pRenderer);
}

void Scene3::load(Renderer* _pRenderer)
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

	Label* pLabelWinKev = new Label(m_pFont, "KEVIN out of COFFEE", col);
	pLabelWinKev->AutoCalcBounds = false;
	pLabelWinKev->m_bounds.x = 50;
	pLabelWinKev->m_bounds.y = 0;
	pLabelWinKev->m_bounds.w = 700;
	pLabelWinKev->m_bounds.h = 200;


	Label* pLabelWin = new Label(m_pFont, "YOU WIN!", col);
	pLabelWin->AutoCalcBounds = false;
	pLabelWin->m_bounds.x = 200;
	pLabelWin->m_bounds.y = 200;
	pLabelWin->m_bounds.w = 400;
	pLabelWin->m_bounds.h = 100;

	Label* pLabelRetryWin = new Label(m_pFont, "Press [Enter] to Retry", col2);
	pLabelRetryWin->AutoCalcBounds = false;
	pLabelRetryWin->m_bounds.x = 100;
	pLabelRetryWin->m_bounds.y = 300;
	pLabelRetryWin->m_bounds.w = 600;
	pLabelRetryWin->m_bounds.h = 100;

	Label* pLabelQuitWin = new Label(m_pFont, "Press [ESC] to Quit", col2);
	pLabelQuitWin->AutoCalcBounds = false;
	pLabelQuitWin->m_bounds.x = 100;
	pLabelQuitWin->m_bounds.y = 400;
	pLabelQuitWin->m_bounds.w = 600;
	pLabelQuitWin->m_bounds.h = 100;


	m_pUI->Add(pLabelWin);
	m_pUI->Add(pLabelRetryWin);
	m_pUI->Add(pLabelQuitWin);
	m_pUI->Add(pLabelWinKev);

}

void Scene3::unload()
{
	SAFE_DELETE(m_pSpace1);
	SAFE_DELETE(m_pSpace2);
	SAFE_DELETE(m_pUI);
	SAFE_DELETE(m_pFont);
}
