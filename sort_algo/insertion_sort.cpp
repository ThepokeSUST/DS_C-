#include <iostream>
#include <vector>

#define floop(n) for (int i = 0; i < n; i++)

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> vec(n);
    // read array
    floop(n) cin >> vec[i];
    for (int i = 1; i < n; i++)
    {

        int ele = vec[i];
        int idx = i;
        for (int j = i - 1; j >= 0; j--)
        {

            if (ele < vec[j])
            {
                vec[j + 1] = vec[j];
                idx = j;
            }
            else
            {

                break;
            }
        }

        vec[idx] = ele;
    }

    floop(n) cout << vec[i] << " ";
}
