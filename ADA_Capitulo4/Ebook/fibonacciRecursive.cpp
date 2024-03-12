#include <iostream>

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
        std::cout << "n: " << n << std::endl;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);

}
int main()
{
    std::cout << "Digite um numero para calcular o fibonacci: ";
    int n = 0;
    std::cin >> n;

    std::cout << "O " << n << " eh numero de fibonacci: " << fibonacci(n) << std::endl;
    return 0;
}