#pragma once
#include"../Base/Base.h"
class GameOver : public Base {
private:
	CImage m_img;
	CImage m_suppl;//•â‘«
public:
	GameOver(CVector2D& pos);
	void Update()override;
	void Draw()override;
};