KDIR  := /lib/modules/$(shell uname -r)/build
obj-m := hello_printk.o
PWD := $(shell pwd)

default:
	     $(MAKE) -C $(KDIR) M=$(PWD) modules
