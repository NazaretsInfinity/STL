#include<iostream>
#include<string>
#include<map>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n============================\n"
#define checking

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef checking

	std::multimap<int, std::string> week =
	{
		{6, "Saturday"},
		std::pair<int, std::string>(0,"Sunday"),
		std::pair<int, std::string>(1,"Monday"),
		std::pair<int, std::string>(2,"Tuesday"),
		std::pair<int, std::string>(3,"Wednesday"),
		{4,"Thursday"},
		{5,"Friday"},
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}cout << delimeter;

	std::map<std::string, std::vector<std::string>> dictionary =
	{
		{"map", {"карта, таблица, личность"}},
		{"image", {"изображение"}},
		std::pair<std::string, std::vector<std::string>>("marble", {"шарик,мрамор"})
	};
	for (std::map<std::string, std::vector<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout.width(16);
		cout << std::left;
		cout << (*it).first << ":\t";
		/*for (std::vector<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt;
			cout << (*jt != it->second.back() ? ", " : ";");
		}
		cout << endl;*/
		for (std::string i : it->second)
		{
			int j = 0;
			cout << it->second[j];
			cout << (it->second[j] != it->second.back() ? ", " : ";");
			++j;
		}
		cout << endl;
	}
#endif
}