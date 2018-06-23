# -*- coding: utf-8 -*-
"""
Created on Thu Mar 15 16:24:24 2018

@author: Himanshu
"""

import random
smal=int(input("Enter the smaller num: "))
large=int(input("enter the larger num: "))
mynum=random.randint(smal,large)
count=0
while True:
    count +=1
    usernum=int(input("Enter your guess: "))
    if usernum<mynum:
        print("Too small")
    elif usernum>mynum:
        print("Too large")
    else:
        print("congratulations! YOU'VE got it in", count, "tries!")
        break
