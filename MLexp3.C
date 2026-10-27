# Ensemble Learning using Bagging and Boosting
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier, AdaBoostClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
iris = load_iris()
X = iris.data
y = iris.target
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)
rf = RandomForestClassifier(n_estimators=100, random_state=42)
rf.fit(X_train, y_train)
y_pred = rf.predict(X_test)
print(" Bagging(Random Forest)")
print("Accuracy:", accuracy_score(y_test, y_pred))
print("Classification Report:\n", classification_report(y_test, y_pred))
print("Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
ab=AdaBoostClassifier(n_estimators=50, learning_rate=1.0, random_state=42)
ab.fit(X_train, y_train)
ab_pred = ab.predict(X_test)
print("\n Boosting(AdaBoost)")
print("Accuracy:", accuracy_score(y_test, ab_pred))
print("Classification Report:\n", classification_report(y_test, ab_pred))
print("Confusion Matrix:\n", confusion_matrix(y_test, ab_pred))
