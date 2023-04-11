from cs50 import get_float

while True:
    # prompting user
    x = get_float("change owed:")
    if x > 0:
        break

cents = round(x * 100)
c = 0

while cents - 25 >= 0:
    # checks for cents in quarters
    cents -= 25
    c += 1

while cents - 10 >= 0:
    # checks for cents in dimes
    cents -= 10
    c += 1

while cents - 5 >= 0:
    # checks for cents in nickels
    cents -= 5
    c += 1

while cents - 1 >= 0:
    # checks for cents in pennies
    cents -= 1
    c += 1

print(f"{c}")

