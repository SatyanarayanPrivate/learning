CROSS_COMPILE=

CC=$(CROSS_COMPILE)g++
# CFLAGS=-c -g -rdynamic -funwind-tables -Wall -I./
CFLAGS=-c -g -rdynamic -funwind-tables -I./
LDFLAGS=   -lpthread -lrt

STRIP=$(CROSS_COMPILE)strip

SOURCES= main.cpp 

OBJECTS=$(SOURCES:.cpp=.o)

TARGET=exe_app

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 
# 	$(STRIP) $(TARGET)
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o $(TARGET)
