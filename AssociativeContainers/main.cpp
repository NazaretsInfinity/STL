#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n============================\n"
#define checking

class PoliceTraffic
{
	std::map<std::string, std::vector<std::string>> given;
public: 
	PoliceTraffic(std::initializer_list<std::pair<std::string, std::vector<std::string>>> il)
	{
		for (auto init : il)
		{
			given.insert(given.end(), init);
		}
	}
	void add(std::string number, std::initializer_list<std::string> breaches)
	{
		if (given.find(number) == given.end())
		{
			given.insert(std::pair<std::string, std::vector<std::string>>(number, breaches));
		}
		else
		{
			given.find(number)->second.insert(given.find(number)->second.end(), breaches);
		}
	}
	void print()
	{
		for(std::map<std::string, std::vector<std::string>>::iterator it = given.begin(); it != given.end(); ++it)
		{
			cout << (*it).first << ":\t";
			for (std::string i : it->second)cout << i << (i != it->second.back() ? ", " : ";");
			cout << endl;
		}
	}
	void print(const std::string filename)
	{
		std::ofstream fout(filename);
		for (std::map<std::string, std::vector<std::string>>::iterator it = given.begin(); it != given.end(); ++it)
		{
			fout << (*it).first << ":\t";
			for (std::string i : it->second)fout << i << (i != it->second.back() ? ", " : ";");
			fout << endl;
		}
		fout.close();
		std::string out = "notepad " + filename;
		system(out.c_str());
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef checking1

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
		std::pair<std::string, std::vector<std::string>>("marble", {"шарик, мрамор"})
	};
	for (std::map<std::string, std::vector<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout.width(12);
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
			cout << i << (i != it->second.back() ? ", " : ";");
			//*(it->second.data()
		}
		cout << endl;
	}
#endif
}

