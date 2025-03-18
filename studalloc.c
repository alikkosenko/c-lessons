#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedList {
    Node *head;
    Node *tail;
} DoublyLinkedList;

// Функция создания списка
DoublyLinkedList* create_list() {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Добавление в конец списка (O(1))
void append(DoublyLinkedList *list, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }

    list->tail = new_node;
}

// Удаление из конца списка (O(1))
void remove_last(DoublyLinkedList *list) {
    if (!list->tail) return; // Список пуст

    Node *temp = list->tail;
    list->tail = list->tail->prev;

    if (list->tail) {
        list->tail->next = NULL;
    } else {
        list->head = NULL; // Список стал пустым
    }

    free(temp);
}

// Вывод списка
void print_list(DoublyLinkedList *list) {
    Node *current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Очистка списка
void free_list(DoublyLinkedList *list) {
    Node *current = list->head;
    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    DoublyLinkedList *list = create_list();

    append(list, 10);
    append(list, 20);
    append(list, 30);

    printf("Список: ");
    print_list(list);

    remove_last(list);
    printf("После удаления последнего элемента: ");
    print_list(list);

    free_list(list);
    return 0;
}

