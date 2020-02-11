#include "stdafx.h"
#include "Bullet.h"
#include "animation.h"
#include "Camera.h"

Bullet::Bullet() : direction({ 0.0f,0.0f }), speed(0.0f), spawnTime(clock()), aliveTime(3000)
{
}


Bullet::~Bullet()
{
}

void Bullet::Awake()
{
	//Camera::AddShake(50);
	PlaySound(L"./resource/sans.wav",NULL,SND_FILENAME | SND_ASYNC);
	Animation->SetAnimaion("Bullet");
}

void Bullet::Update()
{
	position += direction * speed;

	if (clock() - spawnTime > aliveTime)
	{
		isActive = false;
	}
}

void Bullet::OnCollisionEnter(GameObject * gameObject)
{

	if (gameObject->name == "Enemy")
	{
		Camera::AddShake(50);
		gameObject->isActive = false;
		this->isActive = false;
	}
}

void Bullet::SetOption(D3DXVECTOR2 direction, float speed)
{
	degree = D3DXToDegree(atan2(direction.y, direction.x));
	this->direction = direction;
	this->speed = speed;
}
