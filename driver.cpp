// Including the necessary header files
#include <iostream>
#include <string>
#include "playlist.h"

int main(int argc, char *argv[]){
    // Variable initializations and declarations 
    std::string input, parameter;
    bool run = true;
    
    // Creates a playlist using the size inputted by the user
    std::getline(std::cin, input);
    Playlist P1(std::stoi(input.substr(2)));
    std::cout << "success" << std::endl;

    // Loop that runs until the user enters the "done" command
    do {
        // Stores user input and parameter
        std::getline(std::cin, input);
        parameter = input.substr(2);

        // Adds the song to the playlist given the 'i' command
        if (input[0] == 'i') {
            // If add_song returns true, the song was added to the playlist, if add_song returns false, it cannot be inserted
            if (P1.add_song(parameter)) {
                std::cout << "success" << std::endl;
            } else {
                std::cout << "can not insert " << parameter << std::endl;
            }
        // Plays the song in the playlist given the 'p' command
        } else if (input[0] == 'p') {
            // If play_song returns true, the song was played, if play_song returns false, it cannot be played
            if (P1.play_song(stoi(parameter))) {
                std::cout << "played " << parameter << " " << P1.get_song(stoi(parameter)) << std::endl;
            } else {
                std::cout << "can not play " << parameter << std::endl;
            }
        // Erases the song in the playlist given the 'e' command
        } else if (input[0] == 'e') {
            // If erase_song returns true, the song was erased, if erase_song returns false, it cannot be erased
            if (P1.erase_song(stoi(parameter))) {
                std::cout << "success" << std::endl;
            } else {
                std::cout << "can not erase " << parameter << std::endl;
            }
        // Ends program given the "done" command
        } else if (input.substr(0,4) == "done") {
            run = false;
        }
    } while (run);
}