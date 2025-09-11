#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "GameOver.h"
Player::Player(const CVector2D& pos, bool flip) :Base(eType_Player) {
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos_old = m_pos = pos;
	m_rad = 12;
	//�����蔻��p��`�ݒ�
	m_rect = CRect(-40, -80, 40, -10);
	m_img.ChangeAnimation(0);
	m_img.SetSize(100, 100);
	m_img.SetCenter(50, 100);
	m_state = eState_Idle;
	//���n�t���O
	m_is_ground = true;
}

Player::~Player()
{

}

void Player::StateIdle()
{
	//�ړ���
	const float move_speed = 6;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 15;
	//���ړ�
	if (HOLD(CInput::eLeft))
	{
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight))
	{
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		//���]�t���O
		m_flip = false;
		move_flag = true;
	}
	//�W�����v
	if (m_is_ground && PUSH(CInput::eButton2))
	{
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
	//�W�����v���Ȃ�
	if (!m_is_ground)
	{
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
		if (move_flag)
		{
			//����A�j���[�V����
			m_img.ChangeAnimation(eAnimRun);
		}
		else
		{
			//�ҋ@�A�j���[�V����
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
	if (PUSH(CInput::eButton5))
	{
		m_state = eState_Death;
	}
}

void Player::StateDeth()
{
	m_img.ChangeAnimation(eAnimDeath, false);
	
	if (m_img.CheckAnimationEnd()) {
		Base::Add(new GameOver(CVector2D(m_pos_old.x-300,1080/2-100)));
		m_kill = true;
		
	}
}


void Player::Update() {
	//�ړ�����
	m_pos_old = m_pos;
	switch (m_state) {
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
		//���S���
	case eState_Death:
		StateDeth();
		break;
	}
	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
	{
		m_is_ground = false;
	}
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
	//�X�N���[���ݒ�
	m_scroll.x = m_pos.x - 1280 / 2;
	//���������}�b�v�ɍ��킹��
	if (m_scroll.x < 0) {
		m_scroll.x = 0;
	}
	//�E�������}�b�v�ɍ��킹��
	if (m_scroll.x > 1200) {
		m_scroll.x = 1200;
	}
	if (m_pos.y >= 1090)
	{
		m_state = eState_Death;
	}
}

void Player::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	DrawRect();
}

void Player::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Enemy:
		if (Base::CollisionRect(this, b))
		{
			b->SetKill();
			m_state = eState_Death;
		}
		break;
	case eType_Map:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = 0;
			t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
			}
		}
	case eType_Item:
		if(Base::CollisionRect(this,b))
		{
			m_state = eState_Death;
		}
	case eType_Needle:
		if(Base::CollisionRect(this, b))
		{
			m_state = eState_Death;
		}
	}
}
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
};

static TexAnim _idle[] = {
	{ 12,5 },
	{ 12,5 },
	{ 14,5 },
	{ 15,5 },
	{ 16,5 },
	{ 17,5 },
	{ 18,5 },
	{ 19,5 },
	{ 20,5 },
	{ 21,5 },
	{ 22,5 },
};
static TexAnim _jump[] = {
	{24,5},
};
static TexAnim _fall[] = {
	{36,5},
};
static TexAnim _deth[] = {
	{60,5},
	{61,5},
	{62,5},
	{63,5},
	{64,5},
	{65,5},
	{66,5},
};

 TexAnimData Player_anim_data[] = {
	ANIMDATA(_run),
	ANIMDATA(_idle),
	ANIMDATA(_jump),
	ANIMDATA(_fall),
	ANIMDATA(_deth),
};
