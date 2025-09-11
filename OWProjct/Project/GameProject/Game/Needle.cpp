#include "Needle.h"
#include "Player.h"

Needle::Needle(CVector2D& pos,int type): Base(eType_Needle){
	m_needle = COPY_RESOURCE("Needle", CImage);
	m_rect = CRect(-21, 0, 23, -21);
	m_pos = pos;
}

void Needle::Update()
{
	Base* player = Base::FindObject(eType_Player);
	if (player && m_isFly)
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
	//DrawRect();
}

void Needle::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (Player* p = dynamic_cast<Player*>(Base::FindObject(eType_Player)))
		{
			if (Base::CollisionRect(this, b))
			{
				if (m_type == 1) {
					m_isFly = true;
				}
				if (m_type == 0)return;
			}
			break;
		}
	}
}
