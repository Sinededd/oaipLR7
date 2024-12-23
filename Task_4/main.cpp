#include <iostream>
#include <string>

long long getOne_int(std::string text, long long start, long long end)
{
    long long variant;
    std::string s = "";
    std::cout << text;
    getline(std::cin, s);

    char* endPtr;
    variant = strtoll(s.c_str(), &endPtr, 0);
    while (errno == ERANGE || s.empty() || endPtr != &(s.back()) + 1 || variant < start || variant > end)
    {
        errno = 0;
        if (!s.empty())
        {
            std::cout << "Incorrect input. Try again" << std::endl << std::endl; // âûâîäèì ñîîáùåíèå îá îøèáêå
        }
        std::cout << text;
        getline(std::cin, s); 
        variant = strtoll(s.c_str(), &endPtr, 0);
    }

    return variant;
}

bool isDivide7(long long x)  //O(1)
{
    while (x > 7)
    {
        x = (x & 7) + (x >> 3);
    }
    return (x == 7);
}

bool isDivide73(long long x)  //O(1)
{
    while (x > 73)
    {
        if (x & 1)
            x = 37 + (x >> 1);
        else
            x = x >> 1;
    }
    return (x == 73);
}

bool isDivide109(long long x)  //O(1)
{
    while (x > 109)
    {
        if (x & 1)
            x = 55 + (x >> 1);
        else
            x = x >> 1;
    }
    return (x == 109);
}

int main()  //O(1)
{
    long long x = getOne_int("Введите число: ",  -__LONG_LONG_MAX__ - 1, __LONG_LONG_MAX__);

    std::cout << "Делится на:";
    if (isDivide7(x))
        std::cout << " " << 7;
    if (isDivide73(x))
        std::cout << " " << 73;
    if (isDivide109(x))
        std::cout << " " << 109;

    std::cout << std::endl;
    return 0;
}