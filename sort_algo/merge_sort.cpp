#include <iostream>
#include <vector>

#define floop(n) for (int i = 0; i < n; i++)
using namespace std;

void merge(int st, int mid, int en, vector<int> &vec)
{

    vector<int> A(mid - st + 1);
    vector<int> B(en - mid);
    int a = 0;
    for (int i = st; i <= mid; i++)
    {
        A[a++] = vec[i];
    }
    int b = 0;
    for (int i = mid + 1; i <= en; i++)
    {
        B[b++] = vec[i];
    }
    vector<int> ans;
    int aa = 0;
    int bb = 0;
    while (aa < a and bb < b)
    {

        if (A[aa] < B[bb])
        {
            ans.push_back(A[aa++]);
        }
        else
        {
            ans.push_back(B[bb++]);
        }
    }

    while (aa < a)
    {
        ans.push_back(A[aa++]);
    }
    while (bb < b)
    {
        ans.push_back(B[bb++]);
    }
    int s = st;
    for (int i = 0; i < ans.size(); i++)
    {
        vec[s++] = ans[i];
    }
}

void merge_sort(int st, int en, vector<int> &vec)
{

    if (st >= en)
        return;
    int mid = (st + en) / 2;

    merge_sort(st, mid, vec);
    merge_sort(mid + 1, en, vec);

    merge(st, mid, en, vec);
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    floop(n) cin >> vec[i];
    merge_sort(0, n - 1, vec);

    floop(n) cout << vec[i] << " ";
}