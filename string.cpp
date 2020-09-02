#include "string.hpp"
#include <cassert>
#include <iostream>

// --Constructors & Destructors--

// Default constructor
String::String()
	: m_start{ new char[STRING_HPP_DEFAULT_SIZE] },
	  m_end{ m_start + STRING_HPP_DEFAULT_SIZE },
	  m_capacity{ m_start } {}

// Constructor with string literal
String::String(const char* string)
{ 
	int length{};
	for(const char* chr{ string }; *chr != '\0'; ++chr)
	{
		++length;
	}

	m_start = new char[length];
	
	for(int i{}; i != length; ++i)
	{
		m_start[i] = string[i];
	}

	m_end = m_start + length + 1;
	m_capacity = m_end - 1;

}

// Copy constructor
String::String(const String& string)
{
	int length{};
	for(char* chr{ string.m_start }; chr < string.m_end; ++chr)
	{
		++length;
	}

	m_start = new char[length];
	m_end = m_start + length + 1;
	m_capacity = m_end - 1;

	--length;

	for(int i{}; i < length; ++i)
	{
		m_start[i] = string.at(i);
	}
	
}

// Destructor
String::~String()
{
	delete[] m_start;
}


// --Member functions--
// --Setters--
// Resizes the string.
void String::resize(const size_type size)
{
	String temp{ *this };
	delete[] m_start;
	m_start = new char[size];
	m_end = m_start + size + 1;
	m_start[size - 1] = '\0';
	*this = temp;
}

// --Getters--
// Returns pointer to the beginning of the string
char* String::begin()
{
	return m_start;
}

const char* String::begin() const
{
	return static_cast<const char*>(m_start);
}

// Return pointer to the end of the string
char* String::end()
{
	return m_end;
}

const char* String::end() const
{
	return static_cast<const char*>(m_end);
}

// Returns pointer to the last used element of the string
char* String::capacity()
{
	return m_capacity;
}

const char* String::capacity() const
{
	return static_cast<const char*>(m_capacity);
}

// Returns value at specified index
char String::at(const size_type index) const
{
	assert(index < length());
	return m_start[index];
}

// Return the length of the string in size_type
String::size_type String::length() const
{
	return static_cast<size_type>(m_end - m_start) - 1;
}

// Returns the capacity of the string in size_type
String::size_type String::capacity_length() const
{
	return static_cast<size_type>(m_capacity - m_start);
}


// --Overloaded operators--
// Overloaded operator '='. Resizes the string if needed
String& String::operator=(const String& string)
{
	if(length() < string.capacity_length())
	{
		resize(static_cast<size_type>(string.m_capacity - string.m_start));
	}
	size_type capacity{};
	for(size_type& i{capacity}; i < string.capacity_length(); ++i)
	{
		m_start[i] = string.at(i);
	}
	m_capacity = m_start;
	m_capacity += capacity;
	return *this;
}

// Returns value at 'index'
char String::operator[](const size_type index)
{
	return m_start[index];
}

// Returns pointer to value at index
char* String::operator+(const size_type index)
{
	return m_start + index;
}

// Returns pointer to the start of the array
String::operator char*()
{
	return m_start;
}

// Outputs the string to the screen.
std::ostream& operator<<(std::ostream& out, String& string)
{
	for(char* chr{ string.begin() }; chr != string.capacity(); ++chr)
	{
		out << *chr;
	}
	return out;
}