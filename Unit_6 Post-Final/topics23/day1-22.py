
file_path = "input.txt"

champ = 0

sum = 0

calories = []

with open("input1-22.txt") as file:
    for line in file.readlines():
        # Process each line here
        line = line.strip()
        if not line:
            if sum > champ:
                champ = sum
            calories.append(sum)
            sum = 0
        else:
            sum += int(line)

print (champ)
calories.sort()

print (calories[-1] + calories[-2] + calories[-3])

