#include "Reset.h"

// コンストラクタ
Reset::Reset(Player* player, Enemy* enemy[kEnemyNum])
{
	// プレイヤーの初期位置と生存フラグを保存
	resetPlayerPos_ = player->GetPos();
	resetPlayerIsAlive_ = player->GetIsAlive();

	// 弾の初期位置と発射フラグを保存
	resetBulletPos_ = player->bullet->GetPos();
	resetBulletIsShot_ = player->bullet->GetIsShot();

	// 敵の初期位置と生存フラグを保存
	for (int i = 0; i < kEnemyNum; i++)
	{
		resetEnemyPos_[i] = enemy[i]->GetPos();
		resetEnemyIsAlive_[i] = enemy[i]->GetIsAlive();
	}
}

// プレイヤーのリセット
void Reset::ResetPlayer(Player* player)
{
	player->SetPos(resetPlayerPos_);
	player->SetIsAlive(resetPlayerIsAlive_);
	player->bullet->SetPos(resetBulletPos_);
	player->bullet->SetIsShot(resetBulletIsShot_);
}

// 敵のリセット
void Reset::ResetEnemy(Enemy* enemy[kEnemyNum])
{
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy[i]->SetPos(resetEnemyPos_[i]);
		enemy[i]->SetIsAlive(resetEnemyIsAlive_[i]);
	}
}
