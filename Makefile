compile:
	g++ -c main.cpp
	g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLEW -lGLU
clean:
	rm main *.o
compile_test:
	g++ -c test.cpp
	g++ test.o -o test -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLEW -lGLU
link_glew:
	sudo ln -s /usr/lib64/libGLEW.so.1.12 /usr/lib/libGLEW.so.1.12