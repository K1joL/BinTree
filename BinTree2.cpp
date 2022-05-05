#include <iostream>

using namespace std;

struct BinTree
{
    BinTree();
    ~BinTree();

    struct node
    {
        node *parent;
        node *pleft;
        node *pright;
        int data;
        node(int data = 0, node *pleft = nullptr, node *pright = nullptr, node *parent = nullptr)
        {
            this->parent = parent;
            this->data = data;
            this->pleft = pleft;
            this->pright = pright;
        }
    };

    void insert(int data);
    int extract();
    void find(int data);
    void remove(node *current);
    int getSize();

    int Size;
    node *Head;
};

BinTree::BinTree()
{
    Size = 0;
    Head = nullptr;
}

BinTree::~BinTree()
{
    remove(Head);
}

void BinTree::insert(int data)
{
    if (Size == 0)
    {
        Head = new node(data);
    }
    else
    {
        node *current = this->Head;

        while (true)
        {
            if (data >= current->data)
            {
                if (current->pright == nullptr)
                {
                    current->pright = new node(data);
                    current->pright->parent = current;
                    break;
                }
                current = current->pright;
            }
            else
            {
                if (current->pleft == nullptr)
                {
                    current->pleft = new node(data);
                    current->pleft->parent = current;
                    break;
                }
                current = current->pleft;
            }
        }
    }
    Size++;
}

int BinTree::extract()
{
    if (getSize())
    {
        node *temp = nullptr;
        int dataMax = 0;
        node *current = this->Head;
        while (current != nullptr)
        {
            if (dataMax < current->data)
            {
                dataMax = current->data;
                temp = current;
            }
            current = current->pright;
        }
        remove(temp);
        return dataMax;
    }
    else
    {
        cout << "Tree is empty" << endl;
    }
}

void BinTree::find(int data)
{
    if (getSize())
    {
        int count = 0;

        node *current = this->Head;
        while (true)
        {
            if (data == current->data)
            {
                count++;
                break;
            }
            if (data >= current->data)
            {
                if (current->pright != nullptr)
                {
                    current = current->pright;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (current->pleft != nullptr)
                {
                    current = current->pleft;
                }
                else
                {
                    break;
                }
            }
        }

        if (count > 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

    }
    else
    {
        cout << "Tree is empty" << endl;
    }
}

void BinTree::remove(node *current)
{
    if (current)
    {
        remove(current->pleft);
        remove(current->pright);
        if (current->parent != nullptr)
        {
            current->parent->pleft = nullptr;
            current->parent->pright = nullptr;
        }
        delete current;
        Size--;
    }
}

int BinTree::getSize()
{
    return Size;
}

int main()
{
    BinTree Tree;
    int N = 0, func = 0, Data = 0;

    enum Function { Insert, Extract, Find };

    cin >> N;

    while (N)
    {
        cin >> func;
        switch (func)
        {
        case Insert:
            cin >> Data;
            Tree.insert(Data);
            N--;
            break;

        case Extract:
            cout << Tree.extract() << endl;
            N--;
            break;

        case Find:
            cin >> Data;
            Tree.find(Data);
            N--;
            break;

        default:
            cout << "Попробуйте ещё раз." << endl;
        }
    }
    return 32;
}