#include <iostream>
#include "Queue2Stacks.h"

int main()
{
    Queue2Stacks<int> q1;

    for (int i = 0; i < 10; i++) {
        q1.push(i);
    }
    
    for (int i = 0; i < 10; i++) {
        std::cout << q1.front() << " ";
        q1.pop();
    }

    //for (int i = 0; i < 10; i++) {
    //    q1.pop();
    //}


    return 0;
}
