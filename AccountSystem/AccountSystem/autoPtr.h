#ifndef _AUTOD_PTR_H_
#define _AUTOD_PTR_H_
#include<memory>
//reload copy construct function and operator= ,for container
template<typename T>
class AutoPtr:public std::auto_ptr<T>
{
public:
	AutoPtr()
	{
		reset((T*)0);
	}
	AutoPtr(T* ptr)
	{
		reset(ptr);
	}
	AutoPtr(const AutoPtr<T>& _Right)
	{
		reset(_Right.get());
	}

	AutoPtr<T>& operator=(AutoPtr<T>& _Right) _THROW0()
	{	
		reset(_Right.get());
		return (*this);
	}
};


#endif
