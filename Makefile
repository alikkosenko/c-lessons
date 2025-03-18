CC = gcc                     # Компилятор
CFLAGS = -Wall -Wextra -g    # Флаги компиляции
TARGET = test    					   # Имя исполняемого файла
SRCS = dbllinkedlist.c               # Исходные файлы
OBJS = $(SRCS:.c=.o)         # Файлы объектных модулей

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

