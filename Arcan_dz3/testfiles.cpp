//#include <iostream>
//#include <Windows.h>
//#include <conio.h>
//#include <stdbool.h>
//#include <locale.h>
//#define N 255
//
//int sumOfNumerals(int number)
//{
//    int numeral;
//    int sum = 0;
//    while (number != 0)
//    {
//        numeral = number % 10;
//        number /= 10;
//
//        sum += numeral;
//    }
//    return sum;
//}
//
//int main()
//{
//    char log_file;
//    FILE* log;
//    log_file = fopen_s(&log, "log.txt", "w");
//    int dr1 = 0; int dr2 = 0; int dr3 = 0;
//    int result = 0;
//    int sum = 0, arc = 0;
//    int knopka = 0;
//    int flag = 1;
//
//    setlocale(LC_ALL, "");
//    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleTextAttribute(h, (1 << 4) + 4); // ������� 4 ���� - ���, ������� 4 ���� - �����
//    while (knopka != 27) {
//
//        system("cls");
//        printf("������� ���� �������� (������ ����� 00.00.0000): ");
//        if (scanf_s("%d.%d.%d", &dr1, &dr2, &dr3) != 3 || 31 < dr1 || dr1 < 0 || 12 < dr2 || dr2 < 0) {
//            fprintf(log, "���� ������� ������������ ����\n");
//            fflush(log);  // ���������� �����
//            system(("cls"));
//            printf("������������ ��������!");
//            scanf_s("%*[^\n]");
//            scanf_s("%*c");
//            knopka = _getch();
//        }
//        else {
//            fprintf(log, "%02d.%02d.%04d\n", dr1, dr2, dr3);
//            fflush(log);  // ���������� �����
//            sum = sumOfNumerals(dr1) + sumOfNumerals(dr2) + sumOfNumerals(dr3);
//            if (sum > 22) {
//                sum %= 22;
//            }
//
//            const char* result[] = {
//            "���",
//            "���",
//            "�����",
//            "�����������",
//            "���������",
//            "��������",
//            "����������",
//            "���������",
//            "��������������",
//            "���������",
//            "������ �������",
//            "����",
//            "����������",
//            "������",
//            "�����������",
//            "������",
//            "�����",
//            "������",
//            "����",
//            "������",
//            "���",
//            "���"
//            };
//            arc = sum;
//
//            printf("��� ������ �����: %s\n", result[arc]);
//            knopka = _getch();
//        }
//    }
//    fclose(log);
//}
