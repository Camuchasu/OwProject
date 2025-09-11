#pragma once
#include "Base/Base.h"

class Goal : public Base
{
private:
	CImage m_img;

public:
	int m_type;

	Goal(const CVector2D& pos,int type);
	void Update()override;
	void Draw() override;
	void Collision(Base* b);

};
