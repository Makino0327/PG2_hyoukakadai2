#include "Scene.h"

// コンストラクタ
Scene::Scene()
{
	scene_ = 0;
}

// シーンの更新処理
void Scene::Update(Player* player, Enemy* enemy[kEnemyNum], Reset* reset, char* keys, char* preKeys)
{
	switch (scene_)
	{
	case TITLE:
		// タイトル画面での操作処理
		if (keys != NULL || preKeys != NULL)
		{
			// プレイヤーと敵をリセット
			reset->ResetPlayer(player);
			reset->ResetEnemy(enemy);

			// スペースキーが押されたらゲーム開始
			if (!preKeys[DIK_SPACE] && keys[DIK_SPACE])
			{
				scene_ = GAME;
			}
		}
		break;

	case GAME:
		// プレイヤーの更新処理
		player->Update(keys, preKeys);

		// 敵の更新処理
		for (int i = 0; i < kEnemyNum; i++)
		{
			enemy[i]->Update();

			if (enemy[i]->GetIsAlive())
			{
				// 敵同士の当たり判定処理
				Vector2 diffEnemy = enemy[0]->GetPos() - enemy[1]->GetPos();
				float distEnemySquared = (diffEnemy.x * diffEnemy.x) + (diffEnemy.y * diffEnemy.y);
				float sumEnemyRadius = enemy[0]->GetRadius() + enemy[1]->GetRadius();

				if (distEnemySquared <= sumEnemyRadius * sumEnemyRadius) {
					enemy[0]->SetSpeed((enemy[0]->GetSpeedX()) * -1.0f, 4.0f);
					enemy[1]->SetSpeed((enemy[1]->GetSpeedX()) * -1.0f, -3.0f);
				}

				// プレイヤーと敵の当たり判定
				Vector2 diffPlayerEnemy = player->GetPos() - enemy[i]->GetPos();
				float distPlayerEnemySquared = (diffPlayerEnemy.x * diffPlayerEnemy.x) + (diffPlayerEnemy.y * diffPlayerEnemy.y);
				float sumPlayerEnemyRadius = player->GetRadius() + enemy[i]->GetRadius();

				if (distPlayerEnemySquared <= sumPlayerEnemyRadius * sumPlayerEnemyRadius) {
					player->SetIsAlive(false);
				}

				// 弾と敵の当たり判定
				Vector2 diffBulletEnemy = player->bullet->GetPos() - enemy[i]->GetPos();
				float distBulletEnemySquared = (diffBulletEnemy.x * diffBulletEnemy.x) + (diffBulletEnemy.y * diffBulletEnemy.y);
				float sumBulletEnemyRadius = player->bullet->GetRadius() + enemy[i]->GetRadius();

				if (distBulletEnemySquared <= sumBulletEnemyRadius * sumBulletEnemyRadius) {
					player->bullet->SetIsShot(false);
					enemy[i]->SetIsAlive(false);
				}
			}
		}

		// ゲームオーバー判定
		if (!player->GetIsAlive())
		{
			scene_ = GAME_OVER;
		}

		// すべての敵が倒されたらクリア
		if (!enemy[0]->GetIsAlive() && !enemy[1]->GetIsAlive())
		{
			scene_ = CLEAR;
		}
		break;

	case CLEAR:
		// クリア画面でスペースキーを押すとタイトルへ
		if (!preKeys[DIK_SPACE] && keys[DIK_SPACE])
		{
			scene_ = TITLE;
		}
		break;

	case GAME_OVER:
		// ゲームオーバー画面でスペースキーを押すとタイトルへ
		if (!preKeys[DIK_SPACE] && keys[DIK_SPACE])
		{
			scene_ = TITLE;
		}
		break;
	}
}

// シーンの描画処理
void Scene::Draw(Player* player, Enemy* enemy[kEnemyNum])
{
	switch (scene_)
	{
	case TITLE:
		// タイトル画面表示
		Novice::ScreenPrintf(600, 360, "TITLE");
		break;

	case GAME:
		// ゲーム画面の描画
		player->Draw();
		for (int i = 0; i < kEnemyNum; i++)
		{
			enemy[i]->Draw();
		}
		break;

	case CLEAR:
		// クリア画面表示
		Novice::ScreenPrintf(600, 360, "CLEAR");
		break;

	case GAME_OVER:
		// ゲームオーバー画面表示
		Novice::ScreenPrintf(580, 360, "GAME OVER");
		break;
	}
}
