#include "Good.h"




Good::Good()
{
name = "";
price = 0;
weight = 0;
dd.dd = 0;
dd.mm = 0;
dd.yy = 0;
quantity = 0;
expiration = 0;
}

Good::Good(string _name, double _price, double _weight, Date _dd,
	int _quantity, int _expiration)
{
	name = _name;
	price = _price;
	weight = _weight;
	dd = _dd;
	quantity = _quantity;
	expiration = _expiration;
}

void Good::Print()
{
	cout << setw(20) << name << setw(8) << price << setw(5) << weight << "   " << dd
		<< setw(7) << quantity << setw(7) << expiration << setw(9) << Sum() << setw(7) << Total_weight() << endl;
}

void Good::Receipt(int n)
{
	Set_quantity('+', n);
}

void Good::Sale(int n)
{
	Set_quantity('-', n);
}

double Good::Sum()
{
	double sum = quantity * price;
	return sum;
}

double Good::Total_weight()
{
	double all_weight = quantity * weight;
	return all_weight;
}

void Good::Set_quantity(char n, int k)
{
	if (n == '-')
	{
		quantity -= k;
	}
	else if (n == '+')
	{
		quantity += k;
	}
	else cout << "Error" << endl;
}

Date Good::Get_date()
{
	return dd;
}

int Good::Get_quantity()
{
	return quantity;
}

int Good::Get_exp_date()
{
	return expiration;
}

ostream& operator<<(ostream& os, Date& d)
{
	os << ((d.dd < 10 && d.dd>0) ? "0" : "") << d.dd << "."
		<< ((d.mm < 10 && d.mm>0) ? "0" : "") << d.mm << "."
		<< d.yy;
	return os;
}

istream & operator>>(istream & is, Date & d)
{
	bool b = 1;
	do
	{
		cout << "Enter day: "; is >> d.dd; cout << endl;
		cout << "Enter month: "; is >> d.mm; cout << endl;
		cout << "Enter year: "; is >> d.yy; cout << endl;
		try
		{
			if (d.dd < 0 || d.dd>31 || d.mm < 0 || d.mm>12
				|| d.yy < 2018 || d.yy > 2022)
			{
				throw 5;
			}
			else
			{
				b = 0;
			}
		}
		catch (int n)
		{
			cout << "Wrong data, try again" << endl;
		}
	} while (b);

	return is;
}



ostream& operator<<(ostream & os, Good & g)
{
	os << setw(20) << g.name << setw(8) << g.price << setw(6) << g.weight << setw(4) << g.dd.dd << setw(4)
		<< g.dd.mm << setw(8) << g.dd.yy << setw(4) << g.quantity << setw(8) << g.expiration << endl;

	return os;
}

void Good::Read(vector<Good> & tmp)
{
	ifstream is;
	is.open("Good.txt");
	if (!is.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{
		cout << "File is opened" << endl;
		Good tmp1;
		while (is >> tmp1.name >> tmp1.price >> tmp1.weight >>
			tmp1.dd.dd >> tmp1.dd.mm >> tmp1.dd.yy >>
			tmp1.quantity >> tmp1.expiration)
		{
			tmp.push_back(tmp1);
		}
		is.close();
		

	}
}

void Good::Read_all()
{
	vector<Good> tmp;
	string path = "";

	try
	{
		Head();
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				path = "Buy.txt";
			}
			else if (i == 1)
			{
				path = "Write_off.txt";
			}
			else if (i == 2)
			{
				path = "Receipts.txt";
			}
			else
			{
				path = "Good.txt";
			}

			ifstream is;
			is.open(path);
			if (!is.is_open())
			{
				throw 5;
			}
			else
			{
				cout << "-------------------------------------------------------" << endl;
				Good tmp1;
				while (is >> tmp1.name >> tmp1.price >> tmp1.weight >>
					tmp1.dd.dd >> tmp1.dd.mm >> tmp1.dd.yy >>
					tmp1.quantity >> tmp1.expiration)
				{
					tmp.push_back(tmp1);
				}
				is.close();
				if (i == 0)		 cout << "Sales:" << endl << endl;
				else if (i == 1) cout << "Write-offs:" << endl << endl;
				else if (i == 2) cout << "Receipts:" << endl << endl;
				else			 cout << "Left-outs:" << endl << endl;

				for (int i = 0; i < tmp.size(); i++)
				{
					tmp[i].Print();
				}
				cout << "-------------------------------------------------------" << endl;
				tmp.clear();
			}

		}
	}
	catch (int n)
	{
		cout << "Error!" << endl;
	}
}




Juice::Juice(string _name, double _price, double _weight, Date _dd, int _quantity,
	int _expiration) : Good(_name, _price, _weight, _dd, _quantity, _expiration)
{
}

void Juice::Print()
{
	Good::Print();
}

void Juice::Receipt(int n)
{
	Set_quantity('+', n);
}

void Juice::Sale(int n)
{
	Set_quantity('-', n);
}

double Juice::Sum()
{
	return Good::Sum();
}

double Juice::Total_weight()
{
	return Good::Total_weight();
}

void Juice::Set_quantity(char n, int k)
{
	Good::Set_quantity(n, k);
}

Cake::Cake(string _name, double _price, double _weight, Date _dd, int _quantity,
	int _expiration) : Good(_name, _price, _weight, _dd, _quantity, _expiration)
{
}

void Cake::Print()
{
	Good::Print();
}

void Cake::Receipt(int n)
{
	Set_quantity('+', n);
}

void Cake::Sale(int n)
{
	Set_quantity('-', n);
}

double Cake::Sum()
{
	return Good::Sum();
}

double Cake::Total_weight()
{
	return Good::Total_weight();
}

void Cake::Set_quantity(char n, int k)
{
	Good::Set_quantity(n, k);
}

Apple::Apple(string _name, double _price, double _weight, Date _dd,
	int _quantity, int _expiration) : Good(_name, _price, _weight, _dd, _quantity, _expiration)
{
}

void Apple::Print()
{
	Good::Print();
}

void Apple::Receipt(int n)
{
	Set_quantity('+', n);
}

void Apple::Sale(int n)
{
	Set_quantity('-', n);
}

double Apple::Sum()
{
	return Good::Sum();
}

double Apple::Total_weight()
{
	return Good::Total_weight();
}

void Apple::Set_quantity(char n, int k)
{
	Good::Set_quantity(n, k);
}


Foam::Foam(string _name, double _price, double _weight, Date _dd,
	int _quantity, int _expiration) : Good(_name, _price, _weight, _dd, _quantity, _expiration)
{
}

void Foam::Print()
{
	Good::Print();
}

void Foam::Receipt(int n)
{
	Set_quantity('+', n);
}

void Foam::Sale(int n)
{
	Set_quantity('-', n);
}

double Foam::Sum()
{
	return Good::Sum();
}

double Foam::Total_weight()
{
	return Good::Total_weight();
}

void Foam::Set_quantity(char n, int k)
{
	Good::Set_quantity(n, k);
}


Soap::Soap(string _name, double _price, double _weight, Date _dd,
	int _quantity, int _expiration) : Good(_name, _price, _weight, _dd, _quantity, _expiration)
{
}

void Soap::Print()
{
	Good::Print();
}

void Soap::Receipt(int n)
{
	Set_quantity('+', n);
}

void Soap::Sale(int n)
{
	Set_quantity('-', n);
}

double Soap::Sum()
{
	return Good::Sum();
}

double Soap::Total_weight()
{
	return Good::Total_weight();
}

void Soap::Set_quantity(char n, int k)
{
	Good::Set_quantity(n, k);
}



Air_freshener::Air_freshener(string _name, double _price, double _weight, Date _dd,
	int _quantity, int _expiration) : Good(_name, _price, _weight, _dd, _quantity, _expiration)
{
}

void Air_freshener::Print()
{
	Good::Print();
}

void Air_freshener::Receipt(int n)
{
	Set_quantity('+', n);
}

void Air_freshener::Sale(int n)
{
	Set_quantity('-', n);
}

double Air_freshener::Sum()
{
	return Good::Sum();
}

double Air_freshener::Total_weight()
{
	return Good::Total_weight();
}

void Air_freshener::Set_quantity(char n, int k)
{
	Good::Set_quantity(n, k);
}


void Shop::Add_r1(vector<Good>& _v)
{
	string str_w[6] = { "Juice","Cake","Apple","Foam","Soap","Spray" };
	string m = str_w[rand() % 6];

	int qun = rand() % 100 + 1;
	double wei = rand() % 4 + 1;
	double pr = rand() % 100 + 1;

	Date d1 = Rand_d2();
	Date d2 = Rand_d1();

	int ex2 = rand() % 730 + 365;
	int ex1 = rand() % 20 + 1;

	if (m == "Juice")
	{
		Juice j("Juice", pr, wei, d1, qun, ex1);
		_v.push_back(j);
	}
	else if (m == "Cake")
	{
		Cake c("Cake", pr, wei, d1, qun, ex1);
		_v.push_back(c);
	}
	else if (m == "Apple")
	{
		Apple a("Apple", pr, wei, d1, qun, ex1);
		_v.push_back(a);
	}

	else if (m == "Foam")
	{
		Foam f("Foam", pr, wei, d2, qun, ex2);
		_v.push_back(f);
	}
	else if (m == "Soap")
	{
		Soap s("Soap", pr, wei, d2, qun, ex2);
		_v.push_back(s);
	}
	else if (m == "Spray")
	{
		Air_freshener af("Spray", pr, wei, d2, qun, ex2);
		_v.push_back(af);
	}
}

void Shop::Remove_1(vector<Good>& _v, Date _d)
{
	vector <Good> ::iterator it = _v.begin();
	vector <Good> tmp;

	for (int i = 0; i < _v.size(); i++)
	{
		it = _v.begin();

		if (Convert_date(_v[i].Get_date()) + _v[i].Get_exp_date() < Convert_date(_d))
		{
			_v[i].Print();
			tmp.push_back(_v[i]);
			cout << "\t\t\t The product is outdated" << endl;
			advance(it, i);
			_v.erase(it);
			break;
		}
	}
	Write(tmp, "Write_off");
	
}

void Shop::Buy_1(vector<Good>& _v)
{
	vector <Good> tmp;
	int m = rand() % _v.size();
	int _n = rand() % _v[m].Get_quantity();
	tmp.push_back(_v[m]);
	_v[m].Sale(_n);
	tmp.push_back(_v[m]);
	Write(tmp, "Buy");
}

void Shop::Add_party(vector<Good>& _v)
{
	vector <Good> tmp;
	int m = rand() % _v.size();
	int _n = rand() % 100 + 100;
	tmp.push_back(_v[m]);
	_v[m].Receipt(_n);
	tmp.push_back(_v[m]);
	Write(tmp,"Receipts");
}

void Shop::Totals(vector<Good>& _v)
{
	double sum = 0;
	double ves = 0;
	for (int i = 0; i < _v.size(); i++)
	{
		sum += _v[i].Sum();
		ves += _v[i].Total_weight();
	}
	cout << "------------------------------------------------------" << endl;
	cout << "Total:     " << sum << " rubles.   " << ves << " kilos." << endl;
}




Date Rand_d1()
{
	Date tmp;
	tmp.dd = rand() % 30 + 1;
	tmp.mm = rand() % 11 + 1;
	tmp.yy = rand() % 4 + 2018;
	return tmp;
}

Date Rand_d2()
{
	Date tmp;
	tmp.dd = rand() % 30 + 1;
	tmp.mm = 12;
	tmp.yy = 2022;
	return tmp;
}


int Convert_date(Date _d)
{
	int _dd = 0;
	_dd = ((_d.yy - 2010) * 365) + (_d.mm * 31) + _d.dd;

	return _dd;
}
void Head()
{
	cout << setw(22) << "Product " << setw(8) << "Price " << setw(5) << "Wgt "
		<< setw(12) << "Prod. date " << setw(8) << "Num "
		<< setw(8) << "Days " << setw(6) << "Sum" << setw(10) << "Tot wgt" << endl;
	cout << "  -----------------------------------------------------------------------------" << endl;
}
void Show_menu()
{
	cout << "Choose action:" << endl;
	cout << "1 - Print data" << endl;
	cout << "2 - Remove outdated good" << endl;
	cout << "3 - Selling good" << endl;
	cout << "4 - Adding good" << endl;
	cout << "5 - Read saved data" << endl;
	cout << "6 - Rewrite data" << endl;
	cout << "7 - Randomize new data" << endl;
	cout << "0 - Exit" << endl;
}
void Write(vector<Good> & _v, string s)
{
	string path = "";

	if (s == "Buy")
		path = "Buy.txt";
	else if (s == "Write_off")
		path = "Write_off.txt";
	else if (s == "Receipts")
		path = "Receipts.txt";
	else if (s == "Rewrite")
		path = "Rewrite.txt";
	else
		path = "Good.txt";

	try
	{
		ofstream fz;

		if (path == "Good.txt")
			fz.open(path, ofstream::out);
		else
			fz.open(path, ofstream::app);

		if (!fz.is_open())
			throw 5;
		else
		{
			cout << "File is opened" << endl;
			for (auto it = _v.begin(); it != _v.end(); it++)
				fz << *it;
			cout << "Data is written" << endl;
		}
		fz.close();
	}
	catch (int n)
	{
		cout << "Error!" << endl;
	}
}