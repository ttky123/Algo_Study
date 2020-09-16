#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

class MyIntVector {
public:
	MyIntVector()
		: data{ NULL }, sz{ NULL }, space{ NULL } {}
	MyIntVector(size_t init_sz) // constructor.
		: data{ new int[init_sz] }, sz{ init_sz }, space{ init_sz } {}
	MyIntVector(const MyIntVector& source) // copy constructor
		: data{ new int[source.sz] }, sz{ source.sz }, space{ source.space } {
		copy(source.data, source.data + space, data);
	}

	~MyIntVector() { delete[] data; } // destructor

	MyIntVector& operator = (const MyIntVector& source) { // = overloading
		int *new_data;
		if (this == &source)
			return *this;
		if (sz != source.sz)
		{
			new_data = new int[source.sz];
			delete[] data;
			data = new_data;
			sz = source.sz;
		}
		space = source.space;
		copy(source.data, source.data + space, data);
	}

	void operator += (const MyIntVector& source) {
		if (sz + source.sz > space)
			reserve(sz + source.sz);
		copy(source.data, source.data + source.sz, data + sz);
		sz += source.sz;
	}

	int& operator[] (int num) {
		//error»ý¼º
		if (sz <= num) {
			cout << "Error : Out Of Range." << endl;
			exit(-1);
		}
		return data[num];
	}

	MyIntVector operator + (const MyIntVector& source) {
		if (sz != source.sz) {
			cout << "Error : size is not equal.";
			exit(-2);
		}
		MyIntVector temp(sz);
		for (int i = 0; i < sz; i++)
			temp[i] = data[i] + source.data[i];
		return temp;
	}

	MyIntVector operator - (const MyIntVector& source) {
		if (sz != source.sz) {
			cout << "Error : size is not equal.";
			exit(-2);
		}
		MyIntVector temp(sz);
		for (int i = 0; i < sz; i++)
			temp[i] = data[i] - source.data[i];
		return temp;
	}

	int operator * (const MyIntVector& source) {
		if (sz != source.sz) {
			cout << "Error : size is not equal.";
			exit(-2);
		}
		int sum = 0;
		for (int i = 0; i < sz; i++)
			sum += (data[i] * source.data[i]);
		return sum;
	}

	MyIntVector& operator -() {
		for (int i = 0; i < sz; i++)
			data[i] = -data[i];
		return *this;
	}

	bool operator == (const MyIntVector source) {
		if (sz != source.sz) {
			cout << "Error : size is not equal.";
			exit(-2);
		}
		for (int i = 0; i < sz; i++) {
			if (data[i] != source.data[i])
				return false;
		}
		return true;
	}

	MyIntVector& operator ()(int num) {
		for (int i = 0; i < sz; i++)
			data[i] = num;
		return *this;
	}

	void reserve(size_t new_space) {
		if (new_space <= space) return;
		int* larger_arr = new int[new_space];
		copy(data, data + space, larger_arr);
		delete[] data;
		data = larger_arr;
		space = new_space;
	}

	void push_back(int x) {
		if (sz == 0) reserve(1);
		else if (sz == space)
			reserve(space + 1);
		data[sz] = x;
		++sz;
	}

	size_t capacity() const {
		return space;
	}

	size_t size() const {
		return sz;
	}

	bool isEmpty() const {
		if (sz == 0)
			return true;
		else
			return false;
	}

	void clear() {
		if (sz == 0)
			return;
		int * new_arr = new int[space];
		delete[] data;
		data = new_arr;
		sz = 0;
	}

private:
	int *data;
	size_t sz;
	size_t space;
};

int main()
{
	MyIntVector a, b, c;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	b.push_back(1);
	b.push_back(2);
	b.push_back(0);
	a += b;
	for (int i = 0; i < 6; i++) cout << a[i] << endl;
	cout << a.size() << b.size() << c.size() << endl;
	cout << a.capacity() << b.capacity() << c.capacity() << endl;
	return 0;
}