#ifndef PERSONNEL_H_
#define PERSONNEL_H_
#include<string>
#include<iostream>
#include<fstream>
#include<map>
using namespace std;

class Personnel
{
	friend class SCPsystem;
public:
	enum class Level { A='A', B, C, D, E };

	Personnel(const string& ID, const string& name, Level lev, const string& password);
	virtual ~Personnel() { overview.close(); }
	virtual void print(ostream& os=cout)const;
	virtual void change_name(const string& new_name);
	virtual void change_password(const string& new_password);

protected:
	static map<Personnel::Level, string> table;
	string ID;
	string name;
	Level lev;
	string password;
	mutable ifstream overview;
	string getLevelOverviewFileName(Level lev);
};

#endif // !PERSONNEL_H_