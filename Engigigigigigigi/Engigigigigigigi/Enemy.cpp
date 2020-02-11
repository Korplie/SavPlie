#include "stdafx.h"
#include "Enemy.h"
#include"TestObj.h"
#include"Animation.h"
#include"Camera.h"
Enemy::Enemy():target(nullptr)
{
}


Enemy::~Enemy()
{
}

void Enemy::Awake()
{
	sortingLayer = 1;
	animation->SetAnimation("Enemy");
	name = "Enemy";

	target=static_cast<TestObj*>(GameObject::Find("Player"));

	/*scale.x += 1;
	scale.y = scale.x;*/
}

void Enemy::OnDestroy()
{
	Camera::AddShake(20);
	PlaySound(L"./Resource/Sound/ATS.wav.", NULL, SND_FILENAME | SND_ASYNC);
}

void Enemy::Update()
{
	if (target->isActive == true) {
		auto diff = target->position - position;
		D3DXVECTOR2 result;
		D3DXVec2Normalize(&result, &diff);
		position += result*1.0f;
	}
	

}
