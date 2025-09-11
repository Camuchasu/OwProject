#pragma once
#include"../Base/Base.h"

class Title :public Base
{
	CImage m_title;
	CImage m_Logo;
	CImage m_haikei;
	CImage m_start;
	int m_cnt;
	int m_fontstate;
	int m_alpha;
public:
	Title();
	void Update()override;
	void Draw()override;
};