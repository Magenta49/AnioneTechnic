#pragma once
#include <d3dx9.h>
static class Camera
{
public:
	Camera();
	~Camera();

	static void Update();

	static int screenWidth;
	static int screenHeight;

	static D3DXVECTOR2 position;
	static D3DXMATRIX matrix;
	static D3DXVECTOR2 scale;
	static float degree;

	static void AddShake(float Shake);

	static float shake;
	
};

