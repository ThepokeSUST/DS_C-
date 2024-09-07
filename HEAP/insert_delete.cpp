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

    void delete_()
    {

        this->arr[0] = this->arr[this->size - 1];
        size--;
        int idx = 0;
        while (idx < size)
        {
            int left = idx * 2 + 1;
            int right = idx * 2 + 2;
            if (left <= size and right <= size)
            {
                if (arr[idx] < arr[left] and arr[left] >= arr[right])
                {
                    swap(arr[idx], arr[left]);
                    idx = left;
                }
                else if (arr[idx] < arr[right] and arr[right] >= arr[left])
                {
                    swap(arr[idx], arr[right]);
                    idx = right;
                }
                else
                    return;
            }
            else if (left <= size)
            {
                if (arr[idx] < arr[left])
                {
                    swap(arr[idx], arr[left]);
                    idx = left;
                }
            }
            else if (right <= size)
            {
                if (arr[idx] < arr[right])
                {
                    swap(arr[idx], arr[right]);
                    idx = right;
                }
            }
            else
                return;
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
    h.delete_();
    cout << endl;
    h.display();
}