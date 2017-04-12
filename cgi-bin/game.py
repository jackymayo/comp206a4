#!/usr/bin/env python
import cgi
import csv
import requests
from random import randint
import cgitb
cgitb.enable()

def printA(message, status):
	print("<div class=\"result " + status + "\">" + message + "</div>")
	return

print "Content-Type: text/html"
print

form = cgi.FieldStorage()
# Generate a number
# guess = randint(0,10)
guess = 2
# Get the number of resources
with open("../resources.csv", "r") as f:
    reader = csv.reader(f, delimiter=',')
    resource = list(reader)
f.close()

# Get his inventory	
playerItem = form['inventory'].value.split(',')
mana = playerItem[0]
gold = playerItem[1]

# Get his command either a number or quit
# If he's not using reward form
if 'command' in form:
	command = form['command'].value.lower()
	if ("quit" in command):
		r = requests.post("http://cs.mcgill.ca/~jma229/cgi-bin/room.cgi", data = { 'command': 'refresh', 'inventory': '{0},{1}'.format(mana, gold)})
		print(r.content)
	elif (command.isdigit()):
		# If player guesses correctely
		if (command == guess):
			with ("../game.html", "r") as f:
				lines = f.readlines()
			lines.replace("display: none", "display: block")
			lines.replace("Room has ...", "Room has {0} Mana and {1} Gold".format(resource[0][1], resource[0][1]))
	# Finish up other process 
# New page reward form processing
else:
	reward = form['reward'].value.split(',')
	rewardMana = float(reward[0]) + float(mana)
	rewardGold = float(reward[1]) + float(gold)
	roomLimitMana = float(resource[0][0]) - float(reward[0])
	roomLimitGold = float(resource[0][1]) - float(reward[1])

	# If player doesn't try to take more than is available
	if (roomLimitMana >= 0 and roomLimitGold >=0):
		r = requests.post("http://cs.mcgill.ca/~jma229/cgi-bin/room.cgi", data = { 'command': 'play', 'inventory': '{0},{1}'.format(rewardMana, rewardGold)})
		print(r.content)
	else:
		r = requests.post("http://cs.mcgill.ca/~jma229/cgi-bin/room.cgi", data = { 'command': 'play', 'inventory': '{0},{1}'.format(mana,gold)})
		print(r.content)
		printA("The room doesn't have the much resources, choose again.", "error")
		# print("<div class=\"result error\"> The room doesn't have that much choose another option... </div>")


