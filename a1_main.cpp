// a1_main.cpp

//
// You can change this file in any way you like.
//
// Thoroughly test your Wordlist class to make sure it is correct.
//

#include "Wordlist.h"
#include "test.h"

void read_from_terminal()
{
    Wordlist lst;
    string w;
    while (cin >> w)
    {
        lst.add_word(w);
    }

    // print the words in sorted order
    vector<string *> index = lst.get_sorted_index();
    for (int i = 0; i < index.size(); i++)
    {
        cout << (i + 1) << ". " << *index[i] << endl;
    }
}


void test_Wordlist()
{
    Test("test_Wordlist");

    Wordlist lst;
    assert(!lst.is_frozen());
    assert(lst.length() == 0);
    assert(!lst.contains("hello"));
    
    
    printf("\nTesting add_word\n");
    
    //testing add_word and length
    const string w = "bob";
    lst.add_word(w);

    const string w2 = "bob";
    lst.add_word(w2);

    const string w3 = "cat";
    lst.add_word(w3);

    //testing contains
    assert(lst.contains("bob"));
    assert(lst.contains("cat"));
    assert(!lst.contains("dog"));

    //testing print
    lst.print();
    printf("\n\n\n");


    //testing get_word

    assert(lst.get_word(0) == "bob");
    assert(lst.get_word(1) == "cat");
    assert(lst.get_word(0) != "joe");
    
  
    assert(lst.first_word() == "bob");
    assert(lst.last_word() == "cat");

    cout << "Testing copy constructor\n\n";
    Wordlist lst2 = Wordlist(lst);
    lst2.print();
    cout << lst2.length() << endl;
    assert(lst2.length() == lst.length());
    lst2.remove_word("cat");
    assert(lst2.contains("cat") == false);
    assert(lst.contains("cat") == true);
    
    assert(lst.length() == 2);
    lst2.print();

    assert(lst2.length() == 1);
    assert(lst2.first_word() == "bob");
    assert(lst2.last_word() == "bob");
    assert(lst2.is_frozen() == false);
    lst2.add_word("bob");
    assert(lst2.length() == 1);
    lst2.remove_word("cat");
    assert(lst2.length() == 1);
    lst2.print();
    lst2.remove_word("bob");
    assert(lst2.length() == 0);
    lst2.remove_word("bob");
    assert(lst2.contains("bob") == false);
    //
    // Add more test cases here. Use assert or if-statements to automatically
    // check the correctness of your code.
    //

} // test_Wordlist


void test_function()
{
    Wordlist lst;
    assert(!lst.is_frozen());
    assert(lst.length() == 0);
    assert(!lst.contains("hello"));

    lst.add_word("hello");
    assert(lst.length() == 1);

    lst.add_word("Hello");
    assert(lst.length() == 2);

    lst.add_word("hello");
    assert(lst.length() == 2);

    lst.add_word("bye");
    assert(lst.length() == 3);

    assert(lst.get_word(1) == "Hello");
    assert(lst.first_word() == "hello");
    assert(lst.last_word() == "bye");
    assert(lst.contains("Hello") == true);

    lst.remove_word("Hello");

    vector<string *> indexTest = lst.get_sorted_index();

    for (int i = 0; i < indexTest.size(); i++)
    {
        cout << (i + 1) << ". " <<indexTest[i] << endl;
    }

    assert(lst.is_frozen() == true);
    lst.add_word("test");
    assert(lst.length() == 2);
    assert(!(lst.contains("test")));
    lst.remove_word("Hello");
    
}


void test_Wordlist1()
{
    Test("test_Wordlist");

    Wordlist lst;
    assert(!lst.is_frozen());
    assert(lst.length() == 0);
    assert(!lst.contains("hello"));

    lst.add_word("hello");
    assert(lst.length() == 1);

    lst.add_word("Hello");
    assert(lst.length() == 2);

    lst.add_word("hello");
    assert(lst.length() == 2);

    lst.add_word("bye");
    assert(lst.length() == 3);

    assert(lst.get_word(1) == "Hello");
    assert(lst.first_word() == "hello");
    assert(lst.last_word() == "bye");
    assert(lst.contains("Hello") == true);

    lst.remove_word("Hello");

    Wordlist lstCopy(lst);

    //lstCopy.remove_word("hello");
    //assert(lstCopy.length() == 1);
    //assert(lstCopy.get_word(0) == "bye");

    vector<string *> indexTest = lst.get_sorted_index();

    for (int i = 0; i < indexTest.size(); i++)
    {
        cout << (i + 1) << ". " << *indexTest[i] << endl;
    }

    assert(lst.is_frozen() == true);
    //lst.add_word("test");
    assert(lst.length() == 2);
    assert(!(lst.contains("test")));
    //lst.remove_word("Hello");

    //
    // Add more test cases here. Use assert or if-statements to automatically
    // check the correctness of your code.
    //

} // test_Wordlist

int main()
{
    //test_Wordlist();
    //test_function();
    // test_Wordlist();
    //read_from_terminal();
    //test_Wordlist1();


    Wordlist lst;
    lst.add_word("bob");
    lst.remove_word("bob");
    
}
