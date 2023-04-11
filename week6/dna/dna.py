from sys import argv, exit
import csv


def get_maximum_num_of_times_substring(s, sub):
    # calculate max # times sub string  repeated
    ans = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]
    return max(ans)


def print_match(reader, actual):
    # prints the match of taking the input
    for line in reader:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == actual:
            print(person)
            return
    print("No match")


def main():
    # main function which implements everything else
    if len(argv) != 3:
        print("Usage: python dna.py dna.csv sequence.txt")
        exit(1)

    csv_path = argv[1]
    with open(csv_path) as csv_file:
        reader = csv.reader(csv_file)
        # for row in reader:
        # print(row)
        all_sequences = next(reader)[1:]

        txt_path = argv[2]
        with open(txt_path) as txt_file:
            s = txt_file.read()
            actual = [get_maximum_num_of_times_substring(s, seq) for seq in all_sequences]

        print_match(reader, actual)


if __name__ == "__main__":
    main()