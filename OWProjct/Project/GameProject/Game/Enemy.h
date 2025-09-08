#pragma once
#include "Base/Base.h"
class Enemy : public Base
{
public:
	
	Enemy(const CVector2D& pos, bool flip);
	~Enemy();
	void Update()override;
	void Draw()override;
	void Collision(Base* b);
private:
	CImage m_img;
};
