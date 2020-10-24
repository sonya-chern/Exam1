#include <iostream>
#include <time.h>
#include <conio.h>
#include"windows.h"
#define BEGIN_GAME "�������� ����������. ����� ��������!"
#define END_GAME "�������� �������. ������!!!"
using namespace std;
int i, j, Q, temp1, temp2, z, x, Direction, DigChange, IndikSteps = 0;
int IndikObezian = 0;										// ���������� ����))))))
time_t StartTime, EndTime;
int a, b;													//������� ����� �� �����
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
template<size_t A> int PossibilitySol(int arr[][A], const int Razmer);										// ����� �� ������ ������������ �����������
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
template<size_t A> void DigitPlace(int arr[][A], const int Razmer, int& a, int& b, int Q);					//������� ����� �� �����
template<size_t A> void PCgame3x3(int arr[][A], const int Razmer, int& temp1, int& temp2, int &IndikSteps);
template<size_t A> void PCgame4x4(int arr[][A], int arr2[][A], const int Razmer, int& temp1, int& temp2, int& IndikSteps);
template<size_t A> void ManualGame(int arr[][A], int arr2[][A], const int Razmer, int& temp1, int& temp2, int& IndikSteps);
template<size_t A> int IsItVictory(int arr[][A], int arr2[][A], const int Razmer);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	cout << "������! �������? " << endl;
	int IndikRegimaIgr = Menu();
	if (IndikRegimaIgr < 1 || IndikRegimaIgr>8) return 0;
	cout << "���� ��������!" << endl;
	if (IndikRegimaIgr == 1) {					//3 �� 3 ������� ������� (p)
		const int Razmer = 3;
		int arr[Razmer][Razmer];
		int arr2[Razmer][Razmer];
		CreateAndFillManual(arr, Razmer);
		ShowMap(arr, Razmer);
		ManualGame(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 2) {				//3 �� 3, ����� �������, ���� �������� (p)
		const int Razmer = 3;
		int arr[Razmer][Razmer];
		CreateAndFillManual(arr, Razmer);
		ShowMap(arr, Razmer);
		PCgame3x3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 3) {				//3 �� 3, ����� ����, ������� �������� (p)
		const int Razmer = 3;
		int arr[Razmer][Razmer]; 	int arr2[Razmer][Razmer];
		CreateAndFillMapPC(arr, Razmer);
		ShowMap(arr, Razmer);
		ManualGame(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 4){				// 3 �� 3 ���� ���� (p)
		const int Razmer = 3;
		int arr[Razmer][Razmer];
		CreateAndFillMapPC(arr, Razmer);
		ShowMap(arr, Razmer);
		PCgame3x3(arr, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 5) {				//4 �� 4 ������� ������� (p)
		const int Razmer = 4;
		int arr[Razmer][Razmer];	int arr2[Razmer][Razmer];
		CreateAndFillManual(arr, Razmer);
		ShowMap(arr, Razmer);
		ManualGame(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 6) {				//4 �� 4, ����� �������, ���� �������� (p)
		const int Razmer = 4;
		int arr[Razmer][Razmer];	int arr2[Razmer][Razmer];
		CreateAndFillManual(arr, Razmer);
		ShowMap(arr, Razmer);
		PCgame4x4(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 7) {				//	4 �� 4 ���� ������� (p)
		const int Razmer = 4;
		int arr[Razmer][Razmer];	int arr2[Razmer][Razmer];
		CreateAndFillMapPC(arr, Razmer);
		ShowMap(arr, Razmer);
		ManualGame(arr, arr2, Razmer, temp1, temp2, IndikSteps);
	}
	else if (IndikRegimaIgr == 8) {				//	4 �� 4 ���� ���� (p)
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
cout << "�������� ������ ����: 1 - 3�3, 2 - 4�4, 0 - �������� ����"<<endl;
cin >> a;
if (a == 0) { cout << "����!"; return 0; }
else if (a > 2 || a < 0) {
	cout << "����������� ������� ��������" << endl<<endl;
	IndikObezian++;
	if (IndikObezian == 3) { cout << "������ �����, �� �������� �� ���������)"<< endl; }
	else { Menu(); }
	return 0;
}
else {
	cout << "�������� ����� �������������: 1 - �������, 2 - ���������, 0 - �������� ����" << endl;
	cin >> b;
	if (b == 0) { cout << "����!"; return 0; }
	else if (b > 2 || b < 0) { cout << "����������� ������� ��������" << endl; Menu(); }
	else {cout << "�������� ����� ����: 1 - ������� ��������, 2 - ��������� ��������, 0 - �������� ����" << endl;
		cin >> c;
		if (c == 0) { cout << "����!"; return 0; }
		else if (c > 2 || c < 0) { cout << "����������� ������ �����" << endl; Menu(); }
		else if (b == 1 && a == 1 && c == 1) return 1;//	3 �� 3 ������� �������
		else if (b == 1 && a == 1 && c == 2) return 2; //	3 �� 3 ������� ����
		else if (b == 2 && a == 1 && c == 1) return 3;//	3 �� 3 ���� �������
		else if (b == 2 && a == 1 && c == 2) return 4;//	3 �� 3 ���� ����
		else if (b == 1 && a == 2 && c == 1) return 5;//	4 �� 4 ������� �������
		else if (b == 1 && a == 2 && c == 2) return 6;//	4 �� 4 ������� ����
		else if (b == 2 && a == 2 && c == 1) return 7;//	4 �� 4 ���� �������
		else if (b == 2 && a == 2 && c == 2) return 8;//	4 �� 4 ���� ����
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
	cout << "����� ������� ����� � ��������, ����� ���������� �������� (������ ����� ������ �����-����, �����-������)" << endl;
	cout << "������ �����������: ���������� ������� ������ ����, ����� ������ � ������ ������ ����!" << endl;
	do {
	ShowMap(arr, Razmer);
	ChangeMap(arr, Razmer, DigChange, IndikSteps);
	} while (DigChange != 1);
	SerchZero(arr, Razmer, temp1, temp2);
	if (temp1 != Razmer - 1 || temp2 != Razmer - 1) {
		cout << "������ ��� �� � ������ ������ ����! ��� ������������� ���������� ������ � ������ ������ ����." << endl;
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
	else cout << "�������� ����������" << endl;
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
	else cout << "�������� ����������" << endl;
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
	else cout << "�������� ����������" << endl;
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
	else cout << "�������� ����������" << endl;
	ShowMap(arr, Razmer);
	Sleep(300);	system("cls");
}
template<size_t A> void ChangeMap(int arr[][A], const int Razmer, int& DigChange, int& IndikSteps) {
	cout << "����� �������� ��������� �� ����������. ��� ������ ������� Enter" << endl;
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
	Q = 2;//													������
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
	Q = 3;//													������
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
	Q = 4;//													��������
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
	Q = 5;//									�������
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
	Q = 6;//													��������
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
	cout << "� ��� ������. � - �������!"<<endl;
	EndTime = time(NULL);
	cout << "����� ����: " << (EndTime - StartTime) / 60 << " ��� " << (EndTime - StartTime) % 60 << " ���" << endl;
	cout << "���������� �����: " << IndikSteps << endl;
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
	Q = 2;//													������
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
	Q = 3;//													������
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
	Q = 4;//													��������
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
	Q = 5;//													�������
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
	Q = 9;//													�������
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
	Q = 13;//											����������
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
	Q = 6;//											��������
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
	Q = 7;//											�������
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
	Q = 8;//											���������
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
	Q = 10;//											�������
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
	Q = 11;//											�����������
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
		cout << "� ��� ������. � - �������!";
	}
	else {
		Q = 12;//											�����������
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
		cout << "� ��� ������. � - �������!" << endl;
		EndTime = time(NULL);
		cout << "����� ����: " << (EndTime - StartTime) / 60 << " ��� " << (EndTime - StartTime) % 60 << " ���" << endl;
		cout << "���������� �����: " << IndikSteps << endl;
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
	if (DigChange == 1) { cout << "����!"; return; }
	EndTime = time(NULL);
	cout << END_GAME << endl;
	cout << "����� ����: " << time_t((EndTime - StartTime) / 60) << " ��� " << time_t((EndTime - StartTime) % 60) << " ���" << endl;
	cout << "���������� �����: " << IndikSteps << endl;
};
template<size_t A> void Corner2(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);		StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);			StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);		StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func1(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//LU2RD ����������� �� ���.������� ����� ���
	SerchZero(arr, Razmer, temp1, temp2);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func2(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//R2D ������� ���� �� 2 ������ � ������
	SerchZero(arr, Razmer, temp1, temp2);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func3(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//DRULD ������� ���� � �������� 2 ������
	SerchZero(arr, Razmer, temp1, temp2);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func4(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//D2R ������� ���� � ������ �� 2 ������ 
	SerchZero(arr, Razmer, temp1, temp2);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func5(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//U2LD ����������� ������ ���.������� ����� ���
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func6(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//UUL �������� ����  �� 2 � �������� ������
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func7(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//URR �������� ���� � �������� ����� �� 2
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func8(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//ULD ������� ���� ����� � ��������� ������
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepLeft(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func9(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {//UUR �������� ���� �� 2 � �������� �����
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
};
template<size_t A> void Func10(int arr[][A], const int Razmer, int& temp2, int& temp1, int& IndikSteps) {
	StepUp(arr, Razmer, temp1, temp2, IndikSteps);
	StepRight(arr, Razmer, temp1, temp2, IndikSteps);
	StepDown(arr, Razmer, temp1, temp2, IndikSteps);
};


