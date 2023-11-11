# Comiler + Flags
GPP = g++
GCC = gcc
GPPFLAGS = -Wall

# Source files
SOURCE = generator.c generatorapp.c count.c

# Object files (a '.o' for every '.c')
OBJS = $(SOURCE:.c=.o)

# Targets
all: generatorapp count

# Generate 'generatorapp' using object files
generatorapp: generator.o generatorapp.o
	$(GPP) $(GPPFLAGS) $^ -o $@

# Generate 'count' using 'count.o'
count: count.o
	$(GCC) $^ -o $@

# Make object files for each source file
%.o: %.c
	$(GPP) $(GPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) generator

.PHONY: all clean 
