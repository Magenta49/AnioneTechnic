#pragma once

#include <map>	
#include <list>
#include <string>
#include <typeinfo.h>
#include <d3dx9.h>

//class Component;


using namespace std;
class GameObject
{
private:

	GameObject();
	~GameObject();

	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	float degree;


	virtual void Update();
	

	//template<class T>
	//T* AddComponent();

	//template<class T>
	//T* GetComponent();

public:

	//map<string, Component *> componentMap;
	//list<Component *> componentList;


};

//template<class T>
//inline T * GameObject::AddComponent()
//{
//	auto comp = new T();
//
//	auto component = dynamic_cast<Component *>(comp);
//
//	if (component == nullptr)
//	{
//		return nullptr;
//	}
//
//	
//
//	auto componentName = typeid(comp).name();
//
//	componentMap.insert(make_pair(componentName, comp));
//	componentList insert(comp);
//
//	return comp;
//}
//
//template<class T>
//inline T * GameObject::GetComponent()
//{
//	auto componentName = typeid(T*).name();
//
//	auto pair = componentMap.find(componentName);
//
//	if (pair == componentMap.end())
//		return nullptr;
//
//	return pair->second;
//}
