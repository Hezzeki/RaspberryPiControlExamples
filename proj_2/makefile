.DEFAULT_GOAL := all
.PHONY: clean help all obj

help :
	@echo "This file will determine when an LED is on."
	@echo "It assumes blink.c is on the device and there is access to a "
	@echo "library -lwiringPi."
	@echo "The available commands are: "
	@echo "make [all] = Build all in project"
	@echo "make obj = Build all in project leave the objects"
	@echo "make button = Build only the basic button command"
	@echo "make clean = remove all built parts of make"
	@exit 0

# COMPILER INFO
SRC_FILES := button.f90 # $(wildcard *.f90)
EXE_FILES := $(SRC_FILES:%.f90=%) # Remove the .f90 extension
OBJ_FILES := $(SRC_FILES:%.f90=%.o)
CC := gfortran
CFLAGS := -Werror -Wall
# If we need to link stuff
LDFLAGS := -lwiringPi
# BUILDS
$(OBJ_FILES): %.o: %.f90
	$(CC) -c $< -o $@ $(CFLAGS)

# Make sure to say the prereqs chain!
$(EXE_FILES): %: %.o $(OBJ_FILES)
# 	$< can be replaced with $(OBJ_FILES) for full dependency
	$(CC) $< -o $@ $(LDFLAGS)

# COMMANDS
clean :
	rm -f *.o button

all: $(EXE_FILES)
	rm -f *.o

obj: $(OBJ_FILES)
