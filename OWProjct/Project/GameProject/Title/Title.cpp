#include"Title.h"
#include"Game/Game.h"

Title::Title() : Base(eType_Scene)
{
	m_title = COPY_RESOURCE("Title", CImage);
	m_Logo = COPY_RESOURCE("Logo", CImage);
	m_haikei = COPY_RESOURCE("Haikei", CImage);
	m_title.SetSize(450, 200);
	m_title.SetPos(700, 200);
	m_Logo.SetSize(800, 120);
	m_Logo.SetPos(550, 800);
	m_haikei.SetSize(1920, 1080);
	m_haikei.SetPos(0, 0);
	m_cnt = 0;
}

void Title::Update()
{
	if (m_cnt++ > 2 && PUSH(CInput::eButton5))
	{
		Base::KillAll();
		Base::Add(new Game());
	}
}

void Title::Draw()
{
	m_haikei.Draw();
	m_title.Draw();
	m_Logo.Draw();
}