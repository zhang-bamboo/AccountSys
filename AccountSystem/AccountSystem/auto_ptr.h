#ifndef _AUTODEL_PTR_H_
#define _AUTODEL_PTR_H_

template<typename T>
class AutoPtr {
public:
	AutoPtr();
	AutoPtr(T* an_ptr);
	AutoPtr(AutoPtr<T> &anto_p);
	~AutoPtr();
	void reset(T* an_ptr);
	T* release();
	T* get();
private:
	T* ptr=0;
};

#include"auto_ptr.cpp"

#endif
