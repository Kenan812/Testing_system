#include "MakeChoice.h"

int DoChoice(string intro, string s1, string s2)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int key;

	bool is_first = true;
	bool is_second = false;

	while (true)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "\n\t\t" << intro << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);

		printf("\tUse\n'%c' to move up\n'%c' to move down\n", ARROW_UP, ARROW_DOWN);
		printf("Press 'ENTER' to chose an option\n\n");


		if (is_first)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s1 << "\n";
		}
		else if (!is_first)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s1 << "\n";
		}


		if (is_second)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s2 << "\n";
		}
		else if (!is_second)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s2 << "\n";
		}

		SetConsoleTextAttribute(hConsole, 15);



		key = _getch();

		if (key == KEY_DOWN && is_first)
		{
			is_first = false;
			is_second = true;
		}
		else if (key == KEY_UP && is_second)
		{
			is_first = true;
			is_second = false;
		}
		else if (key == ENTER && is_first)
		{
			system("cls");
			return 1;
		}
		else if (key == ENTER && is_second)
		{
			system("cls");
			return 2;
		}
		system("cls");
	}


	return 0;
}



int DoChoice(string intro, string s1, string s2, string s3)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int key;

	bool is_first = true;
	bool is_second = false;
	bool is_third = false;

	while (true)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "\n\t\t" << intro << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);

		printf("\tUse\n'%c' to move up\n'%c' to move down\n", ARROW_UP, ARROW_DOWN);
		printf("Press 'ENTER' to chose an option\n\n");


			/* Dislay choices */

		if (is_first)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s1 << "\n";
		}
		else if (!is_first)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s1 << "\n";
		}


		if (is_second)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s2 << "\n";
		}
		else if (!is_second)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s2 << "\n";
		}


		if (is_third)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s3 << "\n";
		}
		else if (!is_third)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s3 << "\n";
		}


		SetConsoleTextAttribute(hConsole, 15);


			/* Get choice */

		key = _getch();

		if (key == KEY_DOWN && is_first)
		{
			is_first = false;
			is_second = true;
		}
		else if (key == KEY_DOWN && is_second)
		{
			is_second = false;
			is_third = true;
		}


		else if (key == KEY_UP && is_second)
		{
			is_first = true;
			is_second = false;
		}
		else if (key == KEY_UP && is_third)
		{
			is_second = true;
			is_third = false;
		}


		else if (key == ENTER && is_first)
		{
			system("cls");
			return 1;
		}
		else if (key == ENTER && is_second)
		{
			system("cls");
			return 2;
		}
		else if (key == ENTER && is_third)
		{
			system("cls");
			return 3;
		}

		system("cls");
	}


	return 0;
}



int DoChoice(int n, string intro, string additional_intro, string s1, string s2, string s3)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int key;

	bool is_first = true;
	bool is_second = false;
	bool is_third = false;

	while (true)
	{
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\t\t" << intro;
		SetConsoleTextAttribute(hConsole, 12);
		cout << additional_intro << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);

		printf("\tUse\n'%c' to move up\n'%c' to move down\n", ARROW_UP, ARROW_DOWN);
		printf("Press 'ENTER' to chose an option\n\n");


		/* Dislay choices */

		if (is_first)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s1 << "\n";
		}
		else if (!is_first)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s1 << "\n";
		}


		if (is_second)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s2 << "\n";
		}
		else if (!is_second)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s2 << "\n";
		}


		if (is_third)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s3 << "\n";
		}
		else if (!is_third)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s3 << "\n";
		}


		SetConsoleTextAttribute(hConsole, 15);


		/* Get choice */

		key = _getch();

		if (key == KEY_DOWN && is_first)
		{
			is_first = false;
			is_second = true;
		}
		else if (key == KEY_DOWN && is_second)
		{
			is_second = false;
			is_third = true;
		}


		else if (key == KEY_UP && is_second)
		{
			is_first = true;
			is_second = false;
		}
		else if (key == KEY_UP && is_third)
		{
			is_second = true;
			is_third = false;
		}


		else if (key == ENTER && is_first)
		{
			system("cls");
			return 1;
		}
		else if (key == ENTER && is_second)
		{
			system("cls");
			return 2;
		}
		else if (key == ENTER && is_third)
		{
			system("cls");
			return 3;
		}

		system("cls");
	}


	return 0;
}



int DoChoice(string intro, string s1, string s2, string s3, string s4)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int key;

	bool is_first = true;
	bool is_second = false;
	bool is_third = false;
	bool is_forth = false;

	while (true)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "\n\t\t" << intro << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);

		printf("\tUse\n'%c' to move up\n'%c' to move down\n", ARROW_UP, ARROW_DOWN);
		printf("Press 'ENTER' to chose an option\n\n");


		/* Dislay choices */

		if (is_first)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s1 << "\n";
		}
		else if (!is_first)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s1 << "\n";
		}


		if (is_second)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s2 << "\n";
		}
		else if (!is_second)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s2 << "\n";
		}


		if (is_third)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s3 << "\n";
		}
		else if (!is_third)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s3 << "\n";
		}

		if (is_forth)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s4 << "\n";
		}
		else if (!is_forth)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s4 << "\n";
		}

		SetConsoleTextAttribute(hConsole, 15);


		/* Get choice */

		key = _getch();

		if (key == KEY_DOWN && is_first)
		{
			is_first = false;
			is_second = true;
		}
		else if (key == KEY_DOWN && is_second)
		{
			is_second = false;
			is_third = true;
		}
		else if (key == KEY_DOWN && is_third)
		{
			is_third = false;
			is_forth = true;
		}

		else if (key == KEY_UP && is_second)
		{
			is_first = true;
			is_second = false;
		}
		else if (key == KEY_UP && is_third)
		{
			is_second = true;
			is_third = false;
		}
		else if (key == KEY_UP && is_forth)
		{
			is_third = true;
			is_forth = false;
		}

		else if (key == ENTER && is_first)
		{
			system("cls");
			return 1;
		}
		else if (key == ENTER && is_second)
		{
			system("cls");
			return 2;
		}
		else if (key == ENTER && is_third)
		{
			system("cls");
			return 3;
		}
		else if (key == ENTER && is_forth)
		{
			system("cls");
			return 4;
		}

		system("cls");
	}


	return 0;
}



int DoChoice(int n, string intro, string additional_intro, string s1, string s2, string s3, string s4)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int key;

	bool is_first = true;
	bool is_second = false;
	bool is_third = false;
	bool is_forth = false;

	while (true)
	{
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\t\t" << intro;
		SetConsoleTextAttribute(hConsole, 12);
		cout << additional_intro << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);

		printf("\tUse\n'%c' to move up\n'%c' to move down\n", ARROW_UP, ARROW_DOWN);
		printf("Press 'ENTER' to chose an option\n\n");


		/* Dislay choices */

		if (is_first)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s1 << "\n";
		}
		else if (!is_first)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s1 << "\n";
		}


		if (is_second)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s2 << "\n";
		}
		else if (!is_second)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s2 << "\n";
		}


		if (is_third)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s3 << "\n";
		}
		else if (!is_third)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s3 << "\n";
		}

		if (is_forth)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s4 << "\n";
		}
		else if (!is_forth)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s4 << "\n";
		}

		SetConsoleTextAttribute(hConsole, 15);


		/* Get choice */

		key = _getch();

		if (key == KEY_DOWN && is_first)
		{
			is_first = false;
			is_second = true;
		}
		else if (key == KEY_DOWN && is_second)
		{
			is_second = false;
			is_third = true;
		}
		else if (key == KEY_DOWN && is_third)
		{
			is_third = false;
			is_forth = true;
		}

		else if (key == KEY_UP && is_second)
		{
			is_first = true;
			is_second = false;
		}
		else if (key == KEY_UP && is_third)
		{
			is_second = true;
			is_third = false;
		}
		else if (key == KEY_UP && is_forth)
		{
			is_third = true;
			is_forth = false;
		}

		else if (key == ENTER && is_first)
		{
			system("cls");
			return 1;
		}
		else if (key == ENTER && is_second)
		{
			system("cls");
			return 2;
		}
		else if (key == ENTER && is_third)
		{
			system("cls");
			return 3;
		}
		else if (key == ENTER && is_forth)
		{
			system("cls");
			return 4;
		}

		system("cls");
	}


	return 0;
}



int DoChoice(string intro, string s1, string s2, string s3, string s4, string s5)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int key;

	bool is_first = true;
	bool is_second = false;
	bool is_third = false;
	bool is_forth = false;
	bool is_fifth = false;

	while (true)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "\n\t\t" << intro << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);

		printf("\tUse\n'%c' to move up\n'%c' to move down\n", ARROW_UP, ARROW_DOWN);
		printf("Press 'ENTER' to chose an option\n\n");


		/* Dislay choices */

		if (is_first)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s1 << "\n";
		}
		else if (!is_first)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s1 << "\n";
		}


		if (is_second)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s2 << "\n";
		}
		else if (!is_second)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s2 << "\n";
		}


		if (is_third)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s3 << "\n";
		}
		else if (!is_third)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s3 << "\n";
		}

		if (is_forth)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s4 << "\n";
		}
		else if (!is_forth)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s4 << "\n";
		}

		if (is_fifth)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c ", ARROW_LEFT);
			cout << s5 << "\n";
		}
		else if (!is_fifth)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  ");
			cout << s5 << "\n";
		}

		SetConsoleTextAttribute(hConsole, 15);




		/* Get choice */

		key = _getch();

		if (key == KEY_DOWN && is_first)
		{
			is_first = false;
			is_second = true;
		}
		else if (key == KEY_DOWN && is_second)
		{
			is_second = false;
			is_third = true;
		}
		else if (key == KEY_DOWN && is_third)
		{
			is_third = false;
			is_forth = true;
		}
		else if (key == KEY_DOWN && is_forth)
		{
			is_forth = false;
			is_fifth = true;
		}




		else if (key == KEY_UP && is_second)
		{
			is_first = true;
			is_second = false;
		}
		else if (key == KEY_UP && is_third)
		{
			is_second = true;
			is_third = false;
		}
		else if (key == KEY_UP && is_forth)
		{
			is_third = true;
			is_forth = false;
		}
		else if (key == KEY_UP && is_fifth)
		{
			is_forth = true;
			is_fifth = false;
		}




		else if (key == ENTER && is_first)
		{
			system("cls");
			return 1;
		}
		else if (key == ENTER && is_second)
		{
			system("cls");
			return 2;
		}
		else if (key == ENTER && is_third)
		{
			system("cls");
			return 3;
		}
		else if (key == ENTER && is_forth)
		{
			system("cls");
			return 4;
		}
		else if (key == ENTER && is_fifth)
		{
			system("cls");
			return 5;
		}



		system("cls");
	}


	return 0;
}

