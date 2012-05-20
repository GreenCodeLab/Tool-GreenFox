gcc -c greenfox.c

gcc -shared -o greenfox.dll greenfox.o -Wl,-e_DllMain@12
