#include"Title.h"
#include"Game/Game.h"

Title::Title() : Base(eType_Scene)
{
	m_title = COPY_RESOURCE("Title", CImage);
	m_Logo = COPY_RESOURCE("Logo", CImage);
	m_haikei = COPY_RESOURCE("Haikei", CImage);
	m_start = COPY_RESOURCE("Title", CImage);
	m_start = COPY_RESOURCE("Logo", CImage);
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
	SOUND("Kyoku")->Play();
}

void Title::Draw()
{
	switch (m_fontstate) {
	case 0:
		//if (PUSH(CInput::eButton1))
		m_fontstate++;
		break;
	case 1:
		//ƒÆ‰ÁZ
		m_alpha += 0.05f;
		if (m_alpha > DtoR(180)) {
			m_alpha = 0;
		}
		break;
	}
	//’Êí‚ÌƒƒS‚Ì•`‰æ
	m_start.SetSize(450, 96);
	m_start.SetPos(750, 700);

	m_start.SetColor(1, 1, 1, 1);
	m_start.Draw();

	//d‚Ë‚Ä•`‰æ

	//sinƒJ[ƒu
	m_start.SetColor(1, 1, 1, sin(m_alpha));
	

	m_haikei.Draw();
	m_title.Draw();
	m_Logo.Draw();
	m_start.Draw();
	
}