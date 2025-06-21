// Including the necessary header files
#include "playlist.h"
#include <string>

// Constructor that creates a dynamically allocated playlist with a specified size
Playlist::Playlist(unsigned int input_size) {
    size = input_size;
    songs = new std::string[input_size]{};
}

// Destructor that deletes the dynamically allocated playlist when the program ends
Playlist::~Playlist() {
    delete [] songs;
    songs = nullptr;
}

// Adds a song to the playlist
bool Playlist::add_song(std::string song) {
    // Checks if the song is a restricted entry or if the playlist is full
    if (song == "Baby;Justin Bieber" || song.substr(0,song.find(';')) == "My Heart Will Go On" || songs[size - 1] != "") {
        return false;
    }
    // Loop that checks if the song is already in the playlist and if not, adds it to the first empty position
    for (unsigned int i = 0; i < size; i++) {
        if (songs[i] == song) {
            return false;
        } else if (songs[i] == "") {
            songs[i] = song;
            return true;
        }
    }
    return false;
}

// Plays the song at a specified position
bool Playlist::play_song(unsigned int position) {
    if (position >= 0 && position < size && songs[position] != "") {
        return true;
    }
    return false;
}

// Erases the song at a specified position
bool Playlist::erase_song(unsigned int position) {
    // Check if the position is out of bounds for the playlist
    if (position < 0 || position >= size || songs[position] == "") {
        return false;
    }
    // Loop that overwrites the current position with the next position stopping once the next position is empty
    for (unsigned int i = position; i < size - 1; i++) {
        songs[i] = songs[i+1];
        if (songs[i+1] == "") {
            break;
        }
    }
    // Erases the last position of the playlist array (a successful erase will always make the last position empty)
    songs[size - 1] = "";
    return true;
}

// Returns the song at the specified position
std::string Playlist::get_song(unsigned int position) {
    return songs[position];
}