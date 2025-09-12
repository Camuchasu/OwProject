#include "UI.h"

UI::UI(CVector2D& pos)
	:Base(eType_UI)
	, m_UI_text("C:\\Windows\\Fonts\\msgothic.ttc", 30)
{
	m_UI1 = COPY_RESOURCE("UI1", CImage);
	m_UI2 = COPY_RESOURCE("UI2", CImage);
	m_UI3 = COPY_RESOURCE("UI3", CImage);
	m_UI4 = COPY_RESOURCE("UI4", CImage);
	m_UI5 = COPY_RESOURCE("UI5", CImage);
	m_UI6 = COPY_RESOURCE("UI5", CImage);
	m_UI7 = COPY_RESOURCE("UI5", CImage);
	m_pos = pos;
}

void UI::Update()
{
}

void UI::Draw()
{
	m_UI1.SetPos(GetScreenPos(CVector2D(m_pos.x + 160, 1080 / 2 - 50)));
	m_UI1.SetSize(100, 100);
	m_UI1.Draw();

	m_UI2.SetPos(GetScreenPos(CVector2D(m_pos.x + 140, 1080 / 2 + 50)));
	m_UI2.SetSize(100, 100);
	m_UI2.Draw();

	m_UI3.SetPos(GetScreenPos(CVector2D(m_pos.x + 340, 1080 / 2 + 50)));
	m_UI3.SetSize(100, 100);
	m_UI3.Draw();

	m_UI4.SetPos(GetScreenPos(CVector2D(m_pos.x + 330, 1080 / 2 - 50)));
	m_UI4.SetSize(100, 100);
	m_UI4.Draw();

	m_UI5.SetPos(GetScreenPos(CVector2D(m_pos.x + 260, 750)));
	m_UI5.SetSize(100, 150);
	m_UI5.Draw();

	m_UI6.SetPos(GetScreenPos(CVector2D(m_pos.x + 1750, 750)));
	m_UI6.SetSize(100, 150);
	m_UI6.Draw();

	/*m_UI7.SetPos(GetScreenPos(CVector2D(m_pos.x + 330, 1080 / 2 - 50)));
	m_UI7.SetSize(100, 100);
	m_UI7.Draw();*/
	m_UI_text.Draw(2500, 200, 1.0f, 1.0f, 1.0f, "Ç±Ç±Ç…óßÇøé~Ç‹ÇÍÅIÅI");
}
