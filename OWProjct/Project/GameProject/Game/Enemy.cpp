#include "Enemy.h"

Enemy::Enemy(const CVector2D& pos, bool flip) :Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_pos = pos;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	m_img.Draw();
}

void Enemy::Collision(Base*b)
{
}
