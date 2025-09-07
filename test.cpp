// a1_main.cpp

//
// You can change this file in any way you like.
//
// Thoroughly test your Wordlist class to make sure it is correct.
//

#include "Wordlist.h"
#include "test.h"

int main()
{
    Wordlist lst;
    lst.add_word("Bob");
    lst.add_word("Joe");
    lst.add_word("Dog");
    lst.print();
    cout << "\n\n";
    cout << lst.head->word << endl;
    cout << lst.head->next->prev->word << endl;
    lst.head->next->prev = lst.tail;
    cout << lst.head->word << endl;


    cout << "\n\n";
    cout << lst.head->next->prev->word << endl;

    lst.print();
}