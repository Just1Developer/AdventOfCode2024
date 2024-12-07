import os

# Range from 3 to 25
for i in range(3, 26):
    # Generate filenames
    file1 = f"day{i}.txt"
    file2 = f"day{i}e1.txt"

    # Create empty files
    open(file1, 'w').close()
    open(file2, 'w').close()

print("Files created successfully.")
