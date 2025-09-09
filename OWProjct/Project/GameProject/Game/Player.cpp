#include "Player.h"


Player::Player(const CVector2D& pos,bool flip) :Base(eType_Player) {
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos_old = m_pos = pos;
	m_rad = 12;
	m_img.ChangeAnimation(0);
	m_img.SetSize(100, 100);
	m_img.SetCenter(50, 100);
}

Player::~Player(){

}

void Player::StateIdle() {
	//�ړ���
	const float move_speed = 6;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 12;
	//���ړ�
	if (HOLD(CInput::eLeft)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		//���]�t���O
		m_flip = false;
		move_flag = true;
		//�W�����v
		if (m_is_ground && PUSH(CInput::eButton2)) {
			m_vec.y = -jump_pow;
			m_is_ground = false;
		}
		//�W�����v���Ȃ�
		if (!m_is_ground) {
			if (m_vec.y < 0)
				//�㏸�A�j���[�V����
				m_img.ChangeAnimation(eAnimJump, false);
			else
				//���~�A�j���[�V����
				m_img.ChangeAnimation(eAnimFall, false);
		}
		//�n�ʂɂ���Ȃ�
		else
		{
			//�ړ����Ȃ�
			if (move_flag) {
				//����A�j���[�V����
				m_img.ChangeAnimation(eAnimRun);
			}
			else {
				//�ҋ@�A�j���[�V����
				m_img.ChangeAnimation(eAnimIdle);
			}
		}
	}
}

void Player::Update(){
}

void Player::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}

void Player::Collision(Base* b)
{
}
static TexAnim _idle[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
	{ 4,5 },
	{ 5,5 },
	{ 6,5 },
	{ 7,5 },
	{ 8,5 },
	{ 9,5 },
	{ 10,5 },
	{ 11,5 },
};

static TexAnim _run[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
	{ 4,5 },
	{ 5,5 },
	{ 6,5 },
	{ 7,5 },
	{ 8,5 },
	{ 9,5 },
	{ 10,5 },
	{ 11,5 },
	{ 12,5 },
};
static TexAnim _jump[] = {
	{0,5},
};
static TexAnim _fall[] = {
	{0,5},
};

extern TexAnimData Player_anim_data[] = {
	ANIMDATA(_idle),
	ANIMDATA(_run),
	ANIMDATA(_jump),
	ANIMDATA(_fall),
};
