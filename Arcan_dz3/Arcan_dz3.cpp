//#include <iostream>
//#include <Windows.h>
//#include <conio.h>
//#include <stdbool.h>
//#include <locale.h>
//#include <chrono>
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
//    char info_file;
//    FILE* log;
//    FILE* info;
//    fopen_s(&log, "log.txt", "w+");
//    fopen_s(&info, "info.txt", "r");
//    int dr1 = 0; int dr2 = 0; int dr3 = 0;
//    int result = 0;
//    int sum = 0, arc = 0;
//    char knopka;
//    int flag = 1;
//    
//    setlocale(LC_ALL, "");
//    
//    while (true) {
//        system("cls");
//        if (flag == 1) {
//            printf("1) Узнать свой аркан <-- \n");
//        }
//        else {
//            printf("1) Узнать свой аркан \n");
//        }
//        if (flag == 2) {
//            printf("2) Посмотреть историю ввода дат <-- \n");
//        }
//        else {
//            printf("2) Посмотреть историю ввода дат \n");
//        }
//        if (flag == 3) {
//            printf("3) Выход <-- \n");
//        }
//        else {
//            printf("3) Выход \n");
//        }
//        knopka = _getch();
//        if (flag == 1 && knopka == 72) {
//            continue;
//        }
//        if (flag == 3 && knopka == 80) {
//            continue;
//        }
//        if (knopka == 80) {
//            flag++;
//        }
//        if (knopka == 72) {
//            flag--;
//        }
//        if (knopka == 27) {
//            exit(0);
//        }
//        if ((knopka == 49) || (knopka == 13 && flag == 1)) {
//            system("cls");
//            while (knopka != 27) {
//
//                system("cls");
//                printf("Введите дату рождения (формат ввода 00.00.0000): ");
//                if (scanf_s("%d.%d.%d", &dr1, &dr2, &dr3) != 3 || 31 < dr1 || dr1 < 0 || 12 < dr2 || dr2 < 0) {
//                    fprintf(log, "Была введена некорректная дата\n");
//                    fflush(log);  // Сброс буфера
//                    system(("cls"));
//                    printf("Некорректные значения!\n");
//                    printf("Выйти на ESC, чтобы продолжить - ENTER");
//                    scanf_s("%*[^\n]");
//                    scanf_s("%*c");
//                    knopka = _getch();
//                }
//                else {
//                    auto start_time = std::chrono::high_resolution_clock::now();
//                    fprintf(log, "%02d.%02d.%04d\n", dr1, dr2, dr3);
//                    fflush(log);  
//                    sum = sumOfNumerals(dr1) + sumOfNumerals(dr2) + sumOfNumerals(dr3);
//                    if (sum > 22) {
//                        sum %= 22;
//                    }
//
//                    const char* result[] = {
//                    "Шут",
//                    "Маг",
//                    "Жрица",
//                    "Императрица",
//                    "Император",
//                    "Иерофант",
//                    "Влюбленные",
//                    "Колесница",
//                    "Справедливость",
//                    "Отшельник",
//                    "Колесо Фортуны",
//                    "Сила",
//                    "Повешенный",
//                    "Смерть",
//                    "Умеренность",
//                    "Дьявол",
//                    "Башня",
//                    "Звезда",
//                    "Луна",
//                    "Солнце",
//                    "Суд",
//                    "Мир"
//                    };
//                    arc = sum;
//                    auto end_time = std::chrono::high_resolution_clock::now();
//                    auto time = end_time - start_time;
//
//                    printf("Ваш высший аркан: %s\n", result[arc]);
//                    fseek(info, 0, SEEK_SET);
//                    char arr[N];
//                    for (int i = 1; i <= 22; i++) {
//                        fgets(arr, N, info);
//                        if (i == sum) {
//                            printf(arr, N, info);
//                            memset(arr, 0, N);
//                        }
//                    }
//                    printf("Время выполнения(в миллисекундах): %.2f\n", time.count() / 1000.0);
//                    printf("Выйти на ESC, чтобы продолжить - ENTER");
//                    knopka = _getch();
//                    
//                }
//            }
//            
//        }
//        if ((knopka == 50) || (knopka == 13 && flag == 2)) {
//            
//            while (true) {
//                system("cls");
//                fseek(log, 0, SEEK_SET);
//                char logrr[N];
//                
//                while (fgets(logrr, N, log)) {
//                    printf("%s", logrr);
//                }
//                printf("Выйти - ESC");
//                knopka = _getch();
//                if (knopka == 27) {
//                    break;
//                }
//            }
//            fclose(log); // закрыть
//            fopen_s(&log, "log.txt", "a+");  // Открыть заново для записи
//        }
//        if ((knopka == 51) || (knopka == 13 && flag == 3)) {
//            exit(0);
//        }
//    }
//    fclose(log);
//}
