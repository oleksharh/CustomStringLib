#include "Str.h"

void Str::Copy(const char* source)
{
	if (source)
	{
		len_ = 0;
		while (source[len_] != '\0')
		{
			len_++;
		}

		str_ = new char[len_ + 1];

		for (size_t i = 0; i < len_; i++)
		{
			str_[i] = source[i];
		}

		str_[len_] = '\0';
	}
	else
	{
		str_ = nullptr;
		size_t len_ = 0;
	}
}

void Str::FreeMem()
{
	delete[] str_;
	str_ = nullptr;
	len_ = 0;
}

Str::Str() 
	: str_(nullptr), len_(0) {};

Str::Str(const char* str)
{
	Copy(str);
}

Str::Str(char& str)
{
	static char str_arr[2] = { str, '\0' };
	Copy(str_arr);
}

Str::Str(const Str& other)
{
	Copy(other.str_);
}

Str::~Str()	
{
	FreeMem();
}

const size_t Str::len() const
{
	return len_;
}

const char* Str::c_str() const
{
	return str_;
}

Str Str::substr(size_t start, size_t end) const
{
	if (start >= len_ || end >= len_)
	{
		throw std::out_of_range("Index out of range");
	}

	char* buffer = new char[end - start + 1];

	for (size_t i = start; i < end; i++)
	{
		if (str_[i] == '\0')
		{
			throw std::out_of_range("Index out of range");
		}

		buffer[i - start] = str_[i];
	}

	buffer[end - start] = '\0';

	Str new_str(buffer);

	delete[] buffer;

	return new_str;
}



char& Str::operator[](size_t index)
{
	if (index >= len_)
	{
		throw std::out_of_range("Index out of range");
	}
	return str_[index];  // Accessing the str_ member directly
}

const char& Str::operator[](size_t index) const
{
	if (index >= len_)
	{
		throw std::out_of_range("Index out of range");
	}
	return str_[index];  // Accessing the str_ member directly
}

Str& Str::operator+=(Str& other)
{
	size_t new_len = len_ + other.len_;

	char* new_str = new char[new_len + 1];

	for (size_t i = 0; i < len_; i++)
	{
		new_str[i] = str_[i];
	}

	for (size_t i = 0; i < other.len_; i++)
	{
		new_str[len_ + i] = other.str_[i]; // Buffer overrun idk why (enough length is initialized)
	}

	new_str[new_len] = '\0';

	FreeMem();
	str_ = new_str;
	len_ = new_len;

	return *this;
}

Str& Str::operator+=(const char* str)
{
	Str str_add(str);
	*this += str_add;
	return *this;
}

Str& Str::operator+=(char str)
{
	static char str_arr[2] = { str, '\0' };
	*this += str_arr;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Str& str)
{
	stream << str.str_;
	return stream;
}

std::istream& operator>>(std::istream& stream, const Str& str)
{
	// TODO: >> reccursive, so this needs better implementation
	stream >> str.str_;
	return stream;
}