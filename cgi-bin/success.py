# 2. [X] Otherwise read from resources to check if someone is in room
with open("../resources.csv", "r") as f:
    reader = csv.reader(f, delimiter=',')
    my_list = list(reader)
f.close()


# 3. [ X ] If room isn't unoccupied print our page.
my_list[0][2] = "0"

# [ ] Rewrite resource with new occupied value
with open('../resources.csv','w') as opened_file:
    writer = csv.writer(opened_file)
    writer.writerow([x for x in my_list[0]])