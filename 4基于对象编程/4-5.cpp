#include <iostream>
using namespace std;
template<typename _TP>
class Matrix{
    public:
        Matrix(_TP **a,int sz):p(a),size(sz){}
        Matrix(int sz):size(sz)
        {
            newP(sz);
            for(int i = 0;i < size;++i)
                for(int j = 0;j < size;++j)
                    p[i][j] = 0;
        }
        Matrix(const Matrix& a):size(a.size){
            newP(a.size);
            for(int i = 0;i < size;++i)
                for(int j = 0;j < size;++j)
                    p[i][j] = a.p[i][j];
        }
        ~Matrix(){
            for(int i = 0;i < size;++i)
                delete [] p[i];
            delete [] p;
        }
        Matrix operator+(const Matrix& a)const
        {
            //if(!checkSize(a.size)) throw;
            Matrix ans(a.size);
            for(int i = 0;i < size;++i)
                for(int j = 0;j < size;++j)
                    ans.p[i][j] = p[i][j] + a.p[i][j];
            return ans;
        }
        Matrix operator*(const Matrix& a)const
        {
            //if(!checkSize(a.size)) throw;
            Matrix ans(a.size);
            for(int i = 0;i < size;++i)
                for(int j = 0;j < size;++j)
                    for(int k = 0;k < size;++k)
                        ans.p[i][j] += p[i][k] * p[k][j];
            return ans;
        }
        void operator+=(const Matrix& a)const
        {
            //if(!checkSize(a.size)) throw;
            for(int i = 0;i < size;++i)
                for(int j = 0;j < size;++j)
                    p[i][j] += a.p[i][j];
        }
        void operator=(const Matrix& a){//必须写copy assignment function
            for(int i = 0;i < size;++i)
                for(int j = 0;j < size;++j)
                    p[i][j] = a.p[i][j];
        }
        _TP& operator()(int row,int column){
            return p[row][column];
        }
        _TP operator()(int row,int column)const{
            return p[row][column];
        }
        void print(){
            for(int i = 0;i < size;++i)
            {
                for(int j = 0;j < size;++j)
                    cout << p[i][j] << ' ';
                cout << endl;
            } 
        }
    private:
        bool checkSize(int sz){
            if(size != sz)
                return false;
            return true;
        }
        void newP(int sz){
            p = new _TP *[size];
            for(int i = 0;i < size;++i)
                p[i] = new _TP [size];
        }
        _TP **p;
        int size;
};
int main(){
    Matrix<double> ma1(4);
    ma1(0,0) = 1.5,ma1(0,1) = 2.5,ma1(0,2) = 3.5,ma1(0,3) = 4.5;
    ma1(1,0) = 1.5,ma1(1,1) = 2.5,ma1(1,2) = 3.5,ma1(1,3) = 4.5;
    ma1(2,0) = 1.5,ma1(2,1) = 2.5,ma1(2,2) = 3.5,ma1(2,3) = 4.5;
    ma1(3,0) = 1.5,ma1(3,1) = 2.5,ma1(3,2) = 3.5,ma1(3,3) = 4.5;
    ma1.print();
    Matrix<double> ma2(ma1);
    ma1 += ma2;
    ma1.print();
    ma1 = ma1 * ma2;
    ma1.print();
    ma1 = ma1 + ma2;
    ma1.print();
    return 0;
}
