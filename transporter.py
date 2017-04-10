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
my_file.close()
print(my_list[0])
if (my_list[0][2] == "0"):
	#import success
	my_list[0][2] = "1"
	print(my_list[0])
	with open('resources.csv','w') as opened_file:
		writer = csv.writer(opened_file)
		writer.writerow([x for x in my_list[0]])
		
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
