#!/usr/bin/env python
import csv
import cgi
# 2. [X] Otherwise read from resources to check if someone is in room

print "Content-Type: text/html"
print

with open("../resources.csv", "r") as f:
    reader = csv.reader(f, delimiter=',')
    my_list = list(reader)
f.close()


# 3. [ X ] If room isn't unoccupied print our page.
my_list[0][2] = "0"

# [ ] Rewrite resource with new occupied value
with open('../resources.csv','w') as f:
    writer = csv.writer(f)
    writer.writerow([x for x in my_list[0]])
f.close()

