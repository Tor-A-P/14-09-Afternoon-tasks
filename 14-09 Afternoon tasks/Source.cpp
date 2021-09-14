#include <iostream>
#include <vector>

void clearcin();
void task1();
void task2();
void task3();
void task4();
void task5();
int Square(int Num);
int SumOfVector(std::vector<int> i);
float SumOfVector(std::vector<float> f);
char MyToUpper(char c);
std::vector<char> RestOfAlphabet(char c);


int main() {

	bool Repeat{};
	char Choice{};
	char RepeatChoice{};

	srand(time(nullptr));
	do {
		Repeat = false;
		system("cls");
		std::cout << "What task would you like to do?\n" << "A. Implement a function that returns the square of an input\n"
			<< "B. Create an array where the size is specified by a variable\n"
			<< "C. Use a function that takes in a vector of int or float and returns the sum\n"
			<< "D. Use a function that returns the uppercase letter\n"
			<< "E. Use a function to return a vector of all letters in the alphabet after a character input\n";
		std::cin >> Choice;
		clearcin();
		Choice = toupper(Choice);
		switch (Choice) {
		case 'A': case '1':
			task1();
			break;
		case 'B': case '2':
			task2();
			break;
		case 'C': case '3':
			task3();
			break;
		case 'D': case '4':
			task4();
			break;
		case 'E': case '5':
			task5();
			break;
		default:
			std::cout << "You did not enter a valid input!\n";
			break;
		}
		std::cout << "\nWould you like to try another task? Y/N\n";
		std::cin >> RepeatChoice;
		clearcin();
		RepeatChoice = toupper(RepeatChoice);
		if (RepeatChoice == 'Y') {
			Repeat = true;
		}
		else {
			Repeat = false;
			std::cout << "Thank you for trying my program, goodbye!\n";
			exit(0);
		}
	} while (Repeat == true);

	return 0;
}

void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}

void task1() {
	int Choice{};
	int Ans{};

	std::cout << "Give me a number:\n";
	std::cin >> Choice;
	clearcin();
	Ans = Square(Choice);
	std::cout << "The square of " << Choice << " is " << Ans << "\n";
}

void task2() {
	const int size{ 5 };
	int MyArray[size];

	std::cout << "The size of MyArray is " << sizeof(MyArray) / sizeof(MyArray[0]) << "\n";
}

void task3() {
	std::vector<int> Integer(10, 0);
	std::vector<float> Float(10, 0);

	for (int i{1}; i <= Integer.size(); i++) {
		Integer.at(i-1) = i;
	}
	for (float j{1}; j <= Float.size(); j++) {
		Float.at(j-1) = j / 2;
	}
	std::cout << "The sum of the integers from 1-10 is " << SumOfVector(Integer) << "\n";
	std::cout << "The sum of the numbers from 1-10 but each divided by 2 is " << SumOfVector(Float) << "\n";
}

void task4() {
	char Choice{};

	std::cout << "Please enter a lowercase character:\n";
	std::cin >> Choice;
	clearcin();
	std::cout << "The uppercase of " << Choice << " is ";
	Choice = MyToUpper(Choice);
	std::cout << Choice << "\n";

}

void task5() {
	std::vector<char> Characters(0,0);
	char Choice{};

	std::cout << "Please enter a character: \n";
	std::cin >> Choice;
	clearcin();
	Choice = toupper(Choice);
	Characters = RestOfAlphabet(Choice);
	std::cout << "All the letters following " << Choice << " is:\n";
	for (int i{}; i < Characters.size(); i++) {
		std::cout << Characters.at(i) << " ";
	}
}

int Square(int Num) {
	return Num*Num;
}

int SumOfVector(std::vector<int> i) {
	int sum{};
	for (int j{}; j < i.size(); j++) {
		sum += i[j];
	}
	return sum;
}

float SumOfVector(std::vector<float> f) {
	float sum{};
	for (int j{}; j < f.size(); j++) {
		sum += f[j];
	}
	return sum;
}

char MyToUpper(char c) {
	return c - 32;
}

std::vector<char> RestOfAlphabet(char c) {
	std::vector<char> Alphabet;
	int NumLetters{};

	NumLetters = 'Z' - c;
	for (int i{1}; i <= NumLetters; i++) {
		Alphabet.push_back(c + i);
	}
	return Alphabet;
}