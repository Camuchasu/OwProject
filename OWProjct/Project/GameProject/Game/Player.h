#pragma once
#include"Base/Base.h"
class Player : public Base {
private:
	//アニメーションの種類
	enum {
		eAnimRun,
		eAnimIdle,
		eAnimJump,
		eAnimFall,
		eAnimDeth,
	};
	//状態
	enum {
		eState_Idle,
		eState_Deth,
	};
	//状態変数
	int m_state;
	//各状態での挙動
	void StateIdle();
	void StateDeth();
	CImage m_img;
	bool m_flip;
	bool m_is_ground;

public:
	Player(const CVector2D& pos,bool flip);
	~Player();
	void Update();
	void Draw();
	void Collision(Base* b);

	
};
extern TexAnimData Player_anim_data[];
