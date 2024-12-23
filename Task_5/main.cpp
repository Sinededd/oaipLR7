#include <iostream>
#include <vector>
// Временная сложность O(1)

bool is(int n, int l, int r, int bit, int del)
{
    std::cout<<bit+1<<" из оставшихся рабов пьет: ";
    for (int i = l - 1; i <= r - 1; i++)
    {
        if (i & (1 << bit))
        {
            std::cout<<i + del - 1<<" ";
            if (n - 1 == i)
            {
                std::cout<<std::endl;
                return true;
            }
        }
    }
    std::cout<<std::endl;
    return false;
}

bool is(int n, int l, int r, int bit)
{
    std::cout<<bit+1<<" из оставшихся рабов пьет: ";
    for (int i = l - 1; i <= r - 1; i++)
    {
        if (i & (1 << bit))
        {
            std::cout<<i + 1<<" ";
            if (n - 1 == i)
            {
                std::cout<<std::endl;
                return true;
            }
        }
    }
    std::cout<<std::endl;
    return false;
}

int main() // O(1)
{
    int n;
    std::cin >> n;
    bool rubs[5] = {1, 1, 1, 1, 1};
    std::vector<std::vector<int>> a(5);

    int l = 1, r = 16;
    for (int i = 0; i < 5; i++)
    {
        for (int j = l; j <= r; j++)
        {
            a[i].push_back(j);
            if (n == j)
            {
                rubs[i] = 0;
            }
        }
        l += 16;
        r += 16;
    }
    r -= 8;
    for (int i1 = 0; i1 < 5; i1++)
    {
        for (int i2 = i1 + 1; i2 < 5; i2++)
        {

            for (int j = l; j <= r; j++)
            {
                a[i1].push_back(j);
                a[i2].push_back(j);
                if (n == j)
                {
                    rubs[i1] = 0;
                    rubs[i2] = 0;
                }
            }
            l += 8;
            r += 8;
        }
    }
    r -= 4;
    for (int i1 = 0; i1 < 5; i1++)
    {
        for (int i2 = i1 + 1; i2 < 5; i2++)
        {
            for (int i3 = i2 + 1; i3 < 5; i3++)
            {
                for (int j = l; j <= r; j++)
                {
                    a[i1].push_back(j);
                    a[i2].push_back(j);
                    a[i3].push_back(j);
                    if (n == j)
                    {
                        rubs[i1] = 0;
                        rubs[i2] = 0;
                        rubs[i3] = 0;
                    }
                }
                l += 4;
                r += 4;
            }
        }
    }
    r -= 2;
    for (int i1 = 0; i1 < 5; i1++)
    {
        for (int i2 = i1 + 1; i2 < 5; i2++)
        {
            for (int i3 = i2 + 1; i3 < 5; i3++)
            {
                for (int i4 = i3 + 1; i4 < 5; i4++)
                {
                    for (int j = l; j <= r; j++)
                    {
                        a[i1].push_back(j);
                        a[i2].push_back(j);
                        a[i3].push_back(j);
                        a[i4].push_back(j);
                        if (n == j)
                        {
                            rubs[i1] = 0;
                            rubs[i2] = 0;
                            rubs[i3] = 0;
                            rubs[i4] = 0;
                        }
                    }
                    l += 2;
                    r += 2;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << i + 1 << " раб пьет бочки:   ";
        for (int j = 0; j < a[i].size(); j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n\n";
    }

    for (int i = 0; i < 5; i++)
    {
        if (rubs[i] == 0)
        {
            std::cout << i + 1 << " раб умер\n";
        }
    }

    std::vector<int> pa;
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        count += !rubs[i];
        if (!rubs[i])
            pa.push_back(i);
    }

    l = 1;
    r = 16;
    int res = 0;
    if (count == 1)
    {
        l = a[pa[0]][0];
        r = l + 16 - 1;

        res = res | (is(n, l, r, 0, l) << 0);
        res = res | (is(n, l, r, 1, l) << 1);
        res = res | (is(n, l, r, 2, l) << 2);
        res = res | (is(n, l, r, 3, l) << 3);
        res += l;
    }
    else if (count == 2)
    {
        l = 81;
        r = 88;
        int f = 1;
        for (int i1 = 0; i1 < 5 && f; i1++)
        {
            for (int i2 = i1 + 1; i2 < 5; i2++)
            {
                if (!rubs[i1] && !rubs[i2])
                {
                    f = 0;
                    break;
                }
                l += 8;
                r += 8;
            }
        }

        res = res | (is(n, l, r, 0) << 0);
        res = res | (is(n, l, r, 1) << 1);
        res = res | (is(n, l, r, 2) << 2);
        res += l;
    }
    else if (count == 3)
    {
        int f = 1;
        l = 161;
        r = 164;
        for (int i1 = 0; i1 < 5 && f; i1++)
        {
            for (int i2 = i1 + 1; i2 < 5 && f; i2++)
            {
                for (int i3 = i2 + 1; i3 < 5; i3++)
                {
                    if (!rubs[i1] && !rubs[i2] && !rubs[i3])
                    {
                        f = 0;
                        break;
                    }
                    l += 4;
                    r += 4;
                }
            }
        }

        res = res | (is(n, l, r, 0) << 0);
        res = res | (is(n, l, r, 1) << 1);
        res += l;
    }
    else if (count == 4)
    {
        int f = 1;
        l = 201;
        r = 202;
        for (int i1 = 0; i1 < 5 && f; i1++)
        {
            for (int i2 = i1 + 1; i2 < 5 && f; i2++)
            {
                for (int i3 = i2 + 1; i3 < 5 && f; i3++)
                {
                    for (int i4 = i3 + 1; i4 < 5; i4++)
                    {
                        if (!rubs[i1] && !rubs[i2] && !rubs[i3] && !rubs[i4])
                        {
                            f = 0;
                            break;
                        }
                        l += 2;
                        r += 2;
                    }
                }
            }
        }

        res = res | (is(n, l, r, 0) << 0);
        res += l;
    }
    else
    {
        l = 1;
        r = 30;
        res = res | (is(n - 210, l, r, 0, 211) << 0);
        res = res | (is(n - 210, l, r, 1, 211) << 1);
        res = res | (is(n - 210, l, r, 2, 211) << 2);
        res = res | (is(n - 210, l, r, 3, 211) << 3);
        res = res | (is(n - 210, l, r, 4, 211) << 4);
        res += 211;
    }

    std::cout << "n: " << n << " -> res: " << res << "\n";
    return 0;
}