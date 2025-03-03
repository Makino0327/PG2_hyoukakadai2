#include "Player.h"
#include <Novice.h>

// コンストラクタ
Player::Player()
{
	// プレイヤーの初期化
	pos_ = { 640.0f,600.0f };
	radius_ = 20.0f;
	speed_ = 5.0f;
	isAlive_ = true;
	bullet = new Bullet();
}

// デストラクタ
Player::~Player()
{
	// 弾オブジェクトのメモリ解放
	delete bullet;
}

// 更新処理
void Player::Update(char* keys, char* preKeys)
{
	// プレイヤーが生きている場合のみ更新処理を行う
	if (isAlive_)
	{
		// nullチェック
		if (keys != NULL || preKeys != NULL)
		{
			// 移動処理
			if (keys[DIK_W])
			{
				pos_.y -= speed_;
			}

			if (keys[DIK_A])
			{
				pos_.x -= speed_;
			}

			if (keys[DIK_S])
			{
				pos_.y += speed_;
			}

			if (keys[DIK_D])
			{
				pos_.x += speed_;
			}

			// SPACEキーで弾を発射
			if (!preKeys[DIK_SPACE] && keys[DIK_SPACE])
			{
				bullet->SetIsShot(true);
			}

			// 弾が発射されていない場合、弾の位置をプレイヤーの位置に設定
			if (!bullet->GetIsShot())
			{
				bullet->SetPos(pos_);
			}
		}
		// 弾の更新処理
		bullet->Update();
	}
}

void Player::Draw()
{
	// プレイヤーが生きている場合のみ描画
	if (isAlive_)
	{
		// プレイヤーの描画
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, WHITE, kFillModeSolid);
		// 弾の描画
		bullet->Draw();
	}
}

// プレイヤーの位置を設定
void Player::SetPos(Vector2 pos)
{
	pos_ = pos;
}

// プレイヤーが生きているかどうかの状態を設定
void Player::SetIsAlive(int isAlive)
{
	isAlive_ = isAlive;
}
