#include <iostream>
#include <string>
#include <cmath>

/* Python code for it
def is_prime(n):
    for x in range(2, math.floor(math.sqrt(n)) + 1):
        if n % x == 0:
            return False
    return True
*/
bool isPrime(int number)
{
    int newnum = floor(sqrt(number));
    for (int i = 2; i <= newnum; i = i + 1)
    {
        if (number % i == 0)
        {
            return false;
        };
    }
    return true;
}

int getUserNum()
{
    std::string userinput;
    std::cout << "Enter a number :" << std::endl;
    std::cin >> userinput;
    std::cout << "\n";
    try
    {
        int i = std::stoi(userinput);
        if (i < 0)
        {
            std::cout << "Cannot commpute if items <0 are prime " << std::endl;
        }
        return i;
    }
    catch (std::invalid_argument const &e)
    {
        std::cout << "Invalid argument" << std::endl;
    }
    catch (std::out_of_range const &e)
    {
        std::cout << "Integer overflow" << std::endl;
    };
    return getUserNum();
}

int main()
{
    int number;
    number = getUserNum();
    if (isPrime(number) == true)
    {
        std::cout << "\n"
                  << number << " is a prime" << std::endl;
    }
    else
    {
        std::cout << "\n"
                  << number << " is not a prime" << std::endl;
    };
    main();
    return 0;
}