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
form = cgi.FieldStorage()

def writeResource(list):
	with open('../resources.csv','w') as opened_file:
		writer = csv.writer(opened_file)
		writer.writerow([x for x in list[0]])
	return
def printHeader():
	print("<!DOCTYPE html><html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"../forthecss.css\"/><meta charset=\"UTF-8\"></head><body>")
	return
print "Content-Type: text/html"
print

if "URL" in form:
	url = form['URL'].value
	# 0.1 [X] Clean URL string to allow for success.py
	if "cgi-bin" not in url:
		successURL = url + "cgi-bin/"

	if "room.cgi" not in url:
		successURL = url + "success.py"
	else:
		successURL = url.replace("room.cgi", "success.py")


# 1. [X] Read from content 
# [ ] Improve dead asthetics
player = form["inventory"].value.split(",")
mana = player[0]
gold = player[1]



# 1. [X] Read from resources to check if someone is in room
with open("../resources.csv", "r") as f:
    reader = csv.reader(f, delimiter=',')
    my_list = list(reader)
f.close()


# 3. [X] If room isn't unoccupied print our page.
if ("0" in my_list[0][2]):
	# 2. Check if player should die
	if (int(mana) == 1):
		print(" <img style=\"display: block; margin: auto; \" src=\"../images/death.png\"/>")
		my_list[0][0] = int(my_list[0][0]) + 1
		# with open('../resources.csv','w') as opened_file:
		# 	writer = csv.writer(opened_file)
		# 	writer.writerow([x for x in my_list[0]])
		writeResource(my_list)
		sys.exit()
	else:
		my_list[0][2] = "1"
		my_list[0][0] = int(my_list[0][0]) + 1
		# [X] Rewrite resource with new occupied value
		# with open('../resources.csv','w') as opened_file:
		# 	writer = csv.writer(opened_file)
		# 	writer.writerow([x for x in my_list[0]])
		writeResource(my_list)
		# [ ] Edge case where people don't have their URL and it calls my success.py
		r = requests.post
		# [X] Call refresh command 
		r = requests.post("http://cs.mcgill.ca/~jma229/cgi-bin/room.cgi", data = { "command":"refresh", "inventory": "{0},{1}".format(mana,gold)})
		print(r.content)
# 4. [ ] Redirect this to the original page.
else:
	printHeader()
	print("Sorry, the room is full o_o")
	print("<body> <form action=\"{0}\" method=\"post\"> <input type=\"submit\" class=\"button\" value=\"Return\"/>".format(url))
	print("<input type=\"hidden\" name=\"inventory\" value=\"{0},{1}\"/>".format(mana,gold))
	print("<input type=\"hidden\" name=\"command\" value=\"refresh\"> </form> </body></html>")
