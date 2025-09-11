#include "Item.h"
#include "Map.h"

#define MOVE_SPEED 2
Item::Item(CVector2D& pos, bool flip)
	:Base(eType_Item)
{
	SOUND("LevelUp")->Play();
	m_mush = COPY_RESOURCE("Mushroom", CImage);
	m_pos = pos;
	m_rect = CRect(-40, -80, 40, -10);
	//着地フラグ
	m_isGround = true;
}

void Item::Update()
{
	//移動処理
	m_pos_old = m_pos;
	m_pos.x += MOVE_SPEED;
	//落ちていたら落下中状態へ移行
	if (m_isGround && m_vec.y > GRAVITY * 4)
	{
		m_isGround = false;
	}
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;
}

void Item::Draw()
{
	m_mush.SetCenter(50, 100);
	m_mush.SetSize(100,100);
	m_mush.SetPos(GetScreenPos(m_pos));
	m_mush.Draw();
	//DrawRect();
}

void Item::Collision(Base* b)
{
	switch (b->m_type) {
	/*case eType_Player:
		if (CollisionRect(this, b))
		{
			b->SetKill();
		}*/

	case eType_Map:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = 0;
			t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_isGround = true;
			}
		}
		break;
	}
}
