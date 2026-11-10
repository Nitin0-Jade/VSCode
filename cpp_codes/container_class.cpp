An array container class

In this example, we are going to write an integer array class from scratch that implements most of the common functionality that containers should have. This array class is going to be a value container, which will hold copies of the elements it’s organizing. As the name suggests, the container will hold an array of integers, similar to std::vector<int>.

First, let’s create the IntArray.h file:

#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
};

#endif
Our IntArray is going to need to keep track of two values: the data itself, and the size of the array. Because we want our array to be able to change in size, we’ll have to do some dynamic allocation, which means we’ll have to use a pointer to store the data.

#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
private:
    int m_length{};
    int* m_data{};
};

#endif
Now we need to add some constructors that will allow us to create IntArrays. We are going to add two constructors: one that constructs an empty array, and one that will allow us to construct an array of a predetermined size.

#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert> // for assert()
#include <cstddef> // for std::size_t

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length):
        m_length{ length }
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[static_cast<std::size_t>(length)]{};
    }
};

#endif
We’ll also need some functions to help us clean up IntArrays. First, we’ll write a destructor, which simply deallocates any dynamically allocated data. Second, we’ll write a function called erase(), which will erase the array and set the length to 0.

~IntArray()
{
    delete[] m_data;
    // we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
}

void erase()
{
    delete[] m_data;

    // We need to make sure we set m_data to nullptr here, otherwise it will
    // be left pointing at deallocated memory!
    m_data = nullptr;
    m_length = 0;
}
Now let’s overload the [] operator so we can access the elements of the array. We should ensure the index parameter has a valid value, which we can do by using the assert() function. We’ll also add an access function to return the length of the array. Here’s everything so far:

#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert> // for assert()
#include <cstddef> // for std::size_t

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length):
        m_length{ length }
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[static_cast<std::size_t>(length)]{};
    }

    ~IntArray()
    {
        delete[] m_data;
        // we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
    }

    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to nullptr here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};

#endif
At this point, we already have an IntArray class that we can use. We can allocate IntArrays of a given size, and we can use the [] operator to retrieve or change the value of the elements.

However, there are still a few thing we can’t do with our IntArray. We still can’t change its size, still can’t insert or delete elements, and we still can’t sort it. Copying the array will also cause problems, since that will shallow copy the data pointer.

First, let’s write some code that will allow us to resize an array. We are going to write two different functions to do this. The first function, reallocate(), will destroy any existing elements in the array when it is resized, but it will be fast. The second function, resize(), will keep any existing elements in the array when it is resized, but it will be slow.

#include <algorithm> // for std::copy_n

    // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
    void reallocate(int newLength)
    {
        // First we delete any existing elements
        erase();

        // If our array is going to be empty now, return here
        if (newLength <= 0)
            return;

        // Then we have to allocate new elements
        m_data = new int[static_cast<std::size_t>(newLength)];
        m_length = newLength;
    }

    // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    void resize(int newLength)
    {
        // if the array is already the right length, we're done
        if (newLength == m_length)
            return;

        // If we are resizing to an empty array, do that and return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Now we can assume newLength is at least 1 element.  This algorithm
        // works as follows: First we are going to allocate a new array.  Then we
        // are going to copy elements from the existing array to the new array.
        // Once that is done, we can destroy the old array, and make m_data
        // point to the new array.

        // First we have to allocate a new array
        int* data{ new int[static_cast<std::size_t>(newLength)] };

        // Then we have to figure out how many elements to copy from the existing
        // array to the new array.  We want to copy as many elements as there are
        // in the smaller of the two arrays.
        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
            std::copy_n(m_data, elementsToCopy, data); // copy the elements
        }

        // Now we can delete the old array because we don't need it any more
        delete[] m_data;

        // And use the new array instead!  Note that this simply makes m_data point
        // to the same address as the new array we dynamically allocated.  Because
        // data was dynamically allocated, it won't be destroyed when it goes out of scope.
        m_data = data;
        m_length = newLength;
    }
Whew! That was a little tricky!

Let’s also add a copy constructor and assignment operator so we can copy the array.

IntArray(const IntArray& a): IntArray(a.getLength()) // use normal constructor to set size of array appropriately
{
    std::copy_n(a.m_data, m_length, m_data); // copy the elements
}

IntArray& operator=(const IntArray& a)
{
    // Self-assignment check
    if (&a == this)
        return *this;

    // Set the size of the new array appropriately
    reallocate(a.getLength());
    std::copy_n(a.m_data, m_length, m_data); // copy the elements

    return *this;
}
Many array container classes would stop here. However, just in case you want to see how insert and delete functionality would be implemented we’ll go ahead and write those too. Both of these algorithms are very similar to resize().

void insertBefore(int value, int index)
 {
     // Sanity check our index value
     assert(index >= 0 && index <= m_length);

     // First create a new array one element larger than the old array
     int* data{ new int[static_cast<std::size_t>(m_length+1)] };

     // Copy all of the elements up to the index
     std::copy_n(m_data, index, data);

     // Insert our new element into the new array
     data[index] = value;

     // Copy all of the values after the inserted element
     std::copy_n(m_data + index, m_length - index, data + index + 1);

     // Finally, delete the old array, and use the new array instead
     delete[] m_data;
     m_data = data;
     ++m_length;
 }

 void remove(int index)
 {
     // Sanity check our index value
     assert(index >= 0 && index < m_length);

     // If this is the last remaining element in the array, set the array to empty and bail out
     if (m_length == 1)
     {
         erase();
         return;
     }

     // First create a new array one element smaller than the old array
     int* data{ new int[static_cast<std::size_t>(m_length-1)] };

     // Copy all of the elements up to the index
     std::copy_n(m_data, index, data);

     // Copy all of the values after the removed element
     std::copy_n(m_data + index + 1, m_length - index - 1, data + index);

     // Finally, delete the old array, and use the new array instead
     delete[] m_data;
     m_data = data;
     --m_length;
 }
Here is our IntArray container class in its entirety.

IntArray.h:

#ifndef INTARRAY_H
#define INTARRAY_H

#include <algorithm> // for std::copy_n
#include <cassert> // for assert()
#include <cstddef> // for std::size_t

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length):
        m_length{ length }
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[static_cast<std::size_t>(length)]{};
    }

    ~IntArray()
    {
        delete[] m_data;
        // we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
    }

    IntArray(const IntArray& a): IntArray(a.getLength()) // use normal constructor to set size of array appropriately
    {
        std::copy_n(a.m_data, m_length, m_data); // copy the elements
    }

    IntArray& operator=(const IntArray& a)
    {
        // Self-assignment check
        if (&a == this)
            return *this;

        // Set the size of the new array appropriately
        reallocate(a.getLength());
        std::copy_n(a.m_data, m_length, m_data); // copy the elements

        return *this;
    }

    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to nullptr here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }


    // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
    void reallocate(int newLength)
    {
        // First we delete any existing elements
        erase();

        // If our array is going to be empty now, return here
        if (newLength <= 0)
            return;

        // Then we have to allocate new elements
        m_data = new int[static_cast<std::size_t>(newLength)];
        m_length = newLength;
    }

    // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    void resize(int newLength)
    {
        // if the array is already the right length, we're done
        if (newLength == m_length)
            return;

        // If we are resizing to an empty array, do that and return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Now we can assume newLength is at least 1 element.  This algorithm
        // works as follows: First we are going to allocate a new array.  Then we
        // are going to copy elements from the existing array to the new array.
        // Once that is done, we can destroy the old array, and make m_data
        // point to the new array.

        // First we have to allocate a new array
        int* data{ new int[static_cast<std::size_t>(newLength)] };

        // Then we have to figure out how many elements to copy from the existing
        // array to the new array.  We want to copy as many elements as there are
        // in the smaller of the two arrays.
        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
            std::copy_n(m_data, elementsToCopy, data); // copy the elements
        }

        // Now we can delete the old array because we don't need it any more
        delete[] m_data;

        // And use the new array instead!  Note that this simply makes m_data point
        // to the same address as the new array we dynamically allocated.  Because
        // data was dynamically allocated, it won't be destroyed when it goes out of scope.
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // Sanity check our index value
        assert(index >= 0 && index <= m_length);

        // First create a new array one element larger than the old array
        int* data{ new int[static_cast<std::size_t>(m_length+1)] };

        // Copy all of the elements up to the index
        std::copy_n(m_data, index, data);

        // Insert our new element into the new array
        data[index] = value;

        // Copy all of the values after the inserted element
        std::copy_n(m_data + index, m_length - index, data + index + 1);

        // Finally, delete the old array, and use the new array instead
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index)
    {
        // Sanity check our index value
        assert(index >= 0 && index < m_length);

        // If this is the last remaining element in the array, set the array to empty and bail out
        if (m_length == 1)
        {
            erase();
            return;
        }

        // First create a new array one element smaller than the old array
        int* data{ new int[static_cast<std::size_t>(m_length-1)] };

        // Copy all of the elements up to the index
        std::copy_n(m_data, index, data);

        // Copy all of the values after the removed element
        std::copy_n(m_data + index + 1, m_length - index - 1, data + index);

        // Finally, delete the old array, and use the new array instead
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    // A couple of additional functions just for convenience
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }

    int getLength() const { return m_length; }
};

#endif
Now, let’s test it just to prove it works:

#include <iostream>
#include "IntArray.h"

int main()
{
    // Declare an array with 10 elements
    IntArray array(10);

    // Fill the array with numbers 1 through 10
    for (int i{ 0 }; i<10; ++i)
        array[i] = i+1;

    // Resize the array to 8 elements
    array.resize(8);

    // Insert the number 20 before element with index 5
    array.insertBefore(20, 5);

    // Remove the element with index 3
    array.remove(3);

    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // A few more tests to ensure copy constructing / assigning arrays
    // doesn't break things
    {
        IntArray b{ array };
        b = array;
        b = b;
        array = array;
    }

    // Print out all the numbers
    for (int i{ 0 }; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    return 0;
}
This produces the result:

40 1 2 3 5 20 6 7 8 30
Although writing container classes can be pretty complex, the good news is that you only have to write them once. Once the container class is working, you can use and reuse it as often as you like without any additional programming effort required.

A few additional improvements that could/should be made:

We could have made this a template class, so that it would work with any copyable type rather than just int.
We should add const overloads of various member functions to properly support const IntArrays.
We should add support for move semantics (via adding a move constructor and move assignment).
When performing resize or insertion operations, we can move elements instead of copying them.
For advanced readers

Some advanced improvements related to exception handling:

When performing resize or insertion operations, move elements only if their move constructor is noexcept, otherwise copy them (27.10 -- std::move_if_noexcept).
Provide a strong exception safety guarantee for resize or insertion operations (27.9 -- Exception specifications and noexcept).
One more thing: If a class in the standard library meets your needs, use that instead of creating your own. For example, instead of using IntArray, you’re better off using std::vector<int>. It’s battle tested, efficient, and plays nicely with the other classes in the standard library. But sometimes you need a specialized container class that doesn’t exist in the standard library, so it’s good to know how to create your own when you need to.



Summary

The process of building complex objects from simpler ones is called object composition. There are two types of object composition: composition, and aggregation.

Composition exists when a member of a class has a part-of relationship with the class. In a composition relationship, the class manages the existence of the members. To qualify as a composition, an object and a part must have the following relationship:

The part (member) is part of the object (class)
The part (member) can only belong to one object (class) at a time
The part (member) has its existence managed by the object (class)
The part (member) does not know about the existence of the object (class)
Compositions are typically implemented via normal member variables, or by pointers where the class manages all the memory allocation and deallocation. If you can implement a class as a composition, you should implement a class as a composition.

Aggregations exists when a class has a has-a relationship with the member. In an aggregation relationship, the class does not manage the existence of the members. To qualify as an aggregation, an object and its parts must have the following relationship:

The part (member) is part of the object (class)
The part (member) can belong to more than one object (class) at a time
The part (member) does not have its existence managed by the object (class)
The part (member) does not know about the existence of the object (class)
Aggregations are typically implemented via pointer or reference.

Associations are a looser type of relationship, where the class uses-an otherwise unrelated object. To qualify as an association, an object and an associated object must have the following relationship:

The associated object (member) is otherwise unrelated to the object (class)
The associated object (member) can belong to more than one object (class) at a time
The associated object (member) does not have its existence managed by the object (class)
The associated object (member) may or may not know about the existence of the object (class)
Associations may be implemented via pointer or reference, or by a more indirect means (such as holding the index or key of the associated object).

In a dependency, one class uses another class to perform a task. The dependent class typically is not a member of the class using it, but rather is temporarily created, used, and then destroyed, or passed into a member function from an external source.

In a container class one class provides a container to hold multiple objects of another type. A value container is a composition that stores copies of the objects it is holding. A reference container is an aggregation that stores pointers or references to objects that live outside the container.

std::initializer_list can be used to implement constructors, assignment operators, and other functions that accept a list initialization parameter. std::initializer_list lives in the <initializer_list> header.

Property\Type	Composition	Aggregation	Association	Dependency
Relationship type	Whole/part	Whole/part	Otherwise unrelated	Otherwise unrelated
Members can belong to multiple classes	No	Yes	Yes	Yes
Members existence managed by class	Yes	No	No	No
Directionality	Unidirectional	Unidirectional	Unidirectional or bidirectional	Unidirectional
Relationship verb	Part-of	Has-a	Uses-a	Depends-on
Quiz time

This chapter is pretty straightforward and a little more abstract than the previous ones, so this quiz will be short and to the point.

What type of relationship (composition, aggregation, association, or dependency) do the following describe?
1a) An Animal class that contains an animal type (enum) and name (string).
Hide Solution

Composition -- The animal type and name don’t have a use outside of the Animal.
1b) A text editor class with a save() function that takes a File object as an argument. The save() function writes the contents of the editor to disk.
Hide Solution

Dependency -- The text editor class is using the File object for the task of saving to disk.
1c) An Adventurer class that can carry various kinds of Items, such as swords, wands, potions, or spellbooks. These Items can be dropped and picked up by other Adventurers.
Hide Solution

Association -- the Adventurer and Items aren’t a whole-part relationship, so this isn’t an aggregation. The Adventurer uses-a Items, and doesn’t manage their existence.
1d) The Player prays at a Shrine (to receive a new power).
Hide Solution

Dependency -- They player depends on the shrine to receive the power, but does not have any long-term association with it.
1e) A Computer class that contains a CPU class. The CPU can be removed from the Computer and tested on its own.
Hide Solution

Aggregation -- The computer has a CPU, but does not manage its existence.
1f) A blacksmith has a specific anvil that he uses to do his work.
Hide Solution

Association -- The blacksmith uses the anvil, but does not have a whole-part relationship with it.
Select one: If you can design a class using (pick one: composition, aggregation, association, or dependency), then you should.
Hide Solution

composition