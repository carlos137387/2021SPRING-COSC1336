#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct node
{
    string firstName;
    string lastName;
    node *next;
};

class List
{
private:
    node *head, *tail;
public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void create_contact(string first, string last) // Create node and add it onto the linked list
    {
        node *temp = new node;
        temp->firstName = first;
        temp->lastName = last;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void display_all() // Prints out current trip
    {
        int contactNum = 1;
        node *temp = new node;
        temp = head;
        while (temp != NULL)    // Loop through the list while the temporary node is not empty
        {
            cout << "\nContact Number: " << contactNum << endl;
            cout << "First Name: " << temp->firstName << endl;
            cout << "Last Name: " << temp->lastName << endl;
            ++contactNum;
            temp = temp->next;
        }
    }

    void delete_position(int pos)   // delete a stop by using the position in the list
    {
        node *current = new node;
        node *previous = new node;
        node *next = new node;
        current = head;
        for (int i = 1;i<pos;i++)   // Loop through the link list while the current node is not empty
        {
            if (current == NULL)
                return;
            previous = current;
            current = current->next;
        }
        next = current->next;
        previous->next = current->next;
        delete current;
    }

    void delete_head()  // delete head node
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }
};

int main()
{
    List Contacts; // create a Contacts item for the List class
    int choice, position;
    string firstName;
    string lastName;

    while (1) {
        cout << "\nWhat would you like to do?: " << endl;
        cout << "1. Show All Contacts" << endl;
        cout << "2. Add A Contact" << endl;
        cout << "3. Remove A Contact" << endl;
        cout << "4. Search Contacts (Coming Soon)" << endl;
        cout << "5. Exit The Program" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << endl;
            Contacts.display_all(); // display all contacts
            cout << endl;
            break;
        case 2:
            cout << "\nEnter your first name: ";
            cin >> firstName;
            cout << "\nEnter your last name: ";
            cin >> lastName;
            Contacts.create_contact(firstName, lastName); // create the contact in the linked list
            cout << endl;
            break;
        case 3:
            cout << "Enter the contact number of the contact you would like to remove: ";
            cin >> position;
            if (position == 1)
                Contacts.delete_head();
            else
                Contacts.delete_position(position); // delete contact from list
            break;
        case 5:
            exit(1);
            break;
        default:
            cout << "\n" << choice << " is not an option. Please select a valid option." << endl;
            break;
        }
    }
    system("pause");
    return 0;
}