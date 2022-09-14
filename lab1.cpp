// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include "dice.h"
#include "DiceSet.h"
using namespace std;




int main()
{
	DiceSet s(3);
	DiceSet s1(2);
	cout << s;
	cout << endl;
	cout << s1;
	cout << (s < s1) << endl;
}

