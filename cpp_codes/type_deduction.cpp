/*
int main()
{
    constexpr double a { 3.4 };  // a has type const double (constexpr not part of type, const is implicit)

    auto b { a };                // b has type double (const dropped)
    const auto c { a };          // c has type const double (const dropped but reapplied)
    constexpr auto d { a };      // d has type const double (const dropped but implicitly reapplied by constexpr)

    return 0;
}

ecause constexpr is not part of the 
type system, it cannot be deduced 
as part of type deduction. However
, a constexpr variable is implicitly 
const, and this const will be dropped during type deduction 
(and can be readded if desired):


int x; // oops, we forgot to initialize x, but the compiler may not complain
auto y; // the compiler will error out because it can't deduce a type for y


std::string_view getString();   // some function that returns a std::string_view

std::string s1 { getString() }; // bad: expensive conversion from std::string_view to std::string (assuming you didn't want this)
auto s2 { getString() };        // good: no conversion required


// harder to read
int a { 5 };
double b { 6.7 };

// easier to read
auto c { 5 };
auto d { 6.7 };


auto sum { add(5, 6) + gravity };
If the return type of add changes from int to double, or gravity changes from int to double, sum will also change type from int to double.
*/