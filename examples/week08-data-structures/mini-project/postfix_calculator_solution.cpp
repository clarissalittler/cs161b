/*
 * Mini-Project: Postfix Expression Evaluator (Solution)
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

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

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isNumber(const string& token) {
    if (token.empty()) return false;

    size_t start = 0;
    if (token[0] == '-' && token.length() > 1) start = 1;

    for (size_t i = start; i < token.length(); i++) {
        if (!isdigit(static_cast<unsigned char>(token[i])) && token[i] != '.') return false;
    }
    return true;
}

double evaluatePostfix(const string& expression) {
    Stack s;
    initStack(s);

    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isNumber(token)) {
            double value = stod(token);
            push(s, value);
        } else if (isOperator(token)) {
            double b = pop(s);
            double a = pop(s);
            double result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") result = a / b;

            push(s, result);
        } else {
            cerr << "Unknown token: " << token << endl;
        }
    }

    double result = 0;
    if (!isEmpty(s)) {
        result = pop(s);
    }

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

    cout << "=== Test Cases ===" << endl;
    testExpression("3 4 +", 7);
    testExpression("10 3 -", 7);
    testExpression("4 5 *", 20);
    testExpression("20 4 /", 5);
    testExpression("3 4 + 2 *", 14);
    testExpression("2 3 4 + *", 14);
    testExpression("5 1 2 + 4 * + 3 -", 14);
    testExpression("2 3 + 4 5 + *", 45);

    cout << endl;

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
