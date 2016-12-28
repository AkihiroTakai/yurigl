BIN = ./bin
DST = ./dst
SRC = ./src
INCLUDE = /home/annet/program/yurigl/include
OBJS = $(DST)/yrgllib.o $(DST)/draw.o $(DST)/color.o $(DST)/yrgl_manager.o $(DST)/mouse.o

CC = g++
CFLAGS = -O2 -L/usr/X11R6/lib -lglut -lGLU -lGL -lXi -lXext -lX11 -lm -lpthread
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

clean:
	rm -f $(BIN)/*
	rm -f $(DST)/*
