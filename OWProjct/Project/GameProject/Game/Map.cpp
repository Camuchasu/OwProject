#include "Map.h"
#include "Player.h"
#include "Enemy.h"
float Map::m_msc(Base::m_scroll.x);
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {5,5,5,5,5,5,5,5,0,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
    {5,5,5,5,5,5,5,5,0,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},



};





Map::Map() :Base(eType_Map)
{
    //�摜�̕���
    m_img = COPY_RESOURCE("Map_Tip1", CImage);
    m_Sky = COPY_RESOURCE("Sky", CImage);
    m_kumo = COPY_RESOURCE("kumo", CImage);
    m_message = COPY_RESOURCE("Message", CImage);
    //�����蔻��p��`�ݒ�
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
            //�\�������Ȃ� [i]�s [j]��
            if (stage1data[i][j] == 0)continue;
            int t = stage1data[i][j];
            //�؂蔲��    //���@//ue   //migi //sita
            m_img.SetRect(44 * t, 0, 44 * t + 44, 46);
            //�T�C�Y
            m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);


            //�ʒu�ݒ�
            m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i - m_scroll.y);
            //�`��
            m_img.Draw();
           // DrawRect();
        }
    }
    //m_message.SetPos(800, 800);
    ////m_message.SetCenter(50, 50);
    //m_message.SetSize(100, 100);
    //m_message.Draw();
  

}

void Map::Collision(Base* b)
{
    switch (b->m_type)
    {
    case eType_Player:
        if (Player* p = dynamic_cast<Player*>(b)) {
            if (Base::CollisionRect(this, p)) {
               
            }
        }
        break;
    }
   
}


int Map::GetTip(const CVector2D& pos, int* tx, int* ty)
{
    //����v�Z
    int x = pos.x / MAP_TIP_SIZE;
    //��̐���
    if (x < 0) x = 0;
    if (x > MAP_WIDTH - 1) x = MAP_WIDTH - 1;
    //�s���v�Z
    int y = pos.y / MAP_TIP_SIZE;
    //�s�̐���
    if (y < 0) y = 0;
    if (y > MAP_HEIGHT - 1) y = MAP_HEIGHT - 1;
    //�s�Ɨ�̏o��
    if (ty) *ty = y * MAP_TIP_SIZE;
    if (tx) *tx = x * MAP_TIP_SIZE;
    //�`�b�v�f�[�^��ԋp
    return stage[y][x];
}
int Map::GetTip(int x, int y)
{
    return stage1data[y][x];

}

int Map::CollisionPoint(const CVector2D& pos)
{


    //1�_�̂݌���
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