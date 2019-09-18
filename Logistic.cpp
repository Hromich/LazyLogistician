#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <string>
#include "LazyLogistician.h"

using namespace std;
void SingleOrder();
void MultiOrder();
void CarCheck();
bool loadRow(double ls, double c, int r);
int loadWidth(std::vector<double>::iterator it, double w);
void EatLine();

int main()
{
	char c;
	cout << "Data should be in meters!";
	cout << "\nExample:  ""Enter length of pallet: 1.35;\t  Enter width of pallet: 0.85\n";

	do
	{ 
	cout << "\n\tEnter which calculation do you wish to do:\n";
	cout << "\n\t1) For SingleOrder\n" << "\t2)For MultiOrder\n" << "\t3)To check wich car do you need for order\n";
	cout << "\t0)Exit\n";

	cout << "Enter your choice: ";
	cin >> c;
	switch(c)
	{
	case '1' :
		SingleOrder();
		break;
	case '2':
		MultiOrder();
		break;
	case '3':
		CarCheck();
		break;
	case '0':
		exit(1);
	default:
		break;
	}
	} while (c != '0');

	system("pause");
	return 0;
}

void SingleOrder()
{
	Pallet p1;
	Car c1;
		cin >> c1;
		c1.setCubeM();
		cout << "\nYou entered\n";
		cout << c1;

		cout << "Enter the size of pallets\n";
		cin.get();
		cin >> p1;
		p1.setCube();

		//c1.setWidthArea();
		//c1.setSload();
		//c1.setSloadQ();
		cout << "\nYou entered\n";
		cout << p1;

		auto s = p1.getCube() + 1;
		auto v = c1.getCubeMetr();
		cout << "\nChecking if car volume is enough for order...\n";
		Sleep(500);
		if ((v - s) < 0)
			cout << "\nNot enough car size for order!\n";
		else if (c1.loadWidth() && c1.multiMachLoad())
		{
			cout << "\nThe order is correct!\n";
			cout << (v - s) << " cubes left in a car!\n";
		}
		else
			cout << "\nNot enough car size for order!\n";
		cout << "Enter any key start calculating size (q for exit!)\n";
}

void MultiOrder()
{
	std::vector<double> w;
	std::vector<double> l;
	string * q = new string;
	int quanity;
	int row;
	double length;
	double width;
	std::vector<int> q1;

	Car c1;

	cin >> c1;
	c1.setCubeM();
	cout << "\nYou entered\n";
	cout << c1;

	double lengthSum = 0.0;
	double widthSum = 0.0;
	
	cout << "Enter 'p' to process entering the data, 'q' for stop\n";
	while (cin >> *q && *q != "q")
	{
		cout << "Enter quanity: ";
		cin >> quanity;
		EatLine();
		if (quanity == 0)
		{
			length = 0;
			width = 0;
			break;
		}
		cout << "Enter length of pallets: ";
		cin >> length;
		EatLine();
		cout << "Enter width of pallets: ";
		cin >> width;
		EatLine();

		for (int i = 0; i < quanity; i++)
		{
			w.push_back(width);
			l.push_back(length);
		}
		cout << "Enter 'p' to process entering the data, 'q' for stop\n";
	} //while (cin.good());

	std::vector<double>::iterator itl = l.begin();
	std::vector<double>::iterator itw = w.begin();
	std::vector<double>::iterator widthMax;
	widthMax = std::max_element(w.begin(), w.end());


	for (; itl != l.end(); itl++)
	{
		lengthSum += *itl;
		widthSum += *itw;
	}
	row = loadWidth(widthMax, c1.getWidth());
	loadRow(lengthSum, c1.getLength(), row);
	delete q;
}

void CarCheck()
{
	Pallet p1;
	CarCatalogue c;
	double w;
	int load;

	cout << "Enter the size of pallets\n";
	cin.get();
	cin >> p1;

	cout << "Checking which car is best choice for order...\n";
	Sleep(500);

	w = c.LoadLength(p1.getLength(), p1.getWidth(), p1.getQuanity());
	load = c.LoadWidth(p1.getWidth());
	c.getCar(w, load, p1.getWidth());
}

bool loadRow(double ls, double c, int r)
{
	double z;
	z = ls / (double)r;

	if (z <= c)
	{ 
		cout << "Car has enough size for order!";
		return true;
	}
	else
	{ 
		cout << "Car has not enough size for order";
		return false;
	}
}

int loadWidth(std::vector<double>::iterator it, double w)
{
	if (*it == 0)
		return 0;
	if ((*it * 2) <= w)
		return 2;
	else if (*it * 3 > w)
		return 2;
	else 
		return 3;
}

void EatLine()
{
	cin.clear();
	cin.ignore(255, '\n');
}