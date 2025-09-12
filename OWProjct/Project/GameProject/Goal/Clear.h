#pragma once
#include"../Base/Base.h"

class Clear : public Base {
private:
	CImage m_img;
public:
	Clear();
	void Update()override;
	void Draw()override;

};