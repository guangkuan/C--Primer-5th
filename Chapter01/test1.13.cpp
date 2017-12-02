#include <iostream>
int main()
{
    /*1.9改写*/
    //int sum = 0;
    //for(int val = 50;val <= 100;val++)
        //sum +=val;
    //std::cout << "50到100的整数相加等于:" << sum << std::endl;


    /*1.10改写*/
    //std::cout << "10到0之间的整数为：" ;
    //for (int i = 10;i >= 0;i--)
        //std::cout << i << " " ;
        //std::cout << std::endl;


    /*1.11改写*/
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "v1 到v2 之间的整数有：";
    if (v1 > v2)
        for (; v1 >= v2; v1--)
        std::cout << v1 << " ";
    else
        for (; v1 <= v2; v1++)
        std::cout << v1 << " ";
    std::cout << std::endl;
    return 0;
}
