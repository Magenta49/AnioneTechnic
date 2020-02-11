#pragma once

#include <d3dx9.h>
#include <ctime>
#include <string>

class GameObject;

class animation
{
public:
	std::string textureName;

	GameObject * parent;

	D3DXVECTOR2 imageSize;//애니메이션의 전체크기
	D3DXVECTOR2 frameSize;//한프레임의 사이즈
	D3DXVECTOR2 nowFrame;//현재 프레임의 위치
	
	clock_t lastChangeTime;//가장 최근 프레임변경 시간
	clock_t timePerFrame;//한 프레임당 시간

	void Update();
	void SetAnimaion(std::string textureName);
	RECT GetRect();


	animation();
	~animation();
};

