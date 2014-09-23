CXX = g++
CFLAGS=-O3 -Wall -I include/
#-std=c++0x
# CFLAGS+=-I `root-config --incdir` -I include/

GTESTLIBS= -lpthread -L /usr/src/gtest -lgtest -lgtest_main

LIBS= -lm  -lstdc++ 
OBJ = $(filter %.o, $^)
TARGET = NuOsc
BIN=./bin/
OBJECTS=$(addprefix $(BIN),$(OBJ))

all:  $(TARGET)

# $(TARGET): $(OBJ)

$(TARGET): main.o tests
	# Compiling $@
	$(CXX) $(CFLAGS)  -o $@ $(OBJECTS) $(LIBS)
	strip $@
	#done!

% : %.o
	# Making executable $@ ( $^ -> $(OBJ) -> $(OBJECTS))
	$(CXX) $(CFLAGS) -o $@ $(OBJECTS)  $(LIBS) $(GTESTLIBS)
	strip $@
	#done!

%.o: src/%.cpp
	$(CXX) $(CFLAGS) -o $@ -c $^
	mv $@ $(BIN)

obj: $(OBJECTS)


tests: test_function1d
	./test_function1d
clean:
	rm $(BIN)*
	rm *.o
