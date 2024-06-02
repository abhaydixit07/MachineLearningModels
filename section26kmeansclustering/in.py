import subprocess

# Compile the C++ program
subprocess.run(["g++", "-o", "sort", "test.cpp"], check=True)

# Run the compiled program and capture its output
result = subprocess.run(["./sort"], capture_output=True, text=True)

# Extract the time taken from the output
time_taken = float(result.stdout.split()[-2])

# Now you can use `time_taken` in your Python program
print(f"The time taken by std::sort() in the C++ program was {time_taken} seconds")