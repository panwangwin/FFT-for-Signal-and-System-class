//
//  Complex.cpp
//  FFT_1st_v
//
//  Created by PAN on 16-5-22.
//  Copyright (c) 2016年 prowind. All rights reserved.
//

#include "Complex.h"
Complex::Complex()
{
    real = img = 0;
}

Complex::Complex(double r, double i)
{
    real = r;
    img = i;
}

Complex Complex::operator+(Complex &rc)
{
    Complex c;
    c.real = real + rc.real;
    c.img = img + rc.img;
    return c;
}

Complex Complex::operator-(Complex &rc)
{
    Complex c;
    c.real = real - rc.real;
    c.img = img - rc.img;
    return c;
}

void Complex::operator=(Complex &rc)
{
    real = rc.real;
    img = rc.img;
}

Complex Complex::operator*(Complex &rc)
{
    Complex c;
    c.real = real*rc.real-img*rc.img;
    c.img = real*rc.img + img*rc.real;
    return c;
}

Complex Complex::operator*(double rc)
{
    Complex c;
    c.real = real*rc;
    c.img = img*rc;
    return c;
}

void Complex::power(int n,Complex &rc)
{
    int *a0 = new int[n / 4 + 1], index0=0;
    int *a1 = new int[n / 4 + 1], index1 = 0;
    int *a2 = new int[n / 4 + 1], index2 = 0;
    int *a3 = new int[n / 4 + 1], index3 = 0;
    a0[n / 4] = a1[n / 4] = a2[n / 4] = a3[n / 4] = -1;
    for (int i = 0; i <= n; i++)
    {
        int j = i % 4;
        switch (j)
        {
            case 0:a0[index0] = i; index0++; break;
            case 1:a1[index1] = i; index1++; break;
            case 2:a2[index2] = i; index2++; break;
            case 3:a3[index3] = i; index3++; break;
        }
    }
    for (int k = 0; k <= n / 4; k++)
    {
        if (a0[k] != -1)
            real += Binomial_Coefficient(n, a0[k])*pow_plus(rc.real, n - a0[k])*pow_plus(rc.img, a0[k]);
        else break;
    }
    for (int k = 0; k <= n / 4; k++)
    {
        if(a2[k]!=-1)
            real-= Binomial_Coefficient(n, a2[k])*pow_plus(rc.real, n - a2[k])*pow_plus(rc.img, a2[k]);
        else break;
    }
    for (int k = 0; k <= n / 4; k++)
    {
        if (a1[k] != -1)
            img += Binomial_Coefficient(n, a1[k])*pow_plus(rc.real, n - a1[k])*pow_plus(rc.img, a1[k]);
        else break;
    }
    for (int k = 0; k <= n / 4; k++)
    {
        if (a3[k] != -1)
            img -= Binomial_Coefficient(n, a3[k])*pow_plus(rc.real, n - a3[k])*pow_plus(rc.img, a3[k]);
        else break;
    }
    delete[]a0;
    delete[]a1;
    delete[]a2;
    delete[]a3;
}

double Binomial_Coefficient(int n, int k)
{
    double i=1;
    for (double index1 = 0; index1 <= k - 1; index1++)
        i *= n - index1;
    for (double index2 = 1; index2 <= k; index2++)
        i /= index2;
    return i;
}

double pow_plus(double x, int k)
{
    double i = 1;
    if (k == 0)
        return i;
    else
    {
        for (int index = 0; index < k; index++)
            i *= x;
    }
    return i;
}