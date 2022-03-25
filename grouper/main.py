from random import sample
import re

grouped_reg_no = {1: [], # dictionary to save the registration numbers in groups
        2: [], # registration numbers ending in 3, 4, 5
        3: [], # registration numbers ending in 6, 7, 8
        4: []} 

class Group:
    instances = dict() # keep track of all the instances of the class
    def __init__(self, group_number, group_members):
        self.group_name = group_number
        self.members = [member for member in group_members]
        self.instances[f"{self.group_name}"] = self.members

def group_reg_no(): # function to group the registrations numbers accordingly
    with open("reg_no.tsv") as file:
        for reg in file:
            reg = re.sub("\t", " | ", reg) # replace tabs with |
            details = re.search("\d\d\d\d", reg) # search for the first occurrence of 4 digits
            match int(details.group()[-1]): # check the last digit of the four above
                case num if num in range(0, 3):
                    grouped_reg_no[1].append(details.string) # save the string originally passed in line 20 to the dictionary
                
                case num if num in range(3, 6):
                    grouped_reg_no[2].append(details.string)

                case num if num in range(6, 9):
                    grouped_reg_no[3].append(details.string)
                
                case 9:
                    grouped_reg_no[4].append(details.string)

                case _:
                    continue
            
def create_groups(): # function to create groups
    group_number  = 1 # counter to name the groups
    counter  = 1 # counter for keys(groups) in the grouped_reg_no dictionary
    while counter <= 4:
        while len(grouped_reg_no[counter]) >= 3:
            group = sample(grouped_reg_no[counter], k=3) # randomly select 3 registration numbers
            Group(group_number, group) # create  a group
            for member in group: # remove the selected samples from the dictionary
                grouped_reg_no[counter].remove(member)

            group_number += 1
        counter += 1


def save_to_txt(): #function to save the groups to a txt file
    file = open("groups.txt", "w+")
    for key in Group.instances: 
        last_group_no = int(key)
        file.write(f"Group {key}\n")
        for member in Group.instances[key]:
            file.write(member)
        file.write("\n")
    # some groups have number of members not divisible by 3
    new_group = []
    for key in grouped_reg_no: # for the ungrouped individuals, make a group for them
        if len(grouped_reg_no[key]) > 0:
            for member in grouped_reg_no[key]:
                new_group.append(member)
    
    file.write(f"\nGroup {last_group_no + 1}\n")
    for member in new_group:
        file.write(member)

    file.close()


if __name__ == "__main__":
    group_reg_no()
    create_groups()
    save_to_txt()

