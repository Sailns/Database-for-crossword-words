#pragma once

#include <string>

class Question
{
public:
	Question(std::string question) : _question(question) {}
	std::string Get() const { return _question; }
	void Set(std::string question) { _question = question; }

private:
	std::string _question;
};