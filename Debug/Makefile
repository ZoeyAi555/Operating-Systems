# make a kernel module example
ifneq ($(KERNELRELEASE),)

obj-m := module01.o

else

top_srcdir	?= ../../../..
include $(top_srcdir)/include/mk/testcases.mk

REQ_VERSION_MAJOR	:= 2
REQ_VERSION_PATCH	:= 6
MAKE_TARGETS		:= test01 test02 module01.ko

include $(top_srcdir)/include/mk/module.mk
include $(top_srcdir)/include/mk/generic_leaf_target.mk

endif
