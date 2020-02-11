#include "stdafx.h"
#include "Enemy.h"
#include "animation.h"

#include "TestObj.h"

Enemy::Enemy() : target(nullptr)
{
}


Enemy::~Enemy()
{
}

void Enemy::Awake()
{
	name = "Enemy";
	sortingLayer = 1;
	Animation->SetAnimaion("Enemy");

	GameObject::Find("Player");

	target = static_cast<TestObj *>(GameObject::Find("Player"));


}

void Enemy::Update()
{
	auto diff = target->position - position;
	D3DXVECTOR2 result;
	D3DXVec2Normalize(&result, &diff);

	position += result * 3.0f;
}

void Enemy::OnDestroy()
{
	PlaySound(L"./resource/marin.wav", NULL, SND_FILENAME | SND_ASYNC);
}
