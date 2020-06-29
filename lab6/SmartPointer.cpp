//---------------------------------------------------------------------------

#pragma hdrstop

#include "SmartPointer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

template <typename T>
class SmartPointer
{
	T *obj;
public:

	SmartPointer(T *x)
	{
        this->obj = x;
	}
	~SmartPointer()
	{
		delete obj;
	}


	T* operator->()
	{
	 return obj;
	}

	T& operator* ()
	{
	 return *obj;
	}
};

