#include "stdafx.h"
#include "Scene.h"
#include <vector>
#include "BoxCollider.h"
#include "TestObj.h"
#include "BackGround.h"
#include "Enemy.h"


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
	auto iter = objectList.begin();
	while (iter != objectList.end())
	{
		auto obj = *iter;
		if (obj->isActive)
		{
			obj->Update();
			obj->UpdateAnimation();
			iter++;

		}
		else
		{
			obj->OnDestroy();
			delete obj;
			iter = objectList.erase(iter);
		}
	}

	/*for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
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
	}*/

	CollisionCheck();

}

void Scene::lateUpdate()
{
	for (auto obj : objectList)
	{
		obj->LateUpdate();
	}
}

void Scene::CollisionCheck()
{
	auto size = objectList.size();
	if (size < 1)
		return;

	vector<GameObject *> vec(size);
	int idx = 0;
	for (auto obj : objectList)
	{
		vec[idx++] = obj;
	}


	for (int i = 0; i < size - 1;i++)
	{
		auto obj1 = vec[i];

		if (!obj1->isActive)
			continue;

		for (int j = i;j < size;j++)
		{
			auto obj2 = vec[j];

			if (!obj2->isActive)
				continue;

			if (obj1 == obj2)
				continue;

			//충돌체크
			if (AABB(obj1, obj2))
			{
				//exit(1);
				obj1->OnCollisionEnter(obj2);
				obj2->OnCollisionEnter(obj1);
			}
		}
	}



}

void Scene::ChangeScene(std::string sceneName)
{
	for (auto obj : objectList)
	{
		obj->isActive = false;

	}

		Update();

			if (sceneName == "Maina")
			{
				mciSendString(L"close sansBGM", 0, 0, 0);
					mciSendString(L"open ./resource/sansBGM.wav type mpegvideo alias sansBGM", 0, 0, 0);
				mciSendString(L"play sansBGM repeat", 0, 0, 0);

				mciSendString(L"setaudio sansBGM volume to 300", 0, 0, 0);

				Instantiate<TestObj>({ 0.0,0.0 });
				Instantiate<BackGround>({ 0.0f,0.0f });
				Instantiate<Enemy>({ 500,500 });
				Instantiate<Enemy>({ -500,-500 });
				Instantiate<Enemy>({ 500,-500 });
				Instantiate<Enemy>({ -500,500 });
				Instantiate<Enemy>({ 600,800 });
			}
}

bool Scene::AABB(GameObject * obj1, GameObject * obj2)
{
	RECT result;
	auto rect1 = obj1->collider->GetRect();
	auto rect2 = obj2->collider->GetRect();



	return 	IntersectRect(&result, &rect1, &rect2);;
}
