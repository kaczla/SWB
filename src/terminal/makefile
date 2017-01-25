CC=gcc
CFLAGS=-o2 -c -Wall -fPIC
OBJDIR=./obj/
LIBDIR=./lib/
NAME_FILES=terminal
OBJ_FILES=$(addprefix $(OBJDIR), $(addsuffix .o, $(NAME_FILES)))
LIB_NAME=$(LIBDIR)libterminal.so
LIB_DESTINATION=../../lib/libterminal.so

ifeq ($(MAKECMDGOALS),arm)
-include ../../makefile.mk
endif

all: build install

arm: all

build: $(OBJ_FILES) $(LIB_NAME)

$(OBJDIR)%.o: %.c %.h | $(OBJDIR)
	$(CC) $(CFLAGS) $< -o $@

$(LIB_NAME): $(OBJ_FILES) | $(LIBDIR)
	$(CC) -shared -o $(LIB_NAME) $^

install:
	cp $(LIB_NAME) $(LIB_DESTINATION)

$(LIBDIR):
	@mkdir -p $(LIBDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

.PHONY:clean
clean:
	rm -f $(OBJDIR)*.o $(LIBDIR)*
