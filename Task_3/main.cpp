#include <iostream>
#include <string>
#include "header.h"
// #include "function.cpp"


int main()  // O(4n + 2m + 2nlogn) = O(nlogn)
{
    long long sysNum;
    std::cout << "Введите систему счисления: ";
    std::cin >> sysNum;
    std::string a, b;
    std::cout << "Введите 1 число: ";
    std::cin >> a;
    std::cout << "Введите 2 число: ";
    std::cin >> b;

    convert(a, sysNum);                                 // O(nlogn)
    convert(b, sysNum);                                 // O(nlogn)
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    sum(a, b, sysNum);                                  // O(3n + 2m)
    std::cout << "--------------\n" << a << std::endl << "~~~~~~~~~~~~~~~~~~\n";
    std::cout << normalView(a, sysNum) << std::endl;    // O(n)

    return 0;
}