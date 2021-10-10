#include <iostream>
using namespace std;

template <typename T>
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
	int a = 10;

	SmartPointer<int> a_sptr(&a);
	SmartPointer<int> b_sptr(&a);
	SmartPointer<int> m_ptr(new int[5]);
	
	cout << *a_sptr << endl;
	cout << *b_sptr << endl;

	delete &b_sptr;

	cout << *a_sptr << endl;
}
