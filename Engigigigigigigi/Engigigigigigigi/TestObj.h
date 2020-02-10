#pragma once
#include "GameObject.h"
class TestObj :
	public GameObject
{
public:
	TestObj();
	~TestObj();

	void Awake() override;
	void Update()override;
	void LateUpdate() override;
private:
	void PlayerMove();
	void CameraMove();
	void MouseInput();
};

