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

	D3DXVECTOR2 imageSize;//�ִϸ��̼��� ��üũ��
	D3DXVECTOR2 frameSize;//���������� ������
	D3DXVECTOR2 nowFrame;//���� �������� ��ġ
	
	clock_t lastChangeTime;//���� �ֱ� �����Ӻ��� �ð�
	clock_t timePerFrame;//�� �����Ӵ� �ð�

	void Update();
	void SetAnimaion(std::string textureName);
	RECT GetRect();


	animation();
	~animation();
};

