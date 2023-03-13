#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Slowo.h"
#include "Question.h"
#include "Indices.h"

//funkcja FindAnswerByQuestion
//szukamy slowo za slowami z opisu
std::string FindAnswerByQuestion(std::string inQuestion, std::vector<Slowo> answers, std::vector<Question> questions)
{
	std::string answer = "Nie znaleziono w BD";
	for (int i = 0; i < answers.size(); i++) //przechodzimy przez wszystkie elementy. begin zwraca wskaźnik do pierwszego elementu end wkzuje do następnego elementu z ostatniego elementu.
	{
		if (questions[i].Get().find(inQuestion) != std::string::npos) // wyszukajemy po  pierwszemu słowu w opisie i w odpowiedzi otrzymamy słowo
		{
			answer = answers[i].Get(); //odpowiedż
			break;
		}
	}
	return answer;
}
//funkcja FindWordsByLength
//szukamy slowo za dlugoscia
std::vector<std::string> FindWordsByLength(int length, std::vector<Slowo> answers)
{
	std::vector<std::string> res;
	for (int i = 0; i < answers.size(); i++) //przechodzimy przez wszystkie elementy. begin zwraca wskaźnik do pierwszego elementu end wkzuje do następnego elementu z ostatniego elementu.
	{
		std::string answer = answers[i].Get(); // otrzymujemy odpowiedz
		if (answer.length() == length) // wyszukajemy po  pierwszemu słowu w opisie i w odpowiedzi otrzymamy słowo
		{
			res.push_back(answer);
		}
	}
	return res;
}
//funkcja FindWordByLetters
//szukamy slowo za literami (jesli 1 litera to po pirwszej szukamy)
std::vector<std::string> FindWordByLetters(std::string symbols, std::vector<Slowo> answers)
{
	std::vector<std::string> res;
	std::transform(symbols.begin(), symbols.end(), symbols.begin(), ::tolower); // zamieniemy odpowiedź na wielkie litery

	for (int i = 0; i < answers.size(); i++) //przechodzimy przez wszystkie elementy. begin zwraca wskaźnik do pierwszego elementu end wkzuje do następnego elementu z ostatniego elementu.
	{
		std::string answer = answers[i].Get(); // otrzymujemy odpowiedz
		if (symbols.length() < 2) // wyszukajemy po  pierwszemu słowu w opisie i w odpowiedzi otrzymamy słowo
		{
			if (answer[0] == symbols[0])
				res.push_back(answer);
		}
		else
		{
			if (answers[i].Get().find(symbols) != std::string::npos)
			{
				res.push_back(answer);
			}
		}
	}
	return res;
}

void WyswietlBD(const std::vector<Indices>& indices,
	const std::vector<Slowo>& answers,
	const std::vector<Question>& questions)
{
	std::cout << "#####BAZA DANYCH######" << std::endl;
	for (int i = 0; i < indices.size(); i++)
	{
		std::cout << indices[i].Get() << "\t" << answers[i].Get() << "\t" << questions[i].Get() << std::endl;
	}
}

void ZapisacDoBD(std::vector<Indices>& indices,
	std::vector<Slowo>& answers,
	std::vector<Question>& questions)
{
	std::string number; // zmienna do przechowywania liczby
	std::string answer; // zmienna do przechowywania słowa
	std::string question; // zmienna do przechowywania opisania

	while (true)
	{
		std::cout << "Podaj numer, slowo i opis: 1 sok chroni wagony" << std::endl;
		std::cin >> number; // odczytujemy numer
		std::cin >> answer; // odczytujemy odpowiedź
		std::getline(std::cin, question); //odczytujemy odpowiedź. Używamy getline, to znaczy ze opisanie może zawierać więcej niż jedno słowo

		indices.push_back(Indices(atoi(number.c_str())));
		answers.push_back(Slowo(answer));
		questions.push_back(Question(question));

		std::cout << "Chcesz jeszcze dopisac BD? [t]/[n]" << std::endl;
		std::cin >> answer;

		std::transform(answer.begin(), answer.end(), answer.begin(), ::toupper); // zamieniemy odpowiedź na wielkie litery
		if (answer == "N") // jeśli odpowiedź brzmi NIE to wychodzimy z cykla
		{
			break; // wyjście z cykla
		}
	}
}