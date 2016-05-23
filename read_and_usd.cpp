#include "read_and_usd.h"

int length;

Complex * read(std::string file_name)
{
    std::fstream in(file_name);
    int n;
    in >> length;
    n=length;
    Complex * a= new Complex[n];
	for (int i = 0; i < n; i++)
	{
        in>>a[i].real;
        in>>a[i].img;
	}
	return a;
}


Complex * upside_down(Complex * coefficient)
{
	int n=log(length)/log(2);
	Complex  * usd=new Complex[length];
	int b = pow(2, n);
	int *a = new int[b];
	for (int i = 0; i < b; i++)
	{
		int dummy = i;
		a[i] = 0;
		for (int j = n - 1; j > -1; j--)
			if ((dummy - pow(2, j)) >= 0)
			{
				a[i] = a[i] + pow(2, n - 1 - j);
				dummy = dummy - pow(2, j);
			}
	}
	for (int i = 0; i < b; i++)
        usd[a[i]] = coefficient[i];
    delete coefficient;
    return usd;
}