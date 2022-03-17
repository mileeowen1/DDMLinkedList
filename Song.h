#ifndef SONG_H
#define SONG_H
/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: March 29, 2020
Programming Assignment: PA6
Description: Create a program that would arrange our music library based attributes such as song title, song artist, song genre, and rating. This assignment is a digital music manager (DMM) for managing a music library using linked list.
Notes: Linked list function prototypes and header file
*/
#include <iostream>
#include <cctype>

using namespace std;

// constant variables
const int MIN_RATING = 1;
const int MAX_RATING = 5;

string convertToLowercase(string);

class Song {
	private:
		string title;
		string artist;
		string genre;
		string clip;
		int rating;
		Song * next; // NEW: link for linking Songs together in a linked list
	public:
		Song();
		Song(string, string, string, string, int);
		Song(const Song&); // NEW: copy constructor
		
		// getters and setters
		string getTitle();
		void setTitle(string);
		
		string getArtist();
		void setArtist(string);
		
		string getGenre();
		void setGenre(string);
		
		string getClip();
		void setClip(string);
		
		int getRating();
		void setRating(int);
		
		Song * getNext(); // NEW: getter for next
		void setNext(Song *); // NEW: setter for next
		
		void displaySong();
		
		string getStringAttributeValue(string);
};

#endif
