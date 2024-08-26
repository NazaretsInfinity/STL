#include<iostream>
#include<array>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n---------------------------\n"

template<typename T>void vector_properties(const std::vector<T>& vec);
#define checking
void main()
{
	std::vector<int> vec = { 3,5,8,13,21 };
	vector_properties(vec);

	std::vector<int>::iterator it = vec.begin();
	int value, index;
	cout << "Enter the index of new element: "; cin >> index;
	cout << "Enter the value to add: "; cin >> value;
	
	vec.insert(it + index, value);
	vector_properties(vec);

	cout << "Enter the index where to delete: "; cin >> index;
	vec.erase(vec.begin() + index);
	vector_properties(vec);
}

template<typename T>void vector_properties(const std::vector<T>& vec)
{
	for (int i : vec)cout << i << tab; cout << endl;
	cout << "Size:\t " << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << delimiter << endl;
}
