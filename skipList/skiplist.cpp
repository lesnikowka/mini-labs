#include <iostream>
#include "skiplist.h"

int main()
{
    SkipList<int, int> s;

    s.emplace(6, 0);
    s.emplace(2, 0);
    s.emplace(3, 0);
    s.emplace(4, 0);
    s.emplace(1, 0);

    s.erase(3);


    std::cout << (int)(s.find(6) != nullptr) << std::endl;
    std::cout << (int)(s.find(2) != nullptr) << std::endl;
    std::cout << (int)(s.find(3) != nullptr) << std::endl;
    std::cout << (int)(s.find(4) != nullptr) << std::endl;
    //std::cout << (int)(s.find(5) != nullptr) << std::endl;
    std::cout << (int)(s.find(1) != nullptr) << std::endl;
    std::cout << (int)(s.find(7) != nullptr) << std::endl;
}
