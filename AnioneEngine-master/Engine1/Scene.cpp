#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}

std::list<GameObject*>& Scene::GetObjectList()
{
	return objectList;
}
	// TODO: 여기에 반환 구문을 삽입합니다.

void Scene::AddGameObject(GameObject * obj)
{
	objectList.push_back(obj);
	obj->Awake();
}

void Scene::Update()
{
	for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
	{
		auto obj = *iter;

		if (!obj->isActive)
		{
			obj->OnDestroy();
			objectList.erase(iter--);
			delete obj;
		}
		else
		{
			obj->Update();
			obj->UpdateAnimation();
		}
	}

	for (auto obj : objectList)
	{
		obj->LateUpdate();
	}
}
