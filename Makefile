CC = gcc -Wno-format

#CFLAGS = -I${LIKWID_INCLUDE} -DLIKWID_PERFMON -Wall
#LFLAGS = -L${LIKWID_LIB} -llikwid -lm
CFLAGS = -Wall
LFLAGS = -lm

TARGET = perfSL

all: $(TARGET)

#$(TARGET): perfSL.o
#	$(CC) -o $(TARGET) perfSL.o $(CFLAGS) $(LDFLAGS)

$(TARGET) : % : %.c
	$(CC) $(CFLAGS) -o $@ $^ utils.c $(LFLAGS)

clean:
	@rm -f $(TARGET) *~ perfSL.out

purge: clean
	@rm -f $(TARGET)