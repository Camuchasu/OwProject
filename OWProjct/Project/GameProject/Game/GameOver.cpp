#include "GameOver.h"
#include "Game.h"
#include "Title/Title.h"
GameOver::GameOver(CVector2D& pos) :Base(eType_GameOver)
{
	m_img = COPY_RESOURCE("GameOver", CImage);
	m_pos_old = m_pos = pos;
	SOUND("GameOver")->Play();
}

void GameOver::Update()
{
	if (PUSH(CInput::eButton5) || PUSH(CInput::eButton6)) {
		//���ׂẴI�u�W�F�N�g��j��
		Base::KillAll();

		Base::Add(new Game());
		////�^�C�g���V�[����
		//Base::Add(new Title());
	}
}

void GameOver::Draw()
{
	//m_img.SetCenter(50, 100);
	//m_img.SetSize(100, 100);
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
