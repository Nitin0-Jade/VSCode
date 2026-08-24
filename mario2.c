#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 1. Prompt user for height between 1 and 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // 2. Outer loop: controls each ROW (from row 0 up to height - 1)
    for (int i = 0; i < height; i++)
    {
        // Inner Loop A: Print left SPACES
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Inner Loop B: Print LEFT HASHES
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Step C: Print the GAP (always 2 spaces)
        printf("  ");

        // Inner Loop D: Print RIGHT HASHES
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Step E: Move to the NEXT LINE after completing the row
        printf("\n");
    }
}