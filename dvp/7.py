#7
import seaborn as sns
import matplotlib.pyplot as plt
a=[rdm.randint(0,100) for _ in range(0,10)]
sns.histplot(a,bins=5,color='green')
plt.xlabel("Age")
plt.ylabel("Frequency")
plt.title("Distribution of Ages")
plt.show()