#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

using std::cout;
using std::cin;
using std::string;

//for conio
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESC 27

// for printf
#define ARROW_LEFT 282
#define ARROW_DOWN 281
#define ARROW_UP 280





	/* To display user choice */

int DoChoice(string intro, string s1, string s2);

int DoChoice(string intro, string s1, string s2, string s3);

int DoChoice(int n, string intro, string additional_intro, string s1, string s2, string s3);

int DoChoice(string intro, string s1, string s2, string s3, string s4);

int DoChoice(int n, string intro, string additional_intro, string s1, string s2, string s3, string s4);

int DoChoice(string intro, string s1, string s2, string s3, string s4, string s5);

