#include "Base.h"
BaseManager* BaseManager::m_instance = nullptr;

Base::Base(BaseType type) : m_type(type), m_kill(false)
, m_pos(0, 0, 0), m_rot(0, 0, 0), m_scale(1, 1, 1), m_vec(0, 0, 0), m_rad(0)
{
}


Base::~Base()
{
}

void Base::Update()
{
}


void Base::Draw()
{
}
void Base::Collision(const std::shared_ptr<Base>&)
{
}

BaseManager::BaseManager() {

}
BaseManager::~BaseManager() {

	m_list.clear();
}
BaseManager* BaseManager::GetInstance()
{
	if (!m_instance) m_instance = new BaseManager();
	return m_instance;
}
void BaseManager::KillALL() {
	auto itr = m_list.begin();
	//末尾まで繰り返す
	while (itr != m_list.end()) {
		(*itr)->m_kill = true;
		itr++;
	}

}
void BaseManager::Kill(int mask)
{
	for (auto& b : m_list)
		if ((1 << (int)b->m_type) & mask)
			b->SetKill();
}
void BaseManager::CheckKillALL() {
	//Killフラグがtrueのオブジェクトをリストから除外する
	auto KillCheck = [](const std::shared_ptr<Base>& b) { return b->m_kill; };
	m_list.remove_if(KillCheck);
	//shared_ptrのため、参照が無くなると勝手にdeleteされる
}
void BaseManager::UpdateALL() {
	for (auto& b : m_list)
	{
		if (!b->m_kill)
			b->Update();
	}
}

void BaseManager::DrawALL() {
	for (auto& b : m_list)
	{
		if (!b->m_kill) b->Draw();
	}

}
void BaseManager::CollisionALL()
{
	for (auto itA = m_list.begin(); itA != m_list.end(); ++itA) {
		if ((*itA)->m_kill) continue;

		for (auto itB = std::next(itA); itB != m_list.end(); ++itB) {
			if ((*itB)->m_kill) continue;

			(*itA)->Collision(*itB);
			(*itB)->Collision(*itA);
		}
	}

}

std::shared_ptr<Base> BaseManager::Add(const std::shared_ptr<Base>& base_obj) {
	//
	auto itr = m_list.begin();
	//末尾まで繰り返す
	while (itr != m_list.end()) {
		if ((*itr)->m_type > base_obj->m_type) {
			m_list.insert(itr, base_obj);
			return base_obj;
		}
		//次のオブジェクト
		itr++;
	}
	m_list.push_back(base_obj);

	return base_obj;

}



std::shared_ptr<Base> BaseManager::FindObject(BaseType type) {
	for (auto& b : m_list)
		//オブジェクトのtypeが引数のtypeと一致すれば　そのオブジェクトを返す
		if (!b->m_kill && b->m_type == type) return b;

	return nullptr;
}

std::list<std::shared_ptr<Base>> BaseManager::FindObjects(BaseType type)
{
	std::list<std::shared_ptr<Base>> list;
	for (auto& b : m_list)
		if (!b->m_kill && b->m_type == type) list.push_back(b);

	return list;
}

void BaseManager::ClearInstance()
{
	delete m_instance;
	m_instance = nullptr;
}