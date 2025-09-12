#include "Game.h"
#include "Title/Title.h"
#include "Map.h"
#include "Enemy.h"
#include "Gimmick.h"
#include "Player.h"
#include "Item.h"
#include "Needle.h"
#include "Brock.h"
#include "PitFall.h"
#include "Goal/Goal.h"
#include "UI/UI.h"

Game::Game()
	: Base(eType_Scene)
{
	Base::Add(new Map());
	Base::Add(new Enemy(CVector2D(1900, 800), true));
	Base::Add(new Gimmick(CVector2D(1300, -80)));
	Base::Add(new Needle(CVector2D(4750, 900),0));
	Base::Add(new Needle(CVector2D(4800, 900),0));
	Base::Add(new Needle(CVector2D(4850, 900),0));
	Base::Add(new Needle(CVector2D(4900, 900),0));
	Base::Add(new Needle(CVector2D(5050, 900),1));
	Base::Add(new Needle(CVector2D(5100, 900),1));
	Base::Add(new Player(CVector2D(300, 900), true));
	Base::Add(new Item(CVector2D(2300, -80), true));
	//Base::Add(new Brock(CVector2D(2100, 800)));
	Base::Add(new PitFall(CVector2D(2700, 900)));
	Base::Add(new PitFall(CVector2D(2700, 1050)));
	Base::Add(new PitFall(CVector2D(5500, 900)));
	Base::Add(new PitFall(CVector2D(5500, 1050)));
	Base::Add(new UI(CVector2D(500, 440)));
	Base::Add(new UI(CVector2D(500, 460)));
	Base::Add(new UI(CVector2D(500, 440)));
	Base::Add(new UI(CVector2D(500, 460)));
	Base::Add(new Goal(CVector2D(3500, 810), 1));
	Base::Add(new Goal(CVector2D(5600, 810), 0));

	m_gamestate = 0;
}

Game::~Game()
{
}

void Game::Update()
{
	switch (m_gamestate) {
	case 0:
		break;
	case 1:

		break;
	case 2:
		if (PUSH(CInput::eButton1)) {
			//すべてのオブジェクトを破壊
			Base::KillAll();
			//タイトルシーンへ
			Base::Add(new Title());
		}
		break;
	}
}
