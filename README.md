Sandbox to play aroud w/ Catch23

For now, do

```g++ -std=c++20 factorial.cpp lib/libCatch2.a lib/libCatch2Main.a -o test.exe && ./test.exe --success``` 

or 

```
# Configure
cmake -S . -B build

# Build app & tests
cmake --build build

# Run the app
./build/my_app

# Run tests via ctest (recommended)
ctest --test-dir build --output-on-failure

# Or run the test binary directly
./build/tests

```
