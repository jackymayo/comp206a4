import sys
import csv
import cgi
import requests
# Dictionary ["url":.."Inventory"]
form = cgi.FieldStorage()

print(form.getvalue('inventory'))

with open("resources.csv", 'r') as my_file:
    reader = csv.reader(my_file, delimiter=',')
    my_list = list(reader)
    #print(my_list)

#print(my_list[0][2])
if (my_list[0][2] == 0):
	#import success
	with open('resources.csv','w') as opened_file:
		writer = csv.writer(opened_file)
		for i in range(len(my_list[0])):
			if (i == 2):
				writer.writerows("1")
else:
	#urlInv = form.values()
	if form.has_key("url"):
		theUrl = form["url"]
		r = requests.post(theUrl, data = {'command':'Refresh'})



#url = ""
#parsed = urlparse.urlparse(url)

#def transporter("", parsed):


#def main(argv):


#if __name__ == "__main__":
#	main(sys.argv)
