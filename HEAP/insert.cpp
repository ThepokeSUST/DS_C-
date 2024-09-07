#include <iostream>

using namespace std;

class heap
{

    int *arr;
    int size;
    int max_size;

public:
    heap(int size)
    {
        this->max_size = size;
        this->size = 0;
        this->arr = new int[size];
    }

    void insert(int ele)
    {

        if (this->size == this->max_size)
        {
            cout << "heap is full\n";
            return;
        }

        int idx = this->size;
        size++;
        arr[idx] = ele;

        while (idx >= 0)
        {
            int par = (idx - 1) / 2;
            if (arr[par] < arr[idx])
            {
                swap(arr[idx], arr[par]);
                idx = par;
            }
            else
            {
                return;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }
};

int main()
{
    int n;
    cin >> n;
    heap h(n);
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        h.insert(ele);
    }

    h.display();
}