

template<typename T>
AutoPtr<T>::AutoPtr()
{
}

template<typename T>
AutoPtr<T>::AutoPtr(T * an_ptr)
{
	ptr = an_ptr;
}

template<typename T>
AutoPtr<T>::AutoPtr(AutoPtr<T>& anto_p)
{
	ptr = anto_p.ptr;
}

template<typename T>
AutoPtr<T>::~AutoPtr()
{
	if(ptr!=0)
		delete ptr;
}

template<typename T>
void AutoPtr<T>::reset(T * an_ptr)
{
	if (ptr != an_ptr&&ptr != 0)
		delete ptr;		
	ptr = an_ptr;
}

template<typename T>
T * AutoPtr<T>::release()
{
	T* tptr = ptr;
	ptr = 0;
	return tptr;
}

template<typename T>
T * AutoPtr<T>::get()
{
	return ptr;
}
