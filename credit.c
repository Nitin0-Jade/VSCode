#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 1. Get credit card number (must use 'long' because ints max out around 2 billion)
    long card = get_long("Number: ");

    // 2. Variables for digit counting and starting digits
    long temp = card;
    int length = 0;
    
    // Count the total number of digits
    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    // Check for valid length first; if invalid length, fail immediately
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // 3. Perform Luhn's Algorithm (Checksum)
    temp = card;
    int sum1 = 0; // Sum of every second digit from right, multiplied by 2
    int sum2 = 0; // Sum of the other digits
    int position = 0;

    while (temp > 0)
    {
        int digit = temp % 10; // Extract the last digit

        if (position % 2 == 0)
        {
            // Position 0, 2, 4... (from right): add directly to sum2
            sum2 += digit;
        }
        else
        {
            // Position 1, 3, 5... (from right): multiply by 2
            int product = digit * 2;
            // Add the digits of the product (e.g., 12 becomes 1 + 2 = 3)
            sum1 += (product / 10) + (product % 10);
        }

        temp /= 10; // Remove the last digit
        position++;
    }

    int total_sum = sum1 + sum2;

    // If checksum doesn't end in 0, card is invalid
    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // 4. Get the starting digits (first 1 or 2 digits)
    long start_digits = card;
    while (start_digits >= 100)
    {
        start_digits /= 10;
    }

    // 5. Determine the card type
    // AMEX: 15 digits, starts with 34 or 37
    if (length == 15 && (start_digits == 34 || start_digits == 37))
    {
        printf("AMEX\n");
    }
    // MASTERCARD: 16 digits, starts with 51, 52, 53, 54, or 55
    else if (length == 16 && (start_digits >= 51 && start_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    // VISA: 13 or 16 digits, starts with 4 (so start_digits / 10 is 4)
    else if ((length == 13 || length == 16) && (start_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}