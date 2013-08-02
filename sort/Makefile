CXX = g++
CXXFLAGS = -std=c++0x -g -Wall

PROJ_ROOT = ..
GTEST_DIR = $(PROJ_ROOT)/gtest
TESTS_DIR = tests

CPPFLAGS += -I$(GTEST_DIR)/include

TESTS = sorttest
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \

SRCS = main.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

all: sort

sort: $(OBJS)
	$(CXX) $(CXXFLAGS) -o sort $(OBJS)

main.o: main.cpp

test: sorttest

clean:
	rm -f *.o sort $(TESTS) gtest.a gtest_main.a

### Build gtest
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^
###

### Build tests
testsim.o : $(TESTS_DIR)/testsim.h $(TESTS_DIR)/testsim.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/testsim.cpp

sorttest.o : $(TESTS_DIR)/sorttest.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/sorttest.cpp

sorttest : sorttest.o testsim.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -pthread $^ -o $@

