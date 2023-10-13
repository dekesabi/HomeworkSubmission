mkdir build
cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
make
./demo
cd ..
mkdir bin
cp ./build/demo ./bin
# optional
rm -rf build
