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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}

void Scene::Update()
{
	for (auto iter = objectList.begin();iter!=objectList.end();iter++)
	{
		auto obj = *iter;
		obj->Update();
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

void Scene::AddGameObject(GameObject*obj)
{
	objectList.push_back(obj);
	obj->Awake();
}
