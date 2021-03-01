#ifndef SCPSYSTEM_H_
#define SCPSYSTEM_H_
#include<list>
#include<fstream>
#include"Personnel.h"
using namespace std;

class SCPsystem
{
protected:
	list<Personnel*> personnel_list;//Basic data structure.
	void remove(const string& id_or_name);
	void modify(const string& id_or_name, const string& new_name, const string& new_password);
	void insert(const string& id, const string& name, const string& password, Personnel::Level lev);
	Personnel* search(const string& id_or_name)const;
	void getData(const string& filename);
	static const string dataName;

public:
	SCPsystem();
	~SCPsystem();
	void save()const;
	void logIn();
	void add();
	void erase();
	void change();
	void search()const;
	void show_menu()const;
	void rm_f();
};
#endif // !SCPSYSTEM_H_