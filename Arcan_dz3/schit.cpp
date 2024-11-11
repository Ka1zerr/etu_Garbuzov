//#include <stdio.h>
//#include <locale.h>
//
//#define N 255
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
//int main() {
//    int sum;
//    setlocale(LC_ALL, "");
//    FILE* file;
//    char arr[N];
//    char log_file;
//
//    log_file = fopen_s(&file,"info.txt", "r");
//    sum = sumOfNumerals(11) + sumOfNumerals(22) + sumOfNumerals(12);
//    for (int i = 1; i <= 22; i++) {
//        fgets(arr, N, file);
//        if (i == sum) {
//            printf(arr, N, file);
//        }
//            
//        
//    }
//    printf("\n");
//    fclose(file);
//}
