CC = gcc                     # Компилятор
CFLAGS = -Wall -Wextra -g    # Флаги компиляции
TARGET = test    					   # Имя исполняемого файла
<<<<<<< HEAD
SRCS = dbllinkedlist.c               # Исходные файлы
=======
SRCS = BinaryTree.c                # Исходные файлы
>>>>>>> e6ae441 (Add Binary tree realization and delete misc files)
OBJS = $(SRCS:.c=.o)         # Файлы объектных модулей

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

