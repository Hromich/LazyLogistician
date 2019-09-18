#include "LazyLogistician.h"

Car::Car(double l, double w, double m)
{
	cubeMetr = m;
	length = l;
	width = w;
}

Car::Car(const Car & c)
{
	cubeMetr = c.cubeMetr;
	length = c.length;
	width = c.width;
}

void Car::setCubeM()
{
	cubeMetr = length * width;
}

bool Car::loadWidth()
{
	if(Pallet::getWidthSize() <= width)
		return true;
	else
		return false;
}

void Car::setWidthArea()
{
	if (Pallet::getWidthSize() < 1.20)
		palletRow = 3;
	else if (Pallet::getWidth() >= 1.30)
		palletRow = 2;
	else
		palletRow = 2;
}

void Car::setSloadQ()
{
	SloadQ = Sload * Pallet::getLength();
}

bool Car::multiMachLoad()
{
	if (SloadQ < getLength())
		return true;
	else
		return false;
}

void Car::setSload()
{
	Sload = (Pallet::getQuanity() / (double)palletRow);
}

std::istream & operator>>(std::istream & is, Car & s)
{
	std::cout << "Enter length of car in meters: ";
	is >> s.length;
	std::cout << "Enter width of car in meters: ";
	is >> s.width;
	return is;
}

std::ostream & operator<<(std::ostream & os, const Car & s)
{
	os << "Length of car is " << s.length << "\t" << " Width of car is " << s.width << "\n";
	os << "CubeMeters of car is " << s.length * s.width << "\n";
	return os;
}

Pallet::Pallet(double l, double w, double c, int q)
{
	p_length = l;
	p_width = w;
	p_cubeMetr = c;
	quanity = q;
}

Pallet::Pallet(const Pallet & p)
{
	p_length = p.p_length;
	p_width = p.p_width;
	p_cubeMetr = p.p_cubeMetr;
	quanity = p.quanity;
}

void Pallet::setCube()
{
	p_cubeMetr = p_length * p_width;
}


std::istream & operator>>(std::istream & is, Pallet & s)
	{
		try
		{
			std::cout << "Enter length of pallet in meters: ";
			is >> s.p_length;

			if (!is)
				throw 1;
		}
		catch (int x)
		{
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << '\a'; //in case of Breakfast!
			std::cout << "Please enter length of pallet again: ";
			is >> s.p_length;
		}
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		try
		{
			std::cout << "Enter width of pallet in meters: ";
			is >> s.p_width;

			if (!is)
				throw 2;
		}
		catch (int e)
		{
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << '\a'; //in case of Breakfast!
			std::cout << "Please enter width of pallet again: ";
			is >> s.p_width;
		}
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		try
		{
			std::cout << "Enter how much pallet(s) do you wish to load: ";
			is >> s.quanity;

			if (!is)
				throw 3;
		}
		catch (int z)
		{
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << '\a'; //in case of Breakfast!
			std::cout << "Please enter numbers of pallet again: ";
			is >> s.quanity;
		}
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return is;
}

std::ostream & operator<<(std::ostream & os, const Pallet & s)
{
	os << "The length of pallet is " << s.p_length << "\n";
	os << "The width of pallet is " << s.p_width << "\n";
	os << "The quanity of pallet is " << s.quanity << "\n";
	os << "The cube metr of pallets is " << s.p_length * s.p_width * s.quanity << "\n";

	return os;
}

int CarCatalogue::LoadWidth(double w)
{

	if (w * 3 <= 2.40)
		return 3;
	else if (w * 2 <= 2.40)
		return 2;
	else
		return 2;
}

double CarCatalogue::LoadLength(double l, double w, int q)
{
	double temp;
	temp = l * (q / LoadWidth(w));
	return temp;
}



void CarCatalogue::getCar(double l, int w, double pw)
{
	CarPorter p;
	CarEuroTrack e;
	CarGazel g;
	CarMersedesSprinter ms;
	CarFiveTonCar f;
	CarTenTonCar t;

	if (l <= p.length && (w * pw) <= p.width)
		std::cout << "Porter is suitable choice for you!";
	else if (l <= g.length && (w * pw) <= g.width)
		std::cout << "Gazel is suitable choice for you!";
	else if (l <= ms.length && (w * pw) <= ms.width)
		std::cout << "MersedesSprinter is suitable choice for you!";
	else if (l <= f.length && (w * pw) <= f.width)
		std::cout << "FiveTonCar is suitable choice for you!";
	else if (l <= t.length && (w * pw) <= t.width)
		std::cout << "TenTonCar is suitable choice for you!";
	else if (l <= e.length && (w * pw) <= e.width)
		std::cout << "EuroTruck is suitable choice for you!";
	else
		std::cout << "There is no suitable car for order!";	
}