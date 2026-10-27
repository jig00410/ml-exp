# Heart Disease Prediction using Machine Learning 
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
data = {
 'age' :[45,38,60,50,55,42,65,48,58,36],
 'bp' :[130,120,140,125,145,118,150,128,138,115],
 'cholesterol' :[230,180,280,210,260,190,300,220,250,170],
 'heartrate' :[150,170,130,160,135,175,125,155,140,180],
 'disease' :[1,0,1,0,1,0,1,0,1,0]
}
df = pd.DataFrame(data)
X = df[['age','bp','cholesterol','heartrate']]
y = df['disease']
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.3,random_state=42)
model = SVC()
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test,y_pred)
print("Accuracy =",accuracy)
print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))
print("\nClassification Report:")
print(classification_report(y_test,y_pred))
# Convert new_patient to a DataFrame with appropriate column names to match training data
new_patient_df = pd.DataFrame([[55,145,260,135]], columns=X.columns)
prediction = model.predict(new_patient_df)
if prediction[0] == 1:
 print("\nHeart Disease Risk: YES")
else:
 print("\nHeart Disease Risk: NO")



# Heart Disease Prediction using Kaggle Dataset:
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, classification_report
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
data = pd.read_csv('/heartdisease.csv')
X = data.drop(columns=['target'])
y = data['target']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)
models = {
 'Logistic Regression': LogisticRegression(random_state=42),
 'Support Vector Machine': SVC(random_state=42),
 'Decision Tree': DecisionTreeClassifier(random_state=42),
 'Random Forest': RandomForestClassifier(random_state=42)
}
for name, model in models.items():
 if name in ['Logistic Regression', 'Support Vector Machine']:
 model.fit(X_train_scaled, y_train)
 y_pred = model.predict(X_test_scaled)
 else:
 model.fit(X_train, y_train)
 y_pred = model.predict(X_test)
 acc = accuracy_score(y_test, y_pred)
 print(f'{name} ')
 print(f'Accuracy: {acc:.4f}\n')
 print(classification_report(y_test, y_pred))
