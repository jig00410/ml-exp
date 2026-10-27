 Program -1 



import numpy as np

X = np.array([5.0, 1.50, 2.00, 4.25, 3.25, 5.50], ndmin=2).reshape((6, 1))
y = np.array([0, 0, 0, 1, 1, 1])

x_mean = np.mean(X)
y_mean = np.mean(y)
n = len(X)

class LogisticRegression:
    b0 = 0
    b1 = 0

    def fit(self, X, y):
        upward_function = 0
        downward_function = 0

        for i in range(n):
            upward_function += (X[i] - x_mean) * (y[i] - y_mean)
            downward_function += (X[i] - x_mean) ** 2

        self.b1 = upward_function / downward_function
        self.b0 = y_mean - (self.b1 * x_mean)

        return self.b0, self.b1

    def predict(self, Xi):
        z = self.b0 + (self.b1 * Xi)
        sigmoid = 1 / (1 + np.exp(-z))

        if sigmoid >= 0.5:
            y_pred = 1
        else:
            y_pred = 0

        return sigmoid, y_pred


model = LogisticRegression()

print(model.fit(X, y))
print(model.predict(2.7))






Program-2 

# Implementation
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix

# Dataset
data = {
    'Marks': [25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80],
    'Result': [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1]
}

# Create DataFrame
df = pd.DataFrame(data)

print("Dataset")
print(df)

# Features and Target
X = df[['Marks']]
y = df['Result']

# Split dataset
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# Create model
model = LogisticRegression()
model.fit(X_train, y_train)

# Predict test data
y_pred = model.predict(X_test)

print("\nPredicted Values:")
print(y_pred)

# Accuracy
acc = accuracy_score(y_test, y_pred)
print("\nAccuracy:", acc)

# Confusion Matrix
cm = confusion_matrix(y_test, y_pred)

print("\nConfusion Matrix:")
print(cm)

# Predict New Student
new_marks = [[58]]
prediction = model.predict(new_marks)

print("\nPrediction for Student with Marks =", new_marks[0][0])

if prediction[0] == 1:
    print("Pass")
else:
    print("Fail")

# Plot graph
plt.figure(figsize=(8, 5))

plt.scatter(
    X[y == 0]['Marks'],
    y[y == 0],
    color='red',
    marker='o',
    s=100,
    label='Fail'
)

plt.scatter(
    X[y == 1]['Marks'],
    y[y == 1],
    color='green',
    marker='s',
    s=100,
    label='Pass'
)

# Sigmoid curve
X_range = np.linspace(20, 85, 500).reshape(-1, 1)
y_prob = model.predict_proba(X_range)[:, 1]

plt.plot(
    X_range,
    y_prob,
    color='blue',
    linewidth=3,
    label='Sigmoid Curve'
)

# Decision Boundary
plt.axhline(
    y=0.5,
    color='black',
    linestyle='--',
    label='Decision Boundary'
)

plt.xlabel('Marks')
plt.ylabel('Probability of Passing')
plt.title('Logistic Regression - Student Pass/Fail Prediction')

plt.legend()
plt.grid(True)
plt.show()
