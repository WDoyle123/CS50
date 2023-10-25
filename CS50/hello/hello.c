#include <stdio.h>
#include <cs50.h>

//printf = print + format
//%s is where the string will go


int main(void)
{
    //Print function that recieves input from user by get_string
    printf("Hello, %s!\n", get_string("What is your name?"));
}