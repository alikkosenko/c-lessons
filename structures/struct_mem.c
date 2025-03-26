#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUD 100

// Определяем структуру студента
typedef struct {
    char fname[50];
    char lname[50];
    float asg;
} Snode;

// Функции
void addstud(Snode **arr, int *size, char *fname, char *lname, float asg);
void printarr(Snode *arr, int size);

int main() {
    // Выделяем память под массив студентов
    Snode *Sarr = (Snode*)malloc(MAX_STUD * sizeof(Snode));
    int *size = (int*)malloc(sizeof(int));
    *size = 0;

    // Добавляем студентов
    addstud(&Sarr, size, "Alex", "Kosenko", 4.65);
    addstud(&Sarr, size, "Aasdasd", "Kokokokokok", 4.64);

    // Выводим список студентов
    printarr(Sarr, *size);

    // Освобождаем память
    free(Sarr);
    free(size);

    return 0;
}

// Функция добавления студента
void addstud(Snode **arr, int *size, char *fname, char *lname, float asg) {
    if (*size >= MAX_STUD) {
        printf("Ошибка: массив переполнен!\n");
        return;
    }

    // Копируем данные в массив
    strcpy((*arr)[*size].fname, fname);
    strcpy((*arr)[*size].lname, lname);
    (*arr)[*size].asg = asg;

    // Увеличиваем размер
    (*size)++;
}

// Функция вывода массива студентов
void printarr(Snode *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s %s %f\n", arr[i].fname, arr[i].lname, arr[i].asg);
    }
}

