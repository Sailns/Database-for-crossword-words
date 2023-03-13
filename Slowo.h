#pragma once

#include <string>

class Slowo
{
public:
	Slowo(std::string answer) : _answer(answer) {}
	std::string Get() const { return _answer; }
	void Set(std::string answer) { _answer = answer; }

private:
	std::string _answer;
};