#include "Goal.h"
#include "Title/Title.h"
#include "Game/Player.h"

Goal::Goal(const CVector2D& pos,int type)
:Base(eType_Goal)
{
	m_img = COPY_RESOURCE("Goal", CImage);
	m_pos = pos;
	m_type = type;
	m_rect = CRect(0, 0, 100, 100);
}

void Goal::Update()
{
}

void Goal::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetSize(100, 100);
	m_img.Draw();
	//DrawRect();
}

void Goal::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (Player* p = dynamic_cast<Player*>(Base::FindObject(eType_Player)))
		{
			if (Base::CollisionRect(this, b))
			{
				if (m_type == 1) {
					p->m_kills = true;
					SetKill();
				}
				if (m_type == 0)
				{
					Base::Add(new Title());
				}
			}
			break;
		}
	}
}
