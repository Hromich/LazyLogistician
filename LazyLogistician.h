#include <iostream>
#include <string>

class Pallet
{
private:
	double p_length;
	double p_width;
	double p_cubeMetr;
	int quanity = 1;
public:
	Pallet() {}
	Pallet(double l, double w, double c, int q);
	Pallet(const Pallet & p);
	~Pallet() {};

	void setCube();

	int getQuanity() { return quanity; };
	double getLength() { return p_length; };
	double getWidth() { return p_width; };
	double getCube() {return p_width * p_length * quanity; };
	double getPalSize() { return p_width * p_length; };
	double getWidthSize() { return p_width * 2; };

	friend std::istream & operator>>(std::istream & is, Pallet & s);
	friend std::ostream & operator<<(std::ostream & os, const Pallet & s);
};

class Car : Pallet
{
private:
	double cubeMetr;
	double length;
	double width;

	double area;
	int palletRow = 2;
	double Sload; //calculation
	double SloadQ;
public:
	Car() {}
	Car(double l, double w, double m);
	Car(const Car & c);
	~Car() {};

	void setCubeM();

	double getLength() { return length; };
	double getWidth() { return width; };
	double getCubeMetr() { return length * width; };
	bool loadWidth();

	friend std::istream & operator>>(std::istream & is, Car & s);
	friend std::ostream & operator<<(std::ostream & os, const Car & s);

	void setWidthArea();
	void setSloadQ();
	void setSload();

	double getArea() { return area; };
	double getLengthLoad() { return Sload; };
	double getSloadQ() { return SloadQ; };

	bool multiMachLoad();
};

class CarCatalogue
{
public:
	enum Truck{Porter, EuroTruck, Gazel, MersedesSprinter, FiveTonCar, TenTonCar };
	struct CarPorter 
	{
		double length = 2.750;
		double width = 1.7;
		double area = 4.675;
		std::string name = "Porter";
	} carPorter;
	struct CarEuroTrack
	{
		double length = 13.6;
		double width = 2.4;
		double area = 32.64;
		std::string name = "EuroTruck";
	};

	struct CarGazel
	{
		double length = 1.9;
		double width = 1.9;
		double area = 3.61;
		std::string name = "Gazel";
	};
	 struct CarMersedesSprinter
	{
		double length = 2.6;
		double width = 1.4;
		double area = 3.64;
		std::string name = "MersedesSprinter";
	};
	 struct CarFiveTonCar
	{
		double length = 5.0;
		double width = 2.4;
		double area= 12;
		std::string name = "FiveTonTruck";
	};
	 struct CarTenTonCar
	{
		double length = 8.0;
		double width = 2.4;
		double area = 19.2;
		std::string name = "TenTonTruck";
	};
	double LoadLength(double l, double w, int q);
	int LoadWidth(double w);
	void getCar(double l, int w, double pw);
};
