#pragma once
#include <iostream>
using namespace std;
class myvector
{
public:
	//constructor & copy constructor & destructor
	myvector(int init_Size = 0)	//default constructor
	{
		cout << "생성자 호출\n";
		data = new int[init_Size];
		capacity = init_Size;
		size = 0;

		for (int i = 0; i < init_Size; i++)
			data[i] = 0;
	}

	myvector(const myvector & source)	//copy constructor
	{
		data = new int[source.size];
		size = source.size;
		capacity = source.capacity;

		copy(source.data, source.data + capacity, data);
	}

	~myvector()	// destructor 
	{
		delete[] data;
	}

	//operator overloading
	myvector & operator = (const myvector & source)
	{	//operator =
		int *temp;

		if (this == &source)
			return *this;
		else
		{
			temp = new int[source.size];
			delete[] data;
			data = temp;
			size = source.size;
		}
		capacity = source.capacity;
		copy(source.data, source.data + capacity, data);
	}

	int &operator[](int i)
	{	//operator []
		if (capacity <= i)
		{
			perror("Capacity exceed!");
			exit(-1);
		}
		return data[i];
	}

	myvector operator + (myvector & source)const
	{
		if (size != source.size)
		{
			perror("Sizes not identical!");
			exit(-1);
		}
		else
		{
			myvector tmp = myvector(size);
			for (int i = 0; i < size; i++)
				tmp.data[i] = data[i] + source.data[i];
			return tmp;
		}
	}

	myvector operator - (myvector & source)const
	{
		if (size != source.size)
		{
			perror("Sizes not identical!");
			exit(-1);
		}
		else
		{
			myvector tmp = myvector(size);
			for (int i = 0; i < size; i++)
				tmp.data[i] = data[i] - source.data[i];
			return tmp;
		}
	}

	myvector& operator -(myvector & source)
	{
		myvector tmp = myvector(size);
		for (int i = 0;i < size; i++)
			data[i] - data[i];
		return tmp;
	}

	int operator *(myvector & source)const
	{
		if (size != source.size)
		{
			perror("Sizes not identical!");
			exit(-1);
		}
		else
		{
			int result = 0;
			for (int i = 0; i < size; i++)
			{
				result += data[i] * source.data[i];
				
			}
			return result;
		}
		
	}
	bool operator == (myvector& source) const
	{
		if (size == source.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (data[i] == source.data[i])
					return true;
				else
				{
					return false;
					break;
				}
			}
		}
		else
		{
			perror("Sizes not identical!");
			exit(-1);
		}
	}
	myvector& operator ()(int value) 
	{
		for (int i = 0; i < size; i++)
			data[i] = value;
		return *this;
		
	}

	void push_back(int value)
	{
		if (full())
		{
			int *temp = new int[capacity];
			for (int i = 0; i < size; i++)
				temp[i] = data[i];
			delete[]data;

			capacity *= 2;
			data = new int[capacity];

			for (int i = 0; i < size; i++)
				data[i] = temp[i];
			delete[]temp;
		}
		data[size++] = value;
	}

	int get_capacity()
	{
		return capacity;
	}
	int get_size()
	{
		cout << size;
		return size;
	}

	bool is_empty()
	{
		return !size;
	}
	void clear() 
	{
		if (size == 0)
			return;
		delete[] data;
		data = NULL;
		size = 0;
		capacity = 0;
	}

	bool full()
	{
		return capacity == size;
	}

private:
	int *data;
	int capacity, size;
};