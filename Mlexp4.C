import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
data = {
'Study_Hours': [2,3,4,5,6,7,8,9,10,11],
'Attendance' : [60,65,70,75,80,85,90,92,95,98],
'Assignements' : [3,4,5,5,6,7,8,8,9,10],
'Marks' : [40,45,50,55,60,65,70,78,85,90]
}
df = pd.DataFrame(data)
# independent variables
X = df[['Study_Hours','Attendance','Assignements']]
# dependent variable
y = df['Marks']
#split dataset
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
#Create model
model = LinearRegression()
#train model
model.fit(X_train, y_train)
#make predictions
y_pred = model.predict(X_test)
# results
print("Regression coefficients:")
print(model.coef_)
print("\nIntercept:")
print(model.intercept_)
print("\nActual values:")
print(y_test.values)
print("\nPredicted values:")
print(y_pred)
#Evaluation
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)
print("\nMean Squared Error:", mse)
print("R-squared:", r2)