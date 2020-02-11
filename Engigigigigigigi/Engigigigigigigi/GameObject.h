#pragma once

#include<map>
#include<list>
#include<string>
#include<typeinfo>
#include"BoxCollider.h"
#include<mmsystem.h>


#include<d3dx9.h>
using namespace std;
class Component;
class Animation;
class boxCollider;

class GameObject
{
public:

	GameObject();
	~GameObject();

	std::string name;

	Animation*animation;
	BoxCollider*collider;

	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	float degree;

	int sortingLayer;

	bool isActive;



	virtual void Awake();
	virtual void Update();
	virtual void LateUpdate();
	virtual void OnDestroy();
	virtual void OnRender();

	virtual void OnCollisionEnter(GameObject*gameObject);

	void UpdateAnimation();

	static GameObject * Find(std::string name);

	/*template<class T>
	T* AddComponent();

	template<class T>
	T*GetComponent();*/

private:
	/*std::map<std::string, Component*>componentMap;
	std::list<Component*>componentlist;*/
};
//
//template<class T>
//inline T * GameObject::AddComponent()
//{
//	auto comp = new T();
//
//	auto component = dynamic_cast<Component*>(comp);
//
//	if (component == nullptr)
//	{
//		return nullptr;
//	}
//	auto componentName typeid(comp).name();
//
//	componentMap.insert(std::make_pair(componentName, comp));
//	componentlist.insert(comp);
//	return NULL;
//}
//
//template<class T>
//inline T * GameObject::GetComponent()
//{
//	auto componentName typeid(T*).name();
//
//	auto pair = componentMap.find(componentName);
//
//	if (pair == componentMap.end())
//		return nullptr;
//
//	return pair->second;
//
//
//	return NULL;
//}
