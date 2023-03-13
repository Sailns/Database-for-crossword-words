/***********************
******** DB.cpp ********
************************/

#include <iostream>
#include <fstream>

#include "DB.h"

std::string DB::FindAnswerByQuestion(std::string inQuestion) const // funkcja dla poszuku z opisu według pirwszego słowa
{
	std::string answer;
	for (auto iterator = _db.begin(); iterator != _db.end(); iterator++) //przechodzimy przez wszystkie elementy. begin zwraca wskaźnik do pierwszego elementu end wkzuje do następnego elementu z ostatniego elementu.
	{
		std::string question = iterator->second.second; // otrzymujemy opis
		if (question.find(inQuestion) != std::string::npos) // wyszukajemy po  pierwszemu słowu w opisie i w odpowiedzi otrzymamy słowo
		{
			answer = iterator->second.first; //odpowiedż
			break;
		}
	}
	return answer;
}

void DB::PrintDb() // funkcja wyświetlania bazy danych
{
	for (auto iterator = _db.begin(); iterator != _db.end(); iterator++) // iterujemy po wszystkich elementach
	{
		std::cout << iterator->first << "\t" << iterator->second.first << "\t" << iterator->second.second << std::endl; // wyświetlamy numer, słowo i opis
	}
}

void DB::Add(int rowNumber, std::pair<std::string, std::string> ansAndQuest)
{
	_db.emplace(rowNumber, ansAndQuest); // wstawiamy w pojemnik liczbę i perę z slowo i opis.
}

std::vector<std::string> DB::FindWords(int length) const
{
	std::vector<std::string> res;
	for (auto iterator = _db.begin(); iterator != _db.end(); iterator++) //przechodzimy przez wszystkie elementy. begin zwraca wskaźnik do pierwszego elementu end wkzuje do następnego elementu z ostatniego elementu.
	{
		std::string answer = iterator->second.first; // otrzymujemy odpowiedz
		if (answer.length() == length) // wyszukajemy po  pierwszemu słowu w opisie i w odpowiedzi otrzymamy słowo
		{
			res.push_back(answer);
		}
	}
	return res;
}

void DB::WriteAnswerToDB(std::string dbName) const
{
	std::ifstream fileBucket_read(dbName); // otwarcie plika do czytania
	std::string question;

	fileBucket_read >> question;
	std::string  answer = FindAnswerByQuestion(question);
	fileBucket_read.close();

	std::ofstream fileBucket_write(dbName); // otwarcie plika do czytania

	if (!answer.empty())
	{
		fileBucket_write << answer;
	}
	else
	{
		fileBucket_write << "None";
	}

	fileBucket_write.close();
	std::cout << "WriteAnswerToDB successful" << std::endl;
}