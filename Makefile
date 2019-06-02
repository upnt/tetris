CC := g++
CFLAGS := -O2
LDLIBS := -lncurses

mineSweeper: mineSweeper.o Bourd.o Panel.o GameMode.o

Bourd.o: Bourd.hpp
Panel.o: Panel.hpp
GameMode.o: GameMode.hpp


clean:
	$(RM) *.o
	$(RM) *.hpp.gch
	$(RM) mineSweeper
