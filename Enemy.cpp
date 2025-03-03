#include "Enemy.h"
#include "Novice.h"

// コンストラクタ
Enemy::Enemy(float posX, float posY, float speedX, float speedY)
{
	pos_.x = posX;
	pos_.y = posY;
	speed_.x = speedX;
	speed_.y = speedY;
	radius_ = 30;
	isAlive_ = true;
}

// 更新処理
void Enemy::Update() {
	if (isAlive_)
	{
		// 位置を更新
		pos_.x += speed_.x;
		pos_.y += speed_.y;

		// 画面端で反射する処理
		if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280) {
			speed_.x *= -1;
		}
		if (pos_.y - radius_ <= 0 || pos_.y + radius_ >= 720) {
			speed_.y *= -1;
		}
		//カウンターリセット
		spawnCounter_ = 0; 
	}

	// 敵が死亡している場合の処理
	if (!isAlive_)
	{
		spawnCounter_++;
		// 100フレーム後に復活
		if (spawnCounter_ == 100)
		{
			isAlive_ = true;
		}
	}
}

// 描画処理
void Enemy::Draw() {
	if (isAlive_)
	{
		// 生存時のみ敵を描画
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, RED, kFillModeSolid);
	}
}

// 位置を設定する関数
void Enemy::SetPos(Vector2 pos)
{
	pos_ = pos;
}

// 生存状態を設定する関数
void Enemy::SetIsAlive(int isAlive)
{
	isAlive_ = isAlive;
}

// 速度を設定する関数
void Enemy::SetSpeed(float x, float y)
{
	speed_.x = x;
	speed_.y = y;
}
