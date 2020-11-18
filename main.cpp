#include"Matrix.cpp"

int main(int argc, const char * argv[]) {

    Matrix<double>m(3,3,0);
    m = m + 2;
    m.print();
    return 0;
}
