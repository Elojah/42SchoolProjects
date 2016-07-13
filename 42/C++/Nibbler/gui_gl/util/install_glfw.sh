cd lib
make -C LoadShaders
if [ ! -d glfw ]
then
	git clone https://github.com/glfw/glfw.git
	cd glfw
	mkdir build
	cmake .
	make
	cd ..
fi
