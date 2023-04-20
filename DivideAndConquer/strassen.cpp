#include<iostream>
#include<vector>

using namespace std;

#define SIZE 4


void display(vector<vector<int>> matrix){
    cout<<endl;
    for(auto i=0; i<matrix.size(); i++){
        for(auto j=0; j<matrix.size(); j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}


//Addition of 2 square matrices
vector<vector<int>> addition(vector<vector<int>> matrix1, vector<vector<int>> matrix2){
    //Can only add square matrices
    int col_size, row_size;
    col_size = row_size = matrix1.size();
    vector<vector<int>> result_matrix(row_size, vector<int>(col_size));
    for(auto i=0; i<row_size; i++){
        for(auto j=0; j<col_size; j++){
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result_matrix;
}


vector<vector<int>> subtraction(vector<vector<int>> matrix1, vector<vector<int>> matrix2){
    //Can only add square matrices
    int col_size, row_size;
    col_size = row_size = matrix1.size();
    vector<vector<int>> result_matrix(row_size, vector<int>(col_size));
    for(auto i=0; i<row_size; i++){
        for(auto j=0; j<col_size; j++){
            result_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result_matrix;
}

vector<vector<int>> divide(vector<vector<int>> matrix,int row_start, int col_start, int row_end, int col_end){
    int split_size = matrix.size()/2;
    vector<vector<int>> result_matrix(split_size, vector<int>(split_size));
    for(auto i=row_start; i<=row_end; i++){
        for(auto j=col_start; j<=col_end; j++){
            result_matrix[i-row_start][j-col_start] = matrix[i][j];
        }
    }
    return result_matrix;
}

vector<vector<int>> merge(vector<vector<int>>C11, vector<vector<int>> C12, vector<vector<int>>C21, vector<vector<int>>C22){
    int split = C11.size();
    vector<vector<int>> result_matrix(2*split, vector<int>(2*split));
    for(auto i=0; i<split*2; i++){
        for(auto j=0; j<split*2; j++){
            if(i<split and j<split){
                result_matrix[i][j] = C11[i][j];
            }
            else if(i<split and j>=split){
                result_matrix[i][j] = C12[i][j-split];
            }
            else if(i>=split and j<split){
                result_matrix[i][j] = C21[i-split][j];
            }
            else{
                result_matrix[i][j] = C22[i-split][j-split];
            }
        }
    }
    return result_matrix;
}


//Matrix multiplication
vector<vector<int>> multiply(vector<vector<int>> matrix1, vector<vector<int>> matrix2){
    int msize = matrix1.size();

    if(msize == 1){
        vector<vector<int>> result_matrix(msize, vector<int>(msize));
        result_matrix[0][0] = matrix1[0][0] * matrix2[0][0];
        return result_matrix;
    }
    else{
        int split_size = msize/2;

        vector<vector<int>> A11(split_size, vector<int>(split_size));
        vector<vector<int>> A12(split_size, vector<int>(split_size));
        vector<vector<int>> A21(split_size, vector<int>(split_size));
        vector<vector<int>> A22(split_size, vector<int>(split_size));

        vector<vector<int>> B11(split_size, vector<int>(split_size));
        vector<vector<int>> B12(split_size, vector<int>(split_size));
        vector<vector<int>> B21(split_size, vector<int>(split_size));
        vector<vector<int>> B22(split_size, vector<int>(split_size));
      
        vector<vector<int>> P(split_size, vector<int>(split_size));
        vector<vector<int>> Q(split_size, vector<int>(split_size));
        vector<vector<int>> R(split_size, vector<int>(split_size));
        vector<vector<int>> S(split_size, vector<int>(split_size));
        vector<vector<int>> T(split_size, vector<int>(split_size));
        vector<vector<int>> U(split_size, vector<int>(split_size));
        vector<vector<int>> V(split_size, vector<int>(split_size));

        A11 = divide(matrix1, 0, 0, split_size-1, split_size-1);
        A12 = divide(matrix1, 0, split_size, split_size-1, msize-1);
        A21 = divide(matrix1, split_size, 0, msize-1, split_size-1);
        A22 = divide(matrix1, split_size, split_size, msize-1, msize-1);

        B11 = divide(matrix2, 0, 0, split_size-1, split_size-1);
        B12 = divide(matrix2, 0, split_size, split_size-1, msize-1);
        B21 = divide(matrix2, split_size, 0, msize-1, split_size-1);
        B22 = divide(matrix2, split_size, split_size, msize-1, msize-1);

        P = multiply(addition(A11,A22), addition(B11, B22));
        Q = multiply(addition(A21,A22), B11);
        R = multiply(A11, subtraction(B12, B22));
        S = multiply(A22, subtraction(B21, B11));
        T = multiply(addition(A11,A12), B22);
        U = multiply(subtraction(A21, A11), addition(B11, B12));
        V = multiply(subtraction(A12, A22), addition(B21, B22));

        vector<vector<int>> C11(split_size, vector<int>(split_size));
        vector<vector<int>> C12(split_size, vector<int>(split_size));
        vector<vector<int>> C21(split_size, vector<int>(split_size));
        vector<vector<int>> C22(split_size, vector<int>(split_size));

        C11 = subtraction(addition(addition(P,S), V), T);
        C12 = addition(R,T);
        C21 = addition(Q, S);
        C22 = subtraction(addition(addition(P,R), U), Q);

        vector<vector<int>> result_matrix(msize, vector<int>(msize));
        result_matrix = merge(C11, C12, C21, C22);
        return result_matrix;
    }
}


int main(){
        vector<vector<int>> A(SIZE, vector<int>(SIZE));
        vector<vector<int>> B(SIZE, vector<int>(SIZE));
        vector<vector<int>> C(SIZE, vector<int>(SIZE));

        cout<<"Enter elements of first matrix: "<<endl;
        for(auto i=0; i<A.size(); i++){
            for(auto j=0; j<A.size(); j++){
                cin >> A[i][j];
            }
        }

        cout<<"Enter elements of second matrix: "<<endl;
        for(auto i=0; i<B.size(); i++){
            for(auto j=0; j<B.size(); j++){
                cin >> B[i][j];
            }
        }
        C = multiply(A,B);

        cout<<"Matrix A:-"<<endl;
        display(A);
        cout<<"Matrix B:-"<<endl;
        display(B);
        cout<<"After multiplication:-"<<endl;
        display(C);
}
