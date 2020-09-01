#ifndef STRING_H
#define STRING_H

class String
{
public:
	using size_type = unsigned long int;
private:
	char* m_start{ nullptr };
	char* m_end{ nullptr };
	char* m_capacity{ nullptr };
	size_type size;
public:
	;
};

#endif

// TODO:
// 1. Private member functions - DONE
// 2. 