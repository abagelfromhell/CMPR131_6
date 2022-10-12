#pragma once
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
	bool empty()
	{
		return array.empty();
	}
	MyBag(T* a, int newSize)
	{
		array.resize(newSize);
		for (int i = 0; i < array.size(); i++)
			array[i] = a[i];
	}
	void display() const
	{
		cout << "\n";
		for (int i = 0; i < array.size(); i++)
			cout << "\t\t\t[" << i << "] - " << array[i] << '\n';
	}
	void sortArray()
	{
		sort(array.begin(), array.end());
	}
	void insert(T value)
	{
		array.push_back(value);
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
		int i = 0;
		for (auto it = array.begin(); it != array.end(); it++)
		{
			i++;
			if (i == index)
			{
				array.erase(it);
				return;
			}
		}
	}
	void clear()
	{
		array.clear();
	}
	int size()
	{
		int size = array.size();
		return size;
	}
	T at(int index)
	{
		return array[index];
	}
};
