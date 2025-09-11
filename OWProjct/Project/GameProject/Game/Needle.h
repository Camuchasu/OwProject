#pragma once
#include "Base/Base.h"

class Needle :public Base 
{
	
private:
	CImage m_needle;
	bool m_isGround;
	bool flag;
	bool m_isFly;
	int m_type;
public:
	Needle(CVector2D& pos,int type);
	void Update();
	void Draw();
	void Collision(Base* b);
};