// Program: MyArgs
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "There are " << argc << " arguments:\n";

    // Loop through each argument and print its number and value
    for (int count{ 0 }; count < argc; ++count)
    {
        std::cout << count << ' ' << argv[count] << '\n';
    }

    return 0;
}
/*
Now, when we invoke this program (MyArgs) with the command line arguments “Myfile.txt” and “100”, the output will be as follows:

There are 3 arguments:
0 C:\MyArgs
1 Myfile.txt
2 100
Argument 0 is the path and name of the current program being run. Argument 1 and 2 in this case are the two command line parameters we passed in.

Note that we cannot use a range-based for-loop to iterate through argv, since range-based for-loops don’t work on decayed C-style arrays.

Dealing with numeric arguments

Command line arguments are always passed as strings, even if the value provided is numeric in nature. To use a command line argument as a number, you must convert it from a string to a number. Unfortunately, C++ makes this a little more difficult than it should be.

The C++ way to do this follows:
*/
#include <iostream>
#include <sstream> // for std::stringstream
#include <string>

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		// On some operating systems, argv[0] can end up as an empty string instead of the program's name.
		// We'll conditionalize our response on whether argv[0] is empty or not.
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
		else
			std::cout << "Usage: <program name> <number>" << '\n';

		return 1;
	}

	std::stringstream convert{ argv[1] }; // set up a stringstream variable named convert, initialized with the input from argv[1]

	int myint{};
	if (!(convert >> myint)) // do the conversion
		myint = 0; // if conversion fails, set myint to a default value

	std::cout << "Got integer: " << myint << '\n';

	return 0;
}
/*
When run with input “567”, this program prints:

Got integer: 567
std::stringstream works much like std::cin. In this case, we’re initializing it with the value of argv[1], so that we can use operator>> to extract the value to an integer variable (the same as we would with std::cin).

We’ll talk more about std::stringstream in a future chapter.

The OS parses command line arguments first

When you type something at the command line (or run your program from the IDE), it is the operating system’s responsibility to translate and route that request as appropriate. This not only involves running the executable, it also involves parsing any arguments to determine how they should be handled and passed to the application.

Generally, operating systems have special rules about how special characters like double quotes and backslashes are handled.

For example:

MyArgs Hello world!
prints:

There are 3 arguments:
0 C:\MyArgs
1 Hello
2 world!
Typically, strings passed in double quotes are considered to be part of the same string:

MyArgs "Hello world!"
prints:

There are 2 arguments:
0 C:\MyArgs
1 Hello world!
Most operating systems will allow you to include a literal double quote by backslashing the double quote:

MyArgs \"Hello world!\"
prints:

There are 3 arguments:
0 C:\MyArgs
1 "Hello
2 world!"
Other characters may also require backslashing or escaping depending on how your OS interprets them.

Conclusion

Command line arguments provide a great way for users or other programs to pass input data into a program at startup. Consider making any input data that a program requires at startup to operate a command line parameter. If the command line isn’t passed in, you can always detect that and ask the user for input. That way, your program can operate either way.*/