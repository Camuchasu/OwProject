#include "Clear.h"
#include"Game/Game.h"
Clear::Clear():Base(eType_Clear){
	m_img = COPY_RESOURCE("GameClear", CImage);
	//m_pos_old = m_pos = pos;
}

void Clear::Update()
{
	if (PUSH(CInput::eButton5) || PUSH(CInput::eButton6)) {
		//���ׂẴI�u�W�F�N�g��j��
		Base::KillAll();

		Base::Add(new Game());
		////�^�C�g���V�[����
		//Base::Add(new Title());
	}
}

void Clear::Draw()
{
	m_img.SetSize(SCREEN_WIDTH+30, SCREEN_HEIGHT+5);
	m_img.Draw();

}
