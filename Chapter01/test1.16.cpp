#include <iostream>
int main()
{
    int sum = 0, val = 0;
    std::cout << "������һ�����֣�" << std::endl;
    for (; std::cin >> val;)
        sum += val;
    std::cout << "�������ĺ�Ϊ��" << sum << std::endl;
    return 0;
}
