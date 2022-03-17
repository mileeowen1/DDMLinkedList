/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: March 29, 2020
Programming Assignment: PA6
Description: Create a program that would arrange our music library based attributes such as song title, song artist, song genre, and rating. This assignment is a digital music manager (DMM) for managing a music library using linked list.
Notes: Function definition cpp file
*/
#include "PA6.h"
/*************************************************************
 * Function: displayMenu()
 * Date Created: 03/06/20
 * Date Last Modified: 03/06/20
 * Description: This function displays the menu for the user
 *				to pick from.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: The display menu is displayed to the terminal.
 *************************************************************/
void displayMenu() {
	// displays the menu options
	cout << endl << "Welcome to the Digital Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Load library" << endl;
	cout << "2) Store library" << endl;
	cout << "3) Display library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Play song clip" << endl;
	cout << "7) Insert song in order" << endl;
	cout << "8) Remove song" << endl;
	cout << "9) Edit song" << endl;
	cout << "10) Exit" << endl;
}
/*************************************************************
 * Function: getValidChoice()
 * Date Created: 03/06/20
 * Date Last Modified: 03/06/20   
 * Description: This function makes sure the user's input is
 *				valid.
 * Input parameters: none
 * Returns: the integer for user's choice
 * Pre: nothing
 * Post: An integer for the user's choice is returned.
 *************************************************************/
int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}
/*************************************************************
 * Function: executeUserChoice()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20         
 * Description: This function takes the user's choice and
 *				executes the corresponding functions.
 * Input parameters: The user's choice and a SongLibrary object 
 *				must be pass by reference.
 * Returns: nothing
 * Pre:  The user's choice and a SongLibrary object, that must 
 *				be pass by reference, had to have been
 *            	scanned in by the user.
 * Post: The class member functions are executed and messages
 *				are displayed.
 *************************************************************/
void executeUserChoice(int choice, SongLibrary& lib) {
	string userFile, userAttribute, userAttributeValue, userEditAttribute, userNewAttribute;
	Song * foundSong;
	bool songFound;
	string titleName, artistName, genreType, clipName, temp;
	int ratingValue, ind;
	Song * editSong;
	Song * userSong;

	switch (choice) {
		case 1:
			// TODO: call a member function, something like lib.loadLibrary();
			// gets file for reading in and loads info to the library
			cout << "What file for reading in: ";
			getline(cin, userFile);
			lib.performLoad(userFile);
			break;
		case 2:
			// TODO: call a member function, something like lib.saveLibrary();
			// gets file for writing out and loads info from the library to the file
			cout << "What file for writing out: ";
			getline(cin, userFile);
			lib.performSave(userFile);
			break;
		case 3: 
			// TODO: call a member function, something like lib.displayLibrary();
			// displays the songs' attributes in the library
			lib.displayLibrary();
			break;
		case 4:
			// TODO: call a member function, something like lib.sortLibrary();
			// sorts the library songs by attribute entered by user
			cout << "What attribute for sorting: ";
			getline(cin, userAttribute);
			// prompt user for another entry if input does not match an attribute
			while (userAttribute != "title" && userAttribute != "artist" && userAttribute != "genre" && userAttribute != "clip" && userAttribute != "rating") {
				cout << "Not a valid attribute. Please re-enter your choice: ";
				getline(cin, userAttribute);
			}
			lib.setSortAttribute(userAttribute);
			lib.performSort();
			break;
		case 5:
			// TODO: call a member function, something like lib.searchLibrary();
			// searchs the library for song by attribute entered by user
			cout << "Attribute to search for: ";
			getline(cin, userAttribute);
			
			// prompt user for another entry if input does not match an attribute
			while (userAttribute != "title" && userAttribute != "artist" && userAttribute != "genre" && userAttribute != "clip" && userAttribute != "rating") {
				cout << "Not a valid attribute. Please re-enter your choice: ";
				getline(cin, userAttribute);
			}
			
			cout << "Attribute value to search for: ";
			getline(cin, userAttributeValue);
			
			foundSong = lib.performSearch(userAttribute, userAttributeValue, &songFound, &ind);
			
			// if statement for if song is found or not
			if (songFound == false) {
				cout << "Song was not found." << endl;
			}
			else {
				cout << "Title: " << foundSong->getTitle() << endl;
				cout << "Artist: " << foundSong->getArtist() << endl;
				cout << "Genre: " << foundSong->getGenre() << endl;
				cout << "Clip: " << foundSong->getClip() << endl;
				cout << "Rating: " << foundSong->getRating() << endl;
			}
			break;
		case 6:
		 	// TODO: call a member function, something like lib.playSongClipInLibrary();
		 	// searchs the library for song to play by attribute entered by user
		 	cout << "Attribute to search for: ";
			getline(cin, userAttribute);
			
			while (userAttribute != "title" && userAttribute != "artist" && userAttribute != "genre" && userAttribute != "clip" && userAttribute != "rating") {
				cout << "Not a valid attribute. Please re-enter your choice: ";
				getline(cin, userAttribute);
			}
			
			cout << "Attribute value to search for: ";
			getline(cin, userAttributeValue);
			
			// play song
			lib.playSongClipInLibrary(userAttribute, userAttributeValue);
		 	break;
		case 7:
			// TODO: call a member function, something like lib.insertSongInLibraryOrder();
			// get's song information to insert
			cout << "What song title to insert: ";
			getline(cin, titleName);
			cout << "What song artist to insert: ";
			getline(cin, artistName);
			cout << "What song genre to insert: ";
			getline(cin, genreType);
			cout << "What song clip to insert: ";
			getline(cin, clipName);
			cout << "What song rating to insert: ";
			getline(cin, temp);
			ratingValue = stoi(temp);
			
			// creates a Song
			userSong = new Song(titleName, artistName, genreType, clipName, ratingValue);
			lib.performInsertSongInOrder(userSong);
			break;
		case 8:
			// TODO: call a member function, something like lib.removeSongFromLibrary();
			// searchs the library for song to remove by attribute entered by user
			cout << "Attribute to search for removal: ";
			getline(cin, userAttribute);
			
			while (userAttribute != "title" && userAttribute != "artist" && userAttribute != "genre" && userAttribute != "clip" && userAttribute != "rating") {
				cout << "Not a valid attribute. Please re-enter your choice: ";
				getline(cin, userAttribute);
			}
			
			cout << "Attribute value to search for removal: ";
			getline(cin, userAttributeValue);
			foundSong = lib.performSearch(userAttribute, userAttributeValue, &songFound, &ind);
			
			// if statement for if song was found
			if (songFound == true) {
				lib.performRemoveSong(foundSong);
			}
			else {
				cout << "Song was not found for removal." << endl;
			}
			break;
		case 9:
			// TODO: call a member function, something like lib.editSongInLibrary();
			// searchs the library for song to edit by attribute entered by user
			cout << "Attribute to search for editing: ";
			getline(cin, userAttribute);
			
			while (userAttribute != "title" && userAttribute != "artist" && userAttribute != "genre" && userAttribute != "clip" && userAttribute != "rating") {
				cout << "Not a valid attribute. Please re-enter your choice: ";
				getline(cin, userAttribute);
			}
			
			cout << "Attribute value to search for editing: ";
			getline(cin, userAttributeValue);
			editSong = lib.performSearch(userAttribute, userAttributeValue, &songFound, &ind);
			
			
			// if song is found, edit attribute
			if (songFound == true) {
				cout << "Attribute to edit: ";
				getline(cin, userEditAttribute);
			
				while (userEditAttribute != "title" && userEditAttribute != "artist" && userEditAttribute != "genre" && userEditAttribute != "clip" && userEditAttribute != "rating") {
					cout << "Not a valid attribute. Please re-enter your choice: ";
					getline(cin, userEditAttribute);
			}
			
				cout << "Attribute value to change to: ";
				getline(cin, userNewAttribute);
				
				if (userEditAttribute == "rating") {
					ratingValue = stoi(userNewAttribute);
					while (ratingValue < 1 || ratingValue > 5) {
						cout << "Not a valid rating. Please enter another value: ";
						getline(cin, userNewAttribute);
						ratingValue = stoi(userNewAttribute);
					}
				}
				
				lib.performEditSong(editSong, userEditAttribute, userNewAttribute);
			}
			else {
				cout << "Song was not found for editing." << endl;
			}
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}
/*************************************************************
 * Function: runDigitalMusicManager()
 * Date Created: 03/06/20
 * Date Last Modified: 03/06/20     
 * Description: This function runs the digital music manager.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: Runs the member functions called that execute the
 *				digital music manager.
*************************************************************/
void runDigitalMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the Digital Music Manager!!" << endl;
}
