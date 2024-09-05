#include <iostream>
#include <vector>
using namespace std;

class seg
{
    vector<int> tree;
    int size;

public:
    seg(int n)
    {
        tree.resize(n);
        size = n;
    }

private:
    void build_(int st, int en, vector<int> &vec, int idx)
    {
        if (st == en)
        {
            this->tree[idx] = vec[st];
            return;
        }
        int mid = (st + en) / 2;
        build_(st, mid, vec, idx * 2);
        build_(mid + 1, en, vec, idx * 2 + 1);

        this->tree[idx] = this->tree[idx * 2] + this->tree[idx * 2 + 1];
    }

    int query_(int l, int r, int st, int en, int idx)
    {

        // l r st en
        // st en l r
        if (st > r or l > en)
            return 0;
        // l st en r
        if (l <= st and en <= r)
            return this->tree[idx];
        // st l r en
        // l st r en
        // st l en r
        int mid = (st + en) / 2;
        int left = query_(l, r, st, mid, idx * 2);
        int right = query_(l, r, mid + 1, en, idx * 2 + 1);

        return left + right;
    }

public:
    void build(vector<int> &vec)
    {
        build_(0, this->size - 1, vec, 1);
    }

    int query(int l, int r)
    {
        return query_(l, r, 0, this->size - 1, 1);
    }
};

int main()
{

    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    seg s(n);
    s.build(vec);

    cout << "query ";
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << s.query(a, b);
        cout << endl;
    }
}