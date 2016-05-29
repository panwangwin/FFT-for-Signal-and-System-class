//
//  main.cpp
//  FFT_1st_v
//
//  Created by PAN on 16-5-22.
//  Copyright (c) 2016年 prowind. All rights reserved.
//

#include "read_and_usd.h"
#include <iostream>
#include <cmath>
#include <omp.h>
#include <time.h>
int main()
{
    Complex* a;
    a=upside_down(read("/temp/test2.txt"));
	const int N = 16384;
	const double pi = 3.1415926;
	int T = 0;
	int temp_i = 0;
	T = log(N) / log(2);
	Complex x[N];
	/*for (int i = 0; i < N; i++) {
		x[i] = a[i];
	}*/
	clock_t t1 = clock();
	Complex temp[N];
    //#pragma omp parallel for
	for (int t = 0; t<T; t++) {
		int ni = 0;
		ni = pow(2, t + 1);//每个模块中的元素数目，同时也是W的底数 
		int n = 0;
		n = N / ni;//模块的总数（此处可以并行）
		int temp_t = 1;
		//temp_t = pow(2, t);
		for (int s = 0; s < t; s++) {
			temp_t = temp_t * 2;
		}
		//int temp_i = 0;
#pragma omp parallel for
		for (int j = 0; j<n; j++) {
			for (int i = j*ni; i<(j + 0.5)*ni; i++) {
				temp_i = i - j*ni;
				Complex w(cos(2 * pi*temp_i/ ni), sin(-2 * pi*temp_i/ ni));//w是在每一个模块中，前半段的序号
				temp[i] = a[i] + a[i + temp_t] * w;
				temp[i + temp_t] = a[i] - a[i + temp_t] * w;
			}
		}
		for (int i = 0; i<N; i++) {
			a[i] = temp[i];
		}
	}
	/*for (int i = 0; i < N; i++) {
		std::cout << a[i].real << "+i"<<a[i].img <<std::endl;
	}*/
	clock_t t2 = clock();
	std::cout <<"time:"<<t2-t1<< std::endl;
	return 0;
}