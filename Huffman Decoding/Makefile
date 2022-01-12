#Tony Le, hnl7vwd, 11/22/2021, makefile

CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g
OBJECTS = heap.o heapnode.o huffmandec.o 
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~ a.out