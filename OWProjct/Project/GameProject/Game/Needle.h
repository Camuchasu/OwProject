#pragma once
#include "Base/Base.h"

class Needle :public Base 
{
	
private:
	CImage m_needle;
	bool m_isGround;
	bool flag;
	int m_type;
public:
	struct TypeNeedle
	{
		enum
		{
			eNeedle,
			eFoolNeedle,
		};
		std::string name;
		int type;
		std::string name1;
		std::string name2;
	};
	static std::vector<TypeNeedle> Needles;
	Needle(CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};