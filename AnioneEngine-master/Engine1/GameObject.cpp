#include "stdafx.h"
#include "GameObject.h"
#include "animation.h"
#include "BoxCollider.h"
#include "GameManager.h"
#include "Scene.h"

GameObject::GameObject() :
	position({ 0.0f, 0.0f }),
	scale({ 1.0f, 1.0f }),
	degree(0.0f),
	isActive(true),
	sortingLayer(0),
	name("NONE")
{
	Animation = new animation();
	collider = new BoxCollider();

	Animation->parent = collider->parent = this;
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

void GameObject::OnRender()
{

}

void GameObject::OnCollisionEnter(GameObject * gameObject)
{
}

GameObject * GameObject::Find(std::string name)
{
	GameObject * result = nullptr;

	//리스트 순회, 검색
	auto objectList = GameManager::nowScene->GetObjectList();

	for (auto gameObject : objectList)
	{
		if (gameObject->name == name)
		{
			result = gameObject;
			break;
		}
	}

	return result;
}

void GameObject::UpdateAnimation()
{
	Animation->Update();
}
