from random import sample
import re

grouped_reg_no = {1: [],
        2: [],
        3: [],
        4: []}

class Group:
    instances = dict()
    def __init__(self, group_number, group_members):
        self.group_name = group_number
        self.members = [member for member in group_members]
        self.instances[f"{self.group_name}"] = self.members

def group_reg_no():
    with open("reg_no.tsv") as file:
        for reg in file:
            reg = re.sub("\t", "|", reg)
            details = re.search("\d\d\d\d", reg)
            match int(details.group()[-1]):
                case num if num in range(0, 3):
                    grouped_reg_no[1].append(details.string)
                
                case num if num in range(3, 6):
                    grouped_reg_no[2].append(details.string)

                case num if num in range(6, 9):
                    grouped_reg_no[3].append(details.string)
                
                case 9:
                    grouped_reg_no[4].append(details.string)

                case _:
                    continue
            
def create_groups():
    group_number  = 1
    counter  = 1
    while counter <= 4:
        while len(grouped_reg_no[counter]) >= 3:
            group = sample(grouped_reg_no[counter], k=3)
            Group(group_number, group)
            for member in group:
                grouped_reg_no[counter].remove(member)

            group_number += 1
        counter += 1


def save_to_txt():
    file = open("groups.txt", "w+")
    for key in Group.instances:
        last_group_no = int(key)
        file.write(f"\nGroup{key}\n")
        for member in Group.instances[key]:
            file.write(member)
    new_group = []
    for key in grouped_reg_no:
        if len(grouped_reg_no[key]) > 0:
            for member in grouped_reg_no[key]:
                new_group.append(member)
    
    file.write(f"\nGroup{last_group_no + 1}\n")
    for member in new_group:
        file.write(member)

    file.close()

if __name__ == "__main__":
    group_reg_no()
    create_groups()
    save_to_txt()

