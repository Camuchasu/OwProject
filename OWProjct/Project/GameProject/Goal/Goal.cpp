#include "Goal.h"
#include "Title/Title.h"
#include "Game/Player.h"
#include "Game/Enemy.h"
#include"Goal/Clear.h"
Goal::Goal(const CVector2D& pos,int type)
:Base(eType_Goal)
{
	SOUND("GoalSound")->Play();
	m_img = COPY_RESOURCE("Goal", CImage);
	m_pos = pos;
	m_type = type;
	m_rect = CRect(0, 0, 80, 80);
}

void Goal::Update()
{
}

void Goal::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetSize(100, 100);
	m_img.Draw();
	DrawRect();
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
					Base::Add(new Clear());
				}
			}
			break;
		}
	case eType_Enemy:
		if (Enemy* e = dynamic_cast<Enemy*>(Base::FindObject(eType_Enemy)))
		{
			if (Base::CollisionRect(this, b) && m_type == 0)
			{
				SetKill();
			}
			break;
		}
	}
}
