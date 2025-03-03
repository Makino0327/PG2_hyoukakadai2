#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player
{
private:
	// メンバ変数
	Vector2 pos_; 
	float radius_; 
	float speed_; 
	int isAlive_; 

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys">現在のキー入力</param>
	/// <param name="preKeys">前フレームのキー入力</param>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 現在の位置を取得
	/// </summary>
	/// <returns>座標</returns>
	Vector2 GetPos() { return pos_; };

	/// <summary>
	/// 半径を取得
	/// </summary>
	/// <returns>半径</returns>
	float GetRadius() { return radius_; };

	/// <summary>
	/// 生存フラグを取得
	/// </summary>
	/// <returns>生存フラグ</returns>
	int GetIsAlive() { return isAlive_; };

	/// <summary>
	/// 生存フラグを設定
	/// </summary>
	/// <param name="isAlive">設定する生存フラグ</param>
	void SetIsAlive(int isAlive);

	/// <summary>
	/// 位置を設定
	/// </summary>
	/// <param name="pos">設定する座標</param>
	void SetPos(Vector2 pos);

public:
	// プレイヤーの弾オブジェクト
	Bullet* bullet; 
};
