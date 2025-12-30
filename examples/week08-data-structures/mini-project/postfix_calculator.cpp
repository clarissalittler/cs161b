/*
 * Mini-Project: Postfix Expression Evaluator
 *
 * Evaluate mathematical expressions in postfix (Reverse Polish) notation
 * using a stack.
 *
 * Postfix: operands come before their operators
 *   3 4 +     means (3 + 4) = 7
 *   3 4 + 2 * means (3 + 4) * 2 = 14
 *   5 1 2 + 4 * + 3 - means 5 + (1+2)*4 - 3 = 14
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

// Stack implementation
struct Node {
    double data;
    Node* next;
};

struct Stack {
    Node* top;
};

void initStack(Stack& s) {
    s.top = nullptr;
}

bool isEmpty(const Stack& s) {
    return s.top == nullptr;
}

void push(Stack& s, double value) {
    Node* newNode = new Node{value, s.top};
    s.top = newNode;
}

double pop(Stack& s) {
    if (isEmpty(s)) {
        cerr << "Error: Stack underflow!" << endl;
        return 0;
    }
    Node* temp = s.top;
    double value = temp->data;
    s.top = s.top->next;
    delete temp;
    return value;
}

void deleteStack(Stack& s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

// Check if a string is an operator
bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// Check if a string is a number
bool isNumber(const string& token) {
    if (token.empty()) return false;

    size_t start = 0;
    if (token[0] == '-' && token.length() > 1) start = 1;

    for (size_t i = start; i < token.length(); i++) {
        if (!isdigit(token[i]) && token[i] != '.') return false;
    }
    return true;
}

// TODO: Implement the postfix evaluator
double evaluatePostfix(const string& expression) {
    Stack s;
    initStack(s);

    // Use stringstream to tokenize the expression
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isNumber(token)) {
            // TODO: Convert token to number and push onto stack
            // Hint: use stod(token) to convert string to double


        } else if (isOperator(token)) {
            // TODO: Pop two operands (note the order!)
            // Perform the operation
            // Push the result

            // Note: for "a b -", we compute a - b
            // So pop b first, then a


        } else {
            cerr << "Unknown token: " << token << endl;
        }
    }

    // TODO: The result should be the only item on the stack
    double result = 0;


    deleteStack(s);
    return result;
}

void testExpression(const string& expr, double expected) {
    double result = evaluatePostfix(expr);
    cout << expr << " = " << result;
    if (result == expected) {
        cout << " [PASS]" << endl;
    } else {
        cout << " [FAIL, expected " << expected << "]" << endl;
    }
}

int main() {
    cout << "=== Postfix Expression Evaluator ===" << endl << endl;

    // Test cases
    cout << "=== Test Cases ===" << endl;
    testExpression("3 4 +", 7);
    testExpression("10 3 -", 7);
    testExpression("4 5 *", 20);
    testExpression("20 4 /", 5);
    testExpression("3 4 + 2 *", 14);      // (3+4)*2
    testExpression("2 3 4 + *", 14);      // 2*(3+4)
    testExpression("5 1 2 + 4 * + 3 -", 14);  // 5+(1+2)*4-3
    testExpression("2 3 + 4 5 + *", 45);  // (2+3)*(4+5)

    cout << endl;

    // Interactive mode
    cout << "=== Interactive Mode ===" << endl;
    cout << "Enter postfix expressions (or 'quit' to exit):" << endl;

    string line;
    while (true) {
        cout << "> ";
        getline(cin, line);

        if (line == "quit" || line == "exit") break;
        if (line.empty()) continue;

        double result = evaluatePostfix(line);
        cout << "= " << result << endl;
    }

    cout << "Goodbye!" << endl;
    return 0;
}

/*
 * Implementation hints:
 *
 * For numbers:
 *   double num = stod(token);
 *   push(s, num);
 *
 * For operators:
 *   double b = pop(s);  // Second operand (popped first!)
 *   double a = pop(s);  // First operand
 *   double result;
 *
 *   if (token == "+") result = a + b;
 *   else if (token == "-") result = a - b;
 *   else if (token == "*") result = a * b;
 *   else if (token == "/") result = a / b;
 *
 *   push(s, result);
 *
 * At the end:
 *   if (!isEmpty(s)) {
 *       result = pop(s);
 *   }
 *
 * Why does this work?
 * - When we see a number, we save it for later (push)
 * - When we see an operator, we apply it to the two most recent numbers
 * - The order is preserved because we pop in reverse order
 *
 * Example trace for "3 4 + 2 *":
 *   Token  | Action          | Stack (top on right)
 *   -------+-----------------+---------------------
 *   3      | push 3          | [3]
 *   4      | push 4          | [3, 4]
 *   +      | pop 4,3; 3+4=7  | [7]
 *   2      | push 2          | [7, 2]
 *   *      | pop 2,7; 7*2=14 | [14]
 *   (end)  | pop result      | [] -> 14
 */
