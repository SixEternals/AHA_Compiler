#!/bin/bash
xmake
xmake build
xmake project -k compile_commands ./build 
xmake config -m debug
echo "[TEST] Compiling add.sy..."
# xmake run aha -- -S -o add.s ../../../../test/add.sy 
# (cd $(pwd) && xmake run aha -- -S -o add.s test/add.sy)

# xmake run -d aha -- -S -o add.s $(pwd)/test/add.sy
xmake run aha -- -S -o add.s $(pwd)/test/add.sy

# ./build/linux/x86_64/release/aha -S -o add.s test/add.sy

# xmake run aha --cwd=. -S -o add.s test/add.sy