INC = -I /usr/include/x86_64-linux-gnu/qt6
LIB = -L /usr/lib/x86_64-linux-gnu
LFLAGS = -l Qt6Core -l Qt6Widgets



a:
	/usr/lib/qt6/libexec/moc widgets.h > moc_widgets.cc
	g++ main.cc -c $(INC)
	g++ moc_widgets.cc -c $(INC)
	g++ main.o moc_widgets.o $(LFLAGS)
	./a.out
