#pragma once
#include "Base/Base.h"

class Brock : public Base
{
private:

public:
	Brock();
	void Update()override;
	void Draw()override;
	void Collision();
};