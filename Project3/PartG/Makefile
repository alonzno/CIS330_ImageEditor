SRC=main3G.C image.C sink.C source.C PNMreader.C PNMwriter.C filter.C logging.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ $(OBJ) -o proj3G

tmp: $(OBJ) tmpMain.o
	g++ tmpMain.o image.o sink.o source.o PNMreader.o PNMwriter.o filter.o logging.o -o tmp3G

blur: $(OBJ) main3G_blur.o
	g++ main3G_blur.o image.o sink.o source.o PNMreader.o PNMwriter.o filter.o logging.o -o tmp3G

main3G_blur.o: main3G_blur.C
	g++ -g -I. -c main3G_blur.C

grayscale: $(OBJ) main3G_grayscale.o
	g++ main3G_grayscale.o image.o sink.o source.o PNMreader.o PNMwriter.o filter.o logging.o -o tmp3G

main3G_grayscale.o: main3G_grayscale.C
	g++ -g -I. -c main3G_grayscale.C

mirror: $(OBJ) main3G_mirror.o
	g++ main3G_mirror.o image.o sink.o source.o PNMreader.o PNMwriter.o filter.o logging.o -o tmp3G

main3G_mirror.o: main3G_mirror.C
	g++ -g -I. -c main3G_mirror.C

rotate: $(OBJ) main3G_rotate.o
	g++ main3G_rotate.o image.o sink.o source.o PNMreader.o PNMwriter.o filter.o logging.o -o tmp3G

main3G_rotate.o: main3G_rotate.C
	g++ -g -I. -c main3G_rotate.C

subtract: $(OBJ) main3G_subtract.o
	g++ main3G_subtract.o image.o sink.o source.o PNMreader.o PNMwriter.o filter.o logging.o -o tmp3G

main3G_subtract.o: main3G_subtract.C
	g++ -g -I. -c main3G_subtract.C

.C.o: $<
	g++  -g -I. -c $<

clean:
	rm *.o proj3G
