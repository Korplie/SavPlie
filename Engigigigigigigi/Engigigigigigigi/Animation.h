#pragma once

#include<d3dx9.h>
#include<ctime>
#include<string>

class Animation
{
public:

	std::string textureName;

	D3DXVECTOR2 imageSize;
	D3DXVECTOR2 frameSize;
	D3DXVECTOR2 nowFrame;

	clock_t lastChangeTime;//젱ㄹ 최근 프레임 변경 시간
	clock_t timePerFrame;//한 프레임당 시간

	RECT GetRect();

	void Update();
	void SetAnimation(std::string textureName);
	Animation();
	~Animation();
};

