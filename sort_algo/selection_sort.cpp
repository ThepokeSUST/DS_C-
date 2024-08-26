#include <iostream>
#include <vector>

#define floop(n) for (int i = 0; i < n; i++)

using namespace std;
int main()
{

    int n;
    cin >> n;

    vector<int> vec(n);

    floop(n) cin >> vec[i];

    for (int i = 0; i < n - 1; i++)
    {
        int ele_idx = i;
        int next_ele = INT32_MAX;
        int idx = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (next_ele > vec[j])
            {
                next_ele = vec[j];
                idx = j;
            }
        }

        if (idx != -1 and vec[ele_idx] > vec[idx])
            swap(vec[ele_idx], vec[idx]);
    }

    floop(n) cout << vec[i] << " ";
}