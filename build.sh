#!/bin/bash

gcc -g -o out/run src/main.c src/requestHandling.c lib/httpLibrary/out/httpLibrary.a

# x86_64-w64-mingw32-gcc -DWINDOWS=1 -o out/runW src/main.c lib/httpLibrary/out/httpLibrary.lib -lws2_32
