#include"Personnel.h"
#include<map>
#include<iostream>
#include<string>
#include<conio.h>

map<Personnel::Level, string> Personnel::table;

Personnel::Personnel(const string& ID, const string& name, Level lev, const string& password)
	:ID(ID),
	name(name),
	lev(lev),
	password(password), 
	overview(getLevelOverviewFileName(lev), ios_base::in)
{}

void Personnel::print(ostream& os) const
{
	//Basic information
	os  << ID << endl
		<< "Name: " << name << endl
		<< "Class Level: " << static_cast<char>(lev) << endl;
	os << "Press 'S' to get more information." << endl;

	//get Overview
	char ch = _getch();
	if (ch == 's' || ch == 'S')//Show information
	{
		string buffer;
		if (!overview.is_open() || !overview)//Exception handling
		{
			cout << "Something unexpected has occured, cannot get the information." << endl;
			return;
		}
		while (!overview.eof())
		{
			overview >> buffer;
			cout << buffer;
		}
	}
}
void Personnel::change_name(const string& new_name)
{
	name = new_name;
}
void Personnel::change_password(const string& new_password)
{
	password = new_password;
}
string Personnel::getLevelOverviewFileName(Level lev)
{
	if (!table.size())
	{	//Create the level table.
		table.insert(pair<Personnel::Level, string >(Level::A, "Alevel.txt"));
		table.insert(pair<Personnel::Level, string >(Level::B, "Blevel.txt"));
		table.insert(pair<Personnel::Level, string >(Level::C, "Clevel.txt"));
		table.insert(pair<Personnel::Level, string >(Level::D, "Dlevel.txt"));
		table.insert(pair<Personnel::Level, string >(Level::E, "Elevel.txt"));
	}
	return table[lev];
}