#pragma once
#include <iostream>

class Str
{
private:
	char* str_;
	size_t len_;

	// Helper Functions
	void Copy(const char* source);
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

	char& operator[](size_t index);
	const char& operator[](size_t index) const;
	Str& operator+=(Str& other);
	Str& operator+=(const char* str);
	Str& operator+=(char str);

	friend std::ostream& operator<<(std::ostream& stream, const Str& obj);
	friend std::istream& operator>>(std::istream& stream, const Str& obj);

};
