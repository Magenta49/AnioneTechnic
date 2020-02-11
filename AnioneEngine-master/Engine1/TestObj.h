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
	void Update() override;
	void LateUpdate() override;
	void PlayerMove();
	void MouseInput();
	void OnCollisionEnter(GameObject * gameObject) override;
	void OnRender() override;
};

