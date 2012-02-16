CFLAGS = -Wall -O2 -Isrc

OBJS = src/rpl/threading/mutex.o \
       src/rpl/threading/thread.o

all: $(OBJS)

%.o: %.c %.h

clean:
	$(RM) $(OBJS)
