#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_FORMULA_SIZE 1000

// Function to evaluate the formula using BODMAS rules
double evaluate_formula(char* formula) {
    double result = 0.0;
    double number = 0.0;
    char operator = '+';
    char* ptr = formula;

    while (*ptr != '\0') {
        if (isdigit(*ptr)) {
            number = number * 10 + (*ptr - '0');
        } else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
            if (operator == '+') {
                result += number;
            } else if (operator == '-') {
                result -= number;
            } else if (operator == '*') {
                result *= number;
            } else if (operator == '/') {
                result /= number;
            }
            operator = *ptr;
            number = 0.0;
        }
        ptr++;
    }

    if (operator == '+') {
        result += number;
    } else if (operator == '-') {
        result -= number;
    } else if (operator == '*') {
        result *= number;
    } else if (operator == '/') {
        result /= number;
    }

    return result;
}

int main() {
    int t;
    char formula[MAX_FORMULA_SIZE];
    double answer, result;

    printf("Enter the number of testcases: ");
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        printf("Enter formula for testcase #%d: ", i);
        scanf("%s", formula);

        printf("Enter answer for testcase #%d: ", i);
        scanf("%lf", &answer);

        result = evaluate_formula(formula);

        printf("Case #%d: %s\n", i, result == answer ? "true" : "false");
    }

    return 0;
}