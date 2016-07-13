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
if [ ! -d glm ]
then
	git clone https://github.com/g-truc/glm.git
	cd glm
	cd ..
fi
cd ..
