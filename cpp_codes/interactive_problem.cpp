In problems of this type, the input data given to your program may be not predetermined but is built specifically for your solution. Jury writes a special program — interactor, such that its output is tranferred to the input of your solution, and the output of your program is sent to interactor’s input. In the other words, your solution and the interactor exchange the data and my decide what to print based on the "history of communication".

When you write the solution for the interactive problem it is important to keep in mind that if you output some data it is possible that this data is first placed to some internal buffer and may be not directly transferred to the interactor. In order to avoid such situation you have to use special flush operation each time you output some data. There are these flush operations in standard libraries of almost all languages. For example, in C++ you may use fflush(stdout) or cout << flush (it depends on what do you use for output data — scanf/printf or cout). In Java you can use method flush for output stream, for example, System.out.flush(). In Python you can use stdout.flush(). In Pascal you can use flush(output).

There are some features for interactive problems:

Input/output in interactive problems works much slower than in usual problems — try to use scanf/printf instead of cin/cout in С++, BufferedReader/PrintWriter in Java and etc.
Usually, manual testing of the solutions for interactive problems much more difficult, because the participant needed to be in the role of interactor during testing.
The "Custom invocation" tab does not know about the interactor for the problem, so you can't fully testing your solution.
Sometimes on the Codeforces Rounds interactive problems will use. In this case the fromat of tests for hacks will described in the statements of the problems.
Output endl in cout in C++ performs flush operation automatically.
Let's consider the following interactive problem. You can try to solve it here http://codeforces.com/gym/101021/problem/1

Problem
Guess the number

Statement
In this problem there is some hidden number and you have to interactively guess it. The hidden number is always an integer from 1 and to 1 000 000.

You can make queries to the testing system. Each query is one integer from 1 to 1 000 000. Flush output stream after printing each query. There are two different responses testing program can provide:

string < (without quotes), if the hidden number is less than the integer in your query;
string >= (without quotes), if the hidden number is greater than or equal to the integer in your query.
When your program wants to guess the hidden number, print string ! x, where x is the answer, and terminate your program immediately after flushing the output stream.

Your program is allowed to make no more than 25 queries (not including printing the answer) to the testing system.

Input
Use standard input to read the responses to the queries.

The input will contain responses to your queries — strings < and >=. The i-th string is a response to the i-th your query. When your program will guess the number print ! x, where x is the answer and terminate your program.

The testing system will allow you to read the response on the query only after your program print the query for the system and perform flush operation.

Output
To make the queries your program must use standard output.

Your program must print the queries — integer numbers xi (1 ≤ xi ≤ 106), one query per line. After printing each line your program must perform operation flush.

Each of the values xi mean the query to the testing system. The response to the query will be given in the input file after you flush output. In case your program guessed the number x, print string ! x, where x — is the answer, and terminate your program.

Solution
Of course, this problem can be solved using binary search. Here is an example of the C++ solution:

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int l = 1, r = 1000000;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        printf("%d\n", mid);
        fflush(stdout);

        char response[3];
        scanf("%s", response);
        if (strcmp(response, "<") == 0)
            r = mid - 1;
        else
            l = mid;
    }

    printf("! %d\n", l);
    fflush(stdout);
}