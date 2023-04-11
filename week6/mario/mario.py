from cs50 import get_int

while (True):
    # takes user input for height
    n = get_int("height:")
    if n >= 1 and n <= 8:
        break


for i in range(n):
    # loops in order to print out the shape
    for x in range(n):
        if x + i >= n - 1:
            print("#", end="")
        else:
            print(" ", end="")
    print()