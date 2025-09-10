#pragma once
#include "Base/Base.h"

class Gimmick :public Base
{
private:
	enum
	{
		eStateIdle,
		eStateBrink,
	};
	CImage m_spaik;
	bool m_isGround;
	bool flag;
	int m_state;
	void StateIdle();
	void StateBrink();
public:
	Gimmick(CVector2D &pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
extern TexAnimData Gimmick_anim_data[];