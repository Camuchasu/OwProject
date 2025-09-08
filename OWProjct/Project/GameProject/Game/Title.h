#pragma once
#include"../Base/Base.h"

class Title :public Base 
{
	CImage m_title;
	CImage m_Logo;
	int m_cnt;
public:
	void Update();
	void Draw();
};