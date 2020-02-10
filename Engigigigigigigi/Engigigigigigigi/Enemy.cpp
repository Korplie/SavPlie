#include "stdafx.h"
#include "Enemy.h"

#include"Animation.h"
Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::Awake()
{
	sortingLayer = 1;
	animation->SetAnimation("Enemy");
	scale.x += 1;
	scale.y = scale.x;
}
