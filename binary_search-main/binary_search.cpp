#include <iostream>
#include <vector>

template<class T>
int binary_search_cycle(const std::vector<T> v, const T& value) {
    int left = 0, right = v.size();
    int prop = (left + right) / 2;
    while (true) {
        prop = (left + right) / 2;
        if (v[prop] == value) {
            return prop;
        }
        else if (v[prop] > value) {
            right = prop;
        }
        else {
            left = prop;
        }
        if ((left + right) / 2 == prop) {
            break;
        }
    }
    return -1;
}

template <class T>
int binary_search_recursion(const std::vector<T>& v, const T& value, int left, int right) {
    int prop = (left + right) / 2;
    if (v[prop] == value) {
        return prop;
    }
    else if (v[prop] > value) {
        right = prop;
    }
    else {
        left = prop;
    }
    if ((left + right) / 2 == prop) {
        return -1;
    }
    return binary_search_recursion(v, value, left, right);
}

int main()
{
    std::vector<int> v = { 1, 2, 4, 100, 1000 };

    std::cout << binary_search_recursion(v, 100, 0, v.size()) << std::endl;
}

