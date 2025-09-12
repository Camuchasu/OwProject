#include "GameOver.h"
#include "Game.h"
#include "Title/Title.h"
GameOver::GameOver(CVector2D& pos) :Base(eType_GameOver)
{
	m_img = COPY_RESOURCE("GameOver", CImage);
	m_suppl = COPY_RESOURCE("Sl", CImage);
	m_pos_old = m_pos = pos;
	SOUND("GameOver")->Play();
}

void GameOver::Update()
{
	if (PUSH(CInput::eButton5) || PUSH(CInput::eButton6)) {
		//すべてのオブジェクトを破壊
		Base::KillAll();

		Base::Add(new Game());
		////タイトルシーンへ
		//Base::Add(new Title());
	}
}

void GameOver::Draw()
{
	//m_img.SetCenter(50, 100);
	//m_img.SetSize(100, 100);
	m_img.SetPos(GetScreenPos(CVector2D(m_pos.x + 50,m_pos.y)));
	m_img.Draw();
	m_suppl.SetPos(GetScreenPos(CVector2D(m_pos.x + 80,m_pos.y +110)));
	m_suppl.Draw();
}
