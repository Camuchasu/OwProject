#include"Title.h"

Title::Title() : Base(eType_Scene)
{
	
}

void Title::Update() 
{

}

void Title::Draw() 
{
	m_title.Draw();
	m_Logo.Draw();
}