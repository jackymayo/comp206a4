#import urlparse
import sys
import csv

with open("resources.csv", 'r') as my_file:
    reader = csv.reader(my_file, delimiter=',')
    my_list = list(reader)
    print(my_list)

print(my_list[0][2])
#url = ""
#parsed = urlparse.urlparse(url)

#def transporter("", parsed):


#def main(argv):


#if __name__ == "__main__":
#	main(sys.argv)
