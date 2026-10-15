//Two-dimensional arrays and loops

//With a one-dimensional array, we can use a single loop to iterate through all of the elements in the array:

#include <iostream>

int main()
{
    int arr[] { 1, 2, 3, 4, 5 };

    // for-loop with index
    for (std::size_t i{0}; i < std::size(arr); ++i)
        std::cout << arr[i] << ' ';

    std::cout << '\n';

    // range-based for-loop
    for (auto e: arr)
        std::cout << e << ' ';

    std::cout << '\n';

    return 0;
}
/*
With a two-dimensional array, we need two loops: one to select the row, and another to select the column.

And with two loops, we also need to determine which loop will be the outer loop, and which will be the inner loop. It is most efficient to access elements in the order they are laid out in memory. Since C++ uses row-major order, the row selector should be the outer loop, and the column selector should be the inner loop.
*/
#include <iostream>

int main()
{
    int arr[3][4] {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }};

    // double for-loop with indices
    for (std::size_t row{0}; row < std::size(arr); ++row) // std::size(arr) returns the number of rows
    {
        for (std::size_t col{0}; col < std::size(arr[0]); ++col) // std::size(arr[0]) returns the number of columns
            std::cout << arr[row][col] << ' ';

        std::cout << '\n';
    }

    // double range-based for-loop
    for (const auto& arow: arr)   // get each array row
    {
        for (const auto& e: arow) // get each element of the row
            std::cout << e << ' ';

        std::cout << '\n';
    }

    return 0;
}
/*
A two-dimensional array example

Let’s take a look at a practical example of a two-dimensional array:
*/
#include <iostream>

int main()
{
    constexpr int numRows{ 10 };
    constexpr int numCols{ 10 };

    // Declare a 10x10 array
    int product[numRows][numCols]{};

    // Calculate a multiplication table
    // We don't need to calc row and col 0 since mult by 0 always is 0
    for (std::size_t row{ 1 }; row < numRows; ++row)
    {
        for (std::size_t col{ 1 }; col < numCols; ++col)
        {
            product[row][col] = static_cast<int>(row * col);
        }
     }

    for (std::size_t row{ 1 }; row < numRows; ++row)
    {
        for (std::size_t col{ 1 }; col < numCols; ++col)
        {
            std::cout << product[row][col] << '\t';
        }

        std::cout << '\n';
     }


    return 0;
}