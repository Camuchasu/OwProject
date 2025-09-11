#include "Needle.h"

std::vector<Needle::TypeNeedle> Needle::Needles =
{
	{"dammy",Needle::TypeNeedle::eNeedle,},
	{"Needle1",Needle::TypeNeedle::eNeedle,"notFly"},
	{"Needle2",Needle::TypeNeedle::eFoolNeedle,"Fly"},
	
};

Needle::Needle(CVector2D& pos): Base(eType_Needle){
	m_needle = COPY_RESOURCE("Needle", CImage);
	m_rect = CRect(-21, 0, 23, -21);
	m_pos = pos;
}

void Needle::Update()
{

}

void Needle::Draw()
{
	m_needle.SetCenter(25, 50);
	m_needle.SetPos(GetScreenPos(m_pos));
	m_needle.SetSize(50,50);
	m_needle.Draw();
	//DrawRect();
}

void Needle::Collision(Base* b)
{

}
