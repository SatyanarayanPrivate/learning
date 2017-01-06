
# Multiple files
# obj-m += file1.o
# obj-m += file2.o
# startstop-objs := file1.o file2.o

# single file
# obj-m += file1.o

obj-m += proc_seq_example2.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


