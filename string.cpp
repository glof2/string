#include "string.h"
#include <cassert>

// --Constructors & Destructors--
String::String()
	: m_start{ new char[STRING_H_DEFAULT_SIZE] },
	  m_end{ m_start + STRING_H_DEFAULT_SIZE },
	  m_capacity{ m_start } {}


String::String(char* string)
{ 
	int length{};
	for(char* chr{ string }; *chr != '\0'; ++chr)
	{
		++length;
	}

	m_start = new char[length];
	m_end = m_start + length + 1;
	m_capacity = m_end - 1;

}


String::String(const String& string)
{
	int length{};
	for(char* chr{ string.m_start }; *chr != '\0'; ++chr)
	{
		m_start[length] = *chr;
		++length;
	} 
	m_end = m_start + length;
	m_capacity = m_end;
}


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
	m_end = m_start + temp.length() + size + 2;
	m_capacity = m_start;
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
String& String::operator=(String& string)
{
	if(length() < string.capacity_length())
	{
		resize(static_cast<size_type>(string.m_capacity - string.m_start));
	}
	
	for(size_type i{}; i < string.capacity_length(); ++i)
	{
		++m_capacity;
		m_start[i] = string.at(i);
	}
	return *this;
}

// Outputs the string to the screen.
std::ostream& operator<<(std::ostream& out, String& string)
{
	for(char* chr_ptr{string.begin()}; chr_ptr <= string.capacity(); ++chr_ptr)
	{
		std::cout << *chr_ptr;
	}
	std::cout.flush();
	return out;
}
