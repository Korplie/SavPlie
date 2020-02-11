#pragma once
#include "GameObject.h"

class TestObj;
class Enemy :
	public GameObject
{
public:
	Enemy();
	~Enemy();

	void Awake()override;
	void OnDestroy()override;
	void Update()override;
	TestObj*target;
	
};

