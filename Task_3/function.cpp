#include <string>

long long delenchiki(std::string &a, long long num) //O(n)
{
    std::string newS;
    long long ostatochki = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ostatochki = ostatochki * 10 + (a[i] - '0');

        if (ostatochki >= num)
        {
            newS += std::to_string(ostatochki / num);
            ostatochki = ostatochki % num;
        }
        else if (!newS.empty())
        {
            newS += '0';
        }
    }
    a = newS;
    return ostatochki;
}

void convert(std::string &a, long long sysNum)  //O(nlogn)
{
    bool nig = 0;
    if (a[0] == '-')
    {
        nig = 1;
        a.erase(0, 1);
    }
    std::string conS;
    std::string getDelen;
    long long getDelenInt;
    while (a != "") // O(nlogn)
    {
        getDelenInt = delenchiki(a, sysNum);
        char q = getDelenInt % 26 + 65;
        getDelen = q + std::to_string(getDelenInt / 26);
        conS.insert(0, getDelen);
    }
    if (nig)
    {
        a = "-" + conS;
    }
    else
    {
        a = conS;
    }
}

int sumNum(std::string &res, std::string x, std::string y, long long sysNum, int k)  //O(1)
{
    char res1Char;
    long long res2Int = 0;

    long long xint = x[0] - 'A' + strtoll((x.c_str() + 1), nullptr, 10) * 26;
    long long yint = y[0] - 'A' + strtoll((y.c_str() + 1), nullptr, 10) * 26;
    res2Int = xint + yint + k;
    if(res2Int >= sysNum)
    {
        k = 1;
        res2Int -= sysNum;
    }
    else
    {
        k = 0;
    }
    res1Char = res2Int % 26 + 'A';
    res2Int /= 26;
    res = res1Char + std::to_string(res2Int);
    return k;
}

int subNum(std::string &res, std::string x, std::string y, long long sysNum, int k) //O(1)

{
    // char res1Char;
    // long long res2Int = 0;

    // res2Int = (strtoll((x.c_str() + 1), nullptr, 10) - strtoll((y.c_str() + 1), nullptr, 10));

    // if (res2Int > 0)
    // {
    //     res1Char = (x[0] - y[0] + 'A') + k;
    //     k = 0;
    //     if (res1Char < 'A')
    //     {
    //         res2Int--;
    //         res1Char += 26;
    //     }
    // }
    // else if (res2Int == 0)
    // {
    //     res1Char = (x[0] - y[0] + 'A') + k;
    //     if (res1Char < 'A')
    //     {
    //         res1Char = (sysNum % 26 + 65) - y[0] + x[0] + k;
    //         res2Int = res2Int + sysNum / 26;
    //         k = -1;
    //     }
    //     else
    //     {
    //         k = 0;
    //     }
    // }
    // else
    // {
    //     res1Char = (sysNum % 26 + 65) - y[0] + x[0];
    //     res2Int = res2Int + sysNum / 26;
    //     k = -1;
    // }

    // res = res1Char + std::to_string(res2Int);
    // return k;
    char res1Char;
    long long res2Int = 0;

    long long xint = x[0] - 'A' + strtoll((x.c_str() + 1), nullptr, 10) * 26;
    long long yint = y[0] - 'A' + strtoll((y.c_str() + 1), nullptr, 10) * 26;
    res2Int = xint - yint + k;
    if(res2Int < 0)
    {
        k = -1;
        res2Int += sysNum;
    }
    else
    {
        k = 0;
    }
    res1Char = res2Int % 26 + 'A';
    res2Int /= 26;
    res = res1Char + std::to_string(res2Int);
    return k;
}

void add(std::string &a, std::string &b, long long sysNum)  //O(n + m)
{
    int k = 0;
    std::string res;
    std::string delA;
    std::string delB;
    long long posA = a.size() - 1;
    long long posB = b.size() - 1;
    while (posA != 0 || posB != 0) // O(n + m)
    {
        if (!a.empty())
        {
            while (!isalpha(a[posA])) //O(1)
            {
                --posA;
            }
            delA = a.substr(posA);
            a.erase(posA);
        }
        else
        {
            delA = "A0";
        }
        if (!b.empty())
        {
            while (!isalpha(b[posB])) //O(1)
            {
                --posB;
            }

            delB = b.substr(posB);
            b.erase(posB);
        }
        else
        {
            delB = "A0";
        }

        std::string resNum;
        k = sumNum(resNum, delA, delB, sysNum, k); // O(1)
        res.insert(0, resNum);
    }
    if (k == 1)
    {
        res.insert(0, "B0");
    }
    a = res;
}

bool compare(std::string a, std::string b) // O(2n + m)
{
    int cifriA = 0;
    int cifriB = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (isalpha(a[i]))
            ++cifriA;
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (isalpha(b[i]))
            ++cifriB;
    }

    if (cifriA != cifriB)
        return cifriA > cifriB;

    char c_A;
    char c_B;
    long long x_A;
    long long x_B;
    char *itA = &a[0];
    char *itB = &b[0];

    while (itA != &(a.back()) + 1 && itB != &(b.back()) + 1)
    {
        c_A = *(itA++);
        c_B = *(itB++);
        x_A = strtoll(itA, &itA, 10);
        x_B = strtoll(itB, &itB, 10);

        if (x_A != x_B)
        {
            return x_A > x_B;
        }
        else if (c_A != c_B)
        {
            return c_A > c_B;
        }
    }
    return true;
}

void subtraction(std::string &a, std::string &b, long long sysNum)  // O(n + m)
{
    int k = 0;
    std::string res;
    std::string delA;
    std::string delB;
    long long posA = a.size() - 1;
    long long posB = b.size() - 1;
    while (posA != 0 || posB != 0)
    {
        if (!a.empty())
        {
            while (!isalpha(a[posA]))
            {
                --posA;
            }
            delA = a.substr(posA);
            a.erase(posA);
        }
        else
        {
            delA = "A0";
        }
        if (!b.empty())
        {
            while (!isalpha(b[posB]))
            {
                --posB;
            }

            delB = b.substr(posB);
            b.erase(posB);
        }
        else
        {
            delB = "A0";
        }

        std::string resNum;
        k = subNum(resNum, delA, delB, sysNum, k);
        res.insert(0, resNum);
    }

    a = res;

    while (a[0] == 'A' && a[1] == '0')
    {
        a.erase(0, 2);
    }
    if (a.empty())
        a = "A0";
}

void sum(std::string &a, std::string &b, long long sysNum) // O(3n + 2m)
{
    if (a[0] == '-' && b[0] == '-')
    {
        a.erase(0, 1);
        b.erase(0, 1);
        add(a, b, sysNum);
        a = '-' + a;
    }
    else if (a[0] != '-' && b[0] != '-')
    {
        add(a, b, sysNum);
    }
    else
    {
        if (a[0] == '-')
        {
            a.erase(0, 1);
            if (compare(a, b))
            {
                subtraction(a, b, sysNum);
                a = '-' + a;
            }
            else
            {
                std::string buffff = b;
                subtraction(b, a, sysNum);
                a = b;
                b = buffff;
            }
        }
        if (b[0] == '-')
        {
            b.erase(0, 1);
            if (compare(a, b))
            {
                subtraction(a, b, sysNum);
            }
            else
            {
                std::string buffff = b;
                subtraction(b, a, sysNum);
                a = '-' + b;
                b = buffff;
            }
        }
    }
    if (a == "-A0")
        a = "A0";
}

std::string normalView(std::string a, long long sysNum) // O(n)
{
    if (sysNum > 36)
        return "-";

    bool f = 0;
    if (a[0] == '-')
    {
        f = 1;
        a.erase(0, 1);
    }

    std::string res;
    int x;
    while (!a.empty())
    {
        x = a[0] - 'A' + (a[1] - '0') * 26;
        if (x < 10)
            res += (x + '0');
        else
            res += (char)('A' - 10 + x);
        a.erase(0, 2);
    }
    if (f)
        return "-" + res;

    return res;
}