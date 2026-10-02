/*
The interface of a class type (also called a class interface) defines how a user of the class type will interact with objects of the class type. Because only public members can be accessed from outside of the class type, the public members of a class type form its interface. For this reason, an interface composed of public members is sometimes called a public interface.
*/


/*

The implementation of a class type consists of the code that actually makes the class behave as intended. This includes both the member variables that store data, and the bodies of the member functions that contain the program logic and manipulate the member variables.

Data hiding

In programming, data hiding (also called information hiding or data abstraction) is a technique used to enforce the separation of interface and implementation by hiding (making inaccessible) the implementation of a program-defined data type from users.

Implementing data hiding in a C++ class type is simple. First, we ensure the data members of the class type are private (so that the user can not directly access them). The statements inside the bodies of member functions are already not directly accessible to users, so we don’t need to do anything else there. Next, we ensure the member functions are public, so that the user can call them.

By following these rules, we force the user of a class type to manipulate objects using the public interface, and prevent them from directly accessing implementation details.

Classes defined in C++ should use data hiding. And in fact, all of the classes provided by the standard library do just that. Structs, on the other hand, should not use data hiding, as having non-public members prevents them from being treated as aggregates.


*/



