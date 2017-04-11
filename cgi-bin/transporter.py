#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import csv
import cgi
import cgitb
cgitb.enable()
import requests
# Dictionary ["url":.."Inventory"]

# form = cgi.FieldStorage()

# Create pseudo form for testing purpose
form = {"URL":"http://cs.mcgill.ca/~jma229/cgi-bin/room.cgi", "inventory":"1,0"}

print "Content-Type: text/html"
print
player = form["inventory"].split(",")
if (player[0] == "1"):
	# Maybe read from a dead.html template?
	print("You just killed yourself. ")
	sys.exit()
with open("../resources.csv", "r") as my_file:
    reader = csv.reader(my_file, delimiter=',')
    my_list = list(reader)
my_file.close()
print(my_list[0])
#If room isn't busy successssss

if (my_list[0][2] == "0"):
	#import success
	my_list[0][2] = "1"
	print(my_list[0])
	with open('../resources.csv','w') as opened_file:
		writer = csv.writer(opened_file)
		writer.writerow([x for x in my_list[0]])

