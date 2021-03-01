#include "SCPsystem.h"
#include<iterator>
#include"AClass.h"
#include"BClass.h"
#include"CClass.h"
#include"DClass.h"
#include"EClass.h"

const string SCPsystem::dataName("Data.txt");

SCPsystem::SCPsystem():personnel_list()
{
	fstream archive(dataName, ios::in);
	if (!archive.is_open())//Fail to open file.
	{
		cout << "Fail to access the dist." << endl;
		return;
	}

	char temp;
	archive >> temp;
	if (archive.eof())//is Empty, create an default Administor.
	{
		personnel_list.push_back(new AClass("001"s, "Administor"s, "001001001"s));

		decltype(personnel_list)::const_iterator it = personnel_list.begin();
		cout << "Welcom to SCP, I believe you are the first User." << endl
			<< "Your account is:" << endl;
		(*it)->print();
		cout << "You can modify your message if you like." << endl;
	}

	else//Not the first times
	{
		getData(dataName);
		cout << "Welcom." << endl;
	}

	archive.close();
}

SCPsystem::~SCPsystem()
{
	save();

	for (auto& p : personnel_list)
	{
		if (p)
			delete p;
		p = nullptr;
	}
}

void SCPsystem::save() const
{
	ofstream archive(dataName, ios::out);
	for (auto& each : personnel_list)
	{
		archive << each->ID << endl
				<< each->name << endl
				<< static_cast<char>(each->lev) << endl
				<< each->password << endl;
	}
	archive.close();
}

Personnel* SCPsystem::search(const string& id_or_name) const
{
	for (list<Personnel*>::const_iterator ix = personnel_list.begin();
		ix != personnel_list.end();
		++ix)
	{
		if ((*ix)->ID == id_or_name || (*ix)->name == id_or_name)
			return *ix;
	}
	return nullptr;
}
void SCPsystem::logIn()
{
	string t_id, t_password;
	cout << "Please log in, input your id:" << endl;
	cin >> t_id;
	cout << "Input your password:" << endl;
	cin >> t_password;

	Personnel* ix = search(t_id);
	if (!ix)//is not found
	{
		cout << "No such a account, please retry." << endl;
		logIn();
	}
	else// has founded, check password
	{
		if (ix->password == t_password)
		{
			cout << "Welcome" << endl;
			return;
		}
		else
		{
			cout << "Password not fit in." << endl;
			logIn();
		}
	}
}

void SCPsystem::insert(const string& t_id, const string& t_name, const string& t_password, Personnel::Level t_lev)
{
	switch (t_lev)
	{
	case Personnel::Level::A:
		personnel_list.push_back(new AClass(t_id, t_name, t_password));
		break;
	case Personnel::Level::B:
		personnel_list.push_back(new BClass(t_id, t_name, t_password));
		break;
	case Personnel::Level::C:
		personnel_list.push_back(new CClass(t_id, t_name, t_password));
		break;
	case Personnel::Level::D:
		personnel_list.push_back(new DClass(t_id, t_name, t_password));
		break;
	case Personnel::Level::E:
		personnel_list.push_back(new EClass(t_id, t_name, t_password));
		break;
	default:
		break;
	}
}

void SCPsystem::add()
{
	string tid, tname, tpassword;
	char tlev;
	cout << "Input id" << endl;
	cin >> tid;
	cout << "Input name:" << endl;
	cin >> tname;
	cout << "Input level" << endl;
	cin >> tlev;
	cout << "Input log in password" << endl;
	cin >> tpassword;

	insert(tid, tname, tpassword, static_cast<Personnel::Level>(tlev));
}

void SCPsystem::modify(const string& id_or_name, const string& new_name, const string& new_password)
{
	decltype(personnel_list)::iterator
	it{ find(personnel_list.begin(),personnel_list.end(),search(id_or_name)) };

	(*it)->change_name(new_name);
	(*it)->change_password(new_password);

	cout << "Modify successfully." << endl;
}

void SCPsystem::getData(const string& filename)
{
	ifstream os(filename, ios::in);

	if (!os.is_open() || !os)
	{
		cout << "Something wrong happened, cannot get data." << endl;
		return;
	}

	string t_id, t_name, t_password;
	char t_lev;
	while (os >> t_id && os >> t_name && os >> t_lev && os >> t_password)
		insert(t_id, t_name, t_password, static_cast<Personnel::Level>(t_lev));

	os.close();
}

void SCPsystem::remove(const string& id_or_name)
{
	decltype(personnel_list)::const_iterator 
	it = find(personnel_list.begin(), personnel_list.end(), search(id_or_name));
	if (it == personnel_list.end())
	{
		cout << "No fit in result." << endl;
		return;
	}
	else
	{
		personnel_list.erase(it);
		cout << "Remove successfully." << endl;
	}
}

void SCPsystem::erase()
{
	string key;
	cout << "Input the key of the personnel, name or id" << endl;
	cin >> key;
	remove(key);
}

void SCPsystem::change()
{
	string key,t_name, t_password;
	cout << "Input the name or id:" << endl;
	cin >> key;
	cout << "Using 2 lines to input the new name and new password." << endl;
	cin >> t_name;
	cin >> t_password;
	modify(key, t_name, t_password);
}
void SCPsystem::search()const
{
	string key;
	cout << "Input the name or id:" << endl;
	cin >> key;

	search(key)->print();
}

void SCPsystem::rm_f()
{
	fstream fs(dataName, ios::trunc);
	fs.close();
}
void SCPsystem::show_menu()const
{
	cout << "Menu" << endl
		<< "1,Ìí¼Ó" << endl
		<< "2,É¾³ý" << endl
		<< "3,ÐÞ¸Ä" << endl
		<< "4,²éÕÒ" << endl
		<< "rm-f" << endl;
	cout << "Choose you like." << endl;
}