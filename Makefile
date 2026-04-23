# Specifies the GNU C compiler
CC = gcc
# Defines the name of the final executable file to be created
TARGET = student_mark
# Tool for static analysis
CPPCHECK = cppcheck
# Finds all .c source files in the current directory and all subdirectories
SRCS = main.c\
	student/src/student.c\
	student/src/menu.c 
# Finds all subdirectories, adds them as include paths
INCLUDES = -Istudent/Inc -I.
# Sets compiler flags: enable all warnings (-Wall), include debug info (-g), 
# add include paths.
# Cppcheck flags: enable all checks and exit with error if bugs found 
CHECKFLAGS = --enable=all --suppress=missingIncludeSystem --error-exitcode=1 \
	$(INCLUDES)
CFLAGS = -Wall -g $(INCLUDES)
# Creates list of object files 
OBJS = $(SRCS: .c=.o)
 # The default rule that tells Make to build the final target executable.
all: $(TARGET)
# Link all compiled object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
# rule telling to compile any .c file into its corresponding .o object file.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# Static Analysis
check:
	$(CPPCHECK) $(CHECKFLAGS) $(SRCS)