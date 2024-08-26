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

    int m = n - 1;
    while (m--)
    {
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {

            if (vec[i] > vec[i + 1])
                swap(vec[i], vec[i + 1]);

            else
                count++;
        }
        if (count == n - 1)
            break;
    }

    floop(n) cout << vec[i] << endl;
}