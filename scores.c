#include <stdio.h>
#include <cs50.h>

float average(int length, int numbers[]);

int main(void)
{
    const int N = 3;// how many no. do you want to take avg off?
    int scores[N]; //array [] and capital letter for const(const int N = 3;)
    for( int i=0;i<N;i++)
    {
        scores[i] = get_int("Scores: ");
    }
    printf("Average: %f\n",average(N,scores));
}

float average(int length, int numbers[])//always get length of array and here numbers are array
{
    int sum = 0;
    for(int i=0;i<length;i++)
    {
        sum += numbers[i];
    }
    return sum / (float)length;
}