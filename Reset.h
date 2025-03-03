#pragma once
#include "Player.h"
#include "Enemy.h"

// リセット
class Reset
{
private:
	// プレイヤーの初期位置
	Vector2 resetPlayerPos_;
	// プレイヤーの生存フラグ
	int resetPlayerIsAlive_;

	// 弾の初期位置
	Vector2 resetBulletPos_;
	// 弾の発射フラグ
	int resetBulletIsShot_;

	// 敵の初期位置
	Vector2 resetEnemyPos_[kEnemyNum];
	// 敵の生存フラグ
	int resetEnemyIsAlive_[kEnemyNum];

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="player">プレイヤー</param>
	/// <param name="enemy">敵</param>
	Reset(Player* player, Enemy* enemy[kEnemyNum]);

	/// <summary>
	/// プレイヤーをリセット
	/// </summary>
	/// <param name="player">プレイヤー</param>
	void ResetPlayer(Player* player);

	/// <summary>
	/// 敵をリセット
	/// </summary>
	/// <param name="enemy">敵</param>
	void ResetEnemy(Enemy* enemy[kEnemyNum]);
};