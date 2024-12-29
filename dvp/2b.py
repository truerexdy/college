#2b
def home():
    print("1. bin to dec")
    print("2. oct to hex")
    print("3. exit")

def bin2dec(x):
    return int(x, 2)

def oct2hex(x):
    return hex(int(x,8))

uin = 1
while uin != 3:
    home()
    uin = int(input())
    if uin == 1:
        print(f"In deciaml {bin2dec(input("Enter the bin number"))}")
    elif uin == 2:
        print(f"In hexadeciaml {oct2hex(input("Enter the oct number"))[2::]}")
    elif uin == 3:
        break
    else:
        print(f"Enter a valid option")