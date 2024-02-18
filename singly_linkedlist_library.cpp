/*1.Implement Library Catalog
- Design a system to keep track of books in a library
-Each node represents a book, and the linked list facilitates easy addition
and removal of books.
-Searching of a book by title / author name.
-Other customisations if you want to add*/

#include <iostream>
#include <string>
using namespace std;

// Define the structure for a book
struct Book {
    string title;
    string author;
    Book* next;
    
    
    Book(string t, string a) : title(t), author(a), next(NULL) {}
};

// Define the Library class
class Library {
public:
    Book* head; 
    Library() : head(NULL) {}
    
    ~Library() {
        while (head != NULL) {
            Book* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // add a book to the catalog
    void addBook(string title, string author) {
        Book* newBook = new Book(title, author);
        newBook->next = head;
        head = newBook;
    }
    
    // search for a book by title
    Book* searchByTitle(string title) {
        Book* current = head;
        while (current != NULL) {
            if (current->title == title) {
                cout<<" "<<current->title<<" \n";
                return current;
            }
            current = current->next;
        }
        // cout<<"Book not found ";
        return NULL; 
    }
    
    // search for a book by author
    Book* searchByAuthor(string author) {
        Book* current = head;
        while (current != NULL) {
            if (current->author == author) {
                cout<<" "<<current->title<<" \n";
                return current;
            }
            current = current->next;
        }
        // cout<<"Book not found ";
        return NULL; 
    }
    
    // display all books in the Library
    void displayLibrary() {
        Book* current = head;
        cout << "Catalog:\n";
        while (current != NULL) {
            cout << "Title: " << current->title << ", Author: " << current->author << endl;
            current = current->next;
        }
    }
};

int main() {
    Library obj;
    int choice;
    string title, author;
    
    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add a book\n";
        cout << "2. Search by title\n";
        cout << "3. Search by author\n";
        cout << "4. Display Library\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter title of the book: ";
                cin.ignore(); 
                getline(cin, title);
                cout << "Enter author of the book: ";
                getline(cin, author);
                obj.addBook(title, author);
                break;
            case 2:
                cout << "Enter title to search: ";
                cin.ignore(); 
                getline(cin, title);
                if (obj.searchByTitle(title) != NULL) {
                    cout << "Book found!\n";
                } else {
                    cout << "Book not found.\n";
                }
                break;
            case 3:
                cout << "Enter author to search: ";
                cin.ignore(); 
                getline(cin, author);
                if (obj.searchByAuthor(author) != NULL) {
                    cout << "Book found!\n";
                } else {
                    cout << "Book not found.\n";
                }
                break;
            case 4:
                obj.displayLibrary();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}
