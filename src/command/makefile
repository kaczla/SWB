CC=gcc
CFLAGS=-o2 -c -Wall
OBJDIR=./obj/
LIBDIR=./lib/
NAME_FILES=command
OBJ_FILES=$(addprefix $(OBJDIR), $(addsuffix .o, $(NAME_FILES)))
LIB_NAME=$(LIBDIR)libcommand.a
LIB_DESTINATION=../../lib/libcommand.a

all: build install

build: $(OBJ_FILES) $(LIB_NAME)

$(OBJDIR)%.o: %.c %.h | $(OBJDIR)
	$(CC) $(CFLAGS) $< -o $@

$(LIB_NAME): $(OBJ_FILES) | $(LIBDIR)
	ar rvs $@ $^

install:
	cp $(LIB_NAME) $(LIB_DESTINATION)

$(LIBDIR):
	@mkdir -p $(LIBDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

.PHONY:clean
clean:
	rm -f $(OBJDIR)*.o $(LIBDIR)*
	
