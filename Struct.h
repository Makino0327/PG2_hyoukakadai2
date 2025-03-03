#pragma once

// 敵の数
const int kEnemyNum = 2;

// 構造体
typedef struct Vector2
{
    float x;
	float y;
	// 減算
	Vector2 operator-(const Vector2& other) const {
		return Vector2{ x - other.x, y - other.y };
	}
}Vector2;

// シーン
enum Scenes
{
	TITLE,
	GAME,
	CLEAR,
	GAME_OVER,
};