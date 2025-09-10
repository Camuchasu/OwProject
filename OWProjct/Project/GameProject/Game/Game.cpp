#include "Game.h"
#include "Title/Title.h"
#include "Map.h"
#include "Enemy.h"
#include "Gimmick.h"
#include "Player.h"
#include "Item.h"

Game::Game()
	: Base(eType_Scene)
{
	Base::Add(new Map());
	Base::Add(new Enemy(CVector2D(1500, 800), true));
	Base::Add(new Gimmick(CVector2D(800, 500)));
	Base::Add(new Player(CVector2D(650, 300), true));
	Base::Add(new Item(CVector2D(800, 500),true));

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
