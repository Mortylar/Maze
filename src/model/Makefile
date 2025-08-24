CC=g++ -std=c++17
SOURCE=model.cc
LIB_TARGET=libmodel.a

libmodel.a:
	$(CC) -c $(SOURCE)
	ar rcs $(LIB_TARGET) *.o
	ranlib $(LIB_TARGET)

clean:
	-rm *.o


