//***********************************************************
// Student Names: Nicolas Palmar and Kevin Wang
// Student Number: 
//
// SYDE 121 Lab: Home Assignment: 5
// Filename: a5_main
// We hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others
//
// Project: Book and Library Classes
// Purpose: Create a library that contains several books, and can insert, remove, or display books 
// Due Date: Friday, November 20, 2020
//**************************************************************

#include <iostream>
#include "a5_book.hpp"
#include "a5_library.hpp"
#include <vector>
using namespace std;

void test_book_constructor();
// PURPOSE: Creates book objects with the four different constructors
//     INPUTS: nothing
//     OUTPUTS: nothing

void test_library_constructor();
// PURPOSE: Creates libraries to contain a vector of book objects
//     INPUTS: nothing
//     OUTPUTS: nothing

void check_insertion_list(vector<bool> insert_list);
// PURPOSE: Checks if the insertion of the books completed or failed
//     INPUTS: insert_list - a vector containing all the books that are being attempted to insert
//     OUTPUTS: nothing; output is to console

void test_book_insertion();
// PURPOSE: Tests simple insertion of book objects into a library
//     INPUTS: nothing
//     OUTPUTS: nothing

void test_book_string_insertion();
// PURPOSE: Tests simple insertion using string values (title, author, dop) for a book into a library
//     INPUTS: nothing
//     OUTPUTS: nothing

void test_repeated_insertion();
// PURPOSE: Tests the insertion of repeated book objects and string values into a library and checks for correct/invalid insertion 
//     INPUTS: nothing
//     OUTPUTS: nothing

void check_removal_list(vector<bool> remove_list);
// PURPOSE: Checks if the removal of the books completed or failed
//     INPUTS: insert_list - a vector containing all the books that are being attempted to remove
//     OUTPUTS: nothing; output is to console

void test_removal();
// PURPOSE: Tests the removal of book objects, books with string values, and books that are not in the library
//     INPUTS: nothing
//     OUTPUTS: nothing

void test_book_constructor() {
    // create 4 books with each constructor
    Book book_1;
    Book book_2("Hamlet");
    Book book_3("Maze Runner", "James Dashner");
    Book book_4("I'm number 4", "Pittacus Lore", "January 4th 2015");

    // call book service method to check values
    cout << "CHECK 1: Should print book 1 (no info), book 2 (hamlet, no author, no dop), book 3 (maze runner, author, no dop), and book 4 (I'm number 4, author, dop)" << endl;
    book_1.print();
    book_2.print();
    book_3.print();
    book_4.print();
}


void check_insertion_list(vector<bool> insert_list) {
    // check insertions to see which have failed
    for (int i = 0; i < insert_list.size(); i++) {
        // output to console
        cout << "Insertion " << (i + 1) << ": " << (insert_list[i] ? "true" : "false") << endl;
    }
    cout << endl;
}


void test_library_constructor() {
    // create books with each constructor
    Book book_1;
    Book book_2("Hamlet");
    Book book_3("Maze Runner", "James Dashner");
    Book book_4("I'm number 4", "Pittacus Lore", "January 4th 2015");
    Book book_5("Hunger Games", "Suzan Collins", "January 4th 2015");
    Book book_6("I, Robot", "Isaac asimov", "July 7th 2007");
    Book book_7("The Rule of 3", "Eric Walters", "November 7th 2002");

    // make a book vector
    vector<Book> book_list = { book_1, book_2, book_3, book_4 };
    vector<Book> book_list_2 = { book_5, book_6, book_7 };

    // create 3 libraries
    Library lib_1;
    Library lib_2(book_list);
    Library lib_3(book_list_2);

    // call library service method to check values
    cout << "CHECK 1: lib_1 -> empty (prints nothing), lib_2 -> prints (book_1-book_4), lib_3 -> prints (book_5 -> book_7) " << endl;
    lib_1.print();
    lib_2.print();
    lib_3.print();
}

void test_book_insertion() {
    // create 4 books with each constructor
    Book book_1;
    Book book_2("Hamlet");
    Book book_3("Maze Runner", "James Dashner");
    Book book_4("I'm number 4", "Pittacus Lore", "January 4th 2015");

    // create 1 libraries
    Library lib_1;

    // insert books
    lib_1.insert_book(book_1);
    lib_1.insert_book(book_2);

    // check values
    cout << "CHECK 1: Should print book 1 (no info) and book 2 (hamlet)" << endl;
    lib_1.print();

    // insert books
    lib_1.insert_book(book_3);
    lib_1.insert_book(book_4);

    // check values
    cout << "CHECK 2: Should print book 1 (no info), book 2 (hamlet), book 3 (maze runner), book 4 (I'm number 4)" << endl;
    lib_1.print();
}

void test_book_string_insertion() {
    // create 2 libraries
    Library lib_1;
    Library lib_2;

    // insert books as strings into the libraries
    lib_1.insert_book("The Elegant Universe", "Brian Greene", "October 3 2009");
    lib_1.insert_book("Catching Fire", "Suzan Collins", "January 4th 2015");

    // check values
    cout << "CHECK 1: Should print the elegant universe and catching fire" << endl;
    lib_1.print();

    // insert into a different library
    lib_2.insert_book("Eyes of Minds", "James Dashner", "November 3 2009");
    
    // check values
    cout << "CHECK 2: Should print eyes of minds" << endl;
    lib_2.print();
}

void test_repeated_insertion() {
    // define an insert list vector
    vector<bool> insert_list;

    // create books
    Book book_1;
    Book book_2("Hamlet");
    Book book_3("Maze Runner", "James Dashner");
    Book book_4("I'm number 4", "Pittacus Lore", "January 4th 2015");
    Book book_5("Hunger Games", "Suzan Collins", "January 4th 2015");
    Book book_6("I, Robot", "Isaac asimov", "July 7th 2007");
    Book book_7("The Rule of 3", "Eric Walters", "November 7th 2002");
    Book book_8("Catching Fire", "Suzan Collins", "January 4th 2015");

    // create 1 library
    Library lib_1;

    // insert a book
    insert_list.push_back(lib_1.insert_book(book_1));
    insert_list.push_back(lib_1.insert_book(book_2));
    insert_list.push_back(lib_1.insert_book(book_3));
    insert_list.push_back(lib_1.insert_book(book_4));

    // check values
    cout << "CHECK 1: Should print books 1 to 4" << endl;
    lib_1.print();
    // check insertions to see which have failed
    cout << "CHECK 1 (continued): Should return true for all insertions" << endl;
    check_insertion_list(insert_list);

    // insert 2 repeated books
    insert_list.push_back(lib_1.insert_book(book_3));
    insert_list.push_back(lib_1.insert_book(book_4));
    // insert 1 un-repeated book
    insert_list.push_back(lib_1.insert_book(book_5));

    // check values
    cout << "CHECK 2: Should print books 1 to 5" << endl;
    lib_1.print();
    // check insertions to see which have failed
    cout << "CHECK 2 (continued): Should return true for insertions 1-4, false for 5-6, true for insertion 7" << endl;
    check_insertion_list(insert_list);

    // insert a repeated book as a string
    insert_list.push_back(lib_1.insert_book("I'm number 4", "Pittacus Lore", "January 4th 2015"));
    // insert an unrepeated book as a string
    insert_list.push_back(lib_1.insert_book("Catching Fire", "Suzan Collins", "January 4th 2015"));

    // check values
    cout << "CHECK 3: Should print books 1 to 5 plus 'Catching fire'" << endl;
    lib_1.print();
    // check insertions to see which have failed
    cout << "CHECK 2 (continued): Should return true for insertions 1-4, false for 5-6, true for insertion 7, false for 8, true for 9" << endl;
    check_insertion_list(insert_list);
}


void check_removal_list(vector<bool> remove_list) {
    // check removals to see which have failed
    for (int i = 0; i < remove_list.size(); i++) {
        // output to console
        cout << "Removal " << (i + 1) << ": " << (remove_list[i] ? "true" : "false") << endl;
    }

    cout << endl;
}

void test_removal() {
    // define an remove list vector
    vector<bool> remove_list;
    // create 4 books with each constructor
    Book book_1;
    Book book_2("Hamlet");
    Book book_3("Maze Runner", "James Dashner");
    Book book_4("I'm number 4", "Pittacus Lore", "January 4th 2015");

    Book book_5("Hunger Games", "Suzan Collins", "January 4th 2015");
    Book book_6("I, Robot", "Isaac asimov", "July 7th 2007");
    Book book_7("The Rule of 3", "Eric Walters", "November 7th 2002");

    Book book_8("Catching Fire", "Suzan Collins", "January 4th 2015");

    // create 2 libraries
    Library lib_1;

    // insert a book
    lib_1.insert_book(book_8);
    lib_1.insert_book(book_2);
    lib_1.insert_book(book_5);
    lib_1.insert_book(book_1);

    // check values
    cout << "CHECK 1" << endl;
    lib_1.print();

    // remove good books
    remove_list.push_back(lib_1.remove_book(book_2));
    remove_list.push_back(lib_1.remove_book(book_1));

    // remove book not in library
    remove_list.push_back(lib_1.remove_book(book_7));

    // check values
    cout << "CHECK 2" << endl;
    lib_1.print();

    // check removals to see which have failed
    check_removal_list(remove_list);

    // check removals usings strings as parameters
    remove_list.push_back(lib_1.remove_book("Hunger Games", "Suzan Collins", "January 4th 2015"));
    remove_list.push_back(lib_1.remove_book("I'm number 4", "Pittacus Lore", "January 4th 2015"));

    // check values
    cout << "CHECK 3" << endl;
    lib_1.print();

    // check removals to see which have failed
    check_removal_list(remove_list);
}

int main()
{
    test_book_constructor();
    test_library_constructor();
    test_book_insertion();
    test_book_string_insertion();
    test_repeated_insertion();
    /*test_removal();*/
}

