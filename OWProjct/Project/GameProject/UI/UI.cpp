#include "UI.h"

UI::UI(CVector2D& pos)
	:Base(eType_UI)
{
	m_UI1 = COPY_RESOURCE("UI1", CImage);
	m_UI2 = COPY_RESOURCE("UI2", CImage);
	m_UI3 = COPY_RESOURCE("UI3", CImage);
	m_UI4 = COPY_RESOURCE("UI4", CImage);
	m_pos = pos;
}

void UI::Update()
{
}

void UI::Draw()
{
	m_UI1.SetPos(GetScreenPos(CVector2D(m_pos.x + 110, 1080 / 2 - 50)));
	m_UI1.SetSize(100, 100);
	m_UI1.Draw();

	m_UI2.SetPos(GetScreenPos(CVector2D(m_pos.x + 110, 1080 / 2 + 50)));
	m_UI2.SetSize(100, 100);
	m_UI2.Draw();

	m_UI3.SetPos(GetScreenPos(CVector2D(m_pos.x + 300, 1080 / 2 - 50)));
	m_UI3.SetSize(100, 100);
	m_UI3.Draw();

	m_UI4.SetPos(GetScreenPos(CVector2D(m_pos.x + 300, 1080 / 2 + 50)));
	m_UI4.SetSize(100, 100);
	m_UI4.Draw();
}
