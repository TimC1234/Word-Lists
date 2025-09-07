// Wordlist.h

#pragma once

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Kuan Ting (Tim) Chou
// St.# : 301562019
// Email: tim_chou@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

//
// Do not use any other #includes
//
#include "Wordlist_base.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Wordlist : public Wordlist_base
{
    //
    // Use this Node to implement the doubly-linked list for the word list.
    // Don't change it any way!
    //
    struct Node
    {
        string word;
        Node *next;
        Node *prev;
    };

    //
    // ... your code goes here ...
    //
    private:
        /*
        Node *head;
        bool frozen;
        Node *tail;
        int total;
        */

    public:
    
    Node *head;
        bool frozen;
        Node *tail;
        int total;

    //Default Constructor
    Wordlist()
    {
        head = nullptr;
        frozen = false;
        tail = nullptr;
        total = 0;
    }

    //Copy Constructor 
    Wordlist(const Wordlist& other)
    {
        head = nullptr;
        frozen = other.frozen;
        tail = nullptr;
        //creates a temp variable that has the value of the original head
        Node *temp = other.head;
        total = 0;
        while (temp != nullptr)
        {
            //iterate through the original list
            //access the string from the original node and add it to the new node
            add_word(temp->word);
            temp = temp->next;
        }
    }
    
    //file constructor
    Wordlist(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            throw runtime_error("File failed to open");
        }
        head = nullptr;
        tail = nullptr;
        total = 0;
        frozen = false;
        string input;
        //redirects the contents/words of the file into the string variable input
        while (file >> input)
        {
            //uses the word stored in input to call add_word
            add_word(input);
        }
        //closes the file
        file.close();
    }


    //Destructor
    ~Wordlist()
    {
        total = 0;
        while(head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool is_frozen() const
    {
        return frozen;
    }

    bool contains(const string &w) const
    {
        Node *temp = head;
        //iterates through the list
        while (temp != nullptr)
        {
            //compares the string value of the ndoe to the value of w
            if (temp->word == w)
            {
                //exits the loop if matches
                return true;
            }
            //continues iterating
            temp = temp->next;
        }
        //returns false no strings match w
        return false;
    }

    int length() const
    {
       return total;
    }

    string get_word(int index) const
    {
        if (index < 0 || index >= length())
        {
            throw runtime_error("get_word: index out of range");
        } 
        else
        {
            int counter = 0;
            Node *temp = head;
            //runs through the loop index times and returns the temp->word at index
            while (counter < index)
            {
                counter++;
                temp = temp->next;
            }
            return temp->word;
        }
    }

    void add_word(const string &w)
    {
        if (is_frozen())
        {
            throw runtime_error("list is frozen");
        }
        
        //checks if list is empty then makes the node the tail and the head of the list.
        if (head == nullptr)
        {
            head = new Node{w, nullptr, nullptr};
            tail = head;
            total++;
            return;
        }

        if (contains(w) == true)
        {
            return;
        }

        //only runs when the word is not a duplicate
        Node *newNode = new Node{w, nullptr, tail};
        //makes the newNode->next = nullptr and newNode->prev = tail
        //appends the newNode to the end of the list so after the original tail
        tail->next = newNode;
        //makes the newNode the new tail
        tail = newNode;
        total++;
    }

    void remove_word(const string &w)
    {
        //checks if wordlist is frozen if yes it will crash the program
        if (is_frozen())
        {
            throw runtime_error("list is frozen");
        }
        
        Node *temp = head;

        while (temp != nullptr)
        {
             //Found node with matching string
            if (temp->word == w)
            {
                //create temp variables that store previous and next Nodes
                Node *nextNode = temp->next;
                Node *prevNode = temp->prev;

                //checks if the word isn't in the head
                if (prevNode != nullptr)
                {
                    //makes the previous node skip the current node and point to the nextNode
                    prevNode->next = nextNode;
                }
                else
                {
                    //makes the head pointer skip to the next node
                    head = nextNode;
                    if (head != nullptr)
                    {
                        //removes the previous node by setting it to nullptr
                        head->prev = nullptr;
                    }
                }
                //tests if the word is in the tail
                if (nextNode != nullptr)
                {
                    nextNode->prev = prevNode;
                }
                else
                {
                    tail = prevNode;
                }

                delete temp;
                temp = nextNode;
                total--;
                //immediately ends the function after finding the node with the string w
                //because there can only be at most 1 node with string w as add_word() 
                //does not allow duplicates
                return;
            }
            else
            {
                //continues iterating the list if the word in the node doesn't match
                temp = temp->next;
            }
        }
        return;
    }

    vector<string *> get_sorted_index()
    {
        frozen = true;
        Node *temp = head;
        //creates a vector variable called sorted_list that stores string pointers
        vector<string *> sorted_list;
        //fills the vector with the addresses/pointers of strings
        while (temp != nullptr)
        {
            sorted_list.push_back(&(temp->word));
            temp = temp->next;
        }

        //c++ standard library sort function
        //specifies where to begin and end sorting
        //Format and how to use sort function taken from https://www.geeksforgeeks.org/sort-c-stl/
        //3rd argument in the sort function is specifies how the sort function should compare
        //the sort function will determine which string is bigger and return a boolean
        sort(sorted_list.begin(), sorted_list.end(), [](const string *x, const string *y) 
        { return *x < *y; });
        
        return sorted_list;
    }

    //
    // ... you can write helper methods if you need them ...
    //
    
    //helper print function

    void print() const
    {
        if (head == nullptr)
        {
            cout << "Empty\n\n\n";
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->word << endl;
            temp = temp->next;
        }
    }

}; // class Wordlist

//
// ... you can write helper functions here (or before Wordlist) if you need them
// ...
//
