#pragma once
#include "../Base/Base.h"

class Field :public Base {
private:
    //�摜�I�u�W�F�N�g�i�ŉ��i�j
    CImage m_sky;
    //�n�ʂ̍���
    float m_Map_Tip;

public:
    CImage m_img;
    Field(const CVector2D& pos);
    void Update();
    void Draw();
};