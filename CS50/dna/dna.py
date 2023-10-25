import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: arg error")

    # TODO: Read database file into a variable
    x = 0
    filename = sys.argv[1]
    with open(filename) as file:
        dna = []
        people = {}
        people_name = []
        for index, row in enumerate(file):
            if index == 0:
                dna = [dna for dna in row.strip().split(",")][1:]
            else:
                current_row = row.strip().split(",")
                people[current_row[0]] = current_row[1:]
                people_name.append([current_row[0]])
    # TODO: Read DNA sequence file into a variable
    dna_seq = sys.argv[2]
    with open(dna_seq) as seq:
        reader = csv.reader(seq)
        for row in reader:
            dna_seq = row
            dna_seq = dna_seq[0]

    str_count = []
    # Searchs through dna_seq for matches
    for strand in dna:
        index = 0
        max_dna = 0
        curr_dna = 0
        # For each different dna strand
        while index < len(dna_seq):
            curr_str = dna_seq[index: index + len(strand)]
            if curr_str == strand:
                curr_dna += 1
                index += len(strand)
            else:
                if curr_dna > max_dna:
                    max_dna = curr_dna
                curr_dna = 0
                index += 1
            smax_dna = str(max_dna)
        # adds all consequtive dna strands to a list
        str_count.append(smax_dna)

    # removes useless dict stuff
    people_dna = list(people.values())

    # looks for matches against peoples dna
    for i in range(len(people_dna)):
        if people_dna[i] == str_count:
            person = people_name[i]
            print(person[0])
            break

    for i in range(len(people_dna)):
        if people_dna[i] != str_count:
            print("No match")


main()
