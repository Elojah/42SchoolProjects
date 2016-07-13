cd lib
if [ ! -d fltk-1.3.3 ]
then
	tar -xf fltk-1.3.3-source.tar.gz
	cd fltk-1.3.3
	./configure
	make
fi
