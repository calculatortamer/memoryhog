# memoryhog
its a (hopefully portable) program that takes a lot of memory

it keeps the memory for itself until you tell him to stop (press enter) or kill it

## how to compile :
```
$ cc main.c -o memoryhog
```

## how to use :
i want to waste 4GB of ram

either :
```
$ ./memoryhog 4G
```
or
```
$ ./memoryhog
how much memory can i eat ?
4G
```
you can put any value that machine supports

supported suffixes : k,M,G,T,P,E (1000) / ki,Mi,Gi,Ti,Pi,Ei (1024)
