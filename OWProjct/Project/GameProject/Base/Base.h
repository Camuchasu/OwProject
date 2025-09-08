#pragma once
#define GRAVITY (9.8f*1.0)

enum class BaseType {
	eCamera,
	eSkyBox,
	eField,
	eEnemy,
	eEnemyManager,
	eCharactor,
	ePlayer,
	eAttack,
	eBullet,
	eArrow,
	ePlayer_Bullet,
	eEnemy_Bullet,
	eGrass,
	eEffect,
	eUI,
	eHUD,
	eCollision,
	eScene,
	eEffectManager,
	eAppearPoint,
	eMax,
};


class Base : public std::enable_shared_from_this<Base> {
private:
	BaseType m_type;
public:
	//���W
	CVector3D m_pos;
	//��]�l
	CVector3D m_rot;
	//�X�P�[��
	CVector3D m_scale;
	//�ړ���
	CVector3D m_vec;
	//���a
	float m_rad;
	//�J�v�Z���p
	CCapsule m_capsule;
	//�폜�t���O
	int m_kill;
public:
	Base(BaseType type);
	virtual ~Base();
	//��ʂ̎擾
	BaseType GetType() {
		return m_type;
	}
	//���W�̐ݒ�
	void SetPos(const CVector3D& pos) {
		m_pos = pos;
	}
	//���W�̎擾
	CVector3D GetPos() {
		return m_pos;
	}
	//��]�l�̐ݒ�
	void SetRot(const CVector3D& rot) {
		m_rot = rot;
	}
	//��]�l�̎擾
	CVector3D GetRot() {
		return m_rot;
	}
	void SetKill() {
		m_kill = true;
	}
	virtual CModel* GetModel() {
		return nullptr;
	}

	virtual void Update();
	virtual void Draw();
	virtual void Collision(const std::shared_ptr<Base>&);

	friend class BaseManager;
};
class BaseManager {
private:
	std::list<std::shared_ptr<Base>> m_list;
	static BaseManager* m_instance;
public:
	BaseManager();
	~BaseManager();
	//�C���X�^���X�擾
	static BaseManager* GetInstance();
	//�����폜
	static void ClearInstance();
	//�S�ẴI�u�W�F�N�g�̍X�V
	void UpdateALL();
	
	//�S�ẴI�u�W�F�N�g�̕`��
	void DrawALL();
	//�S�ẴI�u�W�F�N�g���m�̏Փˌ���
	void CollisionALL();
	//�S�ẴI�u�W�F�N�g�̍폜
	void KillALL();
	//�w���ނ̃I�u�W�F�N�g�폜
	void Kill(int mask);
	//�S�ẴI�u�W�F�N�g�̍폜�`�F�b�N
	void CheckKillALL();
	//�I�u�W�F�N�g��ǉ�
	std::shared_ptr<Base> Add(const std::shared_ptr<Base>&);
	//�I�u�W�F�N�g�̌���
	std::shared_ptr<Base> FindObject(BaseType type);
	//�I�u�W�F�N�g�̌���
	std::list<std::shared_ptr<Base>> FindObjects(BaseType type);

};