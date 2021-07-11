# memoryhog
its a (hopefully portable) program that takes a lot of memory

it keeps the memory for itself until you ~~tell him to stop (press enter) or~~ kill it

## how to compile :
```
$ cc main.c -o memoryhog
```
some flags can be added for optimisation
```
$ cc main.c -o memoryhog -O3 -s
```

## how to use :
i want to waste 3.5GB of ram

either :
```
$ ./memoryhog 3.5G
```
or
```
$ ./memoryhog
how much memory can i eat ?
3.5G
```
you can put any value that machine supports

supported suffixes : k,M,G,T,P,E (1000) / ki,Mi,Gi,Ti,Pi,Ei (1024)

decimal commas and points are also supported
