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
	//座標
	CVector3D m_pos;
	//回転値
	CVector3D m_rot;
	//スケール
	CVector3D m_scale;
	//移動量
	CVector3D m_vec;
	//半径
	float m_rad;
	//カプセル用
	CCapsule m_capsule;
	//削除フラグ
	int m_kill;
public:
	Base(BaseType type);
	virtual ~Base();
	//種別の取得
	BaseType GetType() {
		return m_type;
	}
	//座標の設定
	void SetPos(const CVector3D& pos) {
		m_pos = pos;
	}
	//座標の取得
	CVector3D GetPos() {
		return m_pos;
	}
	//回転値の設定
	void SetRot(const CVector3D& rot) {
		m_rot = rot;
	}
	//回転値の取得
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
	//インスタンス取得
	static BaseManager* GetInstance();
	//即時削除
	static void ClearInstance();
	//全てのオブジェクトの更新
	void UpdateALL();
	
	//全てのオブジェクトの描画
	void DrawALL();
	//全てのオブジェクト同士の衝突検証
	void CollisionALL();
	//全てのオブジェクトの削除
	void KillALL();
	//指定種類のオブジェクト削除
	void Kill(int mask);
	//全てのオブジェクトの削除チェック
	void CheckKillALL();
	//オブジェクトを追加
	std::shared_ptr<Base> Add(const std::shared_ptr<Base>&);
	//オブジェクトの検索
	std::shared_ptr<Base> FindObject(BaseType type);
	//オブジェクトの検索
	std::list<std::shared_ptr<Base>> FindObjects(BaseType type);

};