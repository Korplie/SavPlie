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
	void OnCollisionEnter(GameObject*gameObject) override;
	void OnDestroy()override;

	void OnRender()override;
private:
	void PlayerMove();
	void CameraMove();
	void MouseInput();
};

