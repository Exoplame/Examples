//
// ���� ���� ������! ������� � ���������� ����� �������� ���������� ��� ��� ����� ���� ���: print_f(), scan_f()
// ��� �� ������� ��� ������� ����
// ��� ������������ ���������� �� �������, � ������!
// 
// �������!
//

#include <stdio.h>

#include <Windows.h>

#include <iostream>
using namespace std;


#include "main.h"

//
// ������ � "����� �����" � ����������
// � ������ � ��������� �� �++ ��� ������� ��� ��������� main
// ��� ����� ������� �������� ���� ����� 
// � ����: ��� ��� �������� ���������� �� ��������� ����� "void main() {" ������ 
//

void main() 
{
#pragma region ��� ������ ���������� ������� �������� ���������� �������������
	//
	// ���� �������� "����������" - ��������������� ������� ����������� ������ ������ ����������
	// ����� ������ ������, � ������� ����� ����� "��������"
	// � �� ������ 22 ��� ������ "���������"
	//
	int		variable;
//	 ^			^ 
//	��� 	�������� 
	//
	// ��� - ������, ������� ���������� �� ����� ������ ����� ������� ����������
	// � �� ���� ������ ���� ���������� �������� ������� �� ��� �� � ��� ������ �������
	// �� ������� ����� ��� ��� ���������� ����� ���� �������, ��� ����������������, ������ ��������� �������������, � �� ���������� �����
	// �� ���� ������� ������ � ��������� �� ������, ����������� �� �������, �� ������� ���� ���� � ���� ������ ������...
	// 
	// �������� - �������� �����, �� �������� �� ����������� � ��� ����� ������� ������ � ���������, ��������� ��� ���������� ���� ������
	// ������ ���������� ���� ������� � �� ����, �� � ��� �������������...
	// ����� ��� � ���������� ���� ����� � ������, ������� ���������� ������������ �������� (��)
	// 
	// ������ ��� ������ �����: "���������� ����������"?
	// ��� ������ ��� � ����������� ����� ���� �� ������� ����������, � ������ ��� �������� ��� ��������� � ���
	//

	//
	// �� � ������ ����������� ���������� ������� �� ��������... ��� ��� ������� "�����"
	// ��� ����� �� �++... ���� "�������������������" � ��������� ��������� �� ���������...
	// �� �������� ������ ������:
	variable = 0;
	// ��� ���! ������� ���� � ����������� �������� � ���������� �������� 0, � �� ��� ������ ������, ����� ������� ��� ��������� ��������������

	// �� ���������� ������ � ������� ���, ������ ��� �� ����� ������! 
	// � ����� ������ �� ����� �������� �������� �� ������, ��������������� ���� ������ ���� ����������!
	// ��� ��� ����������? �������� ����:
	variable =			12 - 5 * 2 / 3.5f + '0';
	//	^ 	 ^			^    ^   ^    ^      ^
	// ���  ��������			��������
	//	   ����������	   ^   ^   ^      ^
	//							���������
	// 
	// ������� ��� ������, �� ������� �����... �� ����� ����� �������� ������ ����������
	// ���� ��������� �������� �������������, ������� � ����������
	// �� ��������� ��������� �������� ����� �������������... �� ������ ��� �������� � ���� ���������� ������!
	// � ������ � ���������� �� ������������� � ��� �� ACII �������, � ������� ������� ������� �����...
	// �� �� �����, ��� �� ����� ������� ���������
	// �������� - �������������� ����������� �����, ������� ����� ������ � ����������/���������
	// � ������� �������� + ������ �������� ����� � ������ �� ����...
	// �� ������ �� ��� ����� ���������� ������������� � ����������� � �����������
	// ���������� �� � ����� ����
	// 
#pragma endregion

#pragma region �������� ������� ����������
	//
	// �������� ��� ���������� � ����� �������� ����� �������������� �����������
	// ������� �� ���� ����� �������� ��������... �� ����� ��� ����� � ��� � ����������...
	// 
	// � ��� �������: � ��� ������ ��� �������������� ���� ���� 
	// ������� ������ ��������� ������� ��������� �� ������, � ���������� ������ �.
	// ��� � ��� ������ ���� ��������, ��������� ���� ������ �������! 
	// ������� ��� �� ��������� � ��������������, ������� ��������� ���� �������� ����������, �������, ������ ��������� � ����������� � KodeStyle
	// �� ������ x1, i, j, k, l1 � b2 ������... �� ������ ��� ����� � ����� �������� ������ ����������, � �� ������� � � ������
	// � ���� �� ��� ��������? � ����� ��������� ������ ������� ������� ���� �� ������, � ��� ��� �� ascw_1 �� 1544 ������... 
	// 
	// ����� � ����������...
	// ���� �������. ������� �� � ��� � ������� Ctrl ����� "������� � � �����������"
	// P.S. ���� ����� �������� �������� ��� ������� ����, � �� � ������� �������� ������ ���������
	int Summ(int left_number, int right_number);

	// ������ "�������" ������� Summ
	int result = Summ(2, 5); // => 2 + 5 = 7
	// � ���������� ���� 7 ���������� � result

	// ��� �� �������� � ���������
	result = 2 + 2 + 4 / 2; // �� ����������� ���������!
	// � ������ � ������� ������� ��������� ������ ������������ ����
	result = Summ(Summ(2, 2), 4 / 2);

	// �� ������ ��������� ����� ���� "�����������", ��� � �������
	// ��� ������ ������� ������������� ������ ����������� ��������� ����� ��������� ������
	// �� ��� ��� ������ ���� ������, � ������� ����� ���������� ���������� �� ������������
	// ������ ������� ����������, ����� �������, ����������� ����� � ���, ������� ����� ������ "��������"
	// �������� � ����� �����. ���������� ������� ��� ���� double: ��� ����, ���������� ���
	double Summ(double left_number, double right_number);
	// � ������ ��� ��������, �� ������� �������� 3 �� 2
	// 3 - ������������� ������� � 2 - ����, � ������ � ��������� ����� ������������ 1, �� ����� �� 1.5, ������� �������� ��� ��������
	double ratio_of_threeand_two = 3 / 2;
#pragma endregion

	// �� � ������� �, ��������, ������� ���� ������� � ����� ��������!
	// ���� ��� �� ����� �� ����� printf � ��� ������ scan_f!
	// ��! �� �� ������ �� ��������� �� ��������� ������ ���������� stdio.h
	int a = printf("Hello World!\n");
	printf("%d\n", a);
	// ������ ���������? �� ��� ���������! �� ��� ���������� ����� ����������� � ������� ��������
	// ���� ������� ���� ���������!!
	// �� ��� ���, �������... ������� � ����!

	// ����� ����� printf? �������� � ������� ������
	// � ��� ��� �� ����� ��������� � ������� cout (�� ���, �� ����!!!)
	// � ��� ����� ���������, ��� � ���������������� ��� ������� ������� �������! 
	// �� ������ ���������: ������ ��� ���, ��� ��� ��� ������! � ���� ��� ������ �� ���������, ����� ������� ��� ��� ��� ��� ����!
	// � ��� �� �������, ���� ����� ������ �������������� � ����� ������, �� � ����� ������� ����� ��������� �� �����... 
	// ���� ������� �����������, � �� ��� ���������� �������...
	// 
	//  � ���, ������ printf � �� cout? 
	// ������� ������! � �� ����� ���� �� ��� �� ������ �� ����� �������, ������ � ��� ������ "���������" 
	// � ���� ����� ������ � ����� ������, � ������ � ����
	// �� ���� ����������, � ��� ������:

	cout << "Hello, I am 20\n";
	char hello[] = "Hello, I am";
	int age = 20;
	cout << hello << " " << age << endl;
	printf("%s %d\n", hello, age);
	printf("Hello, I am %d\n", age);

	// ��, ����� ����� ����������� ������ � ��� ������� ��������� ����������
	// ������� �� ���������: ������ ���������� - ����� ���������� ������, ��� ������ ����� ������� � �����...
	// ��� ������� ��� 21 � ���? ������ ��� ������ ��� ������������ ��� ������ � ������� ��?
	// ���� ������ � � ������������� ����������, ����� � ��� ������ ������ � ����������� �� ������� �����, �� ��� �� �������������� � ��������� ����...
	// 
	// ���������������� �� ���������, � �� ����� ���, � ����� ���� � ����� ����� 4 ����...
	// ������� ����� ��� �������� �� ������� ����� ���� � ����� ������������
	// ��� ������ ������� ������� cout, �� �� ������� � ���������, � �� ��� ��� � ������ ��������� ������ � ����� ��������...
	// �� ���� �� �� �� �����, � ���� �������� � ���������� C# � ��� ��� ������ �� printf:
	// Console.WriteLine(f"Today I have {money:.2f} ���.");
	// �� ������� ��! ������� ���������, � ������! � ����� ������� ��� �������� �� ������ ��� ������ � �������, � � ����� ������ ��� ������ ������� ������!
	// 
	// �� �������� � �++... � ��� ������ ��� ��������� ������ printf...
	// ���� ��� ��� ������������: ���� ��� ������ ������, ������� ������ ������, ��� ���������� "������"
	// � � ����������� ��������� ������� �������� ������ ������� ��� ������ ������ %d %c � �������...
	// ����� ���������� (���� ���� � ����) ��������� ����� ��������� �������� �� �������� ����� ����� �������� � ���������!

	print_f("Hello World! 100%%\n");	// �� ���� ��������� ���������� � ��������� ������� ����� ��������� ��� � ����������� "��� � �������"
	print_f("3 / 2 = %d\n", 3 / 2);
	print_f("3 / 2 = %d\n", 3.0 / 2);
	print_f("3 / 2 = %f\n", 3.0 / 2);

	// �� �� �������� ��� ��������... ������ ��� ������ ����� %6.3f �������� �� �����...
	// scanf �������� �� ��� �� ������... ��� �� ������... ������� ������������������ ������!
	/*int input;
	a = scanf("%d", &input);
	cout << a << input;*/
	// ���, �� �� �� ��:
	// ������	C4996	'scanf': This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.Examples	C : \Users\akoko\!My_Folder\I_Teacher\CppProgects\Examples\main.cpp	169

	// � ����� �� ���� ���� ��, �� �������� ������� ������ ��� ���� ���������...

	system("pause");
}

#pragma region ������� Summ
//
// ���� �������, ��� ��������� ��������� � ���������� ������� �������� � ����������� ����� ������
// � ����� ������ Summ ��������� 2 ������������[ ���������: left_number � right_number
// � ��� �� �� �������� ������� ��� ������� ������ �� ������� � ������� ��������� ��������
//
int Summ(int left_number, int right_number) {
	// ��� �� �������� �������� +, ��� �� � ����������
	int result =  left_number + right_number; // == int result = Summ(left_number, right_number)
	// �������� �� ������� ���������� ���� �����������

	// ���� ���� ��������, return ���������� ��������� ������ ������� � ��������� � ����������
	return result;

	// ����� �������� ����� 
	// � ��� ����� ������ ���� ������� �� ���������� XD
	return  left_number + right_number;
}
double Summ(double left_number, double right_number) {
	return left_number + right_number;
}
#pragma endregion

void print_f(const char *s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                throw std::runtime_error("������������ ������ ������: ����������� ���������");
            }
        }
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void print_f(const char *s, T value, Args... args)
{
    while (*s) {
        if (*s == '%') { // ����� ������� %
            if (*(s + 1) == '%') { // ���� �� �����������: "%%"
				cout << '%';
                ++s;
            }
            else {
				switch (*(s+1)) // ������ ������ ����� %_
				{
				case 'd':		// ������������� �����
					std::cout << (int)value;
					break;
				case 'f':		// ����� �������� �����
					cout << (float)value;
					break;
				default:
					cout << value;
					break;
				}
				// ������������� �� 2 ������� �� ������� �� ������� ����� %
                s += 2; /// �������� ������ ��� �������������� ������� �� ���� �������� (����. %d, %f ).�� ����� �������� � %5.4f

				// � ��� ��� ��� ��������! ��� ������ ����� ���������, �� ���� � ��� ��� �� ����� �� ������� % ������� ���������� value
				// � ����� �������� ���� � ��������� ��������, � �� ������� ����� "����������� ������" (���� ������ "�����")
				// ����� value �������� ��������� ���������� � ��������� ���� ����� ������� � args
                print_f(s, args...); /// ����� ���������� ���� ����� *s == 0, ����� ���������� ���������� ���������
				// ��� �������� ���:
				// 1 - print_f("%d %f %c\n", value = 2, args = [1.5, 'H']);
				// ����� >> 2;
				// ������;
				// 2 - print_f("%f %c\n", value = 1.5, args = ['H']);
				// ����� >> 1.5;
				// ������;
				// 3 - print_f("%c\n", value = 'h');
				// ����� >> H;
				// 4 - print_f("\n");
				// ������� ������;
				// return;
                return;
            }
        }
        std::cout << *s++;
    }    
}