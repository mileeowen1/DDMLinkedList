#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H
/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: March 29, 2020
Programming Assignment: PA6
Description: Create a program that would arrange our music library based attributes such as song title, song artist, song genre, and rating. This assignment is a digital music manager (DMM) for managing a music library using linked list.
Notes: Linked list function prototypes and header file
*/
#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

class SongLibrary {
	private:
		Song * head;
		string sortAttribute; // NEW: keep track of what attribute the library is currently ordered by
	public:
		SongLibrary();
		SongLibrary(const SongLibrary&); // NEW: copy constructor
		~SongLibrary();
		
		// getters and setters
		Song * getHead(); // UPDATED: name
		void setHead(Song *); // UPDATED: name
		string getSortAttribute(); // NEW: getter for sortAttribute
		void setSortAttribute(string); // NEW: setter for sortAttribute
		
		void performLoad(string);
		void performSave(string);
		void performSort(); // UPDATED: no parameter for sort attribute, using Song's sortAttribute member variable
		Song * performSearch(string, string, bool *, int *); // UPDATED: parameter list and return type
		void performInsertSongInOrder(Song *); // NEW: replaces addSong()
		void performRemoveSong(Song *); // UPDATED: parameter list
		void performEditSong(Song *, string, string); // UPDATED: parameter list
		
		void displayLibrary();
		void playSongClipInLibrary(string, string);
};

#endif
