const unsigned int width = 600;
const unsigned int height = 600;
unsigned int BUFFER[width*height];

void go() {
    for(int i = 0; i < width; ++i){
        for(int j = 0; j < height; ++j){
            BUFFER[width * i + j] = 0xffff0000;
        }
    }
}

// clang --target=wasm32 -O2 -nostdlib -Wl,--no-entry -Wl,--export-all -o example.wasm wasm.c

// clang --target=wasm32 -O3 -flto -nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--lto-O3 -Wl,-z,stack-size=$[8 * 1024 * 1024] -o add.wasm wasm.cpp