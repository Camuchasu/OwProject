#pragma once
#include"../Base/Base.h"
class GameOver : public Base {
private:
	CImage m_img;
	CImage m_suppl;//�⑫
public:
	GameOver(CVector2D& pos);
	void Update()override;
	void Draw()override;
};