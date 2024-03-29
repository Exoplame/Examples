﻿#include <Windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// Забыл как называется, но тут оно для того, чтобы НЕ компилировались те строки, которые вызовут исклучение
#define SAVE

// namespace - Отдельное пространство имён недоступное из вне, без обращения к его имени.
// я его тут использую чтобы отделить его от другого кода
namespace Functions 
{
	void foo();	// Прототип функции
	void foo()	// Описание функции
	{
		cout << "bar";
	}

	// 100% копия foo
	void foo2() 
	{
		cout << "bar";
	}


	void func1(int, int);	// Так можно
	void func1(int x, int y) 
	{ }

	void func2(int, int)	// Так тоже, нооо
	{ }


	void F1() 
	{
#ifndef SAVE

		F2();	// F2 объявлен ниже по коду поэтому вызвать её сейчас нельзя

#endif // SAVE
	}

	void F3();

	void F2()
	{
		F1();	// А вот F2 вызвать F1 может, тк он был объявлен выше
		F3();	// В свою очередь F3 вызвать можно, тк выше есть его прототип
	}

	void F3() {};


	int A(int a) 
	{
		return ++a;
	}

	int B(int b) 
	{
		return A(++b);
	}
}

#pragma region Arrays

/// Копирует часть элементов из массива "copy" в массив "paste"
/// copy_count - число элементов (начиная с индекса 0) которые будут скопированны во второй
void copy(int* copy, int* paste, int copy_count);

// Создаёт новый массив, копирует в него данные из старого, записывает в конец массива "number"
void append(int* &mass, int& size, int number);

void Arrays() 
{
// Отвечает за компиляцию первого примера
// Закоментируй или удали строку ниже, и связванный с ней блок кода не скомпилируется, а значит не будет выполнен!
#define PREVIEW_1
#ifdef PREVIEW_1

	int a;				// Вот переменная типа int
	a = 1;				// А вот мы её инициализировали как 1
	cout << a << endl;	// .. и вывели на экран

	int* b;				// Вот указатель на переменную типа int
	b = new int(2);		// Вот мы выделили память из кучи для переменной типа int и записали в неё 1
	cout << *b << endl;	// .. и вывели переменную на которую указывает "b" на экран

	delete b;			// А вот тут освободили ячейку памяти в куче, если так не делать будет утечка памяти

	b = &a;				// А вот тут мы сделали так чтобы "b" указывал на "a"
	a = 3;				// Изменим значение a для наглядности
	cout << *b << endl;	// .. и вывели переменную на которую указывает "b" на экран

#ifndef SAVE
	delete b;			// В этом случае очищать память нельзя! Т.к. "a" в статической памяти программы, а не в куче!
#endif // !SAVE

#endif // PREVIEW_1

// Отвечает за компиляцию второго примера
#define PREVIEW_2
#ifdef PREVIEW_2

	// А теперь когда немного показал правила работы с указателями перейдём к массивам

	int mass[3];	// Вот переменная типа int.. или стоп не совсем, это массив из 3-х переменных типа int

	// Выведим массив в цикле..
	for (int i = 0; i < 3; i++)
		cout << mass[i] << ' ';
	cout << endl;
	// .. упс, забыли проинициализировать, итог: на экране мусор!

	// Исправим это...
	mass[0] = 1;
	mass[1] = 2;
	mass[2] = 3;

	// ... и повторим вывод на экран
	for (int i = 0; i < 3; i++)
		cout << mass[i] << ' ';
	cout << endl;

	/*
	Хорошо, но слишком много строк кода было задействовано...
	Сократим запись
	*/
	// Новый массив...
	int mass1[]{ 3, 2, 1 };

	// Выведим массив в цикле..
	for (int i = 0; i < 3; i++)
		cout << mass1[i] << ' ';
	cout << endl;

#endif // PREVIEW_2

// Отвечает за компиляцию перевой задачи
#define TEST_1 
#ifdef TEST_1	

	/*
	А теперь задача!
	Надо сосчитать сколько денег у пользователя.
	*/
	// Легко!

	// Балланс пользователя
	int money = 0;

	// Число монет
	int n;
	cout << "Couns count: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		// Номинал монеты
		int coin_cost;
		cout << "Coin " << i + 1 << " : ";
		cin >> coin_cost;
		money += coin_cost;
	}
	cout << "You have " << money << " money." << endl;

#endif // !TEST_1

// Отвечает за компиляцию первой версии второй задачи
#define TEST_2_1
#ifdef TEST_2_1

	// Но вот незадача, нужно посчитать количество монет каждого номинала.
	// Да если у нас монеты реальные номиналом 1, 2, 5, 10 то тут нет никаких проблем. А если монеты могут быть от 1 до 1000?
	// Данная задача резко возрасла в сложности, тем что надо соотнести каждую монету её количесвом
	// Вдабавок мы не знаем того сколько монет у пользователя и сколько уникальных манет будет...
	// Чтож попробуем использовать массив из 1000 элементов для подсчёта числа монет каждого номинала

	// Инициализируем массив заполняя его нулями
	int coin_counts[1000] { 0 };	// Число манет каждого номинала

	// Число всех монет
	int n1;
	cout << "Couns count: ";
	cin >> n1;

	for (int i = 0; i < n1; i++)
	{
		// Номинал монеты
		int coin_cost;
		cout << "Coin " << i + 1 << " : ";
		cin >> coin_cost;
		coin_counts[coin_cost]++;
	}
	// Осталось пройтись по массиву и вывести его не нулевые элементы
	for (int i = 0; i < 1000; i++)
	{
		int count = coin_counts[i];
		if (count != 0)
			cout << i << ": x" << count << endl;
	}
#endif // TEST_2_1

// Отвечает за компиляцию второй версии второй задачи
#define TEST_2_2
#ifdef TEST_2_2

	// Правда у нас получается следующая ситуация, пользователь врятли будет использовать все типы монет, а массив наш будет всегда на 1000 элементов.
	// Поэтому давайте используем другой метод...

	// Массив монет
	// coins[i][0] - номинал монеты
	// coins[i][1] - количество монет этого номинала
	int** coins;				

	// Число номиналов текущих монет пользователя
	int coins_type_count = 0;

	// Число монет
	int n2;
	cout << "Coins count: ";
	cin >> n2;

	// Инициализируем массив размером с число монет, тк это максимальное число уникальных монет
	coins = new int* [n2];
	for (int i = 0; i < n2; i++)
	{
		// Номинал монеты
		int coin_cost;
		cout << "Coin " << i + 1 << " : ";
		cin >> coin_cost;

		// Флаг символизирующий наличие номинала монеты в массиве
		bool found = false;
		for (int j = 0; j < coins_type_count; j++)
		{
			if (coins[j][0] == coin_cost)
			{
				coins[j][1]++;
				found = true;
				break;
			}
		}

		if (found == false) 
		{
			coins[coins_type_count++] = new int[2] {coin_cost, 1};
		}
	}

	for (int i = 0; i < coins_type_count; i++)
	{
		cout << coins[i][0] << ": x" << coins[i][1] << endl;
	}

	// Не забываем отчищать память, да С++ сам этого не умеет...
	for (int i = 0; i < coins_type_count; i++)
	{
		delete[] coins[i];
	}
	delete[] coins;

#endif // TEST_2_2

// Отвечает за компиляцию третьего примера
#define PREVIEW_3
#ifdef PREVIEW_3

	// Ну а теперь самая главная беда С++...
	// Статичность всех, абсолютно всех базовых массивов

	/*Вот смотрите есть массив :*/	int* arr = new int[3]{ 1, 2, 3 };	delete[] arr;
	// Массив динамический, но добавить в него 4тый элемент мы просто так не можем
	// для этого надо пересоздать массив уже с размером 4, скопировать в него все элементы из старого и записать в последюю ячейку новый элемент
	// И копирование прийдётся тоже писать самому.
	// Ну давайте напишем это!

	int size = 5;
	int* arr1 = new int[size];
	for (int i = 0; i < size; i++) 
	{
		arr1[i] = i;
	}

	for (int i = 0; i < size; i++) 
	{
		cout << arr1[i] << ' ';
	}
	cout << endl;

	append(arr1, size, size);

	for (int i = 0; i < size; i++)
	{
		cout << arr1[i] << ' ';
	}
	cout << endl;

	delete[] arr1;

#endif // PREVIEW_3
}

void copy(int* copy, int* paste, int copy_count) 
{
	for (int i = 0; i < copy_count; i++) 
	{
		paste[i] = copy[i];
	}
}

void append(int* &mass, int& size, int number) 
{
	int* result = new int[size + 1]{};	// Новый массив на 1 элемент больше зтарого

	copy(mass, result, size);			// Копируем значения из старого в новый

	result[size++] = number;			// Записываем "number" в конец новго массива

	delete[] mass;						// Удаляем старый массив

	mass = result;						// Перепривязываем указатель старого массива на новый
}

#pragma endregion

#pragma region Strings

#include <string>
#include <string.h>

void Strings() 
{
//#define EXAMPLE_1
#ifdef EXAMPLE_2

	// Итак, теперь поговорим о строках...
	// На самом деле тут нет ничего сложного, строка - массив символов.
	// но прежде чем поговорить о строках, поговорим о символах

	char c = 'c'; // Создадим символьную переменную, и передадим в неё символ 'c'
	// А теперь выведем её на экран двумя спосабами, первый как символ, а второй как число
	printf_s("Key - %c, Code - %i\n", c, c);	// Тут стоит впомнить про кодировку ASCII
	// Уяснили, символ = число, только другого типа

	// Зная это сделаем кое что не логичное..
	cout << "ASCII table:" << endl;
	for (int i = 0; i < 256; i++)
		printf_s("Key - %c, Code - %i\n", i, i);

	// Что получилось? Да в консоль вывелась вся таблица ASCII
	// Но запомнить код каждого символа, весьма глупая затея...
	// Но что делать если надо вывести весь алфавит?
	// Нууу, вы же помните что символ = число?
	// Тогда кто мешает сделать так?
	cout << "ABC:" << endl;
	for (int i = 'A'; i <= 'Z'; i++)
		printf_s("Key - %c, Code - %i\n", i, i);

	// Занятно, да?
	// Ну чтож, надеюсь этого хватит для начала...

#endif // EXAMPLE_2

	// Итак строки, начнём с простого:
	char str[] = "Some text\n";
	printf_s(str);

	// Но стоит помнить что строка константна, и её менять в коде нельзя..
#ifndef SAVE
	str = "";
#endif // SAVE

	// Вы же помните динамические массивы?
	// Ну вот, тут тоже можно так сделать!
	char* str1 = new char[] {"Line\n"};
	printf_s(str1);
	delete[] str1;

	// Но и тут есть нюансы...					 
	str1 = new char[] {'L', 'i', 'n', 'e', '\n', '\0'};
	printf_s(str1);								// ^ Вот без этой штуки, вас ждёт исключение!
	delete[] str1;

	// Что такое '\0'? - спросите вы меня..
	// Нуль терминатор - отвечу я
	// Это сивлол конца строки (не путайте с символом переноса строки!)
	// Если инициализировать посимвольно, вы обязаны его добавить!
	// Если через "" то \0 поставят за вас!
	char str2[] = "";	// Обратите внимание! Размер массива 1, хотя между "" ничего нет!

	// Но что будет если его поставить не в конце строки, а гдето посередине?
	// Ну вот что...
	str1 = new char[] {'H', 'e', 'l', 'l', 'o', ' ', '\0', 'W', 'o', 'r', 'l', 'd', '\0'};
	printf_s(str1); cout << endl;	// Тадааам, строку обрезало на середине!
	delete[] str1;

	// Ну и на последок держите цикл for each в C++
	for (char c1 : "Hello world!")
	{
		if (c1 == '\0')
			cout << endl;
		else
			cout << c1;
	}

	// Чтож, теперь нюанс, в С++ по умолчанию со строками работать нельзя, строка - массив символов
	// Иначе говоря, С++ не видит строку как отдельный тип данных, а значит (str + str) незя..
	// Тут на помощь приходит класс string из одноимённой библиотеки

	// И уже это можно считать, полноценной строковой переменной
	string string1 = "Hello";
	string1 += " world!";
	cout << string1 << endl;

	// Тут стоит рассказать для начала что такое классы, методы, операторы и тд...
	// но, это как нибудь потом, пока что просто запомните синтаксис
	// Всю информацию беру с статьи:
	// https://server.179.ru/tasks/cpp/total/161.html
	
	// Начнём с конструкторов - способов инициализации
	// Строки можно создавать с использованием следующих конструкторов:
	// string() - конструктор по умолчанию(без параметров) создает пустую строку.
	// string(string & S) - копия строки S
	// string(size_t n, char c) - повторение символа c заданное число n раз.
	// string(string & S, size_t start, size_t len) - строка, содержащая не более, чем len символов данной строки S, начиная с символа номер start.
	
	// Итак потестируем:
	string string2 = string();
	printf_s("%s\n", string2.c_str());

	string2 = string(string1);
	string2 += " I love C++";
	printf_s("Source string - %s\n", string1.c_str());
	printf_s("Copy string - %s\n", string2.c_str());
	
	string2 = string(10, '%');
	printf_s("%s\n", string2.c_str());

	string2 = string(string1, 6, 5);
	printf_s("%s\n", string2.c_str());

	// Конструктор, можно считать специальной процедурой, а значит, можно делать так:
	string2 = string(5, '@') + ' ' + string1 + ' ' + string(5, '@');
	printf_s("%s\n", string2.c_str());

	// Конечно же вы заметили что я использую операторы сложения и присваивания?
	//	Со строками можно выполнять следующие арифметические операции :
	//	= -присваивание значения.
	//	+= -добавление в конец строки другой строки или символа.
	//	+ -конкатенация двух строк, конкатенация строки и символа.
	//	== , != -посимвольное сравнение.
	//	<, >, <= , >= -лексикографическое сравнение.

	// Первые 3 я использовал, так что тепереь посмотрим на оставшиеся:
	string1 = "Hello";
	string2 = "hello";
	string1 == string2 ? printf("True") : printf("False");	cout << endl;

	string2 = "Hello world";
	cout << string1 << " > " << string2<< " - " << (string1 > string2) << endl;
	cout << string1 << " < " << string2 << " - " << (string1 < string2) << endl;
	cout << string1 << " >= " << string2 << " - " << (string1 >= string2) << endl;
	cout << string1 << " <= " << string2 << " - " << (string1 <= string2) << endl;

	// Ну а теперь самое сладенькое!
	// Методы объектов класса string:
	// Их ооочень много, и их описание (если хотите) прочитайте в статье которую я упоминул выше

	// Но разберём основные из них!

	int size1 = string1.size();
	int size2 = string1.length();
	int size3 = strlen(string1.c_str());

	printf(".size() - %i\n", size1);
	printf(".length() - %i\n", size2);
	printf("strlen() - %i\n", size3);

	string2 = string(string1);
	cout << "Source string: " << string2 << endl;

	string2.append("@");
	cout << ".append('@') - " << string2 << endl;

	string2.append(4, '&');
	cout << ".append(4, '@') - " << string2 << endl;

	string2.append("12345", 1, 3);
	cout << ".append(\"12345\", 1, 3) - " << string2 << endl;

	// Ну и для тех кто любит выпендрёжный синтаксис, держите!
	string2 = string(string1).append("@").append(4, '&').append("12345", 1, 3);
	cout << "string(string1).append(\"@\").append(4, '&').append(\"12345\", 1, 3) - " << string2 << endl;

	string2.insert(0, string(5, '@'));
	cout << ".insert(0, string(5, '@')) - " << string2 << endl;

	// Ну и теперь настоящая магия!
	string2 = "Hello world!";
	string find = "world";
	string replace = "C++";
	int index = string2.find(find);
	string2.erase(index, find.length());
	string2.insert(index, replace);
	cout << string2 << endl;
}

#pragma endregion

#pragma region How to code?
void HowToCode()
{
	// Итак, я рассказал вам о базовых инструментах языка С++, их должно хватить для написания простеньких программ
	// Остался последний вопрос - как запрограмировать алгоритм? иначе говоря как кодить?
	// Тут больше идёт не знание языка а логическое мышление, если его не хватает то тут пригодятся базовые алгоритмы 
	// (загуглите эту тему если интересно: Алгоритмы С++)
	// Лично я придумываю все алгоритмы находу, и получалось неплохо...
	
	// Задача, найти максимальное число в массиве:

	int max = 0;					// Максимальное число инициализируем как минимально возможное
									// чтобы не было так что это число больше чем любой элемент массива
	// количество элементов в массиве
	const int mass_size = 6;
	// Массив чисел, в котором осуществляется поиск
	int mass[mass_size]{4, 5, 6, 1, 7, 0};
	// Цикл поиска максимального числа
	for (int i = 0; i < mass_size; i++)
	{
		if (mass[i] > max)
			max = mass[i];
	}
	cout << max << endl;
	// Алгоритм крайне прост! но его можно написать поразному...

	max = 0; // Сбросим значение вновь до 0

	// Аналогичный цикл поиска
	for (int num : mass) max = num > max ? num : max;
	cout << max << endl;

	// Ещё вариант
	max = 0;
	int* num = begin(mass);
	while (num < end(mass))
	{
		*num > max ? max = *(num++) : *num++;
	}
	cout << max << endl;

	// Все они работают абсолютно одинаково, только использются разные инструменты языка
	// И вполне обоснованна тогда проблема трудности проектирования программы
	// она может быть реализованна всевозможными способами!
	// поэтому уместно высказываение: 
	// "Чтобы научится программировать - начни программировать!"
	// а алгоритм работы программиста-специалиста от новичка почти не отличается
	// 
	// while (code.working == false)
	// {
	//		programerr.write(code);
	// }
	// 
	// отличие только в опыте:
	//  = у вас только десяток лабораторок
	//  = у меня свыше сотни лабораторок, почти десяток курсовых и несколько дипломов (мои + моих однокурсников из колледжа)
	// 
	// и вы так же как и я после прочтения задания понятия не имеете как писать код
	// 
	// И вот потом начинаются различия:
	//  = Я могу начать сразу писать код, пробывать разные идеи, исходя из своего опыта
	//  = Вам же будет проще начать с сёрфинга в гугле, найти там подходящее решение, или хотябы идею для реализации
	//    ВАЖНО! не тупо скопировать, вставить и сдать, а обязательно понять как оно работает например: 
	//	-	изменить условие на противоположное
	//	-	изметнить количество и значение вводных данных
	//	-	попробывать сломать код, чтобы он перестал работать правлино, или вызвал исключение
	// 
	// всё это, возможно, пригадится вам в будующем, и вам не прийдётся снова обращатся в гугл, чтобы понять как выполнить аналогичную задачу
	// И вновь повторюсь, пишите код! то что вы возмёте готовый не даст вам опыт, а значит ползы вы не получили и потратили время зря
	// 
	// Так, а вы поните что я писал:
	//	Хм, я тут подумал... И решил, напишу КА я для вас свой универсальный метод проектирования любого кода😇
	//	Итак первый шаг :
	//	"Постановка задачи" для начала надо определиться что надо, и представить как этого можно достич
	//	Шаг второй :
	//	"Гуглинг аналогов" с некотором шансом найдёте пару тройку проектов похожих на ваш
	//	Шаг третий :
	//	"Гуглинг модулей", да возможно вы найдёте модули из которые ускорят разработку
	//	Шаг четвёртый :
	//	"Программирование" Собираем всю собранную информацию в кучу и пробуем закодировать так чтобы оно работало
	//	P.S.Если вдруг возникают трудности и / или что - то не работает, опрашиваем гугл, если не находим решение проблемы(что тоже возможно) обращаемся к более опытному в этой сфере(только если гугл вам не помог!)
	// 
	// Так вот, давайте разберём одну задачку по этим шагам:
	// Задача: Написать программу, которая отчистит строку от символов препинания, лишних пробелов и все буквы будут строчными
	// 
	// Первый шаг - "Постановка задачи":
	// здесь надо определить как должна работать ваша программа, для её тестирования
	// нам нужна программа которой на вход подают предложение (массив смволов который можно разбить на слова, разделённый знаками препинания)
	// результатом работы программы должна быть такая строка, в которой нет знаков препинания, и все слова разделены только одним пробелом
	// 
	// Пример 1: 
	// Ввод: Привет мир!
	// Вывод: привет мир
	// 
	// Пример 2:
	// Ввод: Привет, мир С++!
	// Вывод: привет мир с
	// 
	// Пример 3:
	// Ввод: П,П,,Р - Р
	// Вывод: п п р р
	// 
	// Готово!
	// 
	// Шаг второй - Гуглим аналоги:
	// Оставлю на вас =)
	// 
	// Шаг третий - Гуглинг модулей:
	// Применю библиотеку string, для упрошения работы со строками
	// 
	// Шаг четвёртый - Кодим! 
	
	// Начнём с ввода:

	string line;			// Исходная строка
	cout << "Enter the string: ";
	getline(cin, line);

	// Далее надо разбить строку на слова

	string clear_words;		// Строка отчищенных слов
	char last_c = line[0];
	for (char c : line)		// Найдём их в цикле
	{
		// Копирует пробел если предыдущий символ был буквой/цифрой
		if (c == ' ' && isalnum(last_c))
		{
			clear_words += c;
			last_c = c;
			continue;
		}

		// Копирует букву в нижнем регистре
		if (isalnum(c))
		{
			if (isalnum(last_c) == false && last_c != ' ')
				clear_words.append(" ");
			clear_words += tolower(c);
		}
		last_c = c;
	}

	cout << clear_words << endl;

	// Ну как то так...
	// Последнее что хотелось сказать, не стесьняйтесь смотреть примеры коды, смотреть чужёй код, это полезно, узнать как другие программируют!

}
#pragma endregion


int main() 
{
	//Arrays();
	//Strings();
	HowToCode();

	system("pause");

	return 0;
}