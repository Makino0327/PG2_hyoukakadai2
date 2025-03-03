#pragma once
#include"Struct.h"

class Enemy
{
private: // メンバ変数
	Vector2 pos_;
	Vector2 speed_;
	float radius_; 
	int isAlive_;
	int spawnCounter_ = 0; 

public: // メンバ関数
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="posX">X座標</param>
	/// <param name="posY">Y座標</param>
	/// <param name="speedX">移動速度X</param>
	/// <param name="speedY">移動速度Y</param>
	Enemy(float posX, float posY, float speedX, float speedY);

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
	/// <returns>現在位置</returns>
	Vector2 GetPos() { return pos_; };

	/// <summary>
	/// 半径を取得
	/// </summary>
	/// <returns>半径</returns>
	float GetRadius() { return radius_; };

	/// <summary>
	/// X方向の移動速度を取得
	/// </summary>
	/// <returns>速度X</returns>
	float GetSpeedX() { return speed_.x; };

	/// <summary>
	/// Y方向の移動速度を取得
	/// </summary>
	/// <returns>速度Y</returns>
	float GetSpeedY() { return speed_.y; };

	/// <summary>
	/// 生存フラグを取得
	/// </summary>
	/// <returns>生存フラグ</returns>
	int GetIsAlive() { return isAlive_; };

	/// <summary>
	/// 位置を設定
	/// </summary>
	/// <param name="pos">設定する位置</param>
	void SetPos(Vector2 pos);

	/// <summary>
	/// 速度を設定
	/// </summary>
	/// <param name="x">X方向の速度</param>
	/// <param name="y">Y方向の速度</param>
	void SetSpeed(float x, float y);

	/// <summary>
	/// 生存フラグを設定
	/// </summary>
	/// <param name="isAlive">設定する生存フラグ</param>
	void SetIsAlive(int isAlive);
};
