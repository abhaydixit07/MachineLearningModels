import time

# Generate a large list of random integers
import random
random_list = [random.randint(0, 1000000) for _ in range(1000000)]

# Measure the time taken by list.sort()
start_time = time.time()
random_list.sort()
end_time = time.time()
print(f"Time taken by list.sort(): {end_time - start_time} seconds")

# Generate a new large list of random integers
random_list = [random.randint(0, 1000000) for _ in range(1000000)]

# Measure the time taken by sorted()
start_time = time.time()
sorted_list = sorted(random_list)
end_time = time.time()
print(f"Time taken by sorted(): {end_time - start_time} seconds")
