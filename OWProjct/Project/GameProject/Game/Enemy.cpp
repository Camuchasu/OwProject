#include "Enemy.h"



Enemy::Enemy(const CVector2D& pos, bool flip) :Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���S�ʒu�ݒ�
	m_img.SetCenter(50, 100);
	m_img.SetSize(100, 100);
	m_pos = pos;
}

Enemy::~Enemy()
{
}

void Enemy::StateRun()
{
	//�ړ���
	const float move_speed = 5;
}

void Enemy::StateDeath()
{
}

void Enemy::Update()
{
	m_pos_old = m_pos;
	switch (m_state) {
		//�ʏ���
	case Run:
		StateRun();
		break;
		//�U�����
	case Death:
		StateDeath();
		break;
	}
	//�����Ă����痎������Ԃֈڍs
	if (m_isGround && m_vec.y > GRAVITY * 4)
		m_isGround = false;
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//�A�j���[�V�����X�V
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