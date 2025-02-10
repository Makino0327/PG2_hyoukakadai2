#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "Reset.h"

const char kWindowTitle[] = "LC1C_24_マキノハルト_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	///================================================
	/// コンストラクタ
	///================================================
	// プレイヤー
	Player* player = new Player();
	// 敵
	Enemy* enemy[kEnemyNum] = { 
		new Enemy(100.0f, 300.0f, 4.0f, 0.0f),
		new Enemy(300.0f, 300.0f, -4.0f, 0.0f) 
	};
	// シーン
	Scene* scene = new Scene();
	// リセット
	Reset* reset = new Reset(player,enemy);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// シーンの更新処理
		scene->Update(player, enemy,reset, keys, preKeys);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// シーンの描画処理
		scene->Draw(player, enemy);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();

	//デストラクタ
	delete player;
	delete enemy[0];
	delete enemy[1];
	delete scene;

	return 0;
}