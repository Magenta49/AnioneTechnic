#pragma once
#include "GameObject.h"
class TestObj;

class Enemy :
	public GameObject
{
public:
	Enemy();
	~Enemy();

	void Awake() override;
	void Update() override;
	void OnDestroy() override;

private:

	TestObj* target;

};

