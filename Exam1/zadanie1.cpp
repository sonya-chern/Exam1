#include <iostream>
#include <time.h>
#include <conio.h>
#include"windows.h"
#define BEGIN_GAME "Пятнашки перемешаны. Можно собирать!"
#define END_GAME "Пятнашки собраны. ПОБЕДА!!!"
using namespace std;
int i, j, Q, temp1, temp2, z, x, Direction, DigChange, IndikSteps = 0;
int IndikObezian = 0;										// пасхальное яйцо))))))
time_t StartTime, EndTime;
int a, b;													//позиция числа на фишке
int Menu();
template<size_t A> void RightMap(int arr[][A], const int Razmer);
template<size_t A> void CreateAndFillMapPC(int arr[][A], const int Razmer);
template<size_t A> void CreateAndFillManual(int arr[][A], const int Razmer);
template<size_t A> void ShowMap(int arr[][A], const int Razmer);
template<size_t A> void SerchZero(int arr[][A], const int Razmer, int &temp1, int& temp2);
template<size_t A> void StepRight(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps);
template<size_t A> void StepLeft(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps);
template<size_t A> void StepUp(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps);
template<size_t A> void StepDown(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps);
template<size_t A> int PossibilitySol(int arr[][A], const int Razmer);										// можно ли решить перемешанное компьютером
template<size_t A> void ChangeMap(int arr[][A], const int Razmer, int& DigChange, int& IndikSteps);
template<size_t A> void Corner(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps);
template<size_t A> void Corner2(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void Func1(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void Func2(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void Func3(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void Func4(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void Func5(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void Func6(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void Func7(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void Func8(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void Func9(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void Func10(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps);
template<size_t A> void DigitPlace(int arr[][A], const int Razmer, int& a, int& b, int Q);					//позиция числа на фишке
template<size_t A> void PCgame3x3(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps);
template<size_t A> void PCgame4x4(int arr[][A], int arr2[][A], const int Razmer, int& temp1, int& temp2, int& IndikSteps);
template<size_t A> void ManualGame(int arr[][A], int arr2[][A], const int Razmer, int& temp1, int& temp2, int& IndikSteps);
template<size_t A> int IsItVictory(int arr[][A], int arr2[][A], const int Razmer);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	cout << "Привет! Сыграем? " << endl;
	int IndikRegimaIgr = Menu();
	if (IndikRegimaIgr < 1 || IndikRegimaIgr>8) return 0;
	cout << "Игра началась!" << endl;
	if (IndikRegimaIgr == 1) {					//3 на 3 вручную человек (p)
		const int Razmer = 3;
		int arr[Razmer][Razmer];
		int arr2[Razmer][Razmer];
		CreateAndFillManual(arr, Razmer);
		ShowMap(arr, Razmer);
		ManualGame(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 2) {				//3 на 3, замес вручную, комп собирает (p)
		const int Razmer = 3;
		int arr[Razmer][Razmer];
		CreateAndFillManual(arr, Razmer);
		ShowMap(arr, Razmer);
		PCgame3x3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 3) {				//3 на 3, замес комп, человек собирает (p)
		const int Razmer = 3;
		int arr[Razmer][Razmer]; 	int arr2[Razmer][Razmer];
		CreateAndFillMapPC(arr, Razmer);
		ShowMap(arr, Razmer);
		ManualGame(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 4){				// 3 на 3 комп комп (p)
		const int Razmer = 3;
		int arr[Razmer][Razmer];
		CreateAndFillMapPC(arr, Razmer);
		ShowMap(arr, Razmer);
		PCgame3x3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 5) {				//4 на 4 вручную человек (p)
		const int Razmer = 4;
		int arr[Razmer][Razmer];	int arr2[Razmer][Razmer];
		CreateAndFillManual(arr, Razmer);
		ShowMap(arr, Razmer);
		ManualGame(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 6) {				//4 на 4, замес вручную, комп собирает (p)
		const int Razmer = 4;
		int arr[Razmer][Razmer];	int arr2[Razmer][Razmer];
		CreateAndFillManual(arr, Razmer);
		ShowMap(arr, Razmer);
		PCgame4x4(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 7) {				//	4 на 4 комп человек (p)
		const int Razmer = 4;
		int arr[Razmer][Razmer];	int arr2[Razmer][Razmer];
		CreateAndFillMapPC(arr, Razmer);
		ShowMap(arr, Razmer);
		ManualGame(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 8) {				//	4 на 4 комп комп (p)
	const int Razmer = 4;
	int arr[Razmer][Razmer];		int arr2[Razmer][Razmer];
	CreateAndFillMapPC(arr, Razmer);
	ShowMap(arr, Razmer);
	PCgame4x4(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
}
///////////////////////////////////////////////////////////////////////////////////
int Menu() {
int a, b, c;
cout << "Выберите размер поля: 1 - 3х3, 2 - 4х4, 0 - покинуть игру"<<endl;
cin >> a;
if (a == 0) { cout << "Пока!"; return 0; }
else if (a > 2 || a < 0) {
	cout << "Неправильно выбрано действие" << endl<<endl;
	IndikObezian++;
	if (IndikObezian == 3) { cout << "Целься лучше, по клавишам не попадаешь)"<< endl; }
	else { Menu(); }
	return 0;
}
else {
	cout << "Выберете режим перемешивания: 1 - вручную, 2 - компьютер, 0 - покинуть игру" << endl;
	cin >> b;
	if (b == 0) { cout << "Пока!"; return 0; }
	else if (b > 2 || b < 0) { cout << "Неправильно выбрано действие" << endl; Menu(); }
	else {cout << "Выберете режим игры: 1 - человек собирает, 2 - компьютер собирает, 0 - покинуть игру" << endl;
		cin >> c;
		if (c == 0) { cout << "Пока!"; return 0; }
		else if (c > 2 || c < 0) { cout << "Неправильно выбран режим" << endl; Menu(); }
		else if (b == 1 && a == 1 && c == 1) return 1;//	3 на 3 вручную человек
		else if (b == 1 && a == 1 && c == 2) return 2; //	3 на 3 вручную комп
		else if (b == 2 && a == 1 && c == 1) return 3;//	3 на 3 комп человек
		else if (b == 2 && a == 1 && c == 2) return 4;//	3 на 3 комп комп
		else if (b == 1 && a == 2 && c == 1) return 5;//	4 на 4 вручную человек
		else if (b == 1 && a == 2 && c == 2) return 6;//	4 на 4 вручную комп
		else if (b == 2 && a == 2 && c == 1) return 7;//	4 на 4 комп человек
		else if (b == 2 && a == 2 && c == 2) return 8;//	4 на 4 комп комп
	}
}
return 0;
};
template<size_t A> void RightMap(int arr[][A], const int Razmer) {
	arr[Razmer][Razmer];
	int indikFill = 1;
	for (i = 0; i < Razmer; i++) {
		for (j = 0; j < Razmer; j++) {
			if (i == Razmer - 1 && j == Razmer - 1) { arr[i][j] = 0; }
			else { arr[i][j] = indikFill++; }
		}
	}
};
template<size_t A> void CreateAndFillMapPC(int arr[][A], const int Razmer){
	arr[Razmer][Razmer];
	RightMap(arr, Razmer);
	do {
		int indikChange = 0;
		while (indikChange != Razmer) {
			i = rand() % Razmer;
			j = rand() % Razmer;
			int a = rand() % Razmer;
			int b = rand() % Razmer;
			int temp = arr[a][b];
			arr[a][b] = arr[i][j];
			arr[i][j] = temp;
			indikChange++;
		}
		for (i = 0; i < Razmer; i++) {
			for (j = 0; j < Razmer; j++) {
				if (arr[i][j] == 0) {
					int temp = arr[Razmer - 1][Razmer - 1];
					arr[Razmer - 1][Razmer - 1] = arr[i][j];
					arr[i][j] = temp;
				}
			}
		}
	} while (PossibilitySol(arr, Razmer));
};
template<size_t A> void ShowMap(int arr[][A], const int Razmer) {
	arr[Razmer][Razmer];
	for (i = 0; i < Razmer; i++) {
		for (j = 0; j < Razmer; j++) { (arr[i][j]) ? cout << arr[i][j] << "\t" : cout << "  " << "\t"; }
		cout << endl;
	}
};
template<size_t A> void SerchZero(int arr[][A], const int Razmer,int  &temp1, int& temp2) {
	for (i = 0; i < Razmer; i++) {
		for (j = 0; j < Razmer; j++) {
			if (arr[i][j] == 0) { temp1 = i; temp2 = j; }
		}
	}
};
template<size_t A> int PossibilitySol(int arr[][A], const int Razmer) {
	int IndikReshenia = 0;
	int* ptr = &arr[0][0];
	for (i = 0; i < Razmer * Razmer; i++) {
		for (j = i; j < Razmer * Razmer; j++) {
			if (*(ptr + j) != 0) { if (*(ptr + i) > * (ptr + j)) IndikReshenia++; }
		}
	}
	return IndikReshenia % 2;
};
template<size_t A> void CreateAndFillManual(int arr[][A], const int Razmer) {
	arr[Razmer][Razmer];
	RightMap(arr, Razmer);
	cout << "Меняя местами числа с пробелом, можно перемешать пятнашки (менять можно только вверх-вниз, влево-вправо)" << endl;
	cout << "Важное напоминание: Правильная позиция начала игры, когда пробел в правом нижнем углу!" << endl;
	do {
	ShowMap(arr, Razmer);
	ChangeMap(arr, Razmer, DigChange, IndikSteps);
	} while (DigChange != 1);
	SerchZero(arr, Razmer, temp1, temp2);
	if (temp1 != Razmer - 1 || temp2 != Razmer - 1) {
		cout << "Пробел был не в правом нижнем углу! При перемешивании установите пробел в правый нижний угол." << endl;
		CreateAndFillManual(arr, Razmer);
	}
};
template<size_t A> void StepRight(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps) {
	SerchZero(arr, Razmer, temp1, temp2);
	if (temp2 > 0) {
		int t = arr[temp1][temp2];
		arr[temp1][temp2] = arr[temp1][temp2 - 1];
		arr[temp1][temp2 - 1] = t;
		IndikSteps++;
	}
	else cout << "Движение невозможно" << endl;
	ShowMap(arr, Razmer);
	Sleep(300);	system("cls");
}
template<size_t A> void StepLeft(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps) {
	SerchZero(arr, Razmer, temp1, temp2);
	if (temp2 < Razmer - 1) {
		int t = arr[temp1][temp2];
		arr[temp1][temp2] = arr[temp1][temp2 + 1];
		arr[temp1][temp2 + 1] = t;
		IndikSteps++;
	}
	else cout << "Движение невозможно" << endl;
	ShowMap(arr, Razmer);
	Sleep(300);	system("cls");
}
template<size_t A> void StepDown(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps) {
	SerchZero(arr, Razmer, temp1, temp2);
	if (temp1 > 0) {
		int t = arr[temp1][temp2];
		arr[temp1][temp2] = arr[temp1 - 1][temp2];
		arr[temp1 - 1][temp2] = t;
		IndikSteps++;
	}
	else cout << "Движение невозможно" << endl;
	ShowMap(arr, Razmer);
	Sleep(300); system("cls");
}
template<size_t A> void StepUp(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps) {
	SerchZero(arr, Razmer, temp1, temp2);
	if (temp1 < Razmer - 1) {
		int t = arr[temp1][temp2];
		arr[temp1][temp2] = arr[temp1 + 1][temp2];
		arr[temp1 + 1][temp2] = t;
		IndikSteps++;
	}
	else cout << "Движение невозможно" << endl;
	ShowMap(arr, Razmer);
	Sleep(300);	system("cls");
}
template<size_t A> void ChangeMap(int arr[][A], const int Razmer, int& DigChange, int& IndikSteps) {
	cout << "Фишки меняются стрелками на клавиатуре. Для выхода нажмите Enter" << endl;
	int Direction = _getch();
	DigChange = 0;
	if (Direction == 0 || Direction == 224) 
		Direction = _getch();
	switch (Direction){
	case 75:
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		break;
	case 77:
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		break;
	case 72:
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		break;
	case 80:
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		break;
	case 13:
		DigChange = 1;
		break;
	default:
		break;
	}
	//ShowMap(arr, Razmer);
	system("cls");
};
template<size_t A> int IsItVictory(int arr[][A], int arr2[][A], const int Razmer) {
	arr2[Razmer][Razmer];
	RightMap(arr2, Razmer);
	int s = 0;
	for (i = 0; i < Razmer; i++) {
		for (j = 0; j < Razmer; j++) {
			if (arr[i][j] == arr2[i][j]) s++;
		}
	}
	if (s == Razmer*Razmer) return 0;
	else return 1;
};
template<size_t A> void Corner(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps) {
	SerchZero(arr, Razmer, temp1, temp2);				StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);	StepRight(arr, Razmer, temp1, temp2, IndikSteps);	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void DigitPlace(int arr[][A], const int Razmer, int& a, int& b, int Q) {
	for (i = 0; i < Razmer; i++) {
		for (j = 0; j < Razmer; j++) {
			if (arr[i][j] == Q) { a = i; b = j; }
		}
	}
};
template<size_t A> void PCgame3x3(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps) {
	cout << BEGIN_GAME << endl << endl;
	StartTime = time(NULL);
	IndikSteps = 0;
	Q = 1;
	SerchZero(arr, Razmer, temp1, temp2);
	a = 0; b = 0;
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 0 && b == 0) { Func2(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 2 && b == 0) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 0) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) {
		Func4(arr, Razmer, temp1, temp2, IndikSteps);			Func8(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func8(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func8(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 2) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func8(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 0 && b == 2) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 1) {
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func7(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 0 && b == 1) {
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		Func7(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 2;//													двойка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 0) { StepLeft(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 1 && b == 0) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 1) { Func8(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 1 && b == 2) {
		Func8(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func8(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 0) {
		Func9(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);	Func8(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func8(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 3;//													тройка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 1 && b == 0) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);		Func5(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 1) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 2) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 0) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);		Func8(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);	Func5(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func8(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);	Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		Func9(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);	Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 4;//													четверка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 1 && b == 1) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 2) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);	Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 0) { Func8(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 2 && b == 1) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);	Func10(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);	Func8(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);	Func10(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 5;//									пятерка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 1) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (b == 0) {
		Func10(arr, Razmer, temp1, temp2, IndikSteps);		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func4(arr, Razmer, temp1, temp2, IndikSteps);		Func8(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (b == 1) {
		Func8(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		Func8(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func8(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 6;//													шестерка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 2 && b == 2) { StepUp(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 2 && b == 1) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);	Func8(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	ShowMap(arr, Razmer);
	cout << endl;
	cout << "Я все собрал. Я - молодец!"<<endl;
	EndTime = time(NULL);
	cout << "Время игры: " << (EndTime - StartTime) / 60 << " мин " << (EndTime - StartTime) % 60 << " сек" << endl;
	cout << "Количество ходов: " << IndikSteps << endl;
};
template<size_t A> void PCgame4x4(int arr[][A], int arr2[][A], const int Razmer, int& temp1, int& temp2, int& IndikSteps) {
	cout << BEGIN_GAME << endl << endl;
	StartTime = time(NULL);
	IndikSteps = 0;
	Q = 1;
	SerchZero(arr, Razmer, temp1, temp2);
	a = 0; b = 0;
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 0 && b == 0) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func2(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 0 && b == 1) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func2(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 0 && b == 2) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func2(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 0 && b == 3) {
		Func2(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 0) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func2(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 1) {
		Func2(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func10(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 2) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func2(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 3) {
		Func2(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 0) {
		Func4(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) {
		Func4(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 3) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 0) {
		Func4(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) {
		Func4(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		Func4(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func4(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 2;//													двойка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 0 && b == 2) { StepLeft(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 0 && b == 3) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 0) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 1) {
		Func8(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 3) {
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 0) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 3) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 0) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func6(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func6(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 3;//													тройка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 0 && b == 3) { StepLeft(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 1 && b == 0) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);			Func5(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func5(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 1) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 2) { Func8(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 1 && b == 3) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 0) {
		Func9(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func5(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func5(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) {
		Func9(arr, Razmer, temp1, temp2, IndikSteps);			Func5(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func8(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 3) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 0) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func9(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func5(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func5(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) {
		Func9(arr, Razmer, temp1, temp2, IndikSteps);			Func8(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func6(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func6(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 4;//													четверка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 1 && b == 3) { Func7(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 1 && b == 0) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 1) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);			Func5(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 2) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);			Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 0) {
		Func9(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) {
		Func9(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 3) {
		Func9(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 0) {
		Func9(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func9(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func5(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func9(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func10(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 5;//													пятерка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 1 && b == 2) {
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 3) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 0) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) {
		Func10(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func10(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 3) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 0) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) {
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func6(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 9;//													девятка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 1 && b == 2) {
		Func8(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 3) {
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 0) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		Func7(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 3) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 0) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func10(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func8(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func1(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 13;//											тринадцать
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 1 && b == 1) {
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func9(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		Corner2(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 2) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func10(arr, Razmer, temp1, temp2, IndikSteps);
		Corner2(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 3) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		Corner2(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func10(arr, Razmer, temp1, temp2, IndikSteps);
		Corner2(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 3) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func10(arr, Razmer, temp1, temp2, IndikSteps);
		Corner2(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 0) {
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) {
		Corner2(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		Func8(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Corner2(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func8(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner2(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 6;//											шестерка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 1 && b == 2) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 1 && b == 3) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) { Func8(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 2 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 3) {
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 7;//											семерка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 1 && b == 3) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 1) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) { Func8(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 2 && b == 3) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func5(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Func8(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		Func6(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 8;//											восьмерка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 2 && b == 1) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);			Func5(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 2) {
		Func7(arr, Razmer, temp1, temp2, IndikSteps);			Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 2 && b == 3) { Func7(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 3 && b == 1) {
		Func9(arr, Razmer, temp1, temp2, IndikSteps);			Func3(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Func5(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			Func10(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		Corner(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 10;//											десятка
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 2 && b == 2) { StepLeft(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 2 && b == 3) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func1(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) { Func8(arr, Razmer, temp1, temp2, IndikSteps); }
	else if (a == 3 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func3(arr, Razmer, temp1, temp2, IndikSteps);
		Func7(arr, Razmer, temp1, temp2, IndikSteps);			StepDown(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	Q = 11;//											одиннадцать
	DigitPlace(arr, Razmer, a, b, Q);
	if (a == 2 && b == 3) {
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 1) {
		Func10(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		Func10(arr, Razmer, temp1, temp2, IndikSteps);
		StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepUp(arr, Razmer, temp1, temp2, IndikSteps);
		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		Func3(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 2) {
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (a == 3 && b == 3) {
		Func8(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
		StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	}
	if (!(IsItVictory(arr, arr2, Razmer))) {
		ShowMap(arr, Razmer);
		cout << endl;
		cout << "Я все собрал. Я - молодец!";
	}
	else {
		Q = 12;//											двеннадцать
		DigitPlace(arr, Razmer, a, b, Q);
		if (a == 3 && b == 1) {
			StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
			StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
			Func8(arr, Razmer, temp1, temp2, IndikSteps);			StepRight(arr, Razmer, temp1, temp2, IndikSteps);
			StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepUp(arr, Razmer, temp1, temp2, IndikSteps);
			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		}
		else if (a == 3 && b == 2) {
			StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
			Corner(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
			StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
		}
		ShowMap(arr, Razmer);
		cout << endl;
		cout << "Я все собрал. Я - молодец!" << endl;
		EndTime = time(NULL);
		cout << "Время игры: " << (EndTime - StartTime) / 60 << " мин " << (EndTime - StartTime) % 60 << " сек" << endl;
		cout << "Количество ходов: " << IndikSteps << endl;
	}
};
template<size_t A> void ManualGame(int arr[][A], int arr2[][A], const int Razmer, int& temp1, int& temp2, int& IndikSteps) {
	cout << BEGIN_GAME << endl << endl;
	StartTime = time(NULL);
	IndikSteps = 0;
	do {
		ShowMap(arr, Razmer);
		ChangeMap(arr, Razmer, DigChange, IndikSteps);
		i = IsItVictory(arr, arr2, Razmer);
		if (i == 0) break;
	} while (i == 1 || DigChange!=1);
	ShowMap(arr, Razmer);
	if (DigChange == 1) { cout << "Пока!"; return; }
	EndTime = time(NULL);
	cout << END_GAME << endl;
	cout << "Время игры: " << time_t((EndTime - StartTime) / 60) << " мин " << time_t((EndTime - StartTime) % 60) << " сек" << endl;
	cout << "Количество ходов: " << IndikSteps << endl;
};
template<size_t A> void Corner2(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func1(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//LU2RD полуповорот по час.стрелке через низ
	SerchZero(arr, Razmer, temp1, temp2);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func2(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//R2D поднять ноль на 2 клетки и налево
	SerchZero(arr, Razmer, temp1, temp2);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func3(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//DRULD поднять ноль и костяшку 2 клетку
	SerchZero(arr, Razmer, temp1, temp2);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func4(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//D2R поднять ноль и налево на 2 клетки 
	SerchZero(arr, Razmer, temp1, temp2);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func5(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//U2LD полуповорот против час.стрелке через низ
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func6(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//UUL опустить ноль  на 2 и сдвинуть вправо
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func7(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//URR отустить ноль и сдвинуть влево на 2
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func8(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//ULD поднять ноль снизу и поставить справа
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func9(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//UUR опустить ноль на 2 и сдвинуть влево
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func10(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};


