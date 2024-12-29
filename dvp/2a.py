#2a
def F(x):
    if x<2:
        return 1
    return F(x-1)+F(x-2)
uin = input("Enter a number(>0):")
if int(uin)<0:
    print("Enter a value greater than 0")
else:
    print(f"F(x) = {F(int(uin))}")