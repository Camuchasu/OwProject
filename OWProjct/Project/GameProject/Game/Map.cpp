#include "Map.h"
#include "Player.h"
#include "Enemy.h"
float Map::m_msc(Base::m_scroll.x);
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
                       //1                   2                   3                   4
   //0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//0
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//1
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//2
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//3
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//4
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},//5
    {2,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},//6
    {5,5,5,5,5,5,5,5,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},//7
    {5,5,5,5,5,5,5,5,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},//8
    //行40
    //列8


};





Map::Map() :Base(eType_Map)
{
    SOUND("BGM")->Play();
    //画像の複製
    m_img = COPY_RESOURCE("Map_Tip1", CImage);
    m_Sky = COPY_RESOURCE("Sky", CImage);
    m_kumo = COPY_RESOURCE("kumo", CImage);
    m_message = COPY_RESOURCE("Message", CImage);
    //当たり判定用矩形設定
    m_rect = CRect(-40, 38, 40, -38);
    memcpy(stage, stage1data, sizeof(stage1data));
    //m_Map_Tip = 900;
}

void Map::Update()
{
   
}

void Map::Draw()
{
    m_Sky.SetSize(1920, 1080);
    m_Sky.Draw();
    m_kumo.Draw();
    float sc;
    m_Sky.Draw();
    sc = Base::m_scroll.x / 3;
    m_kumo.SetRect(sc, 0, sc + 1920, 376);
    m_kumo.Draw();
   
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            //表示させない [i]行 [j]列
            if (stage[i][j] == 0)continue;
            int t = stage[i][j];
            //切り抜き    //左　//ue   //migi //sita
            m_img.SetRect(44 * t, 0, 44 * t + 44, 46);
            //サイズ
            m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);


            //位置設定
            m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i - m_scroll.y);
            //描画
            m_img.Draw();
            DrawRect();
        }
    }
    m_message.SetPos(GetScreenPos(CVector2D(m_pos.x+800,1080/2)));
    //m_message.SetCenter(50, 50);
    m_message.SetSize(100, 100);
    m_message.Draw();
  

}

void Map::Collision(Base* b)
{
    switch (b->m_type)
    {
    case eType_Player:
        if (Player* p = dynamic_cast<Player*>(b)) {
            if (Base::CollisionRect(this, p)) {
                b->SetKill();
            }
        }
        break;
    }
   
}


int Map::GetTip(const CVector2D& pos, int* tx, int* ty)
{
    //列を計算
    int x = pos.x / MAP_TIP_SIZE;
    //列の制限
    if (x < 0) x = 0;
    if (x > MAP_WIDTH - 1) x = MAP_WIDTH - 1;
    //行を計算
    int y = pos.y / MAP_TIP_SIZE;
    //行の制限
    if (y < 0) y = 0;
    if (y > MAP_HEIGHT - 1) y = MAP_HEIGHT - 1;
    //行と列の出力
    if (ty) *ty = y * MAP_TIP_SIZE;
    if (tx) *tx = x * MAP_TIP_SIZE;
    //チップデータを返却
    return stage[y][x];
}
int Map::GetTip(int x, int y)
{
    return stage[y][x];

}

void Map::SetTip(int col, int row, int type)
{
    stage[row][col] = type;
}

void Map::SetTip(const CVector2D& pos, int type)
{
    int col = pos.x / MAP_TIP_SIZE;
    if (col < 0)col = 0;
    if (col > MAP_WIDTH - 1)col = MAP_WIDTH - 1;
    int row = pos.y / MAP_TIP_SIZE;
    if (row < 0)row = 0;
    if (row > MAP_HEIGHT - 1)row = MAP_HEIGHT - 1;
    SetTip(col, row, type);
}

int Map::CollisionPoint(const CVector2D& pos)
{


    //1点のみ検証
    int t = GetTip(pos);
    if (t != 0)return 1;
    return 0;
}

int Map::CollisionRect(const CVector2D& pos, const CRect& rect)
{
    CRect r = CRect(
        pos.x + rect.m_left,
        pos.y + rect.m_top,
        pos.x + rect.m_right,
        pos.y + rect.m_bottom);
    int t;
    t = CollisionPoint(CVector2D(r.m_left, r.m_top));
    if (t != 0) return t;
    t = CollisionPoint(CVector2D(r.m_right, r.m_top));
    if (t != 0) return t;
    t = CollisionPoint(CVector2D(r.m_left, r.m_bottom));
    if (t != 0) return t;
    t = CollisionPoint(CVector2D(r.m_right, r.m_bottom));
    if (t != 0) return t;
    return 0;
}