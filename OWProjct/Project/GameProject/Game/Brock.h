#pragma once
#include "Base/Base.h"

class Brock : public Base
{
private:
	CImage m_brock;
	bool m_isGround;
	bool flag;

public:
	Brock(CVector2D& pos);
	void Update()override;
	void Draw()override;
	void Collision();
};
extern TexAnimData Brock_anim_data[];