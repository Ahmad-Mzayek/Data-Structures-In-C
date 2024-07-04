# =============================================================

CC = gcc
SRC := src
OUTPUT := bin
BUILD := build
INCLUDE := include
CFLAGS := -Wall -Wextra -g
LFLAGS =

# =============================================================

ifeq ($(OS),Windows_NT)	# For Windows OS.
MAIN := main.exe
SOURCEDIRS := $(SRC)
BUILDDIRS := $(BUILD)
INCLUDEDIRS := $(INCLUDE)
FIXPATH = $(subst /,\,$1)
RM := del /q /f
MD := mkdir
RUNCMD := $(OUTPUT)/$(MAIN)

else	# For UNIX OS.
MAIN := main
SOURCEDIRS := $(shell find $(SRC) -type d)
INCLUDEDIRS := $(shell find $(INCLUDE) -type d)
BUILDDIRS := $(BUILD)
FIXPATH = $1
RM = rm -f
MD := mkdir -p
RUNCMD := time ./$(OUTPUT)/$(MAIN)

endif	# OS.

# =============================================================

SOURCES := $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
OBJECTS := $(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(SOURCES))
DEPS := $(OBJECTS:.o=.d)
OUTPUTMAIN := $(call FIXPATH,$(OUTPUT)/$(MAIN))
LIBS := $(patsubst %,-L%, $(BUILDDIRS:%/=%))
INCLUDES := $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))

# =============================================================

all: $(OUTPUT) $(BUILD) $(MAIN) run clean

$(OUTPUT):
	$(MD) $(OUTPUT)

$(BUILD):
	$(MD) $(BUILD)

$(MAIN): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)

-include $(DEPS)

$(BUILD)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -MMD $< -o $@

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	$(RM) $(call FIXPATH,$(DEPS))

run: all
	$(RUNCMD)

# =============================================================
