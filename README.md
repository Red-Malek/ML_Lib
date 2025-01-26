hi we are two university student 
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Example data points (X: independent variable, y: dependent variable)
X = np.array([2,4,2,5,6.5,8,5,8,4,7]).reshape(-1, 1)  # Reshape for a single feature (column)
y = np.array([5,4,7,2,5,6,5.2,8.2,6.1,10.2])

# Create and fit the model
model = LinearRegression()
model.fit(X, y)

# Get the slope (a) and intercept (b)
a = model.coef_[0]  # Slope
b = model.intercept_  # Intercept

print(f"Optimal slope (a): {a}")
print(f"Optimal intercept (b): {b}")

# Plotting the results
plt.scatter(X, y, color='blue', label="Data Points")
plt.plot(X, model.predict(X), color='red', label="Fitted Line")
plt.xlabel("X")
plt.ylabel("y")
plt.legend()
plt.show()
