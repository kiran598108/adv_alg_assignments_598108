#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Sparse_matrix {
    private:
    int rows, columns;
    vector<vector<int>> elem;

    public:
    Sparse_matrix(int r, int c) : rows(r),columns(c){}

    void set(int row,int col,int val) 
    {
        if(rows <0 || row >=rows || col < 0 || col >= columns)
        {
            cout <<"Invaild\n";
            return;
        }

        if(val != 0) 
        {
            for (auto& elem : elem)
            {
                if (elem[0] == rows && elem[1] == col) 

                {
                    elem[2] = val;
                    return;
                }
            }
            elem.push_back({row,col,val});

        }
    }

    int get(int rows,int columns) const
    {
        for (const auto & element : elem) 
        {
            if(element[0] == rows && element[1] == columns) {
                return element[2];
            }
        }
        return 0;
    }

    void printmatrix() const
    {
        cout <<"rows\tColumns\tVal\n";

        for(const auto& element : elem) 
        {
            cout << element[0] << "\t" << element[1] <<"\t"<< element[2] << "\n";
        }
    }

    vector<vector<int>> toDense() const 
    {
        vector<vector<int>>dense(rows,vector<int>(columns, 0));
        for (const auto& element : elem) 
        {
            dense[element[0]][element[1]] = element[2];
        }
        return dense;
    
    }
};

int main()
 {
    Sparse_matrix sparseMatrix(4,5);

    sparseMatrix.set(0,2,3);
    sparseMatrix.set(0,4,4);
    sparseMatrix.set(1,2,5);
    sparseMatrix.set(1,3,7);
    sparseMatrix.set(3,1,2);
    sparseMatrix.set(3,2,6);

    cout << "Spare matrix representation: \n" ;
    sparseMatrix.printmatrix();
    cout<<"\n";
    
    auto denseMatrix = sparseMatrix.toDense();
    cout << "\nDense Matrix Representation:\n";

    for (const auto& rows : denseMatrix) {
        for (int val : rows) 
        {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;

 }