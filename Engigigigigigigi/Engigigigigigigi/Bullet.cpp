#include "stdafx.h"
#include "Bullet.h"
#include"Animation.h"
#include"Camera.h"

Bullet::Bullet():direction({0.0f,0.0f}),speed(0),sTime(clock()),lTime(3000)
{
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	position += direction*speed;

	if (clock() - sTime > lTime)
	{
		isActive = false;
	}
}

void Bullet::Awake()
{
	PlaySound(L"./Resource/Sound/BS.wav.",NULL,SND_FILENAME|SND_ASYNC);
	animation->SetAnimation("Bullet");
}

void Bullet::OnCollisionEnter(GameObject * gameObject)
{
	
	if (gameObject->name == "Enemy")
	{
		isActive = false;
		gameObject->isActive = false;
		Camera::AddShake(20);
	}
}

void Bullet::SetOption(D3DXVECTOR2 direction, float speed)
{
	degree = D3DXToDegree(atan2(direction.y, direction.x));
	this->direction = direction;
	this->speed = speed;
}
