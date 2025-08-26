CC=g++ -std=c++17
INC=-I /usr/include/x86_64-linux-gnu/qt6
LIB=-L /usr/lib/x86_64-linux-gnu
LFLAGS=-l Qt6Core -l Qt6Widgets -l Qt6Gui
TARGET=Maze

libs:
	cd model && make libmodel.a
moc:
	cd view && make moc

maze: libs moc
	$(CC) -c main.cc view/*.cc $(INC)
	$(CC) -o $(TARGET) *.o $(LIB) $(LFLAGS)

clean:
	-rm *.o	
