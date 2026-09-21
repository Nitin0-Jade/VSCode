#include <plog/Log.h> // Step 1: include the logger headers
#include <plog/Initializers/RollingFileInitializer.h>
#include <iostream>

int getUserInput()
{
	PLOGD << "getUserInput() called"; // PLOGD is defined by the plog library

	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger

	PLOGD << "main() called"; // Step 3: Output to the log as if you were writing to the console

	int x{ getUserInput() };
	std::cout << "You entered: " << x << '\n';

	return 0;
}

//plog::init(plog::none , "Logfile.txt"); // plog::none eliminates writing of most messages, essentially turning logging off


/*
----------------------------IMPORTANT--------------------
In a prior lesson, we mentioned that std::cout is buffered, which means there may be a delay between when you ask std::cout to print a value, and when it actually does. Because of this, you may not see the value 5 appear at this point. To ensure that all output from std::cout is output immediately, you can temporarily add the following statement to the top of your main() function:
std::cout << std::unitbuf; // enable automatic flushing for std::cout (for debugging)



For performance reasons, this statement should be removed or commented out after debugging.

If you don’t want to continually add/remove/comment/uncomment the above, you can wrap the statement in a conditional compilation preprocessor directive (covered in lesson 2.10 -- Introduction to the preprocessor):

#ifdef DEBUG
std::cout << std::unitbuf; // enable automatic flushing for std::cout (for debugging)
#endif
You’ll need to make sure the DEBUG preprocessor macro is defined, either somewhere above this statement, or as part of your compiler settings.*/

/*
Stepping is the name for a set of related debugging features that allow you to step through your code statement by statement.

Step into executes the next statement in the normal execution path of the program, and then pauses execution. If the statement contains a function call, step into causes the program to jump to the top of the function being called.

Step over executes the next statement in the normal execution path of the program, and then pauses execution. If the statement contains a function call, step over executes the function and returns control to you after the function has been executed.

Step out executes all remaining code in the function currently being executed and then returns control to you when the function has returned.

Run to cursor executes the program until execution reaches the statement selected by your mouse cursor.

Continue runs the program, until the program terminates or a breakpoint is hit. Start is the same as continue, just from the beginning of the program.

A breakpoint is a special marker that tells the debugger to stop execution of the program when the breakpoint is reached.

The set next statement command allows us to change the point of execution to some other statement (sometimes informally called jumping). This can be used to jump the point of execution forwards and skip some code that would otherwise execute, or backwards and have something that already executed run again.

Watching a variable allows you to inspect the value of a variable while the program is executing in debug mode. The watch window allows you to examine the value of variables or expressions.

The call stack is a list of all the active functions that have been executed to get to the current point of execution. The call stack window is a debugger window that shows the call stack.*/