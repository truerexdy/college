#3a
uin = input("Enter a sentence:")
print(f"Number of words = {len(uin.split())}")
count = [0,0,0,0]
for i in uin:
    if i.isdecimal():
        count[0] += 1
    elif i.islower():
        count[1] += 1
    elif i.isupper():
        count[2]+= 1
    else:
        count[3] += 1
print(f"Digits = {count[0]}")
print(f"Lowercase = {count[1]}")
print(f"Uppercase = {count[2]}")
print(f"Special = {count[3]}")