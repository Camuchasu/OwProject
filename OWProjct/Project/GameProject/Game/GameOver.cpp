#include "GameOver.h"
#include "Game.h"
GameOver::GameOver() :Base(eType_GameOver) 
{
	m_img = COPY_RESOURCE("GameOver", CImage);
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
	m_img.SetPos(1920 / 2, 1080/ 2);
	m_img.Draw();
}
