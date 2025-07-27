import matplotlib.pyplot as plt

# Read timings from file
versions = []
times = []

with open("o2.txt", "r") as f:
    for line in f:
        if ':' in line:
            parts = line.strip().split(':')
            version = parts[0]
            time_str = parts[1].split()[0]
            versions.append(version)
            times.append(float(time_str))

# Plot
plt.figure(figsize=(10,6))
bars = plt.bar(versions, times, color='red')

plt.title('Merge Sort Optimizations Benchmark')
plt.xlabel('Version')
plt.ylabel('Average Time (seconds)')
plt.ylim(0, max(times)*1.1)

for bar, time in zip(bars, times):
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2.0, yval + 0.005, f'{time:.4f}', ha='center', va='bottom')

plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.tight_layout()
plt.savefig('benchmark_results2.png', dpi=300)
plt.show()
