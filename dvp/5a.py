#5a
import matplotlib.pyplot as plt
import random as rdm
a=[rdm.randint(0,100) for _ in range(0,10)]
plt.hist(a,bins=5)
plt.xlabel("Days")
plt.ylabel("Score")
plt.title("Cricket Score")
plt.grid(True)
plt.show()