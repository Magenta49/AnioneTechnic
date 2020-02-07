#include "stdafx.h"
#include "animation.h"
#include "GraphicManager.h"

void animation::Update()
{
	if (timePerFrame < 0)
		return;

	auto curTime = clock();

	if (lastChangeTime + timePerFrame < clock())
	{
		lastChangeTime = curTime;

		if (nowFrame.x + frameSize.x + 1.0f>= imageSize.x)
		{
			nowFrame.x = 0;
		}
		else
		{
			nowFrame.x += frameSize.x;
		}

		
	}

}

void animation::SetAnimaion(std::string textureName)
{
	this->textureName = textureName;
	lastChangeTime = clock();
	imageSize = GraphicManager::GetTextureSize(textureName);

	if (textureName == "TestAnimaion");
	{
		//clock_t 단위는 1초에 1000
		timePerFrame = 1000;
		frameSize = { 100,100 };
	}
}

RECT animation::GetRect()
{
	int left = nowFrame.x;
	int top = 0;
	int right = left + frameSize.x;
	int bottom = top + frameSize.y;

	return RECT{ left,top,right,bottom };
}

animation::animation() : textureName(""),imageSize({0.0f,0.0f}), frameSize({0.0f,0.0f}),nowFrame({ 0.0f,0.0f }),lastChangeTime(0),timePerFrame(-1)
{
}


animation::~animation()
{
}
