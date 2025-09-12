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
	CImage m_UI8;
	CImage m_UI9;
	CImage m_UI10;

public:
	UI(CVector2D& pos);
	void Update()override;
	void Draw()override;
};