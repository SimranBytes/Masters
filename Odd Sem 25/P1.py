import numpy as np
import matplotlib.pyplot as plt

n = [1000, 5000, 10000, 50000, 100000, 500000, 1000000]
linear_time = [2.165, 11.301, 36.983, 58.769, 137.556, 68.16, 100.897]
binary_time = [0.059, 0.103, 0.119, 0.227, 0.12, 0.11, 0.087]
logn = np.log2(n)

plt.figure(figsize=(9,6))
plt.plot(n, linear_time, marker='o', label='Linear Search (measured)')
plt.plot(n, binary_time, marker='s', label='Binary Search (measured)')

plt.xlabel("Number of elements (n)")
plt.ylabel("Execution Time (microseconds)")
plt.title("Linear vs Binary Search Time Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
