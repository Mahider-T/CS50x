#include <stdio.h>
#include <cs50.h>

//American Express - 15 digits
//MasterCard uses 16-digit numbers, and 
//Visa uses 13- and 16-digit numbers.

int numberOfDigits;
int firstDigit;

void checkCard(int cardNumber){
    int digit = 0;
    int sumOne = 0;
    int sumTwo = 0;
    bool isLegit = false;
    while(cardNumber > 0){
        int currentDigit = cardNumber % 10;
        if(digit % 2 != 0){
            sumOne += currentDigit;
        }
        else{
            sumTwo += currentDigit;
        }

        int finalSum = sumOne + sumTwo;
        if(finalSum % 10 == 0){
            isLegit = true;
        } 
        
        digit++;
        cardNumber /= 10;
    }
    if(isLegit == true && (numberOfDigits == 16 || numberOfDigits == 13) && firstDigit == 4){
        printf("VISA\n");
    }
    else if (isLegit == true && numberOfDigits == 15)
    {
        printf("AMEX\n");
    }
    else if( isLegit == true && numberOfDigits == 16){
        printf("MASTERCARD\n");
    }
    else{
        printf("INVALID\n");
    }
    

}

long getCardNumber(){
    long cardNumber;
    
    do{
        cardNumber = get_long("Numer: ");
        while(cardNumber > 0){
        cardNumber /=10;
        firstDigit = cardNumber%10;
        numberOfDigits++;
    }
    }while(numberOfDigits != 13 || numberOfDigits != 15 || numberOfDigits != 16);

    
    return cardNumber;
}

int main(void){
    checkCard(getCardNumber());

}