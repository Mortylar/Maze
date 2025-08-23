CC=g++
INC = -I /usr/include/x86_64-linux-gnu/qt6
LIB = -L /usr/lib/x86_64-linux-gnu
LFLAGS = -l Qt6Core -l Qt6Widgets -lQt6Gui
MOC=/usr/lib/qt6/libexec/moc




a:
	$(MOC) widgets.h > moc_widgets.cc
	$(MOC) main_window.h > moc_main_window.cc
	g++ main.cc -c $(INC)
	g++ moc_widgets.cc moc_main_window.cc -c $(INC)
	g++ main.o moc_widgets.o moc_main_window.o $(LFLAGS)
	./a.out

aa:
	echo $(CC)

clean:
	-rm moc_widgets.cc moc_main_window.cc
	-rm a.out *.o

