#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Bitset {
public:
    //vector<bool> s, r; 
    //bool *s, *r;
    string s, r;
    int cnt, n;

    Bitset(int sz)// : s(sz), r(sz, 1)
    {
        // s = new bool[sz]();
        // r = new bool[sz];
        // fill_n(r, sz, 1);
        s = string(sz, '0');
        r = string(sz, '1');
        n = sz;
        cnt = 0;
    }

    void fix(int i)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
            r[i] = '0';
            cnt++;
        }
    }

    void unfix(int i)
    {
        if (s[i] == '1')
        {
            s[i] = '0';
            r[i] = '1';
            cnt--;
        }
    }

    void flip()
    {
        // for(int i = 0; i < n; i++)
        // {
        //     s[i] = !s[i];
        // }
        swap(s, r);
        cnt = n - cnt;
    }

    bool all()
    {
        return n == cnt;
    }

    bool one()
    {
        return cnt;
    }

    int count()
    {
        return cnt;
    }

    string toString()
    {
        // string str;
        // for(int i = 0; i < n; i++) str.push_back(char(s[i]+'0'));
        // return str;
        return s;
    }
};

int main(void)
{

	return 0;
}