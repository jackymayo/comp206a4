#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import csv
import cgi
import cgitb
cgitb.enable()
import requests
# Dictionary ["url":.."Inventory"]


# [ ] Replace with actual form when done debugging
# form = cgi.FieldStorage()
form = {"URL":"http://cs.mcgill.ca/~jma229/cgi-bin/room.cgi", "inventory":"10,1"}


# 0.1 [ ] Clean URL string to allow for success.py
if ("cgi-bin") not in form["URL"]:
	successURL = form["URL"] + "cgi-bin/"

if ("room.cgi") not in form["URL"]:
	successURL = form["URL"] + "success.py"
else:
	successURL = form["URL"].replace("room.cgi", "success.py")

print "Content-Type: text/html"
print

# 1. [X] Read from content 
# [ ] Improve dead asthetics
player = form["inventory"].split(",")
mana = player[0]
gold = player[1]

# 1. Check if player should die
if (mana == "1"):
	print("You just killed yourself. ")
	sys.exit()

# 2. [X] Otherwise read from resources to check if someone is in room
with open("../resources.csv", "r") as f:
    reader = csv.reader(f, delimiter=',')
    my_list = list(reader)
f.close()

# 3. [ X ] If room isn't unoccupied print our page.
if ("0" in my_list[0][2]):
	my_list[0][2] = "1"
	print(my_list[0])
	# [ ] Rewrite resource with new occupied value
	with open('../resources.csv','w') as opened_file:
		writer = csv.writer(opened_file)
		writer.writerow([x for x in my_list[0]])
	# [ ] Call refresh command 
	r = requests.post("http://cs.mcgill.ca/~jma229/cgi-bin/room.cgi", data = { "command":"refresh", "inventory": "{0},{1}".format(mana,gold)})

	print r.content
	# [ ] Remember to call success.py
	r = requests.post(successURL)

# 4. [ ] 