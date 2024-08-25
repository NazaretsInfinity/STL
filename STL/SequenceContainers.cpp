#include<iostream>
#include<array>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
void main()
{
	std::vector<int> vec = { 3,5,8,13,21 };
	for (int i : vec)
	{
		cout << i << tab;
	}cout << endl;
}