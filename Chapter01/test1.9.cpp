#include <iostream>
int main()
{
    int sum = 0, val = 50;
    while(val <= 100)
    {
        sum += val;
        ++val;
    }
    std::cout<<"50到100的整数相加等于"<<sum<<std::endl;
    return 0;
}
