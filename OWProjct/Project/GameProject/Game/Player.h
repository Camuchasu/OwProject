#pragma once
#include"Base/Base.h"
class Player : public Base {
private:
	//�A�j���[�V�����̎��
	enum {
		eAnimRun,
		eAnimIdle,
		eAnimJump,
		eAnimFall,
		eAnimDeth,
	};
	//���
	enum {
		eState_Idle,
		eState_Deth,
	};
	//��ԕϐ�
	int m_state;
	//�e��Ԃł̋���
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
