total = 0

def reformat_line(line: str) -> str:
    mapping = {
        'one': 1,
        'two': 2,
        'three': 3,
        'four': 4,
        'five': 5,
        'six': 6,
        'seven': 7,
        'eight': 8,
        'nine': 9,
    }

    for key in mapping:
        line = line.replace(key, key + str(mapping[key]) + key)
    
    return line

with open("../input.txt") as f:
    for line in f:

        formatted_line = reformat_line(line)

        digits = "".join([char for char in formatted_line if char.isdigit()])
        digits = digits[0] + digits[-1]

        total += int(digits)

print(total)