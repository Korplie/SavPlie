#pragma once

#include<list>
#include<d3dx9.h>
#include"GameManager.h"
#include"GameObject.h"
class GameObject;

class Scene
{
public:
	Scene();
	~Scene();

	std::string nextSceneName;

	std::list<GameObject*>&GetObjectList();
	void Update();
	void LateUpdate();
	std::list<GameObject*>objectList;
	void AddGameObject(GameObject *obj);
	void CheackNextScene();
	void CollisionCheck();
	void ChangeScene(std::string sceneName);

private:

	bool AABB(GameObject*obj1, GameObject*obj2);


};

template <class T>
T* Instantiate(D3DXVECTOR2 position)
{
	auto obj = new T;
	auto gameObject = dynamic_cast<GameObject*>(obj);
	if (gameObject == nullptr)
	{
		delete obj;
		return nullptr;
	}
	gameObject->position = position;
	GameManager::nowScene->AddGameObject(obj);



	return obj;
}

