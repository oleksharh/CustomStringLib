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
	Str(const Str& other);
	~Str();

	char& operator[](size_t index);
	const char& operator[](size_t index) const;
	Str& operator+=(Str& other);
	Str& operator+=(const char* str);

	const size_t len();

	friend std::ostream& operator<<(std::ostream& stream, const Str& obj);
	friend std::istream& operator>>(std::istream& stream, const Str& obj);

};
