#include <stdio.h>
#include <cs50.h>


int main(void){
    int numberOfWeeks = get_int("Number of weeks taking CS50: ");
    float hoursEachWeek[numberOfWeeks];
    float sum = 0;
    float average;
    char preference;
    for( int i = 0; i <numberOfWeeks ; i++){
        hoursEachWeek[i] = get_float("Week %i HW Hours: ", i);
        sum += hoursEachWeek[i];
    }
    average = sum/(float)numberOfWeeks;
    
    preference = get_char("Enter T for total hours and A fir average hours per week: ");
    switch (preference)
    {
    case 'T': case 't':
        printf("%f hours \n", sum);
        break;
    case 'A': case 'a':  
        printf("%f hours\n", average);
    default:
        break;
    }
}