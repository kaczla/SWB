CC=gcc
CFLAGS=-o2 -c -Wall
CFLAGS_OUT=-o2 -Wall
LDFLAGS=-lcommand -lterminal
SRCDIR=./src/
OBJDIR=./obj/
LIBDIR=./lib/
BINDIR=./bin/
OUTDIR=./out/
LD_PATH=-L$(LIBDIR)
NAME_FILES=update print sort_string_list files
NAME_MAIN_FILE=$(SRCDIR)main.c
OBJ_FILES=$(addprefix $(OBJDIR), $(addsuffix .o, $(NAME_FILES)))
LIB_STATIC_NAME=$(LIBDIR)libcommand.a
LIB_DYNAMIC_NAME=$(LIBDIR)libterminal.so
MAIN_NAME=main.app
SUPPORT_UNICODE=0
SUPPORT_UNICODE_SHELL=$(shell echo $(LANG) | grep -i 'UTF-8\|UTF-16\|UTF-32')

all: prebuild build install

install: $(OUTDIR)$(MAIN_NAME)

$(OUTDIR)$(MAIN_NAME): $(BINDIR)$(MAIN_NAME) | $(OUTDIR)
	@echo ""
	cp $^ $@
	@chmod u+x $@

prebuild:
ifeq ($(SUPPORT_UNICODE_SHELL),)
SUPPORT_UNICODE=0
else
SUPPORT_UNICODE=1
endif

build: $(OBJ_FILES) $(NAME_MAIN_FILE) | $(BINDIR) $(LIB_STATIC_NAME) $(LIB_DYNAMIC_NAME)
	$(CC) $(LD_PATH) $(CFLAGS_OUT) $^ -o $(BINDIR)$(MAIN_NAME) $(LDFLAGS)

$(LIB_STATIC_NAME): lib_static | $(LIBDIR)

lib_static: | $(LIBDIR)
	@echo ""
	@$(MAKE) -C $(SRCDIR)command
	@echo ""

$(LIB_DYNAMIC_NAME): lib_dynamic | $(LIBDIR)

lib_dynamic: | $(LIBDIR)
	@$(MAKE) -C $(SRCDIR)terminal
	@echo ""

$(OBJDIR)%.o: $(SRCDIR)%.c $(SRCDIR)%.h | $(OBJDIR)
ifeq ($(SUPPORT_UNICODE), 1)
	$(CC) $(CFLAGS) -D SUPPORT_UNICODE $< -o $@
else
	$(CC) $(CFLAGS) $< -o $@
endif

$(LIBDIR):
	@mkdir -p $(LIBDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(OUTDIR):
	@mkdir -p $(OUTDIR)

.PHONY:clean
clean:
	@$(MAKE) clean -C $(SRCDIR)command
	@echo ""
	@$(MAKE) clean -C $(SRCDIR)terminal
	@echo ""
	rm -f $(OBJDIR)*.o $(BINDIR)* $(OUTDIR)* $(LIBDIR)*
