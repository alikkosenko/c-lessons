# Имя модуля (без .ko)
obj-m := hellomod.o

# Указываем путь к исходникам ядра
KERNEL_DIR := /lib/modules/$(shell uname -r)/build

# Текущая директория
PWD := $(shell pwd)

# Основные команды
all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
