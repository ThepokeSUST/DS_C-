#include <iostream>

using namespace std;

class node
{

public:
    node *child[26];
    bool terminate;

    node()
    {
        terminate = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class trie
{
    node *root;

public:
    trie()
    {
        this->root = new node();
    }

private:
    void insert_word(string str, node *root)
    {
        if (str.size() == 0)
        {
            root->terminate = true;
            return;
        }
        int idx = str[0] - 'a';
        if (root->child[idx] == NULL)
        {
            node *newnode = new node();
            root->child[idx] = newnode;
            root = newnode;
        }
        else
        {
            root = root->child[idx];
        }

        insert_word(str.substr(1), root);
    }

    bool find_word(string str, node *root)
    {

        if (str.size() == 0)
        {
            return root->terminate;
        }
        int idx = str[0] - 'a';
        if (root->child[idx] == NULL)
            return false;
        else
        {
            root = root->child[idx];
        }

        if (not find_word(str.substr(1), root))
            return false;
        else
            return true;
    }

public:
    void insert(string str)
    {
        insert_word(str, this->root);
    }

    bool find(string str)
    {
        return find_word(str, this->root);
    }
};
int main()
{
    trie t;

    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        t.insert(str);
    }

    cout << "enter number of query ";
    int q;
    cin >> q;
    while (q--)
    {
        string str;
        cin >> str;
        if (t.find(str))
            cout << "found\n";
        else
            cout << "not found\n";
    }
}