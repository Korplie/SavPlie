#pragma once
#include "GameObject.h"

#include<ctime>
class Bullet :
	public GameObject
{
public:
	Bullet();
	~Bullet();

	D3DXVECTOR2 direction;
	float speed;

	clock_t sTime;
	clock_t lTime;

	void Update() override;
	void Awake()override;
	void OnCollisionEnter(GameObject*gameObject) override;
	void SetOption(D3DXVECTOR2 direction,float speed);
};

