#include<iostream>
#include<stdlib.h>
using namespace std;
template<typename T>
class Auto_ptr{
private:
	T *_ptr;
public:
    Auto_ptr(T * ptr)
		:_ptr(ptr)
	{}
	~Auto_ptr()
	{
		delete _ptr;
	}

	T &operator *()
	{
		return *_ptr;
	}
	T *operator ->()
	{
		return _ptr;
	}
	*Auto_ptr(Auto_ptr<T> &s)
		:_ptr(s._ptr)
	{
		s._ptr = NULL;
	}
	Auto_ptr<T> &operator = (Auto_ptr<T> &s)
	{
		if(_ptr != ptr){
			delete _ptr;
			_ptr = s._ptr;
			s._ptr = NULL;
		}
		return *this;
	}

};
template<typename T>

class Scoped_ptr{
private:
	T *_ptr;
	Scoped_ptr(Scoped_ptr<T> &s)
		:_ptr(s._ptr)
	{
		s._ptr = NULL;
	}
	Scoped_ptr<T> &operator = (Scoped_ptr<T> &s)
	{
		if(_ptr != ptr){
			delete _ptr;
			_ptr = s._ptr;
			s._ptr = NULL;
		}
		return *this;
	}

public:
    Scoped_ptr(T * ptr)
		:_ptr(ptr)
	{}
	~Scoped_ptr()
	{
		delete _ptr;
	}

	T &operator *()
	{
		return *_ptr;
	}
	T *operator ->()
	{
		return _ptr;
	}
};
template<typename T>

class Shared_ptr{
private:
	T* _ptr;
	int* _pcount;
public:
	Shared_ptr(T *ptr)
		:_ptr(ptr)
		,_pcount(new int(1))
	{}
	Shared_ptr(Shared_ptr<T> &s)
		:_ptr(s._ptr)
		,_pcount(s._pcount)
	{
		(*_pcount)++;
	}
	Shared_ptr<T> operator = (Shared_ptr<T> &s)
	{
		if(_ptr != s._ptr){
			(*_pcount)--;
			if(*_pcount == 0){
				delete _ptr;
				delete _pcount;
			}
			_ptr = s._ptr;
			_pcount = s._pcount;
			(*_pcount)++;
		}
		return *this;
	}
};
void test()
{
	Auto_ptr<char> s1("asdf");
	Auto_ptr<char> s2(s1);

}
int main()
{
	test();
	system("pause");
	return 0;
}