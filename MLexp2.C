
str1 <- readline("Enter first string: ")
str2 <- readline("Enter second string: ")

cat("\n--- String Functions ---\n")

cat("Concatenated string:", paste(str1, str2), "\n")
cat("Length of first string:", nchar(str1), "\n")
cat("Uppercase:", toupper(str1), "\n")
cat("Lowercase:", tolower(str1), "\n")
cat("Replace first string:", sub("a", "A", str1), "\n")

num <- readline("\nEnter a number: ")

cat("\n--- Type Conversion Functions ---\n")

int_num <- as.integer(num)
cat("Integer value:", int_num, "\n")

num_value <- as.numeric(num)
cat("Numeric value:", num_value, "\n")

char_num <- as.character(num_value)
cat("Character value:", char_num, "\n")

logical_value <- as.logical(num_value)
cat("Logical value:", logical_value, "\n")
