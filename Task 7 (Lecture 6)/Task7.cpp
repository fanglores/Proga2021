#include <iostream>
using namespace std;

class cls
{
private:
	int data;
public:
	cls(int v)
	{
		data = v;
	}

	void print() 
	{
		cout << data << endl;
	}
};


template <class T>
class SmartPointer
{
private:
	T* ptr;

public:

	SmartPointer()
	{
		ptr = nullptr;
	}

	SmartPointer(T* ptr)
	{
		this->ptr = ptr;
	}

	~SmartPointer()
	{
		flush();
	}

	SmartPointer(const SmartPointer& obj) = delete;
	SmartPointer& operator=(const SmartPointer& obj) = delete;

	SmartPointer(SmartPointer&& obj)
	{
		flush();

		this->ptr = obj.ptr;
		obj.ptr = nullptr;
	}

	void operator=(SmartPointer&& obj)
	{
		flush();
		this->ptr = obj.ptr;
		obj.ptr = nullptr;
	}

	T* operator->()
	{
		return this->ptr;
	}

	T& operator*()
	{
		return *(this->ptr);
	}

	T& operator[](int index)
	{
		if (index < 0)
		{
			throw(new std::exception("Negative index exception"));
		}
		return this->ptr[index];
	}

private:
	void flush()
	{
		if (ptr != nullptr)
			delete[] ptr;
	}
};

int main()
{
	SmartPointer<cls> a_sptr(new cls(1));

	a_sptr->print();

	SmartPointer<int> b_sptr(new int(100));

	cout << *b_sptr << endl;
}
