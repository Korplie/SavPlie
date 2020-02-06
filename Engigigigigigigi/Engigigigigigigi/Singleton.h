#pragma once

template<class T>
class Singleton
{
private:
	static T*instansce;
public:
	vir~Singleton()
	{

	}
	static T * Get()
	{
		if (instansce != nullptr)
			return instansce;
		instansce = new T();
	}

};

template<class T>
T* Singleton<T>::instansce = nullptr;