#pragma once
#include "Base/Base.h"

class Needle :public Base 
{
private:
	CImage m_needle;
	CImage m_needle2;
	bool m_isGround;
	bool flag;
public:
	Needle(CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};