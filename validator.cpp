#include <iostream>
#include <string>
#include <sstream>

int getDigitSum(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
bool validateCreditCard(const std::string& cardNumber)
{
    int sum = 0;
    bool doubleDigit = false;

    for (int i = cardNumber.length() - 1; i >= 0; --i)
    {
        int digit = cardNumber[i] - '0';

        if (doubleDigit)
            digit = getDigitSum(digit * 2);

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10 == 0);
}
int main()
{
    std::string cardNumber;
    std::cout << "Enter the credit card number: ";
    std::getline(std::cin, cardNumber);


    std::stringstream ss;
    for (char c : cardNumber)
    {
        if (std::isdigit(c))
            ss << c;
    }
    cardNumber = ss.str();

    if (validateCreditCard(cardNumber))
        std::cout << "Valid credit card number." << std::endl;
    else
        std::cout << "Invalid credit card number." << std::endl;

    return 0;
}
