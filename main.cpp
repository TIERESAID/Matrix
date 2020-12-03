#include"Matrix.cpp"

int main(int argc, const char * argv[]) {

    Matrix<double>m(3,3,2);
   // m = m+1;
     m.print();
    std::cout<<"Determinant: "<<m.Determinant(m,3)<<std::endl;
    return 0;
}
