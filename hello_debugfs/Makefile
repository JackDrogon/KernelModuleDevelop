CONFIG_MODULE_SIG=n

obj-m = hello_debugfs.o
KVERSION = $(shell uname -r)
PWD = $(shell pwd)

all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
