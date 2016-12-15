WFLAGS := -Wall -Wstrict-prototypes -Wno-trigraphs
LDFLAGS := -Map /var/tmp/lllmap.txt
EXTRA_CFLAGS := $(WFLAGS)
# EXTRA_CFLAGS += -g -Wa,-adhln=$(<:.c=.lst)
EXTRA_CFLAGS += -D_DEBUG -g3 -fno-stack-protector

KDIR  := /lib/modules/$(shell uname -r)/build

MODULE = hello
obj-m := $(MODULE).o
PWD := $(shell pwd)

.PHONY: all default
all: default

default:
	     $(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	-$(RM) -r *.o *~ *.*.cmd *.ko *.ko.unsigned *.mod.c *.order *.symvers .tmp_versions built-in.o
