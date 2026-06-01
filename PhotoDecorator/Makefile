editor_exe : add_frame.o add_sticker.o apply_filter.o main.o make_sticker.o process_png_file.o read_png_file.o write_png_file.o write_cutted_png_file.o
	        g++ add_frame.o add_sticker.o apply_filter.o main.o make_sticker.o process_png_file.o read_png_file.o write_png_file.o write_cutted_png_file.o -o editor_exe -lpng

add_frame.o : add_frame.cpp editor.hpp
	        g++ -c add_frame.cpp -lpng

add_sticker.o : add_sticker.cpp editor.hpp
	        g++ -c add_sticker.cpp -lpng

apply_filter.o : apply_filter.cpp editor.hpp
	        g++ -c apply_filter.cpp -lpng

main.o : main.cpp editor.hpp editor.hpp
	        g++ -c main.cpp -lpng

make_sticker.o : make_sticker.cpp editor.hpp
	        g++ -c make_sticker.cpp -lpng

process_png_file.o : process_png_file.cpp editor.hpp
	        g++ -c process_png_file.cpp -lpng

read_png_file.o : read_png_file.cpp editor.hpp
	        g++ -c read_png_file.cpp -lpng

write_png_file.o : write_png_file.cpp editor.hpp
	        g++ -c write_png_file.cpp -lpng

write_cutted_png_file.o : write_cutted_png_file.cpp editor.hpp
	        g++ -c write_cutted_png_file.cpp -lpng

clean :
	        rm *.o main.out
