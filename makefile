#Place this makefile in the same directory as your
#all .cpp and .h files
#at the command prompt, type the following ``make'' to initiate compiling
# of all the c++ source files.
#make
#Then, at the prompt run the following, or whatever value you put for TARGET
#./hw1
#To clean, type
#make clean
#To create the zip file with name ``Biswas_A_HW1.zip'' type:
#make zipIt

#for use with c++ files
.SUFFIXES : .cpp
#Compile with g++
CC = g++
#use-g for gnu debugger and-std= for c++11 compiling
CXXFLAGS = -g -std=c++11
######Change to match all .cpp files.  Do not include .h files####
OBJS = main.o
######Change from hw1 to whatever TARGET name you want for the executable.###
TARGET = hw4
######Do NOT change the following 5 lines...Tabs Matter!#########
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<
#In order to get rid of all .o files create, at the command prompt
#make clean

clean:
	rm -f $(OBJS) $(TARGET) core
#Create the zip file. Please change the name of the zip file
# and list the files you would like to add to it.
zipIt:
	zip -r Tran_T_HW4.zip main.cpp README.txt makefile

