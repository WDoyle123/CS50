#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Declare and initialise variables
    long long cardNumber;
    int count = 0;
    int getCardLength(long long);
    int getSecondNumberAMEX();
    void getCardBrand();
    int getMultiplyAlternateDigit();
    int getRemainingDigitSum();
    bool luhnsAlgo();

    // Ask user for cc number

    cardNumber = get_long_long("Enter Credit Card Number:");


    //Finds brand of card
    getCardBrand(cardNumber, getCardLength(cardNumber));


}

// Gets the length of credit card number

int getCardLength(long long n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count += 1;
    }
    return (count);
}

// Gets the first digit of a Visa card

int getFirstNumberVisa(long long cardNumber)
{
    int firstNumber;
    if (cardNumber >= pow(10, 15)) // Does allow for numbers greater than or equal to 10^15
    {
        return firstNumber = cardNumber / pow(10, 15);
    }
    else if (cardNumber >= pow(10, 12)) // If previous if statement fails it goes to this one.
    {
        return firstNumber = cardNumber / pow(10, 12);
    }
    else // Any smaller number will just return zero as to not out put VISA
    {
        return (0);
    }
}


// Gets the first two digits of an AMEX card

int getSecondNumberAMEX(long long cardNumber)
{
    int secondNumber;
    return secondNumber = cardNumber / pow(10, 13); 
}

// Gets the first two digits of a Mastercard

int getSecondNumberMastercard(long long cardNumber)
{
    int secondNumber;
    return secondNumber = cardNumber / pow(10, 14);
}

// Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.

int getMultiplyAlternateDigit(long long cardNumber)
{
    int multiplyAlternateDigit;
    int sum = 0;
    cardNumber /= 10;
    while (cardNumber > 0)
    {
        int lastDigit = cardNumber % 10;
        int timesTwo = lastDigit * 2;
        sum += (timesTwo % 10) + (timesTwo / 10); // spilts integers in the double digits into two
        cardNumber = cardNumber / 100;
    }
    return sum;
}

// Add the sum to the sum of the digits that weren’t multiplied by 2.

int getRemainingDigitSum(long long cardNumber)
{
    int sum = 0;
    while (cardNumber > 0)
    {
        int lastDigit = cardNumber % 10;
        sum += lastDigit;
        cardNumber /= 100;
    }
    return sum;
}

// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

bool luhnsAlgo(int sum1, int sum2)
{
    int total = sum1 + sum2;
    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}



// Prints to the terminal the brand of card when they meet the condionts of the brand

void getCardBrand(long long cardNumber, int cardLength)
{
    if ((cardLength == 13 || cardLength == 16) && getFirstNumberVisa(cardNumber) == 4
        && (luhnsAlgo(getMultiplyAlternateDigit(cardNumber), getRemainingDigitSum(cardNumber)) == true))
    {
        printf("VISA\n");
    }
    else if (cardLength == 15 && (getSecondNumberAMEX(cardNumber) == 34 || getSecondNumberAMEX(cardNumber) == 37)
             && (luhnsAlgo(getMultiplyAlternateDigit(cardNumber), getRemainingDigitSum(cardNumber)) == true))
    {
        printf("AMEX\n");
    }
    else if (cardLength == 16 && (getSecondNumberMastercard(cardNumber) == 51 || getSecondNumberMastercard(cardNumber) == 52
                                  || getSecondNumberMastercard(cardNumber) == 53 || getSecondNumberMastercard(cardNumber) == 54
                                  || getSecondNumberMastercard(cardNumber) == 55)
             && (luhnsAlgo(getMultiplyAlternateDigit(cardNumber), getRemainingDigitSum(cardNumber)) == true))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

