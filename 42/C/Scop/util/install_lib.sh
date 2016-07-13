cd lib
if [ ! -d glfw ]
then
	git clone https://github.com/glfw/glfw.git
	cd glfw
	# cmake . -DCMAKE_INSTALL_PREFIX= ./
	cmake .
	make
fi
cd ..
