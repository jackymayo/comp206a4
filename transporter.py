import urlparsse
import sys
import csv

with open("resource.csv", 'r') as my_file:
    reader = csv.reader(my_file, delimiter='\t')
    my_list = list(reader)
    print(my_list)

url = ""
parsed = urlparse.urlparse(url)

def transporter("", parsed):


def main(argv):


if __name__ == "__main__":
	main(sys.argv)
