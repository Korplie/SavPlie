#include "stdafx.h"
#include "TestObj.h"
#include"Animation.h"

TestObj::TestObj()
{
}


TestObj::~TestObj()
{
}

void TestObj::Awake()
{
	animation->SetAnimation("TestAni");
}

void TestObj::Update()
{

}
