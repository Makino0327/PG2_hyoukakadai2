#pragma once
#include "Struct.h"

class Bullet
{
private:// メンバ変数
	Vector2 pos_;
	float speed_;
	float radius_;
	int isShot_;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bullet();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 位置を取得
	/// </summary>
	/// <returns>弾の位置</returns>
	Vector2 GetPos() { return pos_; };

	/// <summary>
	/// 半径を取得
	/// </summary>
	/// <returns>半径</returns>
	float GetRadius() { return radius_; };

	/// <summary>
	/// 発射フラグを取得
	/// </summary>
	/// <returns>発射フラグ</returns>
	int GetIsShot() { return isShot_; };

	/// <summary>
	/// 位置を設定
	/// </summary>
	/// <param name="pos">設定する位置</param>
	void SetPos(Vector2 pos);

	/// <summary>
	/// 発射状態を設定
	/// </summary>
	/// <param name="isShot">発射フラグ</param>
	void SetIsShot(int isShot);
};
