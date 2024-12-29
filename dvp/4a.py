#4a
import matplotlib.pyplot as plt
import random as rdm
a=[1,2,3,4,5]
b=[rdm.randint(0,100) for _ in range(0,5)]
plt.bar(a,b)
plt.xlabel("Days")
plt.ylabel("Score")
plt.title("Cricket Score")
plt.show()