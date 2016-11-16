GCC=		/proj/SEAD3/mips-2014.11/bin/mips-linux-gnu-gcc
PORT_DIR = linux

SRCPATH = .. ../$(PORT_DIR)
HEADER  = $(SRCPATH)

TARGET = coremark

OBJS =	core_list_join.o \
		core_main.o \
		core_matrix.o \
		core_state.o \
		core_util.o \
		core_portme.o 

VPATH  = $(SRCPATH:%=:%)
IPATH  = $(HEADER:%=-I%)

CFLAGS = -O2 


PORT_CFLAGS = -O2 -EL
XCFLAGS = -DPERFORMANCE_RUN=1
XLFLAGS = -lrt -static

FLAGS_STR = "$(PORT_CFLAGS) $(XCFLAGS) $(XLFLAGS) $(LFLAGS_END)"

CFLAGS  = $(PORT_CFLAGS) $(IPATH) -DFLAGS_STR=\"$(FLAGS_STR)\"
CFLAGS += -DITERATIONS=0 
CFLAGS += $(XCFLAGS)

all:	$(TARGET)

$(TARGET) : $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) $(XLFLAGS) -o $@

%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
