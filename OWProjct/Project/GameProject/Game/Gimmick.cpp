#include "Gimmick.h"

Gimmick::Gimmick(CVector2D &pos)
	:Base(eType_Gimmick)
{
	m_spaik = COPY_RESOURCE("NeedleDossin", CImage);
}

void Gimmick::Update()
{
}

void Gimmick::Draw()
{

	m_spaik.Draw();
}

void Gimmick::Collision()
{
}
