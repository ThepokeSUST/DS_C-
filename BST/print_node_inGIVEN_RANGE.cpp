#include <iostream>
#include <vector>
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

class tree
{

    node *root;

public:
    tree()
    {
        root = NULL;
    }

private:
    node *insert_ele(int ele, node *root)
    {

        if (root == NULL)
        {
            node *newnode = new node(ele);
            return newnode;
        }
        if (root->data > ele)
            root->left = insert_ele(ele, root->left);
        else
            root->right = insert_ele(ele, root->right);
    }

    void inorder_(node *temp)
    {
        if (temp == NULL)
            return;

        inorder_(temp->left);
        cout << temp->data << " ";
        inorder_(temp->right);
    }
    void print(int a, int b, node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (root->data < a)
            print(a, b, root->right, ans);
        else if (root->data > b)
            print(a, b, root->left, ans);
        else
        {
            print(a, b, root->left, ans);
            ans.push_back(root->data);
            print(a, b, root->right, ans);
        }
    }

public:
    void insert(int ele)
    {
        this->root = insert_ele(ele, root);
    }
    void inorder()
    {
        inorder_(root);
    }
    vector<int> print_range(int a, int b)
    {
        vector<int> ans;
        print(a, b, this->root, ans);

        return ans;
    }
};

void solve()
{

    int n;
    cin >> n;
    tree t;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        t.insert(ele);
    }
    t.inorder();
    cout << endl;
    int a, b;
    cin >> a >> b;
    vector<int> ans = t.print_range(a, b);

    for (auto ele : ans)
        cout << ele << " ";
}

int main()
{
    solve();
}