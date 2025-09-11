#include "Brock.h"

Brock::Brock(CVector2D& pos)
	:Base(eType_Brock)
{
	m_brock = COPY_RESOURCE("Brock", CImage);
	m_rect = CRect(-21, 0, 23, -21);
	m_pos = pos;
}

void Brock::Update()
{

}

void Brock::Draw()
{
	m_brock.SetCenter(25, 50);
	m_brock.SetPos(GetScreenPos(m_pos));
	m_brock.SetSize(50, 50);
	m_brock.Draw();
	DrawRect();
}

void Brock::Collision()
{

}
