#pragma once
#include"../Base/Base.h"
class GameOver : public Base {
private:
	CImage m_img;
public:
	GameOver(CVector2D& pos);
	void Update()override;
	void Draw()override;
};