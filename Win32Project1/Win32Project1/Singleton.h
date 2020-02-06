#pragma once

template<class T>
class Singleton
{
public:


private:

	static T *instance;

public:

	virtual ~Singleton()
	{

	}

	static T * GET()
	{
		if (instance != nullptr)
			return instance;
		instance = new T();
	}
};

template <class T>
T * Singleton<T>::instance = nullptr;

