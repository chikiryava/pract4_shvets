#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <locale.h>  
using namespace std;

void AddDate() {
    FILE* file;
    if ((file = fopen("graphic.txt", "a")) == NULL) {
        printf("Файл невозможно создать или открыть\n");
        return;
    }

    char day[11];
    char starttime[9];
    char endtime[9];

    std::cout << "Введите дату: ";
    std::cin >> day;

    std::cout << "Введите время начала работы: ";
    std::cin >> starttime;

    std::cout << "Введите время конца: ";
    std::cin >> endtime;

    fprintf(file, "%s %s %s\n", day, starttime, endtime);

    fclose(file);
}

void ShowDates() {
    char day[11];
    char starttime[9];
    char endtime[9];
    FILE* file;

    if ((file = fopen("graphic.txt", "r")) == NULL) {
        printf("Файл невозможно открыть\n");
        return;
    }
    printf("---------------------------------------------------------\n");
    printf("  Дата\t     |\tВремя начала\t|\tВремя конца\t|\n");
    printf("---------------------------------------------------------\n");

    while (fscanf(file, "%10s %8s %8s", day, starttime, endtime) == 3){
        printf("%s   |\t %s\t|\t %s\t|\n", day, starttime, endtime);
    }
    printf("---------------------------------------------------------\n");

    fclose(file);
}

int main() {
    setlocale(LC_ALL, "rus");
    int choise = 0;
    while (choise != 3)
    {
        cout << "Выберите, что вы хотите сделать:\n";
        cout << "1: Добавить дату\n";
        cout << "2: Вывести из файла\n";
        cout << "3: Закрыть программу\n";
        cin >> choise;
            switch (choise) {
            case 1:
                AddDate();
                break;
            case 2:
                ShowDates();

                break;
            default:
                cout << "Такого выбора нет";
                break;

            };
    }

    

    return 0;
}
