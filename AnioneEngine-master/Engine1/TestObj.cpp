#include "stdafx.h"
#include "TestObj.h"

#include "animation.h"

TestObj::TestObj()
{
}


TestObj::~TestObj()
{
}

void TestObj::Updatae()
{
}

void TestObj::Awake()
{
	Animation->SetAnimaion("TestAnimaion");
}
