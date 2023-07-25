#include "StackFunctions.h"



bool isOperator (char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

bool isBalanced(string entry) {
    stack<char> expression;
    for (int i = 0; i < entry.length(); i++) {
        char ch = entry[i];
        if (ch == '{' || ch == '[' || ch == '(') {
            expression.push(ch);
        }
        else if (ch == '}' || ch == ']' || ch == ')') {
            if (expression.empty()) {
                return false;
            }
            if ((ch == '}' && expression.top() == '{') || (ch == ']' && expression.top() == '[') || (ch == ')' && expression.top() == '(')) {
                expression.pop();
            }
            else {
                return false;
            }
        }
    }
    return expression.empty();
}

int OperatorValue(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '%':
        return 3;
    }
}

string infixToPostfix(string entry) {
    stack<char> opStack;
    string postExpression = "";
    for (int i = 0; i < entry.length(); i++) {
        char ch = entry[i];
        if (isalnum(ch)) {
            postExpression += ch;
        }

        else if (ch == '(' || ch == '{' || ch == '[') {
            opStack.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {
            char tempCh = ch;

            switch (tempCh) {
            case ')':
                while (!opStack.empty() && opStack.top() != '(') {
                    postExpression += opStack.top();
                    opStack.pop();
                }
                if (!opStack.empty() && opStack.top() != '(') {
                    return "Invalid Expression";
                }


            case '}':
                while (!opStack.empty() && opStack.top() != '{') {
                    postExpression += opStack.top();
                    opStack.pop();
                }
                if (!opStack.empty() && opStack.top() != '{') {
                    return "Invalid Expression";
                }

            case ']':
                while (!opStack.empty() && opStack.top() != '[') {
                    postExpression += opStack.top();
                    opStack.pop();
                }
                if (!opStack.empty() && opStack.top() != '[') {
                    return "Invalid Expression";
                }
            }

        }

        else if (isOperator(ch)) {
            while (!opStack.empty() && opStack.top() != '(' && opStack.top() != '{' && opStack.top() != '[' && OperatorValue(ch) <= OperatorValue(opStack.top())) {
                postExpression += opStack.top();
                opStack.pop();
            }
            opStack.push(ch);
        }

    }

    while (!opStack.empty()) {
        if (opStack.top() == '(' || opStack.top() == ')' || opStack.top() == '{' || opStack.top() == '}' || opStack.top() == '[' || opStack.top() == ']') {
            return "Invalid Expression";
            break;
        }
        postExpression += opStack.top();
        opStack.pop();
    }
    return postExpression;

}
