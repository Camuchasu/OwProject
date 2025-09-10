#include "GameOver.h"

GameOver::GameOver() :Base(eType_GameOver) {

}

void GameOver::Update()
{
	if (PUSH(CInput::eButton5)) {
		KillAll();
		new Game();
	}
}

void GameOver::Draw()
{

}
