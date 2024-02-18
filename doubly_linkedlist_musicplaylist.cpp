/*1.Music playlist creation
-Design a system to keep track of songs in a playlist
-Song details are represented by nodes in a doubly linked list.
-Navigate through previous and next song in the list
-Display the songs according to producer, singer and genre.
-Other customisations if you want to add*/

#include <iostream>
#include <string>
using namespace std;

// Class to represent a song Node
class Song {
public:
    string title;
    string singer;
    Song* prev;
    Song* next;

    
    Song(string t, string s) : title(t), singer(s), prev(NULL), next(NULL) {}
};

// Class to represent a playlist
class Playlist {
public:
    Song* head;
    Song* current;

    Playlist() : head(NULL), current(NULL) {}

    // add a song to the end of the playlist
    void addSong(string title, string singer) {
        Song* newSong = new Song(title, singer);
        if (head == NULL) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->prev = temp;
        }
        cout << "Song \"" << title << "\" added to the end of the playlist." << endl;
    }

    
    // display all songs in the playlist
    void displaySongs() {
        if (head == NULL) {
            cout << "Playlist is empty." << endl;
            return;
        }
        cout << "Playlist Songs:" << endl;
        cout << "----------------------------------------" << endl;
        Song* temp = head;
        while (temp) {
            cout << "Title: " << temp->title << endl;
            cout << "Singer: " << temp->singer << endl;
            cout << "----------------------------------------" << endl;
            temp = temp->next;
        }
    }

    // select a song by it's title
    void selectSongByTitle(string title) {
        Song* temp = head;
        while (temp) {
            if (temp->title == title) {
                current = temp;
                cout<<"searching....\n";
                cout<<"now playing "<<current->title<<"\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Song \"" << title << "\" not found in the playlist." << endl;
    }
    
// select a song by singer
    /*void selectSongBySinger(string singer) {
        Song* temp = head;
        while (temp) {
            if (temp->singer == singer) {
                current = temp;
                cout<<"searching....\n";
                cout<<"now playing "<<current->title<<"by "<<current->singer<<"\n";
            }
            temp = temp->next;
        }
        cout << "Song \"" << title << "\" not found in the playlist." << endl;
    }*/

    // move to the next song
    void nextSong() {
        if (current && current->next){
            current = current->next;
            cout<<"moving to next song \n";
            cout<<"now playing "<<current->title<<" \n";
        }
        else{
            cout << "No next song available." << endl;
        }
    }

    // move to the previous song
    void previousSong() {
        if (current && current->prev){
            current = current->prev;
            cout<<"moving to previous song \n";
            cout<<"now playing "<<current->title<<" \n";
        }
        else{
            cout << "No previous song available.";
        }
    }

    // remove a song by its title
    void removeSongByTitle(string title) {
        if (head == NULL) {
            cout << "Playlist is empty. Cannot remove song." << endl;
            return;
        }
        Song* temp = head;
        while (temp) {
            if (temp->title == title) {
                if (temp == head) {
                    head = head->next;
                    if (head)
                        head->prev = NULL;
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next)
                        temp->next->prev = temp->prev;
                }
                if (current == temp) 
                    current = NULL;  
                delete temp;
                cout << "Song \"" << title << "\" removed successfully." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song \"" << title << "\" not found in the playlist." << endl;
    }

    // delete the currently selected song
    void deleteCurrentSong() {
        if (current) {
            string title = current->title;
            removeSongByTitle(title);
            current = NULL; 
        } else {
            cout << "No song selected." << endl;
        }
    }

    // remove the last song from the playlist
    void removeLastSong() {
        if (head == NULL) {
            cout << "Playlist is empty. Cannot remove song." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Last song removed successfully." << endl;
            return;
        }
        Song* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        cout << "Last song removed successfully." << endl;
    }

    // remove the first song from the playlist
    void removeFirstSong() {
        if (head == NULL) {
            cout << "Playlist is empty. Cannot remove song." << endl;
            return;
        }
        Song* temp = head;
        head = head->next;
        if (head)
            head->prev = NULL;
        delete temp;
        cout << "First song removed successfully." << endl;
    }

};

int main() {
    Playlist myPlaylist;
    int choice;
    string title, singer;

    do {
        cout<<"\n1. Add Song\n";
        cout<<"2. Display Playlist\n";
        cout<<"3. Select Song\n";
        cout<<"4. Next Song\n";
        cout<<"5. Previous Song\n";
        cout<<"6. Remove Current Song\n";
        cout<<"7. Remove Song by Title\n";
        cout<<"8. Remove Last Song\n";
        cout<<"9. Remove First Song\n";
        cout<<"10. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                cin.ignore(); 
                getline(cin, title);
                cout << "Enter singer: ";
                getline(cin, singer);
                myPlaylist.addSong(title, singer);
                break;
            case 2:
                myPlaylist.displaySongs();
                break;
            case 3:
                cout << "Enter the title of the song to select: ";
                cin.ignore(); 
                getline(cin, title);
                myPlaylist.selectSongByTitle(title);
                break;
            case 4:
                myPlaylist.nextSong();
                break;
            case 5:
                myPlaylist.previousSong();
                break;
            case 6:
                myPlaylist.deleteCurrentSong();
                break;
            case 7:
                cout << "Enter the title of the song to remove: ";
                cin.ignore(); 
                getline(cin, title);
                myPlaylist.removeSongByTitle(title);
                break;
            case 8:
                myPlaylist.removeLastSong();
                break;
            case 9:
                myPlaylist.removeFirstSong();
                break;
            case 10:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
