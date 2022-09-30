OBJS=main.o #Other object files go here
CXX=g++
CFLAGS=-g
TARGET=main

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run:
	./main
#marks

clean:
	rm -f $(TARGET) $(OBJS)