#include "Bullet.h"
#include <Novice.h>

// コンストラクタ
Bullet::Bullet()
{
	// 弾の初期位置
	pos_ = { 0.0f,0.0f };
	// 弾の速度
	speed_ = 10.0f;
	// 半径
	radius_ = 10.0f;
	// 発射フラグ
	isShot_ = false;
}

// 更新処理
void Bullet::Update()
{
	// 弾が発射状態のとき上方向に移動
	if (isShot_)
	{
		pos_.y -= speed_;
	}

	// 画面外に出たら発射フラグをオフにする
	if (pos_.y <= radius_)
	{
		isShot_ = false;
	}
}

// 描画処理
void Bullet::Draw()
{
	// 弾が発射状態のときのみ描画
	if (isShot_)
	{
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, WHITE, kFillModeSolid);
	}
}

// 弾の位置を設定
void Bullet::SetPos(Vector2 pos)
{
	pos_ = pos;
}

// 発射フラグの設定
void Bullet::SetIsShot(int isShot)
{
	isShot_ = isShot;
}
