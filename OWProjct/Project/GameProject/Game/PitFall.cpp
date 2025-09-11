#include "PitFall.h"
#include "Map.h"

PitFall::PitFall(const CVector2D& pos)
	:Base(eType_Pit)
{	
	m_pos = pos;
}

void PitFall::Update()
{
	//CVector2D pos = CVector2D(792, 264);
	Base* player = Base::FindObject(eType_Player);
	if (player)
	{

		CVector2D v = player->m_pos - m_pos;
		if (abs(v.x)<130)
		{
			Map* m = dynamic_cast<Map*>(Base::FindObject(eType_Map));
			m->SetTip(CVector2D(m_pos), 0);
			
		}
	}
}

void PitFall::Collision()
{
}
