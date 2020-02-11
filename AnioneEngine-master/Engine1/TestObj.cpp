#include "stdafx.h"
#include "TestObj.h"

#include "animation.h"
#include "InputManager.h"
#include "Camera.h"
#include "Scene.h"
#include "Bullet.h"
#include "Enemy.h"
#include "GraphicManager.h"

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
	name = "Player";
	Animation->SetAnimaion("TestAnimaion");
	sortingLayer = 1;
}

void TestObj::Update()
{
	PlayerMove();
	MouseInput();

	Camera::position = position;
	position.x += 5.0f;
	degree += 5.0f;
	if (degree > 360.0f)
		degree -= 360.0f;
	
	/*float scaleVal = abs(sin(D3DXToRadian(degree) * 5.0f) * 2.0f) + 0.5f;
	scale.x = scale.y = scaleVal;*/
}

void TestObj::LateUpdate()
{
	position.x -= 5.0f;
}

void TestObj::PlayerMove()
{
	if (InputManager::GetKey(InputManager::KeyCode::W))
	{
		position.y -= 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::S))
	{
		position.y += 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::A))
	{
		position.x -= 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::D))
	{
		position.x += 5.0f;
	}

}

void TestObj::MouseInput()
{
	auto mousePosition = InputManager::mousePosition;

	auto diff = mousePosition - position;

	auto radian = atan2(diff.y, diff.x);

	degree = D3DXToDegree(radian);
	
	D3DXVECTOR2 normal;

	D3DXVec2Normalize(&normal, &diff);

	if (InputManager::GetKeyDown(InputManager::KeyCode::mouse0))
	{
		auto bullet = Instantiate <Bullet>(position);
		if (bullet != nullptr)
		{
			bullet->SetOption(normal, 5.0f);
		}
		
	}

	if (InputManager::GetKeyDown(InputManager::KeyCode::mouse1))
	{
		Instantiate<Enemy>({ 500,500 });
		Instantiate<Enemy>({ -500,-500 });
		Instantiate<Enemy>({ 500,-500 });
		Instantiate<Enemy>({ -500,500 });
		Instantiate<Enemy>({ 600,800 });
	}
}

void TestObj::OnCollisionEnter(GameObject * gameObject)
{

	if (gameObject->name == "Enemy")
	{
		gameObject->isActive = false;
		this->isActive = false;
	}
}

void TestObj::OnRender()
{
	GraphicManager::RenderText("하위하위", { 0.0f,0.0f });
}
