OBJECTS=obj/main.o obj/handlers.o obj/count.o obj/buffer.o obj/random.o
PKG_CONFIG=`pkg-config --cflags --libs gtk+-3.0`

GCC=gcc
LVLDB=-g3

BIN_NAME=rcnv
SRCDIR=src
OBJDIR=obj

$(BIN_NAME): $(OBJECTS)
	$(GCC) $(LVLDB) $(PKG_CONFIG) -o $(BIN_NAME) $(OBJECTS)

$(OBJDIR)/main.o: $(SRCDIR)/main.c
	$(GCC) $(LVLDB) -c $(SRCDIR)/main.c -o $(OBJDIR)/main.o $(PKG_CONFIG)

$(OBJDIR)/handlers.o: $(SRCDIR)/handlers.c
	$(GCC) $(LVLDB) -c $(SRCDIR)/handlers.c -o $(OBJDIR)/handlers.o $(PKG_CONFIG)

$(OBJDIR)/count.o: $(SRCDIR)/count.c
	$(GCC) $(LVLDB) -c $(SRCDIR)/count.c -o $(OBJDIR)/count.o $(PKG_CONFIG)

$(OBJDIR)/buffer.o: $(SRCDIR)/buffer.c
	$(GCC) $(LVLDB) -c $(SRCDIR)/buffer.c -o $(OBJDIR)/buffer.o $(PKG_CONFIG)

$(OBJDIR)/random.o: $(SRCDIR)/random.c
	$(GCC) $(LVLDB) -c $(SRCDIR)/random.c -o $(OBJDIR)/random.o $(PKG_CONFIG)

install:
	install $(BIN_NAME) /usr/local/bin/

uninstall:
	rm -rf /usr/local/bin/$(BIN_NAME)

clean:
	rm -rf $(OBJDIR)/*.o
