#pragma once
#include"Base/Base.h"
class Player : public Base {
private:
	//アニメーションの種類
	enum {
		eAnimIdle = 0,
		eAnimRun,
		eAnimJumpUp,
		eAnimJumpDown,
		eAnimDamage,
		eAnimDown,
	};
	//状態
	enum {
		eState_Idle,
		eState_Damage,
		eState_Down,
	};
	//状態変数
	int m_state;
	//各状態での挙動
	void StateIdle();
	void StateDamage();
	void StateDown();

	CImage m_img;
	bool m_flip;
	bool m_is_ground;

public:
	Player(const CVector2D& pos);
	~Player();
	void Update();
	void Draw();
	void Collision(Base* b);

	static TexAnimData _anim_data[];

};