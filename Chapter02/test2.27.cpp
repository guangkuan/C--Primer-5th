#include <iostream>
int main()
{
   // const double pi = 3.14;
    //const double *cptr = &pi;
    //std::cout << *cptr << " " << cptr << std::endl;
    //double dval = 4.32;
    //cptr = &dval;
    //std::cout << *cptr << " " << cptr << std::endl;
    int errNumb = 123;
    int *const curErr = &errNumb;
    const double pi = 3.14159;
    const double *const pip = &pi;
    std::cout << *curErr << " " << curErr << std::endl;
    std::cout << *pip << " " << pip << std::endl;
    int errNumb1 = 321;
    errNumb = errNumb1;
    std::cout << *curErr << " " << curErr << std::endl;
    return 0;
}
