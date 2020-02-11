#include "stdafx.h"
#include "GameObject.h"
#include"Animation.h"
#include"GameManager.h"
#include"Scene.h"

GameObject::GameObject() :degree(0.0f), position({ 0.0f,0.0f }), scale({ 1.0f,1.0f }), isActive(true), sortingLayer(0),name("Basic")
{
	animation = new Animation();
	collider = new BoxCollider();
	animation->parent=collider->parent = this;

}


GameObject::~GameObject()
{
	delete animation;
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


void GameObject::UpdateAnimation()
{
	animation->Update();
}

GameObject * GameObject::Find(std::string name)
{
	GameObject*result = nullptr;

	//��ȸ �˻�
	auto objectList=GameManager::nowScene->GetObjectList();
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
