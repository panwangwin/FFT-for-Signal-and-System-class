extern double Binomial_Coefficient(int n, int k);
extern double pow_plus(double x, int k);
class Complex
{
public:Complex();
	Complex(double r, double i);
	   Complex operator+(Complex &rc);
	   Complex operator-(Complex &rc);
	   Complex operator*(Complex &rc);
	   Complex operator*(double rc);
	   void power(int n,Complex &rc);
	   void operator=(Complex &rc);
	   double real;
	   double img;
};

