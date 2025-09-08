#pragma once
#include "Base/Base.h"
class  Enemy : public Base
{
public:
	CImage m_img;
private:
	Enemy(const CVector2D& pos);
	~Enemy();
	void Update();
	void Draw();
	void Collision();
};
