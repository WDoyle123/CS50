from cs50 import get_int

# Do while loop -- works
while True:
    n = get_int("Height: ")
    if n <= 8 and n >= 1:
        break

for row in range(1, n+1):
    print(" " * (n - row) + "#" * row + " " * 2 + "#" * row)
