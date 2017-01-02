BIN = ./bin
DST = ./dst
SRC = ./src
INCLUDE = /home/Anne/program/yurigl/include
OBJS = $(DST)/yrgllib.o $(DST)/draw.o $(DST)/color.o $(DST)/yrgl_manager.o $(DST)/mouse.o $(DST)/keyboard.o \
	$(DST)/yrgl_config.o $(DST)/timer.o $(DST)/drawmat.o

CC = g++
CFLAGS = -O2 -L/usr/X11R6/lib -lglut -lGLU -lGL -lXi -lXext -lX11 -lm -lpthread `pkg-config --cflags opencv` `pkg-config --libs opencv`
export CC
export CFLAGS

$(BIN)/libyurigl.a: $(OBJS) Makefile
	ar rcs $(BIN)/libyurigl.a $(OBJS)

$(DST)/%.o: $(SRC)/%.cxx
	$(CC) $(CFLAGS) -I$(INCLUDE) -c -o $(DST)/$*.o $(SRC)/$*.cxx

all:
	make clean
	make
      
example: $(BIN)/libyurigl.a
	$(CC) $(CFLAGS) -I$(INCLUDE) ./example/example.cxx $(BIN)/libyurigl.a -o $(BIN)/example
	$(CC) $(CFLAGS) -I$(INCLUDE) ./example/example2.cxx `pkg-config --cflags opencv` `pkg-config --libs opencv` $(BIN)/libyurigl.a -o $(BIN)/example2

clean:
	rm -f $(BIN)/*
	rm -f $(DST)/*
