#include "stdafx.h"
#include "Scene.h"
#include<vector>
#include"BoxCollider.h"
#include"TestObj.h"
#include"BackGround.h"
#include"InputManager.h"
#include"Enemy.h"

Scene::Scene():nextSceneName("")
{
}


Scene::~Scene()
{
}

std::list<GameObject*>& Scene::GetObjectList()
{
	return objectList;
	// TODO: 여기에 반환 구문을 삽입합니다.
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
			iter=objectList.erase(iter);
		}
	}
	

	

	
}

void Scene::LateUpdate()
{
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

void Scene::CheackNextScene()
{
	if (nextSceneName != "")
	{
		ChangeScene(nextSceneName);
		nextSceneName = "";
	}
}

void Scene::CollisionCheck()
{
	auto size = objectList.size();
	if (size < 1)
		return;

	vector<GameObject*>vec(size);
	int idx = 0;
	for (auto obj : objectList)
	{
		vec[idx++] = obj;
	}

	for (int i = 0;i < size - 1;i++)
	{
		auto obj1 = vec[i];
		if (!obj1->isActive)
			continue;

		for (int j = 0;j < size;j++)
		{
			auto obj2 = vec[j];
			if (!obj2->isActive)
				continue;

			if (obj1 == obj2)
				continue;


			if (AABB(obj1, obj2))
			{
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

	if (sceneName == "Main")
	{

		mciSendString(L"close BGM", 0, 0, 0);
		mciSendString(L"open ./Resource/Sound/BGM.wav type mpegvideo alias BGM", 0, 0, 0);
		mciSendString(L"play BGM", 0, 0, 0);

		mciSendString(L"staudio BGM volume to 300", 0, 0, 0);

		//PlaySound(L"Resource/Sound/BS.wav", NULL, SND_FILENAME | SND_ASYNC);
		Instantiate<TestObj>({ 0.0f,0.0f });
		Instantiate<BackGround>({ 0.0f,0.0f });
		Instantiate < Enemy >({ 200,200 });
		Instantiate < Enemy >({ -200,200 });
		Instantiate < Enemy >({ -200,-200 });
		Instantiate < Enemy >({ 200,-200 });
		Instantiate < Enemy >({ 400,400 });
		Instantiate < Enemy >({ -400,400 });
		Instantiate < Enemy >({ -400,-400 });
		Instantiate < Enemy >({ 400,-400 });
		Instantiate < Enemy >({ 400,0 });
		Instantiate < Enemy >({ -400,0 });
		Instantiate < Enemy >({ 0,-400 });
		Instantiate < Enemy >({ 0,400 });
	}
}

bool Scene::AABB(GameObject * obj1, GameObject * obj2)
{

	RECT result;
	auto rc1 = obj1->collider->GetRect();
	auto rc2 = obj2->collider->GetRect();
	
	return IntersectRect(&result, &rc1, &rc2);
}
