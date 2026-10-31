cat("CONDITIONAL BRANCHING IN R\n")
cat("--------------------------\n")

num <- as.numeric(readline("Enter a number: "))

cat("\n1. Simple IF Statement\n")
if (num > 0) {
  cat("The number is positive.\n")
}

cat("\n2. IF-ELSE Statement\n")
if (num %% 2 == 0) {
  cat("The number is even.\n")
} else {
  cat("The number is odd.\n")
}

cat("\n3. IF-ELSE-IF Ladder\n")

if (num > 0) {
  cat("Number is positive.\n")
} else if (num < 0) {
  cat("Number is negative.\n")
} else {
  cat("Number is zero.\n")
}

cat("\n4. Nested IF Statement\n")

if (num >= 0) {
  if (num == 0) {
    cat("The number is zero.\n")
  } else {
    cat("The number is positive.\n")
  }
} else {
  cat("The number is negative.\n")
}

cat("\n5. Grade Calculation\n")

marks <- as.numeric(readline("Enter marks (0-100): "))

if (marks < 0 || marks > 100) {
  cat("Invalid marks! Enter marks between 0 and 100.\n")
} else if (marks >= 90) {
  cat("Grade: A+\n")
} else if (marks >= 80) {
  cat("Grade: A\n")
} else if (marks >= 70) {
  cat("Grade: B\n")
} else if (marks >= 60) {
  cat("Grade: C\n")
} else if (marks >= 40) {
  cat("Grade: D\n")
} else {
  cat("Grade: F (Fail)\n")
}

cat("\nProgram executed successfully!\n")
