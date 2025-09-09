#pragma once
#include"Base/Base.h"
class Player : public Base {
private:
	//�A�j���[�V�����̎��
	enum {
		eAnimIdle = 0,
		eAnimRun,
		eAnimJump,
		eAnimFall,
		eAnimHit,
	};
	//���
	enum {
		eState_Idle,
		eState_Hit,
	};
	//��ԕϐ�
	int m_state;
	//�e��Ԃł̋���
	void StateIdle();

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
