#ifndef __TMONOM_H__
#define __TMONOM_H__
const int MAX_DEG = 999;

class TMonom
{
private:
	double  coef;
	int deg;
public:
	TMonom(int d,double c);
	TMonom();
	int GetDeg() { return deg; }
	double GetCoef() { return coef; }
	TMonom operator+(const TMonom &m);
	TMonom operator*(double c);
	TMonom& operator=(const TMonom &m);
	TMonom operator-(const TMonom &m);

	bool operator==(const TMonom &m) const;
	bool operator!=(const TMonom &m) const;
};


#endif 

