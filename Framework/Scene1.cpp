#include "Scene2.h"
#include "TestScene.h"
#include "Scene1.h"
#include "System.h"
#include "Entity.h"
#include "Font.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Animation.h"
#include "UI.h"
#include "Level.h"
#define CREATE_SPRITE_FROM_SHEET(SHEET, X, Y, W, H) new Sprite(SHEET, X * W, Y * H, W, H)

UIElement* pLabelProjectX;
UIElement* pLabelStart;
UIElement* pLabelQuit1;




Scene1::Scene1(System* _pSystem)
	: Scene(_pSystem)
{

}

Scene1::~Scene1()
{

}

void Scene1::update(Uint32 _dt)
{




#pragma region Controlls

	if (m_pSystem->IsKeyPressed(Key::RETURN))
	{
		TestScene* _x =new  TestScene(m_pSystem);
		m_pSystem->m_pScene = _x;
		m_pSystem->changeScene(_x);
		//Old Scene still needs to be deleted
	}

	if (m_pSystem->IsKeyPressed(Key::ESC))
	{
		m_pSystem->clean();
		
		
	}

#pragma endregion
	Scene::update(_dt);
}

void Scene1::render(Renderer* _pRenderer)
{
	Scene::render(_pRenderer);


}

void Scene1::load(Renderer* _pRenderer)
{
	m_pFont = new Font(getAssetPath("Fonts/comic.ttf").c_str(), 16);






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

	Label* pLabelProjectX = new Label(m_pFont, "PROJECT X", col);
	pLabelProjectX->AutoCalcBounds = false;
	pLabelProjectX->m_bounds.x = 200;
	pLabelProjectX->m_bounds.y = 0;
	pLabelProjectX->m_bounds.w = 400;
	pLabelProjectX->m_bounds.h = 300;

	Label* pLabelStart = new Label(m_pFont, "Press [Enter] to Start", col2);
	pLabelStart->AutoCalcBounds = false;
	pLabelStart->m_bounds.x = 100;
	pLabelStart->m_bounds.y = 300;
	pLabelStart->m_bounds.w = 600;
	pLabelStart->m_bounds.h = 100;

	Label* pLabelQuit1 = new Label(m_pFont, "Press [ESC] to Quit", col2);
	pLabelQuit1->AutoCalcBounds = false;
	pLabelQuit1->m_bounds.x = 100;
	pLabelQuit1->m_bounds.y = 400;
	pLabelQuit1->m_bounds.w = 600;
	pLabelQuit1->m_bounds.h = 100;


	m_pUI->Add(pLabelProjectX);
	m_pUI->Add(pLabelStart);
	m_pUI->Add(pLabelQuit1);

}

void Scene1::unload()
{
	EntityList toRemove = m_entitiesToRender;
	for each (Entity* pEntity in toRemove)
	{
		RemoveEntity(pEntity);
		delete pEntity;
	}

	SAFE_DELETE(m_pFont);
}
