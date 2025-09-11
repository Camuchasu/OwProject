#include "Enemy.h"
#include "Map.h"
#include"../Base/Base.h"
//移動速度
#define MOVE_SPEED 2.0f

Enemy::Enemy(const CVector2D& pos, bool flip) 
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	
	//当たり判定用矩形設定
	m_rect = CRect(-40, -38, 40, 38);
	//座標
	m_pos_old = m_pos = pos;
	//通常状態へ
	m_state = Run;
	//反転フラグ
	m_flip = flip;
	//着地フラグ
	m_isGround = true;
}

Enemy::~Enemy()
{
}

void Enemy::StateRun()
{
	m_pos.x += MOVE_SPEED;
}

void Enemy::StateDeath()
{
	m_img.ChangeAnimation(eAnimDeath, false);
	if (m_img.CheckAnimationEnd()) {
		m_kill = true;
	}
}

void Enemy::Update()
{
	//移動処理
	m_pos_old = m_pos;
	switch (m_state) {
		//通常状態
	case Run:
		StateRun();
		break;
		//攻撃状態
	case Death:
		StateDeath();
		break;
	}
	//落ちていたら落下中状態へ移行
	if (m_isGround && m_vec.y > GRAVITY * 4)
	{
		m_isGround = false;
	}
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//アニメーション更新
	m_img.UpdateAnimation();
	//m_scroll.x = m_pos.x - 1280 / 2;

}

void Enemy::Draw()
{
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//中心位置設定
	m_img.SetCenter(50, 50);
	m_img.SetSize(100, 100);
	//描画
	m_img.Draw();
	//当たり判定矩形表示
	DrawRect();
}

void Enemy::Collision(Base*b)
{
	switch (b->m_type) {
	case eType_Player:
		if (Base::CollisionRect(this, b))
		{
			//m_state = Death;
			// b->SetKill();
		}
		break;

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

static TexAnim enemyrun[] = {

	{ 0,6 },
	{ 1,6 },
	{ 2,6 },
	{ 3,6 },
	{ 4,6 },
	{ 5,6 },
	{ 6,6 },
	{ 7,6 },
	{ 8,6 },
	{ 9,6 },
	{ 10,6 },
	{ 11,6 },
	
};

static TexAnim enemydeath[] = {

	{ 12,6 },
	{ 13,6 },
	{ 14,6 },
	{ 15,6 },
	{ 16,6 },
};
TexAnimData Enemy_anim_data[] = {
	ANIMDATA(enemyrun),
	ANIMDATA(enemydeath),
};