#include<iostream>
using namespace std;
namespace nm9
{
	class Rect;
	class Polar
	{
		double angle;
		double dist;
	public:
		Polar(double angle, double dist) :angle(angle), dist(dist)
		{
		}
		operator Rect();
	};
	class Rect
	{
		double xCor;
		double yCor;
	public:
		Rect(double xCor, double yCor) :xCor(xCor), yCor(yCor)
		{
		}
		Rect() :xCor(0.0), yCor(0.0)
		{
		}
		friend ostream & operator<<(ostream & os, Rect &rect)
		{
			os << "x=" << rect.xCor << " and y=" << rect.yCor << endl;
			return os;
		}
	};
	Polar::operator Rect()
	{
		Rect temp;// (10.0, 20.0);
		return temp;
	}

	void main()
	{
		Polar p(3.14 / 2.0, 15.0);
		Rect r;
		r = p;
		cout << r << endl;
	}
}