CFLAGS = -mmsa -mhard-float -mfp64 -mnan=2008 -g

all:
	mipsisa64r6el-linux-gnuabi64-gcc main.c $(CFLAGS)

clean:
	@rm -f a.out