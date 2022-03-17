/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: March 29, 2020
Programming Assignment: PA6
Description: Create a program that would arrange our music library based attributes such as song title, song artist, song genre, and rating. This assignment is a digital music manager (DMM) for managing a music library using linked list.
Notes: Linked list function definition cpp file
*/
#include "SongLibrary.h"
/*************************************************************
 * Function: SongLibrary()
 * Date Created: 03/06/20
 * Date Last Modified: 03/06/20          
 * Description: This function is the default value constructor
 *				and sets newly declared SongLibrary to default
 *				values.
 * Input parameters: none
 * Returns: nothing
 * Pre: Sets the values for the SongLibrary class.
 * Post: The values for the attributes are set to its default.
 *************************************************************/
SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	// BONUS default sort attribute is title
	sortAttribute = "title";
}
/*************************************************************
 * Function: SongLibrary()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20          
 * Description: This function is the copy constructor and it
 *				copies contents from one SongLibrary to another.
 * Input parameters: A constant SongLibrary must be entered.
 * Returns: nothing
 * Pre: A constant SongLibrary, that is pass by reference, had
 *				to have been scanned in by the user.
 * Post: The values for the attributes are copied over.
 *************************************************************/
// TODO: finish SongLibrary copy constructor
// no dynamically allocated memory should be shared
// between the two SongLibrary objects!!
// calls Song's copy constructor
SongLibrary::SongLibrary(const SongLibrary& other) {
	Song * curr = other.head;
	
	// copy over contents
	curr = new Song(*curr);
	head = curr;
	while (curr->getNext() != NULL) {
		curr->setNext(new Song(*curr->getNext()));
		curr = curr->getNext();
	}
	
	sortAttribute = other.sortAttribute;
}
/*************************************************************
 * Function: ~SongLibrary()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20         
 * Description: This function is the destructor and it frees
 *				all dynamically allocated memory.
 * Input parameters: none
 * Returns: nothing
 * Pre: none
 * Post: When an object is about to be destoryed, memory is
 *				deallocated.
 *************************************************************/
// TODO: finish SongLibrary destructor
// be sure to properly free memory!!
SongLibrary::~SongLibrary() {
	Song * currSong = head;
	Song * nextSong = NULL;
	
	while (currSong != NULL) {
		// save the link to the next node
		nextSong = currSong->getNext();
		// can safely delete currNode
		delete currSong;
		currSong = nextSong;
	}
	head = NULL; // for good practice
}
/*************************************************************
 * Function: getHead()
 * Date Created: 03/06/20
 * Date Last Modified: 03/06/20          
 * Description: This function is a getter that gets the head.
 * Input parameters: none
 * Returns: the head
 * Pre: nothing
 * Post: The head is returned.
 *************************************************************/
Song * SongLibrary::getHead() {
	return head;
}
/*************************************************************
 * Function: setHead()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20         
 * Description: This function is a setter that sets the head
 *				according to the user.
 * Input parameters: the Song pointer to a new head
 * Returns: nothing
 * Pre: The Song pointer to a new head had to have been scanned
 *				in by the user.
 * Post: The new head replaces the old.
 *************************************************************/
// TODO: finish this setter to properly free memory if head != NULL
void SongLibrary::setHead(Song * newHead) {
	if (head != NULL) {
		// TODO: free old list here!!
		Song * temp = head;
		head = head->getNext();
		delete temp;
	}
	head = newHead;
}
/*************************************************************
 * Function: getSortAttribute()
 * Date Created: 03/06/20
 * Date Last Modified: 03/06/20          
 * Description: This function is a getter that gets the attribute
 *				for sorting.
 * Input parameters: none
 * Returns: the attribute for sorting
 * Pre: nothing
 * Post: The string for sorting the library is returned.
 *************************************************************/
string SongLibrary::getSortAttribute() {
	return sortAttribute;
}
/*************************************************************
 * Function: setSortAttribute()
 * Date Created: 03/06/20
 * Date Last Modified: 03/06/20         
 * Description: This function is a setter that sets the sorting
 *				attribute according to the user.
 * Input parameters: the string of the new sort attribute
 * Returns: nothing
 * Pre: The string of the new sort attribute had to have been
 *				scanned in by the user.
 * Post: The new sort attribute replaces the old.
 *************************************************************/
void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}
/*************************************************************
 * Function: performLoad()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20           
 * Description: The function reads songs from a library file
 *				into program memory.
 * Input parameters: the string for the file name
 * Returns: nothing
 * Pre: The string for the file name had to have been scanned
 *            	in by the user.
 * Post: The information of songs in a file is saved to a Song
 *				object.
 *************************************************************/
// TODO: finish this function
void SongLibrary::performLoad(string filename) {
	ifstream inputFile;
	string line;
	string titleName;
	string artistName;
	string genreType;
	string clipName;
	int ratingValue;
	int numSongs = 0, count = 0;
	Song * inputSong;
	
	Song * currSong = head;
	Song * nextSong = NULL;
	
	while (currSong != NULL) {
		// save the link to the next node
		nextSong = currSong->getNext();
		// can safely delete currNode
		delete currSong;
		currSong = nextSong;
	}
	head = NULL; // for good practice
	
	inputFile.open(filename);
	if (inputFile.is_open()) {
		cout << "Successfully opened file." << endl;
	}
	else {
		cout << "Failed to open file." << endl;
		exit(-1);
	}
	
	// get number of songs in file
	while(!inputFile.eof()){
		if(inputFile.good()){
			getline(inputFile, titleName);
			getline(inputFile, artistName);
			getline(inputFile, genreType);
			getline(inputFile, clipName);
			inputFile >> ratingValue;
			getline(inputFile, line);
			getline(inputFile, line);
			inputFile >> line;
			count++;
		}
	}
	numSongs = count;
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	
	// create new song and insert it library
	head = NULL;
	if (inputFile.good()) {
		for (int i = 0; i < numSongs; i++) {         
			getline(inputFile, titleName);
			getline(inputFile, artistName);
			getline(inputFile, genreType);
			getline(inputFile, clipName);
			inputFile >> ratingValue;
			getline(inputFile, line);
			getline(inputFile, line);
			inputSong = new Song(titleName, artistName, genreType, clipName, ratingValue);
			performInsertSongInOrder(inputSong);
        }    
    }
	
	inputFile.close();
}
/*************************************************************
 * Function: performSave()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20  
 * Description: The function writes songs from a library file
 *				into an output file.
 * Input parameters: the string for the file name
 * Returns: nothing
 * Pre: The string for the file name had to have been scanned
 *            	in by the user.
 * Post: The attributes of songs is written in a file.
 *************************************************************/
// TODO: finish this function
void SongLibrary::performSave(string filename) {
	ofstream outputFile;
	
	outputFile.open(filename);
	
	Song * outputSong = head;
	
	// outputs information to the file
	while (outputSong != NULL) {
		outputFile << outputSong->getTitle();
		outputFile << endl;
		outputFile << outputSong->getArtist();
		outputFile << endl;
		outputFile << outputSong->getGenre();
		outputFile << endl;
		outputFile << outputSong->getClip();
		outputFile << endl;
		outputFile << outputSong->getRating();
		if (outputSong->getNext() != NULL) {
			outputFile << endl;
			outputFile << endl;
		}
		else {
			outputFile << endl;
		}
		outputSong = outputSong->getNext();
	}
	
	outputFile.close();
}
/*************************************************************
 * Function: performSort()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20   
 * Description: The function sorts songs by attribute.
 * Input parameters: none
 * Returns: nothing
 * Pre: The SongLibrary is not sorted.
 * Post: The songs are sorted in order by the attribute.
 *************************************************************/
// TODO: finish this function
void SongLibrary::performSort() {
	Song * newCopy = head;
	Song * temp;
	Song * newHead = NULL;
	Song * insertSong;
	Song * curr;
	Song * prev = NULL;
	
	// sorts library
	while (newCopy != NULL) {
		insertSong = new Song(*newCopy);
		if (!newHead) {
		newHead = insertSong;
		insertSong->setNext(NULL);
		}
		else {
			curr = newHead;
			
			while (curr != NULL && curr->getStringAttributeValue(sortAttribute) < newCopy->getStringAttributeValue(sortAttribute)) {
				prev = curr;
				curr = curr->getNext();
			}
			
			if (prev == NULL) {
				newHead = insertSong;
				insertSong->setNext(curr);
			}
			else {
				prev->setNext(insertSong);
				insertSong->setNext(curr);
			}
		}
		
		// deallocates memory so no leaks
		temp = newCopy;
		newCopy = newCopy->getNext();
		delete temp;
	}
	head = newHead;
}
/*************************************************************
 * Function: performSearch()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20
 * Description: The function searchs for songs by an attribute
 *				and attribute name chosen by the user and the
 *				bool and index is returned by output param.
 * Input parameters: the string for the attribute and value, 
 *				pointer to bool and int.
 * Returns: a pointer to the found song
 * Pre: The string for the attribute and value, pointer to bool
 *				and int had to have been scanned in by the user.
 * Post: The found song is returned.
 *************************************************************/
// TODO: finish this function
Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
	int i = 0;
	Song * curr = head;
	
	// searches for song by attribute and value and if found, it writes info to output parameters
	while (curr != NULL) {
		if (curr->getStringAttributeValue(searchAttribute) == searchAttributeValue) {
			*found = true;
			*index = i;
			return curr;
		}
		else {
			*found = false;
			*index = -1;
		}
		i++;
		curr = curr->getNext();
	}
	return curr;
}
/*************************************************************
 * Function: performInsertSongInOrder()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20
 * Description: The function inserts songs into a library one
 *				by one according to the sort attribute.
 * Input parameters: the pointer to the song to be inserted
 * Returns: nothing
 * Pre: The pointer to the song to be inserted had to have been
 *				scanned in by the user.
 * Post: The song library is in sorted order.
 *************************************************************/
// TODO: finish this function
// inserts the songToInsert in its sorted position based on 
// the SongLibrary sortAttribute value (what the list is
// currently ordered by)
void SongLibrary::performInsertSongInOrder(Song * songToInsert) {
	Song * insertSong;
	Song * curr;
	Song * prev;
	
	insertSong = songToInsert;
	insertSong->setNext(NULL);
	
	// inserts songs into library one by one by attribute order
	if (!head) {
		head = insertSong;
		insertSong->setNext(NULL);
	}
	else {
		curr = head;
		prev = NULL;
		
		while (curr != NULL && curr->getStringAttributeValue(sortAttribute) < songToInsert->getStringAttributeValue(sortAttribute)) {
			prev = curr;
			curr = curr->getNext();
		}
		
		if (prev == NULL) {
			head = insertSong;
			insertSong->setNext(curr);
		}
		else {
			prev->setNext(insertSong);
			insertSong->setNext(curr);
		}
	}
}
/*************************************************************
 * Function: performRemoveSong()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20 
 * Description: The function removes a song from the library.
 * Input parameters: the pointer to the song to be removed
 * Returns: nothing
 * Pre: The pointer to the song to be removed had to have
 *            	been scanned in by the user.
 * Post: A song is removed from the song library.
 *************************************************************/
// TODO: finish this function
// set head to NULL if list becomes empty after remove
void SongLibrary::performRemoveSong(Song * songToRemove) {
	Song * curr;
	Song * prev;
	
	// remove song
	if (!head)
		return;
		
	if (head->getStringAttributeValue(sortAttribute) == songToRemove->getStringAttributeValue(sortAttribute)) {
		curr = head->getNext();
		delete head;
		head = curr;
	}
	else {
		curr = head;
		while (curr != NULL && curr->getStringAttributeValue(sortAttribute) != songToRemove->getStringAttributeValue(sortAttribute)) {
			prev = curr;
			curr = curr->getNext();
		}
		
		if (curr) {
			prev->setNext(curr->getNext());
			delete curr;
		}
	}
}
/*************************************************************
 * Function: performEditSong()
 * Date Created: 03/06/20
 * Date Last Modified: 03/29/20          
 * Description: The function edits an attribute of a song from
 *				the library.
 * Input parameters: the pointer to the song to be edited,
 *				the string for the attribute and new attribute
 * Returns: nothing
 * Pre: The pointer to the song to be edited, the string for
 *				the attribute and new attribute had to have
 *            	been scanned in by the user.
 * Post: A song attribute is edited in the song library.
 *************************************************************/
// TODO: finish this function
void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {
	char c;
	
	attribute = convertToLowercase(attribute);
	c = char(attribute.at(0));
	
	// edits song attribute depending on the user's input
	switch (c) {
		case 't':
			songToEdit->setTitle(newAttributeValue);
			break;
		case 'a':
			songToEdit->setArtist(newAttributeValue);
			break;
		case 'g':
			songToEdit->setGenre(newAttributeValue);
			break;
		case 'c':
			songToEdit->setClip(newAttributeValue);
			break;
		case 'r':
			songToEdit->setRating(stoi(newAttributeValue));
			break;
	} 
}
/*************************************************************
 * Function: displayLibrary()
 * Date Created: 03/28/20
 * Date Last Modified: 03/28/20          
 * Description: The function displays all attributes of all
 *				songs from the library.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: All song attributes in library are displayed.
 *************************************************************/
void SongLibrary::displayLibrary() {
	Song * songToDisplay = head;
	
	// displays all song attributes
	while (songToDisplay != NULL) {
		cout << "Title: " << songToDisplay->getTitle() << endl;
		cout << "Artist: " << songToDisplay->getArtist() << endl;
		cout << "Genre: " << songToDisplay->getGenre() << endl;
		cout << "Clip: " << songToDisplay->getClip() << endl;
		cout << "Rating: " << songToDisplay->getRating() << endl << endl;
		songToDisplay = songToDisplay->getNext();
	}
}
/*************************************************************
 * Function: playSongClipInLibrary()
 * Date Created: 03/29/20
 * Date Last Modified: 03/29/20          
 * Description: The function plays the clip for a song in library.
 * Input parameters: the integer for the index to be played
 * Returns: nothing
 * Pre: The integer for the index of a song to be played had to
 * 				have been scanned in by the user.
 * Post: A song clip is played.
 *************************************************************/
void SongLibrary::playSongClipInLibrary(string attribute, string attributeValue) {
	Song * foundSong;
	bool songFound = false;
	int ind;
	
	// searches for song in library
	foundSong = performSearch(attribute, attributeValue, &songFound, &ind);
	
	// if song is found or not
	if (songFound == false) {
		cout << "Song was not found for playing." << endl;
	}
	else {
		string commandStr1 = "cvlc --play-and-exit ";
		string commandStr2 = " 2> /dev/null &";
		string commandStr = commandStr1 + foundSong->getClip() + commandStr2;
		system(commandStr.c_str());
	}
}
