//
//  main.cpp
//  FFT_1st_v
//
//  Created by PAN on 16-5-22.
//  Copyright (c) 2016年 prowind. All rights reserved.
//

#include "read_and_usd.h"
#include <iostream>
int main()
{
    Complex* a;
    a=upside_down(read("/users/panou/desktop/aaaaa.txt"));
    for (int i = 0; i < 8; i++)
    {
        std::cout<<a[i].real<<" ";
        std::cout<<a[i].img<<" ";
    }
        return 0;
    
}
