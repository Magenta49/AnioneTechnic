#include "stdafx.h"
#include "GameObject.h"
#include "animation.h"

GameObject::GameObject() : 
	position({ 0.0f, 0.0f }), 
	scale({ 0.0f, 0.0f }),
	degree(0.0f), 
	isActive(true)
{
	Animation = new animation();
}

GameObject::~GameObject()
{
	delete Animation;
}

void GameObject::Awake()
{
}

void GameObject::Update()
{
}

void GameObject::LateUpdate()
{
}

void GameObject::OnDestroy()
{
}

void GameObject::UpdateAnimation()
{
	Animation->Update();
}
