#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include<time.h>
#include<string>
#include<mmsystem.h>

#pragma comment(lib, "winmm")

using namespace std;

//Goto fucntion which will set the cursor position

const int width = 120;
const int height = 80;
int jump;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void delay(int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

//Fucntion to move the arrows

void arrowHere(int realPosition, int arrowPosition)
{
	if (realPosition == arrowPosition)
	{
		cout << "===> ";
	}
	else
	{
		cout << "    ";
	}
}

//Classes

class GeometryDash
{
	string name;
	string password;

public:
	GeometryDash()
	{
		
	}
	GeometryDash(string name, string password)
	{
		this->name = name;
		this -> password = password;
	}

	void Menu();

	void login();

	void levels();

	void instructions();

	void creadits();

	void info();

	void special();
};

class Levels : public GeometryDash
{
public:
	Levels(){}

	void Block(int);

	void Input(int);

	virtual void Ground(){}

	virtual void Spikes(){}

	~Levels(){};
};

class Deadlocked : public Levels
{
public:
	Deadlocked() {};

	void Music();

	void Ground();

	void Spikes();

	int Score(int);

	void Score_display(int);

	void EndScreen();
};

class HighScore : public Levels
{
public:
	HighScore() {};

	void Music();

	void Ground();

	void Spikes();

	int Score(int);

	void Score_display(int);

	void EndScreen();
};

class PressStartIV : public Levels
{
public:
	PressStartIV() {};

	void Music();

	void Ground();

	void Spikes();

	int Score(int);

	void Score_display(int);

	void EndScreen();
};

class FingerDash : public Levels
{
public:
	FingerDash() {};

	void Music();

	void Ground();

	void Spikes();

	int Score(int);

	void Score_display(int);

	void EndScreen();
};

//Function of Class GeometryDash

void GeometryDash::Menu()
{
	int position = 1;
	int keypressed = 0;

	//Music

	PlaySound(TEXT("Slushi - All I Need.wav"), NULL, SND_ASYNC);

	while (keypressed != 13)
	{
		system("cls");

		printf("   ____   _____    ___    __  __   _____   _____   ____   __   __    ____       _      ____    _   _ \n  / ___| | ____|  / _ \\  |  \\/  | | ____| |_   _| |  _ \\  \\ \\ / /   |  _ \\     / \\    / ___|  | | | |\n | |  _  |  _|   | | | | | |\\/| | |  _|     | |   | |_) |  \\ V /    | | | |   / _ \\   \\___ \\  | |_| |\n | |_| | | |___  | |_| | | |  | | | |___    | |   |  _ <    | |     | |_| |  / ___ \\   ___) | |  _  |\n  \\____| |_____|  \\___/  |_|  |_| |_____|   |_|   |_| \\_\\   |_|     |____/  /_/   \\_\\ |____/  |_| |_|                                                                                                     \n\n");

		arrowHere(1, position);		cout << "Start Game" << endl;
		arrowHere(2, position);		cout << "Instructions" << endl;
		arrowHere(3, position);		cout << "Credits" << endl;
		arrowHere(4, position);		cout << "Info" << endl;
		arrowHere(5, position);		cout << "Exit" << endl;
		arrowHere(6, position);		cout << "Something Special" << endl;

		//here will be the options

		keypressed = _getch();

		if (keypressed == 80 && position != 6)
		{
			position++;
		}
		else if (keypressed == 72 && position != 1)
		{
			position--;
		}
		else
		{
			position = position;
		}
	}
	switch (position)
	{
	case 1:
		levels();
		break;

	case 2:
		instructions();
		break;

	case 3:
		creadits();
		break;

	case 4:
		info();
		break;

	case 5:
		exit(0);
		break;

	case 6:
		special();
	default:
		break;
	}
	
}

void GeometryDash::levels()
{
	int position = 1;
	int keyPressed = 0;

	while (keyPressed != 13) {

		system("cls");

		cout << "\n LEVEL SELECTION\n";

		cout << "\n Select the level from the following:";
		cout << "\n\n Select at your own RISK!\n\n";

		arrowHere(1, position);		cout << "Deadlocked" << endl;
		arrowHere(2, position);		cout << "PRESS START IV" << endl;
		arrowHere(3, position);		cout << "FINGERDASH" << endl;
		arrowHere(4, position);		cout << "HIGHSCORE" << endl;

		keyPressed = _getch();

		if (keyPressed == 80 && position != 4) {
			position++;
		}
		else if (keyPressed == 72 && position != 1) {
			position--;
		}
		else {
			position = position;
		}
	}

	Levels *L;

	switch (position)
	{
	case 1:
		L = new Deadlocked;
		L->Input(1);
		break;

	case 2:
		L = new PressStartIV;
		L->Input(2);
		break;
		
	case 3:
		L = new FingerDash;
		L->Input(3);
		break;

	case 4:
		L = new HighScore;
		L->Input(4);
		break;
	}
}

void GeometryDash::login()
{
	system("cls");

	cout << "\n LOGIN\n" << endl;

	cout << " Enter Your User Name:";
	getline(cin, name);

	cout << " Enter Password:";
	getline(cin, password);

	if (password == "OOPS")
	{
		system("cls");
		
		cout << " \n Welcome \"" << name << "\"" << endl;
		cout << "\n LOADING RAGE CANNON..... :)\n" << endl;

		Sleep(500);

		for (int i = 0; i < 10; i++)
		{
			Sleep(400);
			cout << "[]";
		}
	}
	else
	{
		cout << "\nInvalid Password, Enter Again in 3 sec.\n" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "[]";
			delay(500);
		}
		login();
	}
}

void GeometryDash::info()
{
	system("cls");

	char* score = new char[50];
	int key;

	cout << "\n YOUR INFO\n";
	cout << "\n User Name:" << name << endl;
	
	ifstream fi;

	fi.open("Score.txt");
	fi.read(score, 50);

	cout << "\n ";

	for (int i = 0; i < 50; i++)
	{
		cout << score[i];
	}

	fi.close();

	cout << "\n-Press 'Enter' to return to Menu.";

	key = _getch();

	if (key == 13)
	{
		Menu();
	}
	else
	{
		info();
	}
}

void GeometryDash::instructions()
{
	int key;

	system("cls");

	cout << "\n INSTRUCTIONS\n";

	cout << "\n-Press 'W' of 'Space' To Jump." << endl;
	cout << "-Hitting Any Spike would cause an Immediate Death." << endl;
	cout << "-Every Spike you dodge, will increase your score" << endl;
	cout << "\n-Press 'Enter' to return to Menu.";

	key = _getch();

	if (key == 13)
	{
		Menu();
	}
	else
	{
		instructions();
	}
}

void GeometryDash::creadits()
{
	int key;

	system("cls");

	cout << "\n CREDITS\n";

	cout << "\nThis Game is mostly made by Me :), but there were other memebers in this group too." << endl;
	cout << "-Group Leader : Muhammad Faiq (21K-4665)" << endl;
	cout << "-Member 1 : Syed Salman Javed Jaffri (21K-3439)" << endl;
	cout << "-Member 2 : Hafiz AbdulRehman Parizaad Silky Muhammad Tahir Sultan SJ (21K-4599)" << endl;
	cout << "\nPress 'Enter' to return to Menu.";

	key = _getch();

	if (key == 13)
	{
		Menu();
	}
	else
	{
		creadits();
	}
}

void GeometryDash::special()
{
	system("cls");

	int key;

	PlaySound(TEXT("Chahe tum kuch na khaho..(asmi).wav"), NULL, SND_ASYNC);

	cout << "\nNow Playing Hindi Song as per request..... ^^" << endl;
	cout << "\nPress Enter to Return to Main Menu" << endl;

	key = _getch();

	if (key == 13)
	{
		Menu();
	}
	else
	{
		special();
	}
}

//Functions of class Levels

void Levels::Input(int level_select)
{
	Deadlocked Dl;
	PressStartIV IV;
	FingerDash Fd;
	HighScore Hs;

	int input, score_value = 0;

	//Here be the commands for music

	if (level_select == 1)
	{
		Dl.Music();
	}
	else if (level_select == 2)
	{
		IV.Music();
	}
	else if (level_select == 3)
	{
		Fd.Music();
	}
	else if (level_select == 4)
	{
		Hs.Music();
	}

	while (1)
	{
		while (!_kbhit())
		{
			if (level_select == 1)
			{
				Dl.Spikes();
				Dl.Ground();
				Dl.Score_display(score_value);
				Block(0);
			}
			else if (level_select == 2)
			{
				IV.Spikes();
				IV.Ground();
				IV.Score_display(score_value);
				Block(0);
			}
			else if (level_select == 3)
			{
				Fd.Spikes();
				Fd.Ground();
				Fd.Score_display(score_value);
				Block(0);
			}
			else if (level_select == 4)
			{
				Hs.Spikes();
				Hs.Ground();
				Hs.Score_display(score_value);
				Block(0);
			}
			//here be the if else statemetnts for the other levels
		}

		input = _getch();

		if (input == ' ' || input == 'w')
		{
			for (int i = 0; i < 8; i++)
			{
				if (level_select == 1)
				{
					Dl.Spikes();
					Dl.Ground();
					Dl.Score_display(score_value);
				}
				else if (level_select == 2)
				{
					IV.Spikes();
					IV.Ground();
					IV.Score_display(score_value);
				}
				else if (level_select == 3)
				{
					Fd.Spikes();
					Fd.Ground();
					Fd.Score_display(score_value);
				}
				else if (level_select == 4)
				{
					Hs.Spikes();
					Hs.Ground();
					Hs.Score_display(score_value);
				}
				Block(1);
				//here be the if else statemetnts for the other levels
			}
			for (int i = 0; i < 8; i++)
			{
				if (level_select == 1)
				{
					Dl.Spikes();
					Dl.Ground();
					Dl.Score_display(score_value);
				}
				else if (level_select == 2)
				{
					IV.Spikes();
					IV.Ground();
					IV.Score_display(score_value);
				}
				else if (level_select == 3)
				{
					Fd.Spikes();
					Fd.Ground();
					Fd.Score_display(score_value);
				}
				else if (level_select == 4)
				{
					Hs.Spikes();
					Hs.Ground();
					Hs.Score_display(score_value);
				}
				Block(2);
			}

			if (level_select == 1)
			{
				score_value = Dl.Score(1);
			}
			else if (level_select == 2)
			{
				score_value = IV.Score(1);
			}
			else if (level_select == 3)
			{
				score_value = Fd.Score(1);
			}
			else if (level_select == 4)
			{
				score_value = Hs.Score(1);
			}
		}
	}
}

void Levels::Block(int position_change)
{
	delay(20);

	if (position_change == 0)
	{
		jump = 0;
	}
	else if (position_change == 1)
	{
		jump++;
	}
	else if (position_change == 2)
	{
		jump--;
	}

	gotoxy(20, 19 - jump);
	cout << "|______|";

	gotoxy(20, 18 - jump);
	cout << "|  __  |";

	gotoxy(20, 17 - jump);
	cout << "| \\  / |";

	gotoxy(20, 16 - jump);
	cout << " ______";

	gotoxy(0, 20);

	gotoxy(70, 4);
	cout << "_/[][][][]\\_";
	gotoxy(70, 5);
	cout << "\\<()>  <()>/";
	gotoxy(70, 6);
	cout << "  |  []  |";
	gotoxy(70, 7);
	cout << "   \\++++/";
	gotoxy(60, 9);
	cout << "I am watching you Mortal Being.";
}

//Fucntions for class Deadlocked

void Deadlocked::Ground()
{
	gotoxy(0, 20);

	for (int i = 0; i < width; i++)
	{
		printf("[]");
	}
}

void Deadlocked::Spikes()
{
	int inc = 2;
	static int a = 2, spikes = 0, spikes1 = 0, spikes2 = 0;

	//Spike 1

	gotoxy(120 - spikes, 17);
	printf("  ^");

	gotoxy(120 - spikes, 18);
	printf(" /|\\");

	gotoxy(120 - spikes, 19);
	printf("/|||\\");

	//Spike 2

	gotoxy(150 - spikes1, 17);
	printf("  ^");

	gotoxy(150 - spikes1, 18);
	printf(" /|\\");

	gotoxy(150 - spikes1, 19);
	printf("/|||\\");

	//Spike 3

	gotoxy(180 - spikes2, 19);
	printf("/|\\");

	spikes = spikes + inc;
	spikes1 = spikes1 + inc;
	spikes2 = spikes2 + inc;

	if (spikes == 120)
	{
		spikes = 0;
	}
	if (spikes1 == 150)
	{
		spikes1 = 0;
	}
	if (spikes2 == 180)
	{
		spikes2 = 0;
	}

	//Collision

	if (120 - spikes == 26 && jump < 3)
	{
		spikes = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}
	if (150 - spikes1 == 26 && jump < 3)
	{
		spikes1 = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}
	if (180 - spikes2 == 26 && jump < 2)
	{
		spikes2 = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}

	if (a % 3 == 0) {
		system("cls");
	}
	a = a + 1;
};

void Deadlocked::EndScreen()
{
	int position = 1;
	int keyPressed = 0;

	system("cls");

	while (keyPressed != 13) {

		system("cls");

		cout << " _     _   ___   _   _    ____   _____  _____  ____   _ \n\\ \\   / / / _ \\ | | | |  |  _ \\ |_   _||  ___||  _ \\ | |\n \\ \\_/ / | | | || | | |  | | | |  | |  | |___ | | | || |\n  \\   /  | | | || | | |  | | | |  | |  |  ___|| | | || |\n   | |   | | | || | | |  | | | |  | |  | |    | | | ||_|\n   | |   | |_| || |_| |  | |_| | _| |_ | |___ | |_| | _ \n   |_|    \\___/  \\___/   |____/ |_____||_____||____/ |_|\n";
		gotoxy(20, 10);
		cout << "_/[][][][]\\_";
		gotoxy(20, 11);
		cout << "\\<()>  <()>/";
		gotoxy(20, 12);
		cout << "  |  []  |";
		gotoxy(20, 13);
		cout << "   \\++++/";
		gotoxy(5, 15);
		cout << "Hahaha! that was just a fraction of my power.";

		cout << "\n\n GAME OVER\n";
	
		cout << "\n Now select more ways to die, or just give up?" << endl;
		arrowHere(1, position);	 cout << " MENU" << endl;
		arrowHere(2, position);	 cout << " RESTART" << endl;
		arrowHere(3, position);	 cout << " EXIT" << endl;


		keyPressed = _getch();

		if (keyPressed == 80 && position != 3) {
			position++;
		}
		else if (keyPressed == 72 && position != 1) {
			position--;
		}
		else {
			position = position;
		}

	}
	//int x;

	switch (position) {

	case 1:
		Menu();
		break;

	case 2:
		system("cls");
		levels();
		break;

	case 3:
		system("cls");
		exit(0);
		break;
	}
}

int Deadlocked::Score(int set)
{
	static int score = 0;

	if (set == 1)
	{
		score = score + 5;

		return score;
	}
	else if (set == 2)
	{
		fstream fo;

		fo.open("Score.txt");

		fo.clear();
		fo << " Deadlocked Score:" << score << endl;

		fo.close();
	}
	else if (set == 3)
	{
		score = 0;

		return score;
	}
	return 0;
}

void Deadlocked::Score_display(int score)
{
	gotoxy(100, 3);
	
	cout << "SCORE: " << score;
}

void Deadlocked::Music()
{
	PlaySound(TEXT("DeadLocked.wav"), NULL, SND_ASYNC);
}

//Functions of class HighScore

void HighScore::Ground()
{
	gotoxy(0, 20);

	for (int i = 0; i < width; i++)
	{
		printf("[]");
	}
}

void HighScore::Spikes()
{
	int inc = 2;
	static int a = 2, spikes = 0, spikes1 = 0, spikes2 = 0;

	//Spike 1

	gotoxy(120 - spikes, 17);
	printf("  ^");

	gotoxy(120 - spikes, 18);
	printf(" /|\\");

	gotoxy(120 - spikes, 19);
	printf("/|||\\");

	//Spike 2

	gotoxy(150 - spikes1, 17);
	printf("  ^");

	gotoxy(150 - spikes1, 18);
	printf(" /|\\");

	gotoxy(150 - spikes1, 19);
	printf("/|||\\");

	//Spike 3

	gotoxy(180 - spikes2, 19);
	printf("/|\\");

	spikes = spikes + inc;
	spikes1 = spikes1 + inc;
	spikes2 = spikes2 + inc;

	if (spikes == 120)
	{
		spikes = 0;
	}
	if (spikes1 == 150)
	{
		spikes1 = 0;
	}
	if (spikes2 == 180)
	{
		spikes2 = 0;
	}

	//Collision

	if (120 - spikes == 26 && jump < 3)
	{
		spikes = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}
	if (150 - spikes1 == 26 && jump < 3)
	{
		spikes1 = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}
	if (180 - spikes2 == 26 && jump < 2)
	{
		spikes2 = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}

	if (a % 2 == 0) {
		system("cls");
	}
	a = a + 1;
};

void HighScore::EndScreen()
{
	int position = 1;
	int keyPressed = 0;

	system("cls");

	while (keyPressed != 13) {

		system("cls");

		cout << " _     _   ___   _   _    ____   _____  _____  ____   _ \n\\ \\   / / / _ \\ | | | |  |  _ \\ |_   _||  ___||  _ \\ | |\n \\ \\_/ / | | | || | | |  | | | |  | |  | |___ | | | || |\n  \\   /  | | | || | | |  | | | |  | |  |  ___|| | | || |\n   | |   | | | || | | |  | | | |  | |  | |    | | | ||_|\n   | |   | |_| || |_| |  | |_| | _| |_ | |___ | |_| | _ \n   |_|    \\___/  \\___/   |____/ |_____||_____||____/ |_|\n";
		gotoxy(20, 10);
		cout << "_/[][][][]\\_";
		gotoxy(20, 11);
		cout << "\\<()>  <()>/";
		gotoxy(20, 12);
		cout << "  |  []  |";
		gotoxy(20, 13);
		cout << "   \\++++/";
		gotoxy(5, 15);
		cout << "Hahaha! that was just a fraction of my power.";

		cout << "\n\n GAME OVER\n";

		cout << "\n Now select more ways to die, or just give up?" << endl;
		arrowHere(1, position);	 cout << " MENU" << endl;
		arrowHere(2, position);	 cout << " RESTART" << endl;
		arrowHere(3, position);	 cout << " EXIT" << endl;


		keyPressed = _getch();

		if (keyPressed == 80 && position != 3) {
			position++;
		}
		else if (keyPressed == 72 && position != 1) {
			position--;
		}
		else {
			position = position;
		}

	}
	//int x;

	switch (position) {

	case 1:
		Menu();
		break;

	case 2:
		system("cls");
		levels();
		break;

	case 3:
		system("cls");
		exit(0);
		break;
	}
}

int HighScore::Score(int set)
{
	static int score = 0;

	if (set == 1)
	{
		score = score + 5;

		return score;
	}
	else if (set == 2)
	{
		fstream fo;

		fo.open("Score.txt");

		fo.clear();
		fo << " Highscore Score:" << score << endl;

		fo.close();
	}
	else if (set == 3)
	{
		score = 0;

		return score;
	}
	return 0;
}

void HighScore::Score_display(int score)
{
	gotoxy(100, 3);


	cout << "SCORE: " << score;
}

void HighScore::Music()
{
	PlaySound(TEXT("New Record.wav"), NULL, SND_ASYNC);
}

//Functions of class PressStartIV

void PressStartIV::Ground()
{
	gotoxy(0, 20);

	for (int i = 0; i < width; i++)
	{
		printf("[]");
	}
}

void PressStartIV::Spikes()
{
	int inc = 2;
	static int a = 2, spikes = 0, spikes1 = 0, spikes2 = 0;

	//Spike 1

	gotoxy(120 - spikes, 17);
	printf("  ^");

	gotoxy(120 - spikes, 18);
	printf(" /|\\");

	gotoxy(120 - spikes, 19);
	printf("/|||\\");

	//Spike 2

	gotoxy(150 - spikes1, 17);
	printf("  ^");

	gotoxy(150 - spikes1, 18);
	printf(" /|\\");

	gotoxy(150 - spikes1, 19);
	printf("/|||\\");

	//Spike 3

	gotoxy(180 - spikes2, 19);
	printf("/|\\");

	spikes = spikes + inc;
	spikes1 = spikes1 + inc;
	spikes2 = spikes2 + inc;

	if (spikes == 120)
	{
		spikes = 0;
	}
	if (spikes1 == 150)
	{
		spikes1 = 0;
	}
	if (spikes2 == 180)
	{
		spikes2 = 0;
	}

	//Collision

	if (120 - spikes == 26 && jump < 3)
	{
		spikes = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}
	if (150 - spikes1 == 26 && jump < 3)
	{
		spikes1 = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}
	if (180 - spikes2 == 26 && jump < 2)
	{
		spikes2 = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}

	if (a % 2 == 0) {
		system("cls");
	}
	a = a + 1;
};

void PressStartIV::EndScreen()
{
	int position = 1;
	int keyPressed = 0;

	system("cls");

	while (keyPressed != 13) {

		system("cls");

		cout << " _     _   ___   _   _    ____   _____  _____  ____   _ \n\\ \\   / / / _ \\ | | | |  |  _ \\ |_   _||  ___||  _ \\ | |\n \\ \\_/ / | | | || | | |  | | | |  | |  | |___ | | | || |\n  \\   /  | | | || | | |  | | | |  | |  |  ___|| | | || |\n   | |   | | | || | | |  | | | |  | |  | |    | | | ||_|\n   | |   | |_| || |_| |  | |_| | _| |_ | |___ | |_| | _ \n   |_|    \\___/  \\___/   |____/ |_____||_____||____/ |_|\n";
		gotoxy(20, 10);
		cout << "_/[][][][]\\_";
		gotoxy(20, 11);
		cout << "\\<()>  <()>/";
		gotoxy(20, 12);
		cout << "  |  []  |";
		gotoxy(20, 13);
		cout << "   \\++++/";
		gotoxy(5, 15);
		cout << "Hahaha! that was just a fraction of my power.";

		cout << "\n\n GAME OVER\n";

		cout << "\n Now select more ways to die, or just give up?" << endl;
		arrowHere(1, position);	 cout << " MENU" << endl;
		arrowHere(2, position);	 cout << " RESTART" << endl;
		arrowHere(3, position);	 cout << " EXIT" << endl;


		keyPressed = _getch();

		if (keyPressed == 80 && position != 3) {
			position++;
		}
		else if (keyPressed == 72 && position != 1) {
			position--;
		}
		else {
			position = position;
		}

	}
	//int x;

	switch (position) {

	case 1:
		Menu();
		break;

	case 2:
		system("cls");
		levels();
		break;

	case 3:
		system("cls");
		exit(0);
		break;
	}
}

int PressStartIV::Score(int set)
{
	static int score = 0;

	if (set == 1)
	{
		score = score + 5;

		return score;
	}
	else if (set == 2)
	{
		fstream fo;

		fo.open("Score.txt");

		fo.clear();
		fo << " Press Start IV Score:" << score << endl;

		fo.close();
	}
	else if (set == 3)
	{
		score = 0;

		return score;
	}
	return 0;
}

void PressStartIV::Score_display(int score)
{
	gotoxy(100, 3);

	cout << "SCORE: " << score;
}

void PressStartIV::Music()
{
	PlaySound(TEXT("Sterrezo - Dungeon Crawler.wav"), NULL, SND_ASYNC);
}

//Functions of Class FingerDash

void FingerDash::Ground()
{
	gotoxy(0, 20);

	for (int i = 0; i < width; i++)
	{
		printf("[]");
	}
}

void FingerDash::Spikes()
{
	int inc = 2;
	static int a = 2, spikes = 0, spikes1 = 0, spikes2 = 0;

	//Spike 1

	gotoxy(120 - spikes, 17);
	printf("  ^");

	gotoxy(120 - spikes, 18);
	printf(" /|\\");

	gotoxy(120 - spikes, 19);
	printf("/|||\\");

	//Spike 2

	gotoxy(150 - spikes1, 17);
	printf("  ^");

	gotoxy(150 - spikes1, 18);
	printf(" /|\\");

	gotoxy(150 - spikes1, 19);
	printf("/|||\\");

	//Spike 3

	gotoxy(180 - spikes2, 19);
	printf("/|\\");

	spikes = spikes + inc;
	spikes1 = spikes1 + inc;
	spikes2 = spikes2 + inc;

	if (spikes == 120)
	{
		spikes = 0;
	}
	if (spikes1 == 150)
	{
		spikes1 = 0;
	}
	if (spikes2 == 180)
	{
		spikes2 = 0;
	}

	//Collision

	if (120 - spikes == 26 && jump < 3)
	{
		spikes = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}
	if (150 - spikes1 == 26 && jump < 3)
	{
		spikes1 = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}
	if (180 - spikes2 == 26 && jump < 2)
	{
		spikes2 = 0;
		Sleep(500);
		Score(2);
		Score(3);
		EndScreen();
	}

	if (a % 2 == 0) {
		system("cls");
	}
	a = a + 1;
};

void FingerDash::EndScreen()
{
	int position = 1;
	int keyPressed = 0;

	system("cls");

	while (keyPressed != 13) {

		system("cls");

		cout << " _     _   ___   _   _    ____   _____  _____  ____   _ \n\\ \\   / / / _ \\ | | | |  |  _ \\ |_   _||  ___||  _ \\ | |\n \\ \\_/ / | | | || | | |  | | | |  | |  | |___ | | | || |\n  \\   /  | | | || | | |  | | | |  | |  |  ___|| | | || |\n   | |   | | | || | | |  | | | |  | |  | |    | | | ||_|\n   | |   | |_| || |_| |  | |_| | _| |_ | |___ | |_| | _ \n   |_|    \\___/  \\___/   |____/ |_____||_____||____/ |_|\n";
		gotoxy(20, 10);
		cout << "_/[][][][]\\_";
		gotoxy(20, 11);
		cout << "\\<()>  <()>/";
		gotoxy(20, 12);
		cout << "  |  []  |";
		gotoxy(20, 13);
		cout << "   \\++++/";
		gotoxy(5, 15);
		cout << "Hahaha! that was just a fraction of my power.";

		cout << "\n\n GAME OVER\n";

		cout << "\n Now select more ways to die, or just give up?" << endl;
		arrowHere(1, position);	 cout << " MENU" << endl;
		arrowHere(2, position);	 cout << " RESTART" << endl;
		arrowHere(3, position);	 cout << " EXIT" << endl;


		keyPressed = _getch();

		if (keyPressed == 80 && position != 3) {
			position++;
		}
		else if (keyPressed == 72 && position != 1) {
			position--;
		}
		else {
			position = position;
		}

	}
	//int x;

	switch (position) {

	case 1:
		Menu();
		break;

	case 2:
		system("cls");
		levels();
		break;

	case 3:
		system("cls");
		exit(0);
		break;
	}
}

int FingerDash::Score(int set)
{
	static int score = 0;

	if (set == 1)
	{
		score = score + 5;

		return score;
	}
	else if (set == 2)
	{
		fstream fo;

		fo.open("Score.txt");

		fo.clear();
		fo << " Finger Dash Score:" << score << endl;

		fo.close();
	}
	else if (set == 3)
	{
		score = 0;

		return score;
	}
	return 0;
}

void FingerDash::Score_display(int score)
{
	gotoxy(100, 3);

	cout << "SCORE: " << score;
}

void FingerDash::Music()
{
	PlaySound(TEXT("Fingerbank by MDK.wav"), NULL, SND_ASYNC);
}

//Main Function

int main()
{
	GeometryDash GD;

	GD.login();
	GD.Menu();
}