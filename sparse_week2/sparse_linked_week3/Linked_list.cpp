#include <iostream>
#include <vector>
using namespace std;

class Node 
{
    public:
    int row, col, data;
    Node* next;
    
    Node(int r, int c, int d) : row(r), col(c), data(d), next(nullptr) {}
};


class SparseMatrix_linked
{
    private:
    Node* head;

    public:
    SparseMatrix_linked() : head(nullptr) {}

    void addElem(int row, int col, int data) 
    {
        Node* newNode = new Node(row, col, data);
        if (!head) 
        {
            head = newNode;
        } else 
        {
            Node* curr = head;
            while (curr->next) 
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void display() 
    {
        Node* curr_1 = head;
        while (curr_1)
        {
            cout << "(" << curr_1->row << ", " << curr_1->col << ", " << curr_1->data << ") ---> ";
            curr_1 = curr_1->next;
        }
        cout << "NULL" << endl;
    }



    ~SparseMatrix_linked() 
    {
        Node* curr_final = head;
        while (curr_final) {
            Node* temp = curr_final;
            curr_final = curr_final->next;
            delete temp;
        }
    }
};

int main() 
{
    SparseMatrix_linked linkedlist;

    vector<vector<int>> matrix = 
    {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j) 
        {
            if (matrix[i][j] != 0) 
            {
                linkedlist.addElem(i, j, matrix[i][j]);
            }
        }
    }

    cout << "Linked list representation:" <<endl;
    linkedlist.display();
    return 0;
}
