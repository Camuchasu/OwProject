#include "Gimmick.h"

Gimmick::Gimmick(CVector2D &pos)
	:Base(eType_Gimmick)
{
	m_spaik = COPY_RESOURCE("NeedleDossin", CImage);
	//再生アニメーション設定
	m_spaik.ChangeAnimation(0);
}

void Gimmick::Update()
{
	//アニメーション更新
	m_spaik.UpdateAnimation();
}

void Gimmick::Draw()
{
	m_spaik.SetCenter(50, 100);
	m_spaik.SetSize(100, 100);
	m_spaik.Draw();
}

void Gimmick::Collision()
{
}
static TexAnim gimmickidle[] = {

	{ 0,6 },
	
};

static TexAnim gimmicklefthit[] = {

	{ 4,6 },
	{ 5,6 },
	{ 6,6 },
	{ 7,6 },
};
static TexAnim gimmickrighthit[] = {

	
	{ 8,6 },
	{ 9,6 },
	{ 10,6 },
	{ 11,6 },
};
static TexAnim gimmicktophit[] = {

	{ 12,6 },
	{ 13,6 },
	{ 14,6 },
	{ 15,6 },
};
static TexAnim gimmickbottomhit[] = {

	{ 16,6 },
	{ 17,6 },
	{ 18,6 },
	{ 19,6 },
};
static TexAnim gimmickbrink[] = {

	{ 20,6 },
	{ 21,6 },
	{ 22,6 },
	{ 23,6 },
};
TexAnimData Gimmick_anim_data[] = {
	ANIMDATA(gimmickidle),
	ANIMDATA(gimmicklefthit),
	ANIMDATA(gimmickrighthit),
	ANIMDATA(gimmicktophit),
	ANIMDATA(gimmickbottomhit),
	ANIMDATA(gimmickbrink),
};
