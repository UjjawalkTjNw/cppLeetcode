def print_kwargs(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}: {value}")

# Calling the function with different keyword arguments
print_kwargs(name="Alice", age=30, city="New York")
print_kwargs(color="blue", size=10, weight=5)