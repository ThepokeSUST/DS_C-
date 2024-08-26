#include <iostream>
#include <vector>

#define floop(n) for (int i = 0; i < n; i++)
#define ll long long
using namespace std;

int find_max(vector<int> &vec)
{

    int ele = INT32_MIN;

    floop(vec.size())
    {
        if (ele < vec[i])
            ele = vec[i];
    }

    return ele;
}
int main()
{

    int n;
    cin >> n;
    vector<int> vec(n);
    // read array
    floop(n) cin >> vec[i];

    int max_ele = find_max(vec);
    max_ele++;

    vector<int> frq(max_ele, 0);
    // for frequency
    floop(vec.size())
    {
        frq[vec[i]]++;
    }
    // for index
    for (int i = 1; i < max_ele; i++)
    {
        frq[i] += frq[i - 1];
    }
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        ans[--frq[vec[i]]] = vec[i];
    }

    floop(n) cout << ans[i] << " ";
}