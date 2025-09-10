#include "Game.h"
#include "Title/Title.h"
Game::Game()
	: Base(eType_Scene)
{
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
