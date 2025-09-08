.DEFAULT_GOAL := all
.PHONY: clean help all obj

help :
	@echo "This file will build a blink LED example."
	@echo "It assumes blink.c is on the device and there is access to a "
	@echo "library -lwiringPi."
	@echo "The available commands are: "
	@echo "make [all] = Build all in project"
	@echo "make obj = Build all in project leave the objects"
	@echo "make blink = Build only the basic blink command"
	@echo "make blink_nosignal = Build a signal intercepting version of blink"
	@echo "make clean = remove all built parts of make"
	@exit 0

# COMPILER INFO
SRC_FILES := blink.c blink_signal.c # $(wildcard *.c)
EXE_FILES := $(SRC_FILES:%.c=%) # Remove the .c extension
OBJ_FILES := $(SRC_FILES:%.c=%.o)
CC := gcc
CFLAGS := -Werror -Wall
# If we need to link stuff
LDFLAGS := -lwiringPi
# BUILDS
$(OBJ_FILES): %.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Make sure to say the prereqs chain!
$(EXE_FILES): %: %.o $(OBJ_FILES)
# 	$< can be replaced with $(OBJ_FILES) for full dependency
	$(CC) $< -o $@ $(LDFLAGS)

# COMMANDS
clean :
	rm -f *.o blink blink_signal

all: $(EXE_FILES)
	rm -f *.o

obj: $(OBJ_FILES)
