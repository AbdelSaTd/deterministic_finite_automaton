CC=gcc
CFLAGS=-I -Wall
CDEBUGFLAGS=-I -Wall -g
ODIR=obj
BDIR=build
TDIR=tst
SDIR=src

all: test_autom test_graph test_queue
clean:
	rm -f $(ODIR)/*.o


test_autom: obj/test_autom.o obj/autom.o obj/graph.o
	$(CC) -o build/test_autom obj/test_autom.o obj/autom.o obj/graph.o $(CFLAGS)

obj/autom.o: src/autom.h
	$(CC) -o obj/autom.o -c $(SDIR)/autom.c $(CFLAGS)

obj/test_autom.o: tst/test_autom.c src/autom.h
	$(CC) -o obj/test_autom.o -c $(TDIR)/test_autom.c $(CFLAGS)






test_graph: obj/test_graph.o obj/graph.o
	$(CC) -o build/test_graph obj/test_graph.o obj/graph.o $(CDEBUGFLAGS)

obj/graph.o: src/graph.c
	$(CC) -o obj/graph.o -c src/graph.c $(CDEBUGFLAGS)

obj/test_graph.o: tst/test_graph.c src/graph.h
	$(CC) -o obj/test_graph.o -c $(TDIR)/test_graph.c $(CDEBUGFLAGS)





##
test_queue: $(ODIR)/test_queue.o $(ODIR)/queue.o
	$(CC) -o build/test_queue obj/test_queue.o obj/queue.o $(CDEBUGFLAGS)

$(ODIR)/queue.o: src/queue.c
	$(CC) -o obj/queue.o -c src/queue.c $(CDEBUGFLAGS)

$(ODIR)/test_queue.o: tst/test_queue.c src/queue.h
	$(CC) -o obj/test_queue.o -c tst/test_queue.c $(CDEBUGFLAGS)

