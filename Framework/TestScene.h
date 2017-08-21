#pragma once
#include "Timer.h"
#include "Scene.h"
#include "Projectile.h"
#include "Player.h"

class Player;
class Font;
class Texture;
class Level;
class Projectile;


class TestScene : public Scene
{

public:
	TestScene(System* _pSystem);
	virtual ~TestScene();

	virtual void update(Uint32 _dt) override;
	virtual void load(Renderer* _pRenderer) override;
	virtual void unload() override;

	virtual void LoadLose(bool _lost) override;
	

protected:
	Texture* m_pHello;
	Font* m_pFont;
	Player* m_pFirst;

	Level* m_pSpace1;
	Level* m_pSpace2;
	Texture* pSpace;
	SDL_Rect boundsBack1;
	SDL_Rect boundsBack2;
	SDL_Rect boundsPlayer;

	Projectile* m_pBeamObject;
	Uint32 m_FireDelay;
	Uint32 m_FireWaitingTime;
	Texture* m_pBeam;
	Texture* m_pPlayer;
	SDL_Rect boundsBeam;

	Texture* pKevin;
	Texture* pAndre;
	Texture* pMattis;
	Texture* pPit;

	Timer SpawnKevin;
	Timer SpawnAndre;
	Timer SpawnMattis;
	Timer SpawnPit;
	Timer WinTimer;

	SDL_Rect boundsKevin;
	SDL_Rect boundsAndre;
	SDL_Rect boundsMattis;
	SDL_Rect boundsPit;

	Mix_Chunk* m_pSwing;
	Mix_Chunk* m_pPitEntry;
	Mix_Chunk* m_pSwing2;

	bool BossTriggered = false;
};