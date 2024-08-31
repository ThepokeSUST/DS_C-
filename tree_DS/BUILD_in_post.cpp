#include <iostream>
#include <vector>

#define floop(n) for (int i = 0; i < n; i++)
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int position(vector<int> &in, int cur, int st, int en)
{

    for (int i = st; i <= en; i++)
        if (in[i] == cur)
            return i;

    return -1;
}

node *BUILD(vector<int> &post, vector<int> &in, int st, int en)
{
    if (st > en)
    {
        return NULL;
    }
    static int idx = post.size() - 1;
    int cur = post[idx];
    idx--;
    node *newnode = new node(cur);
    int pos = position(in, cur, st, en);

    newnode->right = BUILD(post, in, pos + 1, en);
    newnode->left = BUILD(post, in, st, pos - 1);

    return newnode;
}

void display(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

int main()
{

    int n;
    cin >> n;

    vector<int> post(n);
    vector<int> in(n);

    floop(n) cin >> post[i];
    floop(n) cin >> in[i];

    node *root = BUILD(post, in, 0, n - 1);
    display(root);
}