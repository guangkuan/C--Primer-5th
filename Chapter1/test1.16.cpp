#include <iostream>
int main()
{
    int sum = 0, val = 0;
    std::cout << "请输入一组数字：" << std::endl;
    for (; std::cin >> val;)
        sum += val;
    std::cout << "这组数的和为：" << sum << std::endl;
    return 0;
}
