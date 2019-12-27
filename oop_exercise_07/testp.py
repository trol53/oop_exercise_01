#!/usr/bin/env python3.7
from tkinter import *
import sys
root = Tk(className='Figure')

c = Canvas(root, width = 500, height = 500, bg = 'white')
c.pack()
i = 0
f = open('temp.txt','r')
mass = f.read()
word = mass.split()
while i < len(word):
    cord = []
    j = 0
    while j < 8:
        cord.append((250 + 3 * float(word[i])))
        j = j + 1
        i = i + 1
        cord.append((250 - 3 * float(word[i])))
        i = i + 1
        j = j + 1
    c.create_line(cord[0], cord[1], cord[2], cord[3])
    c.create_line(cord[2], cord[3], cord[4], cord[5])
    c.create_line(cord[4], cord[5], cord[6], cord[7])
    c.create_line(cord[6], cord[7], cord[0], cord[1])

c.create_line(250,0,250,500)
c.create_line(0,250,500,250)
root.mainloop()

