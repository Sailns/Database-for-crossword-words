#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Slowo.h"
#include "Question.h"
#include "Indices.h"

//realizacja w innym pliku
extern std::string FindAnswerByQuestion(std::string inQuestion, std::vector<Slowo> answers, std::vector<Question> questions);
extern std::vector<std::string> FindWordsByLength(int length, std::vector<Slowo> answers);
extern std::vector<std::string> FindWordByLetters(std::string symbols, std::vector<Slowo> answers);
extern void WyswietlBD(const std::vector<Indices>& indices,
						const std::vector<Slowo>& answers,
						const std::vector<Question>& questions);

extern void ZapisacDoBD(std::vector<Indices>& indices,
						std::vector<Slowo>& answers,
						std::vector<Question>& questions);

int main()
{
	//zapisana do pamieci BD
	std::vector<Indices> indices = { Indices(1), Indices(2), Indices(3), Indices(4), Indices(5), Indices(6), Indices(7), Indices(8), Indices(9), Indices(10), Indices(11), Indices(12), Indices(13), Indices(14), Indices(15), Indices(16), Indices(17) };
	std::vector<Slowo> answers = { Slowo("sok"), Slowo("sterta"), Slowo("bomba"), Slowo("rozum"), Slowo("grzebien"), Slowo("motocykl"), Slowo("perkusja"), Slowo("fasolka"), Slowo("konferencja"), Slowo("porwanie"), Slowo("welna"), Slowo("kult"), Slowo("ser"), Slowo("dom"), Slowo("samolot"), Slowo("mowa"), Slowo("mewa") };
	std::vector<Question> questions = { Question("chroni wagony"), Question("gora, kopiec"), Question("atomowa lub zegarowa"), Question("chlopski"), Question("co lysemu po nim"), Question("dwukolowy pojazd mechaniczny"), Question("beben i talerze"), Question("magiczna lub po bretonsku"), Question("burza mozgow"), Question("dokonane dla okupu"), Question("prawobrzezny doplyw warty"), Question("spiewa w nim Kazik Staszewski"), Question("Wlochy produkt spozywczy"), Question("z dachem"), Question("statek powietrzny"), Question("wypowiadanie slow"), Question("smieszka z plazy") };

	std::cout <<	"Wyberz operacje:\n"
					"Wyswietlic BD [1]\n"
					"Zapisac do BD [2]\n"
					"Znalezc slowo za ilosca liter [3]\n"
					"Znalezc slowo za opisem [4]\n"
					"Znalezc slowo za litera [5]\n" 
					"Koniec programy [6]\n"	<< std::endl;

	std::vector<std::string> findedWords;
	std::string answer;
	std::string question;
	std::string number;
	std::string symbols;
	std::vector<std::string> findedWordsByLetters;

	bool flag = true;

	while (flag)
	{
		std::cout << "Wpisz: ";
		std::cin >> number;
		switch (number[0]) //bierzemy pierwszu literu 
		{
		case('1'):
			WyswietlBD(indices, answers, questions);
			break;

		case('2'):
			ZapisacDoBD(indices, answers, questions);
			break;

		case('3'):
			std::cout << "Funkcja FindWordsByLength\n";
			int length;
			std::cin >> length;
			findedWords = FindWordsByLength(length, answers);
			std::cout << "FindWordsByLength returned\n";

			if (findedWords.empty())
				std::cout << "Nie znaleziono w BD" << std::endl;
			for (const auto& i : findedWords)
			{
				std::cout << i << std::endl;
			}
			break;

		case('4'):
			std::cout << "\nFunkcja FindAnswerByQuestion\n";
			while (getline(std::cin, question))
			{
				if (question != "") break;
			}
			answer = FindAnswerByQuestion(question, answers, questions);
			std::cout << "FindAnswerByQuestion returned " << answer << std::endl;
			break;

		case('5'):
			std::cout << "Funkcja FindWordByLetters\n";
			std::cin >> symbols;
			findedWordsByLetters = FindWordByLetters(symbols, answers);

			if (findedWordsByLetters.empty())
			{
				std::cout << "Nie znaleziono w BD" << std::endl;
			}

			for (const auto& i : findedWordsByLetters)
			{
				std::cout << i << std::endl;
			}
			break;
		case('6'):
			flag = false;
			break;
		default:
			std::cout << "Wpisz od 1 do 6:" << std::endl;
			break;
		}
	}

	return 0;
}
