#pragma once
#include"Base/Base.h"
class Player : public Base {
private:
	//�A�j���[�V�����̎��
	enum {
		eAnimIdle = 0,
		eAnimRun,
		eAnimJumpUp,
		eAnimJumpDown,
		eAnimDamage,
		eAnimDown,
	};
	//���
	enum {
		eState_Idle,
		eState_Damage,
		eState_Down,
	};
	//��ԕϐ�
	int m_state;
	//�e��Ԃł̋���
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