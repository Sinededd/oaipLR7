#include <iostream>

bool delenchiki(std::string &a);  //
void convert(std::string &a);

int main()
{
    std::string s;
    std::cin >> s;
    convert(s);
    std::cout << s << std::endl;
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
        a = "1|" + conS;
    }
    else
    {
        a = "0|" + conS;
    }
}