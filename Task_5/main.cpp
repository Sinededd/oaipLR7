#include <iostream>
#include <vector>
// Временная сложность O(1)

bool is(int n, int l, int r, int bit)
{
    for (int i = l - 1; i <= r - 1; i++)
    {
        if (i & (1 << bit))
        {
            if (n - 1 == i)
            {
                return true;
            }
        }
    }
    return false;
}

// void check(bool &rubs, int ind, int &pos, int del)
// {
//     if ()
// }

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
    std::vector<int> pa;
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        count += !rubs[i];
        if (!rubs[i])
            pa.push_back(i);
    }

    // if(count == 1)
    // {
    //     l = 1 + 0 * rubs[0] * 16;
    //     l = 1 + 1 * rubs[1] * 16;
    //     l = 1 + 2 * rubs[2] * 16;
    //     l = 1 + 3 * rubs[3] * 16;
    //     l = 1 + 4 * rubs[4] * 16;
    //     l = 1 + 5 * rubs[5] * 16;
    //     r = l + 16 - 1;
    // }

    for (int i = 0; i < 5; i++)
    {
        std::cout << i + 1 << ":\t";
        for (auto j : a[i])
        {
            std::cout << j << ", ";
        }
        std::cout << "\n\n";
    }

    l = 1;
    r = 16;
    int res = 0;
    if (count == 1)
    {
        l = a[pa[0]][0];
        r = l + 16 - 1;

        res = res | (is(n, l, r, 0) << 0);
        res = res | (is(n, l, r, 1) << 1);
        res = res | (is(n, l, r, 2) << 2);
        res = res | (is(n, l, r, 3) << 3);
        res += l;
    }
    else if (count == 2)
    {
        l = a[pa[0]][16];
        r = l + 8 - 1;

        res = res | (is(n, l, r, 0) << 0);
        res = res | (is(n, l, r, 1) << 1);
        res = res | (is(n, l, r, 2) << 2);
        res += l;
    }
    else if (count == 3)
    {
        l = a[pa[0]][24];
        r = l + 4 - 1;

        res = res | (is(n, l, r, 0) << 0);
        res = res | (is(n, l, r, 1) << 1);
        res += l;
    }
    else if (count == 4)
    {
        l = a[pa[0]][28];
        r = l + 2 - 1;

        res = res | (is(n, l, r, 0) << 0);
        res += l;
    }
    else
    {
        l = 211;
        r = 240;

        res = res | (is(n, l, r, 0) << 0);
        res = res | (is(n, l, r, 1) << 1);
        res = res | (is(n, l, r, 2) << 2);
        res = res | (is(n, l, r, 3) << 3);
        res = res | (is(n, l, r, 4) << 4);
        res += l;
    }
    std::cout << l << " " << r << '\n';

    // res = res | (is(n, 5) << 5);
    // std::cout << res << std::endl;
    for (auto i : rubs)
        std::cout << i << " ";
    std::cout << "\n"
              << count << '\n';
    std::cout <<"-> "<< res << "\n";
    return 0;
}