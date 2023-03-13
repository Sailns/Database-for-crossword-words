/***********************
********* DB.h *********
************************/

#pragma once

#include <string>
#include <map>
#include <utility>
#include <vector>

class DB
{
public:
	DB() {} // konstruktor
	~DB() {} // destruktor 

	std::vector<std::string> FindWords(int length) const; // poszuk za dlugosciu slowa
	void WriteAnswerToDB(std::string dbName) const; // dla komukikacji czytujemy z opisu i zapisujemy odpowidz

	void PrintDb(); // funkcja wyświetlania bazy danych
	void Add(int rowNumber, std::pair<std::string, std::string> ansAndQuest); // wpisywanie w bd

	//std::string FindWordByIndex(int index);
	//std::string FindQuestionByIndex(int index);

	// Getters
	std::map<int, std::pair<std::string, std::string>> GetDb() { return _db; } // otrzymanie bd
	std::vector<std::string> GetQuestion() { return _questions; }
	std::vector<std::string> GetAnswer() { return _answers; }
	std::vector<int> GetIndices() { return _indices; }

	// Setters
	void SetQuestion(std::string question) { _questions.push_back(question); }
	void SetAnswers(std::string answer) { _answers.push_back(answer); }
	void SetIndices(int index) { _indices.push_back(index); }

private:
	std::string FindAnswerByQuestion(std::string inQuestion) const; // funkcja dla poszuku z opisu według pirwszego słowa.

	std::map<int, std::pair<std::string, std::string>> _db; //kontejnier liczby, odpowiedz i opis  
	std::vector<std::string> _questions;
	std::vector<std::string> _answers;
	std::vector<int> _indices;
};
