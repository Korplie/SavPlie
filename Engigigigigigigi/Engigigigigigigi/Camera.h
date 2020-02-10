#pragma once

#include<d3dx9.h>
static class Camera
{
public:
	Camera();
	~Camera();

	static void Update();

	static D3DXVECTOR2 position;
	static D3DXMATRIX matrix;
	static D3DXVECTOR2 scale;
	static float degree;

	static int screenWidth;
	static int screenHeight;
};

