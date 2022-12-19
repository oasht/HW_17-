#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
struct Date
{
	int dd;
	int mm;
	int yy;
	friend ostream& operator <<(ostream& os, Date& d);
	friend istream& operator >>(istream& is, Date& d);
};
class Good
{
	string name;
	double price;
	double weight;
	Date dd;
	int quantity;
	int expiration;
public:
	Good();
	Good (string _name, double _price, double _weight, Date _dd,
		int _quantity, int _expiration);
	virtual void Print();
	virtual void Receipt(int n);
	virtual void Sale(int n);
	virtual double Sum();
	virtual double Total_weight();
	void Set_quantity(char n, int k);
	friend void Write(vector <Good>& _v, string s);
	Date Get_date();
	int Get_quantity();
	int Get_exp_date();
	friend ostream& operator <<(ostream& os, Good& g);
	void Read(vector<Good>& tmp);
	void Read_all();
};


class Juice :public Good
{
public:
	Juice() {}
	Juice(string _name, double _price, double _weight, Date _dd,
		int _quantity, int _expiration);
	virtual void Print();
	virtual void Receipt(int n);
	virtual void Sale(int n);
	virtual double Sum();
	virtual double Total_weight();
	void Set_quantity(char n, int k);
};

class Cake :public Good
{
public:
	Cake() {  }
	Cake(string _name, double _price, double _weight, Date _dd,
		int _quantity, int _expiration);
	virtual void Print();
	virtual void Receipt(int n);
	virtual void Sale(int n);
	virtual double Sum();
	virtual double Total_weight();
	void Set_quantity(char n, int k);
};

class Apple :public Good
{
public:
	Apple() {  }
	Apple(string _name, double _price, double _weight, Date _dd,
		int _quantity, int _expiration);
	virtual void Print();
	virtual void Receipt(int n);
	virtual void Sale(int n);
	virtual double Sum();
	virtual double Total_weight();
	void Set_quantity(char n, int k);
};
class Foam : public Good
{
public:
	Foam() {  }
	Foam (string _name, double _price, double _weight, Date _dd, int _quantity, int _expiration);
	virtual void Print();
	virtual void Receipt(int n);
	virtual void Sale(int n);
	virtual double Sum();
	virtual double Total_weight();
	void Set_quantity(char n, int k);
};

class Soap : public Good
{
public:
	Soap() {  }
	Soap(string _name, double _price, double _weight, Date _dd,
		int _quantity, int _expiration);
	virtual void Print();
	virtual void Receipt(int n);
	virtual void Sale(int n);
	virtual double Sum();
	virtual double Total_weight();
	void Set_quantity(char n, int k);
};

class Air_freshener : public Good
{
public:
	Air_freshener() {  }
	Air_freshener(string _name, double _price, double _weight, Date _dd,
		int _quantity, int _expiration);
	virtual void Print();
	virtual void Receipt(int n);
	virtual void Sale(int n);
	virtual double Sum();
	virtual double Total_weight();
	void Set_quantity(char n, int k);
};


Date Rand_d1();
Date Rand_d2();
int Convert_date(Date _dd);
void Head();
void Show_menu();
class Shop : public Good
{
public:
	Shop() {}
	void f()
	{
		bool key = 1;
		char c;
		Good g1;
		vector <Good> v1;
		Date n_dd;
		n_dd.yy = 2022; n_dd.mm = 12; n_dd.dd = 19;
		cout << "Data:   " << n_dd << endl << endl;


		g1.Read(v1); cout << endl << endl;

		do
		{
			Show_menu();
			cout << "Enter: "; cin >> c;
			system("cls");
			if (c<'0' || c>'7')
			{
				cout << "Incorrect data, enter again " << endl;
			}
			else
			{
				switch (c)
				{
				case '1':
				{
					for (int i = 0; i < v1.size(); i++)
						v1[i].Print();
					Totals(v1);
				}break;
				case '2':
				{
					Head();
					for (int i = 0; i < v1.size(); i++)
						Remove_1(v1, n_dd);
				}break;
				case '3':
				{
					Head();
					for (int i = 0; i < rand() % 10 + 5; i++)
						Buy_1(v1);
					for (int i = 0; i < v1.size(); i++)
						v1[i].Print();
					Totals(v1);
				}break;
				case '4':
				{
					for (int i = 0; i < rand() % 10 + 5; i++)
						Add_party(v1);
					for (int i = 0; i < v1.size(); i++)
						v1[i].Print();
					Totals(v1);
				}break;
				case '5':
				{
					Read_all();
				}break;
				case '6':
				{
					Write(v1, "Rewrite");
				}break;
				case '7':
				{
					v1.clear();
					Head();
					for (int i = 0; i < 20; i++)
						Add_r1(v1);

					for (int i = 0; i < v1.size(); i++)
						v1[i].Print();
					Totals(v1);
				}break;
				case '0':
				{
					key = 0;
				}break;

				default:
					break;
				}
			}

		} while (key);
	}

	void Add_r1(vector<Good> & _v);
	void Remove_1(vector<Good> & _v, Date _d);
	void Buy_1(vector<Good> & _v);
	void Add_party(vector<Good> & _v);
	void Totals(vector<Good> & _v1);
};
