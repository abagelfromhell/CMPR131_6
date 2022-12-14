#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

	class MyBag2 {
	private:
		vector<int> array;
	public:
		//Preconditions: N/A
		//Postconditions: clears array
		MyBag2()
		{
			array.clear();
		}
		//Preconditions: N/A
		//Postconditions: returns true if array is empty, otherwise false
		bool empty()
		{
			return array.empty();
		}
		//Preconditions: a must be vector<int>
		//Postconditions: initializes array
		MyBag2(vector<int> a, int newSize)
		{
			array.resize(newSize);
			for (int i = 0; i < array.size(); i++)
				array[i] = a[i];
		}
		//Preconditions: 
		//Postconditions: resizes array
		void resize(int a, int newSize)
		{
			array.resize(newSize);
			for (int i = 0; i < array.size(); i++)
				array[i] = a;

		}
		//Preconditions: N/A
		//Postconditions: displays all elements in the array
		void display() const
		{
			cout << "\n";
			for (int i = 0; i < array.size(); i++)
				cout << "\t\t\t[" << i << "] - " << array[i] << '\n';
		}
		//Preconditions: N/A
		//Postconditions: sorts array
		void sortArray()
		{
			sort(array.begin(), array.end());
		}
		//Preconditions: N/A
		//Postconditions: inserts a value at the back
		void insert(int value)
		{
			array.push_back(value);
		}
		//Preconditions: N/A
		//Postconditions: if the value is found in the array, return the index. Otherwise, return -1
		int search(int value)
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

		//Preconditions: index must be in bounds
		//Postconditions: removes the element at the index
		void remove(int index)
		{
			auto it = array.begin();
			advance(it, index);
			array.erase(it);

		}
		//Preconditions: N/A
		//Postconditions: clears array
		void clear()
		{
			array.clear();
		}
		//Preconditions: N/A
		//Postconditions: returns size
		int size()
		{
			int size = array.size();
			return size;
		}
		//Preconditions: index must be in bounds
		//Postconditions: returns element at the index
		int at(int index)
		{
			return array[index];
		}
		//Preconditions: index must be in bounds
		//Postconditions: sets the value at the index 
		void setArrayIndex(int index, int value)
		{
			array[index] = value;
		}
		//Preconditions: a must be MyBag2
		//Postconditions: copies a to the array
		const MyBag2 operator =(const MyBag2& a)
		{
			array.resize(a.array.size());
			for (int i = 0; i < a.array.size(); i++)
			{
				array[i] = a.array[i];
			}
			return *this;
		}

	};
