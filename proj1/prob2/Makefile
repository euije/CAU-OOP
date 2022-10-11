CC=g++ 
OBJS=main.o io_provider.o file_manager.o student_info.o unit_test.o
TARGET=a.exe

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.cpp io_provider.h
io_provider.o: io_provider.cpp io_provider.h
file_manager.o: file_manager.cpp file_manager.h
student_info.o: student_info.cpp student_info.h
unit_test.o: unit_test.cpp unit_test.h

clean:
	rm -f $(TARGET)
	rm -f *.o