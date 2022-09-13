// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include "dice.h"
#include "DiceSet.h"
using namespace std;




int main()
{
	cout << "Hello";
	DiceSet s(3);
	
	s.getSumProbability();
	cout << s;
}

