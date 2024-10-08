#pragma once
#include <iostream>

class Str
{
private:
	char* str_;
	size_t len_;

	// Helper Functions
	void Init(const char* source);
	void FreeMem();

public:
	Str();
	Str(const char* str);
	Str(char str);
	Str(const Str& other);
	~Str();

	// Note to self: Str& is refernece to existing object,
	// const Str& is reference to existing object that
	// cannot be modified. Meanwhile Str is a new object

	const size_t len() const;
	const char* c_str() const;
	Str substr(size_t start, size_t end) const;

	// TODO: YET TO BE IMPLEMENTED ------------------------------

	std::tuple<size_t, size_t> find(const Str& substr) const;
	std::tuple<size_t, size_t> find(const char* substr) const;
	std::tuple<size_t, size_t> find(char substr) const;
	Str& append(const Str& str); // Appends another Str to this one
	Str& insert(size_t position, const Str& str); // Inserts another Str at a specified position
	Str& erase(size_t position, size_t length); // Erases part of the string
	Str format(const char* format, ...) const; // Formats the string (similar to Python's formatting)

	Str operator+(const Str& other) const; // Concatenates two Str objects
	bool operator==(const Str& other) const; // Compares for equality
	bool operator!=(const Str& other) const; // Compares for inequalit

	//------------------------------------------------------

	char& operator[](size_t index);
	const char& operator[](size_t index) const;
	Str& operator+=(Str& other);
	Str& operator+=(const char* str);
	Str& operator+=(char str);

	friend std::ostream& operator<<(std::ostream& stream, const Str& obj);
	friend std::istream& operator>>(std::istream& stream, const Str& obj);

};
