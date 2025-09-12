#pragma once
#include "Base/Base.h"
class Item : public Base
{
private:
	CImage m_mush;
	bool m_isGround;
public:
	Item(CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
extern TexAnimData Item_anim_data[];