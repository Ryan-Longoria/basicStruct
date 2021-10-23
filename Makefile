# Define the machine object files for your program
OBJECTS = basicStruct.o
# Define your include file
INCLUDES = basicStruct.h

# make for the executable
sampleProject: ${OBJECTS}
	gcc -g -o basicStruct ${OBJECTS}

# Simple suffix rules for the .o
%.o: %.c ${INCLUDES}
	gcc -g -c $<

# Clean the .o files
clean:
	rm -f ${OBJECTS}
