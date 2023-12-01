total = 0

with open("../input.txt") as f:
    for line in f:
        digits = "".join([char for char in line if char.isdigit()])
        digits = digits[0] + digits[-1]
        total += int(digits)

print(total)