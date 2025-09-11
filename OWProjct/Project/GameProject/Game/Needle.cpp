#include "Needle.h"

Needle::Needle(CVector2D& pos): Base(eType_Needle){
	m_needle = COPY_RESOURCE("Needle", CImage);
	m_needle2 = COPY_RESOURCE("Needle", CImage);
	m_rect = CRect(-21, 0, 23, -21);
	m_pos = pos;
}

void Needle::Update()
{
	Base* player = Base::FindObject(eType_Player);
	if (player)
	{

		CVector2D v = player->m_pos - m_pos;
		if (abs(v.x) < 70)
		{
			if (abs(v.y) < 1000)
			{
				m_vec.y -= GRAVITY * 6;

			}
		}
	}
}

void Needle::Draw()
{
	m_needle.SetCenter(25, 50);
	m_needle.SetPos(GetScreenPos(m_pos));
	m_needle.SetSize(50,50);
	m_needle.Draw();
	m_needle2.SetCenter(25, 50);
	m_needle2.SetPos(GetScreenPos(m_pos)*1.5);
	m_needle2.SetSize(50, 50);
	m_needle2.Draw();
	DrawRect();
}

void Needle::Collision(Base* b)
{

}
