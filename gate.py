#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2020-09-13 15:08:05
# @Author  : Your Name (you@example.org)
# @Link    : link
# @Version : 1.0.0

import os

def solve(landing, takeoff, wait, init) :
    waiting_arr = []
    for i in landing :
        temp_i = str(i)
        final_time = temp_i
        temp_add = int(temp_i[-2:]) + wait
        if temp_add > 59 :
            temp_hr = int(temp_i[:-2]) + 1
            print(temp_hr,'hr')
            temp_add -= 60
            temp_add = str(temp_add)
            if int(temp_add) < 10 : 
                temp_add = str(temp_add)
                temp_add = '0' + temp_add
            final_time = str(temp_hr) + (temp_add)
            waiting_arr.append(int(final_time))
        else :
            final_time = int(final_time)
            final_time += wait
            waiting_arr.append(final_time)
    
    print(waiting_arr)


if __name__ == "__main__":
    landing = [630,645,730,1100]
    solve(landing,[],20,1)
