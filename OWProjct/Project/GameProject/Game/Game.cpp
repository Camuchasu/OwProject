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
			//���ׂẴI�u�W�F�N�g��j��
			Base::KillAll();
			//�^�C�g���V�[����
			Base::Add(new Title());
		}
		break;
	}
}
