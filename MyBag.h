#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
template <class T>
class MyBag {
private:
	vector<T> array;
public:
	MyBag()
	{
		array.clear();
	}
	MyBag(T* a, int newSize)
	{
		array.resize(newSize);
		for (int i = 0; i < array.size(); i++)
			array[i] = a[i];
	}
	void display() const
	{
		for (int i = 0; i < array.size(); i++)
			cout << array[i] << '\n';
	}
	void sortArray()
	{
		sort(array.begin(), array.end());
	}
	void insert(T value)
	{
		array.insert(value);
	}
	int search(T value)
	{
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] == value)
			{
				return i;
			}
		}
		return -1;
	}
	void remove(int index)
	{
		array.erase(index);
	}
	void clear()
	{
		array.clear();
	}
};
