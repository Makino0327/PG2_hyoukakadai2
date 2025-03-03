#pragma once
#include<Novice.h>
#include"Struct.h"
#include "Player.h"
#include "Enemy.h"
#include "Reset.h"

class Scene
{
private:
	//シーン管理変数
	int scene_;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Scene();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="player">プレイヤー</param>
	/// <param name="enemy">敵</param>
	/// <param name="reset">リセット</param>
	/// <param name="keys">キーを受け取る</param>
	/// <param name="preKeys">前のキーを受け取る</param>
	void Update(Player *player,Enemy *enemy[kEnemyNum],Reset *reset, char* keys, char* preKeys);

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="player">プレイヤー</param>
	/// <param name="enemy">敵</param>
	void Draw(Player *player, Enemy *enemy[kEnemyNum]);
};


