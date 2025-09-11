#pragma once
#include "Base/Base.h"

class Needle :public Base 
{
	
private:
	CImage m_needle;
	bool m_isGround;
	bool flag;
public:
	struct TypeNeedle
	{
		enum
		{
			eNeedle,
			eFoolNeedle,
		};
		
	};
	Needle(CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};