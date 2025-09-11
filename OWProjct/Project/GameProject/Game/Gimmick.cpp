#include "Gimmick.h"
#include "Player.h"
#include "Map.h"

#define MOVE_SPEED 0.5

Gimmick::Gimmick(CVector2D &pos)
	:Base(eType_Gimmick)
	,m_isGround(false)
	//,flag(true)
{
	m_spaik = COPY_RESOURCE("NeedleDossin", CImage);
	//再生アニメーション設定
	m_spaik.ChangeAnimation(0);
	//当たり判定用矩形設定
	m_rect = CRect(-15, 40, 65, -40);
	m_pos = pos;
	m_state = eStateIdle;
}



void Gimmick::StateIdle()
{
	Base* player = Base::FindObject(eType_Player);
	if (player)
	{

		CVector2D v = player->m_pos - m_pos;
		if (abs(v.x) < 70)
		{
			if (abs(v.y) < 1000)
			{
				m_vec.y += GRAVITY * 6;

			}
		}
	}
}

void Gimmick::StateBrink()
{
	if (m_pos.y <= 300)
	{
		//flag = true;
	}
	else {
		m_pos -= m_vec;
	}
	
}

void Gimmick::Update()
{
	m_pos_old = m_pos;
	switch (m_state) {
		//通常状態
	case eStateIdle:
		StateIdle();
		break;
	case eStateBrink:
		StateBrink();
		break;
		}
		//if (m_isGround == true)
		//{
		//	m_state = eStateBrink;
		//}
		//落ちていたら落下中状態へ移行
		//if (m_isGround && m_vec.y > GRAVITY * 4 && flag==true)
		if (m_isGround && m_vec.y > GRAVITY * 4)
		{
			m_isGround = false;
			
		}
		m_pos += m_vec;

		//アニメーション更新
		m_spaik.UpdateAnimation();
	}


void Gimmick::Draw()
{
	m_spaik.SetCenter(25, 50);
	m_spaik.SetPos(GetScreenPos(m_pos));
	m_spaik.SetSize(100, 100);
	m_spaik.Draw();
	DrawRect();
}

void Gimmick::Collision(Base* b)
{
	switch (b->m_type) {

	case eType_Map:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t;
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
				//flag = false;
			}
		}
	}
}
static TexAnim gimmickidle[] = {

	{ 0,6 },
	
};

static TexAnim gimmicklefthit[] = {

	{ 4,6 },
	{ 5,6 },
	{ 6,6 },
	{ 7,6 },
};
static TexAnim gimmickrighthit[] = {

	
	{ 8,6 },
	{ 9,6 },
	{ 10,6 },
	{ 11,6 },
};
static TexAnim gimmicktophit[] = {

	{ 12,6 },
	{ 13,6 },
	{ 14,6 },
	{ 15,6 },
};
static TexAnim gimmickbottomhit[] = {

	{ 16,6 },
	{ 17,6 },
	{ 18,6 },
	{ 19,6 },
};
static TexAnim gimmickbrink[] = {

	{ 20,6 },
	{ 21,6 },
	{ 22,6 },
	{ 23,6 },
};
TexAnimData Gimmick_anim_data[] = {
	ANIMDATA(gimmickidle),
	ANIMDATA(gimmicklefthit),
	ANIMDATA(gimmickrighthit),
	ANIMDATA(gimmicktophit),
	ANIMDATA(gimmickbottomhit),
	ANIMDATA(gimmickbrink),
};
