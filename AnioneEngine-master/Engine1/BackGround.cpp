#include "stdafx.h"
#include "BackGround.h"

#include "animation.h"

BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

void BackGround::Awake()
{
	Animation->SetAnimaion("BackGround");
}
