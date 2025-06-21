// Including the necessary header file
#include <string>

// Playlist class definiton
class Playlist {
    // Private member variables
    private:
    unsigned int size;  // Maximum size of the playlist
    std::string* songs; // Array to store songs

    // Public member functions
    public:
    Playlist(unsigned int input_size);  // Constructor that creates a dynamically allocated playlist with a specified size
    ~Playlist();                        // Destructor that deletes the dynamically allocated playlist when the program ends

    bool add_song(std::string song);                // Adds a song to the playlist
    bool play_song(unsigned int position);          // Plays the song at a specified position
    bool erase_song(unsigned int position);         // Erases the song at a specified position
    std::string get_song(unsigned int position);    // Returns the song at a specified position
};