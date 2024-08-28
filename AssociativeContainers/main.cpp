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

class PoliceTraffic
{
	std::map<std::string, std::vector<std::string>> given;
public: 
	PoliceTraffic(std::map<std::string, std::vector<std::string>> given):given(given){}
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
		for (std::map<std::string, std::vector<std::string>>::iterator it = given.begin(); it != given.end(); ++it)
		{
			cout << (*it).first << ":\t";
			for (std::string i : it->second)cout << i << (i != it->second.back() ? ", " : ";");
			cout << endl;
		}
	}
};

void add(std::map<std::string, std::vector<std::string>>& given, std::string number, std::initializer_list<std::string> breaches);
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
#ifdef checking2

	std::map<std::string, std::vector<std::string>> TrafficPolice =
	{
		{"0345el", {"chirped too loud", "ate kids" , "a dog"}}
	};
	add(TrafficPolice, "0345el", { "being silly" });
	add(TrafficPolice, "t266uh", { "no paying attention on the road" });

	for (std::map<std::string, std::vector<std::string>>::iterator it = TrafficPolice.begin(); it != TrafficPolice.end(); ++it)
	{
		cout << (*it).first << ":\t";
		for (std::string i : it->second)cout << i << (i != it->second.back() ? ", " : ";");
		cout << endl;
	}
#endif 
	/*std::map<std::string, std::vector<std::string>> listok =
	{
		{"0345el", {"chirped too loud", "ate kids" , "a dog"}}
	};

	PoliceTraffic opt(listok);*/

	PoliceTraffic opt =
	{
		{"0345el", {"chirped too loud", "ate kids" , "a dog"}}
	};

	opt.add("t266uh", { "no paying attention on the road" });

	opt.print();
}


void add(std::map<std::string,std::vector<std::string>>& given, std::string number, std::initializer_list<std::string> breaches)
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
