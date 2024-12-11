#include <iostream>

bool delenchiki(std::string &a);
void convert(std::string &a);
void sum(std::string &a, std::string &b);

int main()
{
    std::string a;
    std::string b;
    std::cout << "Введите 1 число: ";
    std::cin >> a;
    std::cout << "Введите 2 число: ";
    std::cin >> b;
    convert(a);
    convert(b);
    std::cout << "s:   " << a << std::endl;
    std::cout << "b:   " << b << std::endl;
    sum(a, b);
    std::cout << "sum: " << a << std::endl;
    return 0;
}

bool delenchiki(std::string &a)
{
    std::string newS;
    int ostatochki = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ostatochki = ostatochki * 10 + (a[i] - '0');

        if (ostatochki >= 2)
        {
            newS += std::to_string(ostatochki / 2);
            ostatochki = ostatochki % 2;
        }
        else if (!newS.empty())
        {
            newS += '0';
        }
    }
    a = newS;
    return ostatochki;
}

void convert(std::string &a)
{
    bool nig = 0;
    if (a[0] == '-')
    {
        nig = 1;
        a.erase(0, 1);
    }
    std::string conS;
    while (a != "")
    {
        conS.insert(0, std::to_string(delenchiki(a)));
    }
    if (nig)
    {
        for (int i = 0; i < conS.size(); i++)
        {
            if (conS[i] == '0')
                conS[i] = '1';
            else
                conS[i] = '0';
        }
        a = "11" + conS;
        std::string oneS = "001";
        sum(a, oneS);
    }
    else
    {
        a = "00" + conS;
    }
}

void sum(std::string &a, std::string &b)
{
    std::string res;
    int posA = a.size();
    int posB = b.size();
    int k = 0;
    int x = 0;
    while (posA > 0 || posB > 0)
    {
        x = 0;
        --posA;
        --posB;
        if (posA > 0)
        {
            x += a[posA] - '0';
        }
        else
        {
            x += a[0] - '0';
        }
        if (posB > 0)
        {
            x += b[posB] - '0';
        }
        else
        {
            x += b[0] - '0';
        }
        x += k;

        if (x > 1)
        {
            k = 1;
            x = x % 2;
        }
        else
        {
            k = 0;
        }
        res = (char)(x + '0') + res;
    }
    a = res;
}