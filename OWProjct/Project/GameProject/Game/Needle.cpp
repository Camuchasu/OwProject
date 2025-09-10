#include "Needle.h"

Needle::Needle(CVector2D& pos): Base(eType_Needle){
	m_needle = COPY_RESOURCE("Needle", CImage);
	m_rect = CRect(-15, 40, 65, -40);
	m_pos = pos;
}

void Needle::Update()
{

}

void Needle::Draw()
{
	m_needle.SetCenter(25, 50);
	m_needle.SetPos(GetScreenPos(m_pos));
	m_needle.SetSize(80,80);
	m_needle.Draw();
	DrawRect();
}

void Needle::Collision(Base* b)
{

}
