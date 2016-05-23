//
//  read_and_usd.h
//  FFT_1st_v
//
//  Created by PAN on 16-5-22.
//  Copyright (c) 2016年 prowind. All rights reserved.
//

#ifndef FFT_1st_v_read_and_usd_h
#define FFT_1st_v_read_and_usd_h


#endif

#include "Complex.h"
#include <fstream>
#include <string>
#include <math.h>


Complex * read(std::string file_name);
Complex * upside_down(Complex * coefficient);

