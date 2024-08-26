#include<iostream>
#include<array>
#include<vector>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n---------------------------\n"

template<typename T>void vector_properties(const std::vector<T>& vec);
#define checking
void main()
{
#ifdef checking1
	std::vector<int> vec = { 3,5,8,13,21 };
	vector_properties(vec);

	int value, index;
	cout << "Enter the index of new element: "; cin >> index;
	cout << "Enter the value to add: "; cin >> value;

	vec.insert(vec.begin()+index, value);
	vector_properties(vec);

	cout << "Enter the index where to delete: "; cin >> index;
	vec.erase(vec.begin() + index);
	vector_properties(vec);

#endif 
#ifdef checking

	std::list<int> mylist = { 3,5,8,13,21 };
	for (int i : mylist)cout << i << tab; cout << endl;


	int value, index;
	std::list<int>::iterator it = mylist.begin();
	cout << "Enter the index of new element: "; cin >> index;
	cout << "Enter the value to add: "; cin >> value;
	while (index)
	{
		++it; --index;
	}
	mylist.insert(it, value); it = mylist.begin();
	for (int i : mylist)cout << i << tab; cout << endl;

	cout << "Enter the index where to delete: "; cin >> index;
	while (index)
	{
		++it; --index;
	}
	mylist.erase(it);
	for (int i : mylist)cout << i << tab; cout << endl;
#endif 

}


template<typename T>void vector_properties(const std::vector<T>& vec)
{
	for (int i : vec)cout << i << tab; cout << endl;
	cout << "Size:\t " << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << delimiter << endl;
}
