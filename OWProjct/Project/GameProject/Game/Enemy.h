#pragma once
#include "Base/Base.h"
class Enemy : public Base
{
private:
	enum 
	{
		Run,
		Death,
	};
	enum
	{
		eAnim_Run,
		eAnim_Death,
	};
	CImage m_img;
	bool m_flip;
	//ó‘Ô•Ï”
	int m_state;
	void StateRun();
	void StateDeath();
	bool m_isGround;
public:
	
	Enemy(const CVector2D& pos, bool flip);
	~Enemy();
	void Update()override;
	void Draw()override;
	void Collision(Base* b);

};
extern TexAnimData Enemy_anim_data[];