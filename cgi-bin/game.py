#!/usr/bin/env python
import cgi
import csv
import requests
from random import randint
import cgitb
cgitb.enable()

#status="error" or status="success"
def printA(message, status):
	print("<div class=\"result " + status + "\">" + message + "</div>")
	return

def printRoom(winForm): 
	with open("../game.html", "r") as file:
		lines = file.read().split('\n')
	file.close()
	for i in range(len(lines)): 
		if (winForm):
			lines[i] = lines[i].replace("none", "block")
		lines[i] = lines[i].replace("Room has...", "Room has {0} Mana and {1} Gold".format(resource[0][0], resource[0][1]))
		lines[i] = lines[i].replace("?", "<input type=\"hidden\" name=\"inventory\"value=\"{0},{1}\">".format(mana,gold))
		lines[i] =lines[i].replace("#", "<div class=\"playerItem\"> Your inventory: </br> Mana: {0} </br> Gold: {1} </div>".format(mana,gold))
	for i in range(len(lines)):
		print(lines[i])
	return

def writeResource(list):
	with open('../resources.csv','w') as opened_file:
		writer = csv.writer(opened_file)
		writer.writerow([x for x in list[0]])
	return

print "Content-Type: text/html"
print

form = cgi.FieldStorage()
# Generate a number
guess = randint(0,3)

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
		if (int(command) == guess):
			printRoom(True)
		else:
			printRoom(False)
			printA("Wrong guess. Try again", "error")
	else:
		printRoom(False)
		printA("Invalid Command", "error")
	# Finish up other process 
	# New page reward form processing
elif 'reward' not in form:
	printRoom(False)
	printA("Invalid Command", "error")
else:
	reward = form['reward'].value.split(',')
	rewardMana = int(reward[0]) + int(mana)
	rewardGold = int(reward[1]) + int(gold)
	roomLimitMana = int(resource[0][0]) - int(reward[0])
	roomLimitGold = int(resource[0][1]) - int(reward[1])

	# If player doesn't try to take more than is available
	if (roomLimitMana >= 0 and roomLimitGold >=0):
		
		if (rewardGold < 100):
			r = requests.post("http://cs.mcgill.ca/~jma229/cgi-bin/room.cgi", data = { 'command': 'play', 'inventory': '{0},{1}'.format(rewardMana, rewardGold)})
			print(r.content)
			resource[0][0] = roomLimitMana
			resource[0][1] = roomLimitGold
			writeResource(resource)
			printA("Successfully added gold and mana to your inventory", "success")
		else:
			print("You won :D")	
	else:
		printRoom(True)
		printA("The room doesn't have the much resources, choose again.", "error")
	


