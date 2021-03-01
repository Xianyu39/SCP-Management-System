#include<iostream>
#include"AClass.h"
#include "SCPsystem.h"
using namespace std;

int main()
{
	SCPsystem sys;
	sys.logIn();
	sys.show_menu();
	
	string ch;
	cin >> ch;

	if (ch == "1")
	{
		sys.add();
	}
	else if(ch=="2")
	{
		sys.erase();
	}
	else if (ch == "3")
	{
		sys.change();
	}

	else if (ch == "4")
	{
		sys.search();
	}
	else if (ch == "rm-f")
	{
		sys.rm_f();
	}


	return 0;
}