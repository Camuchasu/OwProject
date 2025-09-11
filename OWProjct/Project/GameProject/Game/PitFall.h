#pragma once
#include"Base/Base.h"

class PitFall : public Base
{
private:

public:
	PitFall(const CVector2D& pos);
	void Update()override;
	void Collision();
};