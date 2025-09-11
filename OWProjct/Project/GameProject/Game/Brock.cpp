#include "Brock.h"

Brock::Brock(CVector2D& pos)
	:Base(eType_Brock)
{
	m_brock = COPY_RESOURCE("Brock", CImage);
	m_rect = CRect(-21, 0, 23, -21);
	m_pos = pos;
}

void Brock::Update()
{

}

void Brock::Draw()
{
	//êÿÇËî≤Ç´    //ç∂Å@ //ue   //migi //sita
	//m_brock.SetRect(,,,);
	m_brock.SetCenter(16,32);
	m_brock.SetPos(GetScreenPos(m_pos));
	m_brock.SetSize(100,100);
	m_brock.Draw();
	DrawRect();
}

void Brock::Collision()
{

}
