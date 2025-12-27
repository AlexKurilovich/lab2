#include "task4.h"

void remove_extra_spaces(char* text) {
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == ' ' && text[i + 1] == ' ') {
			for (int j = i; j < strlen(text); j++)
			{
				text[j] = text[j + 1];
			}
			i--;
		}
	}
}

bool is_punctuation_or_space(char c) {
	return ispunct(c) || isspace(c);
}

void remove_extra_punct(char* text) {
	while (is_punctuation_or_space(text[0]))
	{
		for (int i = 0; i < strlen(text); i++) {
			text[i] = text[i + 1];
		}
	}

	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == '.' && !is_punctuation_or_space(text[i - 1])) {
			int tochka = 1;
			int j = i + 1;
			while (text[j] == '.') {
				tochka++;
				j++;
			}

			if (tochka == 3) {
				i += 2;
				continue;
			}
			else if (tochka >= 4) {
				for (int b = i + 1; b < strlen(text); b++) {
					text[b] = text[b + tochka - 1];
				}
				i--;
				continue;
			}
		}
		if (is_punctuation_or_space(text[i]) && is_punctuation_or_space(text[i + 1])) {
			for (int j = i + 1; j < strlen(text); j++)
			{
				text[j] = text[j + 1];
			}
			i--;
		}
	}

	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == '.' && text[i + 1] == '.') {
			i += 2;
			continue;
		}
		if (ispunct(text[i])) {
			for (int j = strlen(text) + 1; j > i; j--)
			{
				text[j] = text[j - 1];
			}
			text[i + 1] = ' ';
		}
	}
}

void text_to_lower(char* text) {
	for (int i = 0; i < strlen(text); i++)
	{
		text[i] = tolower(text[i]);
	}
}


void sort_words(char words[50][11], int count_word) {
	for (int i = 0; i < count_word; i++)
	{
		for (int j = 0; j < count_word - 1; j++)
		{
			if (strcmp(words[j], words[j + 1]) > 0) {
				char temp[11];
				strcpy_s(temp, words[j]);
				strcpy_s(words[j], words[j + 1]);
				strcpy_s(words[j + 1], temp);
			}
		}
	}
}

void additional_task(char* text) {
	char words[50][11];
	int count_word = 0;
	char word[11];
	int index = 0;

	for (int i = 0; i <= strlen(text); i++)
	{
		if (ispunct(text[i]) || text[i] == ' ' || text[i] == '\0') {
			if (index > 0) {
				word[index] = '\0';
				strcpy_s(words[count_word], word);
				index = 0;
				count_word++;
			}
		}
		else {
			word[index] = text[i];
			index++;
		}
	}

	sort_words(words, count_word);

	cout << "Слова  в алфавитном порядке" << endl;

	for (int i = 0; i < count_word; i++)
	{
		cout << words[i] << " ";
	}
	cout << endl;


	for (int i = 0; i < count_word; i++)
	{
		for (int j = 0; j < strlen(words[i]); j++)
		{
			if (isdigit(words[i][j])) {
				int digit = words[i][j] - '0';
				words[i][j] = 'a' + digit;
			}
		}
	}
	cout << "После замены цифр на буквы" << endl;

	for (int i = 0; i < count_word; i++)
	{
		cout << words[i] << " ";
	}
	cout << endl;
}

int est(char pattern[], int M, char c) {
	for (int i = 0; i < M; i++) {
		if (pattern[i] == c) return 1;
	}
	return 0;
}



int boyer_moore(char arr[], char pattern[], int& N, int& M) {
	int ALPH = 256;
	int* shift = new int[ALPH];
	int count_letters = 1;


	for (int c = 0; c < ALPH; ++c)
		shift[c] = M;


	for (int i = 0; i < M; ++i) {
		unsigned char c = static_cast<unsigned char>(pattern[i]);
		shift[c] = max(1, M - i - 1);
	}


	for (int i = M - 1; i < N;) {
		char current_chr = arr[i];


		if (current_chr == pattern[M - count_letters]) {
			int j = M - count_letters;
			int k = i;


			while (j >= 0 && pattern[j] == arr[k] && k >= 0) {
				k--;
				count_letters++;
				j = M - count_letters;
			}


			k = k + (count_letters - 1);


			if ((count_letters - 1) == M) {
				delete[] shift;
				return true;
			}
			else {
				if (est(pattern, M, arr[k])) {
					i += shift[static_cast<unsigned char>(arr[k])];
				}
				else {
					i += M;
				}
			}
			count_letters = 1;
		}
		else {
			bool found = false;


			for (int j = 0; j < M; j++) {
				if (pattern[j] == current_chr) {
					i += shift[static_cast<unsigned char>(current_chr)];
					found = true;
					break;
				}
			}


			if (!found) {
				i += M;
			}
		}
	}

	delete[] shift;
	return false;
}

void task4()
{

	char text[1000];

	cout << "Выберите откуда считывать текст 1.Из файла 2.С клавиатуры\n";
	int choice;
	cin >> choice;
	cin.ignore();


	if (choice == 1) {
		char filename[100];
		cout << "Введите название файла: ";
		cin.getline(filename, 100);

		ifstream file(filename);
		if (!file.is_open()) {
			cout << "Нет такого файла";
			return;
		}
		file.getline(text, 502);
		file.close();

		cout << "Исходный текст:\n" << text << endl;
	}
	else {
		cout << "Введите текст: ";
		cin.getline(text, 502);
	}

	remove_extra_spaces(text);
	remove_extra_punct(text);

	text_to_lower(text);

	cout << text << endl;

	additional_task(text);
	char pattern[100];
	cout << "Введите подстроку для поиска: ";
	int M = 0;
	int N = strlen(text);

	char symbol;
	char* ptr = pattern;
	while (cin.get(symbol)) {
		if (symbol == '\n') break;
		*ptr++ = symbol;
		M++;
	}

	*ptr = '\0';

	if (boyer_moore(text, pattern, N, M)) {
		cout << "Подстрока НАЙДЕНА в тексте." << endl;
	}
	else {
		cout << "Подстрока НЕ НАЙДЕНА в тексте." << endl;
	}
	system("pause");
}