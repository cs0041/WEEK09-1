#include <iostream>
using namespace std;
int countstr(string  a)
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    string a, b;
    int c[40001], d[40001];
    for (int i = 0; i < 40001; i++)
    {
        c[i] = 0;
        d[i] = 0;
    }
    cin >> a;
    cin >> b;
    for (int i = 0; i < countstr(a); i++)
    {
        int x = i;
        bool frist = true;
        for (int k = 0; k < countstr(b); k++)
        {
            if (a[x] == b[k])
            {
                c[i]++;
                x++;
                frist = false;
            }
            else
            {
                if (c[i] > d[i])
                {
                    d[i] = c[i];
                }
                c[i] = 0;
                x = i;
                if (!frist)
                {
                    k--;
                    frist = true;
                }
            }
        }
    }

    int maxx = -2140000000;
    int index;
    for (int i = 0; i < countstr(a); i++)
    {
        if (d[i] > maxx)
        {
            maxx = d[i];
            index = i;
        }
    }
    for (int j = index; j < index + maxx; j++)
    {
        cout << a[j];
    }
    return 0;
}
