#include "Enemy.h"



Enemy::Enemy(const CVector2D& pos, bool flip) :Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//中心位置設定
	m_img.SetCenter(50, 100);
	m_img.SetSize(100, 100);
	m_pos = pos;
}

Enemy::~Enemy()
{
}

void Enemy::StateRun()
{
	//移動量
	const float move_speed = 5;
}

void Enemy::StateDeath()
{
}

void Enemy::Update()
{
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
		m_isGround = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//アニメーション更新
	m_img.UpdateAnimation();
	//m_scroll.x = m_pos.x - 1280 / 2;

}

void Enemy::Draw()
{
	m_img.SetPos(1920 / 2, 1080 / 2);
	m_img.Draw();
}

void Enemy::Collision(Base*b)
{
}

static TexAnim enemyrun[] = {

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
	{ 12,6 },
};

static TexAnim enemydeath[] = {

	{ 1,6 },
	{ 2,6 },
	{ 3,6 },
	{ 4,6 },
	{ 5,6 },
	{ 6,6 },
	{ 7,6 },
	{ 8,6 },
	{ 9,6 },
};
TexAnimData Enemy_anim_data[] = {
	ANIMDATA(enemyrun),
	ANIMDATA(enemydeath),
};