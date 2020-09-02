#ifndef STRING_H
#define STRING_H

#include <iostream>
#define STRING_H_DEFAULT_SIZE 25

class String
{
public:
	using size_type = unsigned long int;
private:
	// m_start marks the start of the string
	char* m_start{ nullptr };
	// m_end marks the maximum capacity of the string
	char* m_end{ nullptr };
	// m_capacity marks how much of the string is actually used
	char* m_capacity{ nullptr };
public:
	// --Constructor & Destructors
	// Default constructor
	String();

	// Constructor with string literal
	String(char* string);

	// Copy constructor
	String(const String& string);

	// Destructor
	~String();

	// --Member Functions--

	// --Setters--
	// Resizes the string.
	void resize(const size_type size);

	// --Getters--
	// Returns pointer to the beginning of the string
	char* begin();
	const char* begin() const;

	// Return pointer to the end of the string
	char* end();
	const char* end() const;

	// Returns pointer to the last used element of the string
	char* capacity();
	const char* capacity() const;

	// Returns value at specified index
	char at(const size_type index) const;

	// Return the length of the string in size_type
	size_type length() const;
	// Returns the capacity of the string in size_type
	size_type capacity_length() const;

	// --Overloaded operators--
	// Overloaded operator '='. Resizes the string if needed
	String& operator=(const String& string);

	// Returns value at index
	char operator[](const size_type index);

	// Returns pointer to m_start + index
	char* operator+(const size_type index);

	// returns m_start
	operator char*();
};


// --Overloaded operators--
// Outputs the string to the screen.
std::ostream& operator<<(std::ostream& out, String& string);

#endif

// TODO:
// 1. Private member functions - DONE
// 2. 