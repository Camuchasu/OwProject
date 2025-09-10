#pragma once
#include"../Base/Base.h"

class Title :public Base
{
	CImage m_title;
	CImage m_Logo;
	CImage m_haikei;
	int m_cnt;
public:
	Title();
	void Update();
	void Draw();
};