#1a
marks = []
print("Enter the 3 tests' marks(out of 100):")
for i in range(3):
    marks.append(int(input(f"Test {i+1} marks = ")))
marks.sort(reverse=True)
best2ave=(marks[0]+marks[1])/2
print(f"The best of two averages is {best2ave}")