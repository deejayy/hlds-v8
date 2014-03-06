#!/bin/bash

mkdir out
rm out/hldsv8_i386.so
rm out/*.o

for f in *.cpp; do
g++ \
	${f} \
	-c \
	-m32 \
	-I../metamod/ \
	-I../../hlsdk/multiplayer/dlls/ \
	-I../../hlsdk/multiplayer/common/ \
	-I../../hlsdk/multiplayer/engine/ \
	-I../../v8/include/ \
	-o out/${f/cpp/}o \
	-Wno-write-strings \
2>&1 || exit
done

ld out/*.o -melf_i386 -lv8 -ldl -lpthread -lrt -shared -o out/hldsv8_i386.so

echo -e "\n\n"

ls -la out/hldsv8_i386.so

echo -e "\n\n"
