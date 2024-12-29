#5b
import matplotlib.pyplot as plt
import random as rdm
data = [rdm.randint(0,100) for _ in range(0,5)]
clrs = ["red", "green", "blue", "gold", "orange"]
lbl = ["p1", "p2", "p3", "p4", "p5"]
plt.pie(data, labels=lbl)
plt.tight_layout()
plt.axis('equal')
plt.title("Player v/s Score")
plt.show()