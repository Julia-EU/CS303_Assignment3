#pragma once
#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool isOperator(char ch);

bool isBalanced(string entry);

int OperatorValue(char ch);

string infixToPostfix(string entry);