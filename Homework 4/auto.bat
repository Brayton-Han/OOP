g++ nsvector.cpp nstest.cpp stopwatch.cpp split.cpp -O0 -o nsvector
g++ nsmap.cpp nstest.cpp stopwatch.cpp split.cpp -O0 -o nsmap
g++ nsumap.cpp nstest.cpp stopwatch.cpp split.cpp -O0 -o nsumap
nsvector < ns40k.txt 1>NUL
nsmap    < ns40k.txt 1>NUL
nsumap   < ns40k.txt 1>NUL