#include"Title.h"

Title::Title() : Base(eType_Scene)
{
	m_title = COPY_RESOURCE("Title", CImage);
	m_Logo = COPY_RESOURCE("Logo", CImage);
	m_title.SetSize(100, 100);
	m_title.SetPos(800, 500);
	m_Logo.SetSize(100, 100);
	m_Logo.SetPos(800, 800);
	m_cnt = 0;
}

void Title::Update() 
{
	if (m_cnt++ > 2 && PUSH(CInput::eButton1)) 
	{
		Base::KillAll();
	}
}

void Title::Draw() 
{
	m_title.Draw();
	m_Logo.Draw();
}