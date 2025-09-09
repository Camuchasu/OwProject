#pragma once
#include "Base/Base.h"

class Gimmick :public Base
{
private:
	CImage m_spaik;
public:
	Gimmick(CVector2D &pos);
	void Update();
	void Draw();
	void Collision();
};
extern TexAnimData Gimmick_anim_data[];