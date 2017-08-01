#include "business-management.h"
#ifdef WIN32

#include <windows.h>
#include <iostream>
using namespace std;

#endif

int main(int ac, char** av)
{
#ifdef WIN32
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
#endif
	CBusinessManagement bm;
	return bm.Start(ac, av);;
}
