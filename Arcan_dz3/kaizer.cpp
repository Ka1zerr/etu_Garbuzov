#include"kaizer.h"
#include <chrono>
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <stdbool.h>
#include <Windows.h>
#define N 255
int flag = 1;
int sumOfNumerals(int number)
{
    int numeral;
    int sum = 0;
    while (number != 0)
    {
        numeral = number % 10;
        number /= 10;

        sum += numeral;
    }
    return sum;
}
const char* getArcana(int arc) {
    const char* result[] = {
                    "���",
                    "���",
                    "�����",
                    "�����������",
                    "���������",
                    "��������",
                    "����������",
                    "���������",
                    "��������������",
                    "���������",
                    "������ �������",
                    "����",
                    "����������",
                    "������",
                    "�����������",
                    "������",
                    "�����",
                    "������",
                    "����",
                    "������",
                    "���",
                    "���"
    };
    return result[arc];
}
void displayLog(FILE* log) {
    char knopka;
    while (true) {
        system("cls");
        fseek(log, 0, SEEK_SET);
        char logrr[N];

        while (fgets(logrr, N, log)) {
            printf("%s", logrr);
        }
        printf("����� - ESC");
        knopka = _getch();
        if (knopka == 27) {
            break;
        }
    }
}  // ������ �����
void vivodArcana(FILE* log, FILE* info)
{
    char knopka;
    int dr1, dr2, dr3, sum, arc;
    while (true) {
        system("cls");
        printf("������� ���� �������� (������ ����� 00.00.0000): ");
        if (scanf_s("%d.%d.%d", &dr1, &dr2, &dr3) != 3 || 31 < dr1 || dr1 < 0 || 12 < dr2 || dr2 < 0) {
            fprintf(log, "���� ������� ������������ ����\n");
            fflush(log);  // ����� ������
            system(("cls"));
            printf("������������ ��������!\n");
            printf("����� �� ESC, ����� ���������� - ENTER");
            scanf_s("%*[^\n]");
            scanf_s("%*c");
            knopka = _getch();
            if (knopka == 27) { break; }
        }
        else {
            auto start_time = std::chrono::high_resolution_clock::now();
            fprintf(log, "%02d.%02d.%04d\n", dr1, dr2, dr3);
            fflush(log);
            sum = sumOfNumerals(dr1) + sumOfNumerals(dr2) + sumOfNumerals(dr3);
            if (sum > 22) {
                sum %= 22;
            }
            arc = sum;
            auto end_time = std::chrono::high_resolution_clock::now();
            auto time = end_time - start_time;
            printf("��� ������ �����: %s\n", getArcana(arc));
            fseek(info, 0, SEEK_SET);
            char arr[N];
            for (int i = 1; i <= 22; i++) {
                fgets(arr, N, info);
                if (i == sum) {
                    printf(arr, N, info);
                    memset(arr, 0, N);
                }
            }
            printf("����� ����������(� �������������): %.2f\n", time.count() / 1000.0);
            printf("����� �� ESC, ����� ���������� - ENTER");
            knopka = _getch();
            if (knopka == 27) { break; }
        }
    }
}
void menu(FILE* log, FILE* info) {
    char knopka;
    system("cls");
    if (flag == 1) {
        printf("1) ������ ���� ����� <-- \n");
    }
    else {
        printf("1) ������ ���� ����� \n");
    }
    if (flag == 2) {
        printf("2) ���������� ������� ����� ��� <-- \n");
    }
    else {
        printf("2) ���������� ������� ����� ��� \n");
    }
    if (flag == 3) {
        printf("3) ����� <-- \n");
    }
    else {
        printf("3) ����� \n");
    }
    knopka = _getch();
    if (flag == 1 && knopka == 72) {
        flag = 2;
    }
    if (flag == 3 && knopka == 80) {
        flag = 2;
    }
    if (knopka == 80) {
        flag++;
    }
    if (knopka == 72) {
        flag--;
    }
    if (knopka == 27) {
        exit(0);
    }
    if ((knopka == 49) || (knopka == 13 && flag == 1)) {
        vivodArcana(log, info);
    }
    if ((knopka == 50) || (knopka == 13 && flag == 2)) {
        displayLog(log);
        fclose(log); // �������
        fopen_s(&log, "log.txt", "a+");  // ������� ������ ��� ������
    }
    if ((knopka == 51) || (knopka == 13 && flag == 3)) {
        exit(0);
    }
}