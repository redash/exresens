CXX = g++
CFLAGS=-O3 -Wall -I include/
#-std=c++0x
# CFLAGS+=-I `root-config --incdir` -I include/
# GTESTLIBS=-lgtest.a -lgtest_main.a
# GTESTLIBS=-L /usr/src/gtest -lgtest -lgtest_main
GTESTLIBS=-L /data/sw/gtest-1.7.0 -lgtest -lgtest_main
GTESTLIBS=-lpthread /data/sw/gtest-1.7.0/libgtest.a /data/sw/gtest-1.7.0/libgtest_main.a
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
