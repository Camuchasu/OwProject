#pragma once
#include "Base/Base.h"

class UI : public Base
{
private:
	CImage m_UI1;
	CImage m_UI2;
	CImage m_UI3;
	CImage m_UI4;
	CImage m_UI5;
	CImage m_UI6;
	CImage m_UI7;

	//�����\���I�u�W�F�N�g
	CFont m_UI_text;
public:
	UI(CVector2D& pos);
	void Update()override;
	void Draw()override;
};