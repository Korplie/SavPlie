#include "stdafx.h"
#include "Camera.h"

int Camera::screenWidth=1280;
int  Camera::screenHeight=720;
D3DXMATRIX Camera::matrix = D3DXMATRIX();
D3DXVECTOR2 Camera::position = { 0.0f,0.0f };
D3DXVECTOR2 Camera::scale = { 1.0f,1.f };

float Camera::degree = 0.0f;
Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::Update()
{
	//scale.y += 0.01f;
	//scale.x = scale.y;

	//degree += 1.0f;

	D3DXMATRIX centerMatrix, positionMatrix, scaleMatrix, rotatematrix;

	D3DXMatrixTranslation(&centerMatrix, screenWidth*0.5f, screenHeight*0.5f, 0.0f);
	D3DXMatrixTranslation(&positionMatrix, -position.x,-position.y, 0.0f);
	D3DXMatrixScaling(&scaleMatrix, scale.x, scale.y, 0.0f);
	D3DXMatrixRotationZ(&rotatematrix,D3DXToRadian(degree));


	matrix = scaleMatrix*positionMatrix*rotatematrix*centerMatrix;
}



