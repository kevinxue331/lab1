## UID: 123456789

## Pipe Up

Implementation of basic command pipes in Linux using C

## Building

To build 
``` sh
make
```

## Running

Ex.
``` sh
./pipe ls cat wc
```
should return the same output as 
``` sh
ls | cat | wc
```

## Cleaning up

To remove all binary and executables 
``` sh 
make clean 
```
