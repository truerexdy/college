#1b
uin = input("Enter the number or string:")
if uin==uin[::-1]:
    print("Given number or string is a palindrome")
else:
    print("Given number or string is not a palindrome")
uniq = set(uin)
for i in uniq:
    print(f"{i} appears {uin.count(i)} times")