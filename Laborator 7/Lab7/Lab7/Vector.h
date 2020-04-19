#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector
{
private:
	unsigned int allocated_size;
	unsigned int elements;
	T *data;

	void doResize()
	{
		if (this->elements == this->allocated_size - 1)
		{
			T *newBuffer = new T[this->allocated_size * 2];
			for (unsigned int i = 0; i < this->elements; i++)
			{
				newBuffer[i] = this->data[i];
			}
			delete[] this->data;
			this->data = newBuffer;
			this->allocated_size *= 2;
		}
	}

public:
	Vector(unsigned int allocated_size = 10)
	{
		this->allocated_size = allocated_size;
		this->elements = 0;
		this->data = new T[this->allocated_size];
	}

	void push(T elem) {
		this->doResize();
		this->data[elements++] = elem;
	}

	T pop() {
		if (this->elements > 0) {
			return this->data[elements - 1];
		}
	}

	void remove(unsigned int index) {
		if (index < this->elements) {
			for (unsigned int i = index; i < this->elements - 1; i++) {
				this->data[i] = this->data[i + 1];
			}
			this->elements--;
		}
	}

	void insert(T elem, unsigned int index) {
		this->doResize();
		if (index == this->elements) {
			this->push(elem);
		}
		else if (index < this->elements) {
			for (unsigned int i = this->elements; i > index; i--) {
				this->data[i] = this->data[i - 1];
			}
			this->data[index] = elem;
			++this->elements;
		}
	}

	void sort(bool(*compare)(const T& first, const T& second) = nullptr) {
		for (unsigned int i = 0; i < this->elements - 1; ++i) {
			for (unsigned int j = 0; j < this->elements - i - 1; ++j) {
				bool result = compare != nullptr ? compare(this->data[j], this->data[j+1]) : this->data[j] < this->data[j + 1];
				if (result) {
					T tmp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = tmp;
				}
			}
		}
	}

	const T& get(unsigned int index) {
		if (index < this->elements) {
			return this->data[index];
		}
	}

	void set(T value, unsigned int index) {
		if (index < this->elements) {
			this->data[index] = value;
		}
	}

	unsigned int count() {
		return this->elements;
	}

	int firstIndexOf(T element, bool(*compare)(const T& first, const T& second) = nullptr) {
		for (unsigned int i = 0; i < this->elements; ++i) {
			bool result = compare != nullptr ? compare(element, this->data[i]) : element == this->data[i];
			if (result) {
				return i;
			}
		}
		return -1;
	}

	void print() {
		for (unsigned int i = 0; i < this->elements; ++i) {
			cout << this->data[i] << " ";
		}
		cout << endl;
	}

};

