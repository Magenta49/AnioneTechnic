#pragma once
#include "GameObject.h"
class TestObj :
	public GameObject
{
public:
	TestObj();
	~TestObj();
	void Updatae();

	void Awake() override;
};

