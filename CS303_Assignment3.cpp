// CS303_Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
#include "StackFunctions.h"
#include "QueueFunctions.h"

using namespace std;

int main()
{

   //Main Code for Infix to Postfix
    string infixExp;
    cout << "Enter infix expression: ";
    getline(cin, infixExp);
    if (!isBalanced(infixExp)) {
        cout << "Imbalanced Expression" << endl;
    }
    else {
        string postfixExp = infixToPostfix(infixExp);
        cout << "Postfix expression: " << postfixExp << endl;
    }
   

    //Main Code for Queue implementation  
    cout << endl;
    cout << "Testing Queue with the following Strings\n";
    cout << "Time\nTruth\nBestie\nBooth\nStable\n";
    cout << endl;
    string addVal;
    Queue<string> testQueue;
    testQueue.enQueue("Time");
    testQueue.enQueue("Truth");
    testQueue.enQueue("Bestie");
    testQueue.enQueue("Booth");
    testQueue.enQueue("Stable");

    cout << "Enter a word to add to end of Queue" << endl;
    cin >> addVal;
    testQueue.enQueue(addVal);

    cout << endl;
    cout << "Printing updated Queue: ";
    cout << endl;
    testQueue.printQueue();


    bool testing = true;
    while (testing) {
        string choice2;
        cout << "\nPlease select number from options:\n";
        cout << "1)Add to rear of Queue\n2)Remove front element in Queue\n3)Print front element without removing\n4)Check if Queue is empty\n5)Print total number of elements in Queue\n6)EXIT" << endl;
        cin >> choice2;
        if (stoi(choice2) == 1) {
            cout << endl;
            cout << "Enter a word to add to end of Queue" << endl;
            cin >> addVal;
            testQueue.enQueue(addVal);

            cout << endl;
            cout << "Printing updated Queue: ";
            cout << endl;
            testQueue.printQueue();
        }

        else if (stoi(choice2) == 2) {
            string fElement = testQueue.deQueue();
            cout << endl;
            cout << "You dequeued '" << fElement << "'" << endl;
            cout << "Printing updated Queue: ";
            cout << endl;
            testQueue.printQueue();
        }

        else if (stoi(choice2) == 3) {
            string fElement2 = testQueue.peek();
            cout << endl;
            cout << "The first element is '" << fElement2 << "'" << endl;
        }

        else if (stoi(choice2) == 4) {
            cout << endl;
            if (!testQueue.isEmpty()) {
                cout << "The queue is not empty" << endl;
            }
            else {
                cout << "The queue is empty" << endl;
            }
        }

        else if (stoi(choice2) == 5) {
            cout << "\nThe number of elements in your queue is: ";
            testQueue.countQueue();
            cout << endl;
        }

        else {
            testing = false;
            cout << endl;
            cout << "exiting program..." << endl;
            cout << endl;
        }

    }
   


}

