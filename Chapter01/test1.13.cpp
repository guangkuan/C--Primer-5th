#include <iostream>
int main()
{
    /*1.9��д*/
    //int sum = 0;
    //for(int val = 50;val <= 100;val++)
        //sum +=val;
    //std::cout << "50��100��������ӵ���:" << sum << std::endl;


    /*1.10��д*/
    //std::cout << "10��0֮�������Ϊ��" ;
    //for (int i = 10;i >= 0;i--)
        //std::cout << i << " " ;
        //std::cout << std::endl;


    /*1.11��д*/
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "v1 ��v2 ֮��������У�";
    if (v1 > v2)
        for (; v1 >= v2; v1--)
        std::cout << v1 << " ";
    else
        for (; v1 <= v2; v1++)
        std::cout << v1 << " ";
    std::cout << std::endl;
    return 0;
}
