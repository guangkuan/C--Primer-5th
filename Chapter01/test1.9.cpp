#include <iostream>
int main()
{
    int sum = 0, val = 50;
    while(val <= 100)
    {
        sum += val;
        ++val;
    }
    std::cout<<"50��100��������ӵ���"<<sum<<std::endl;
    return 0;
}
