mkdir build && cd build
cmake ..
cmake --build .
cmake --install .
cd ..
./results/bin/create_web_site  > web_app/test.html
see web_app/test.html
