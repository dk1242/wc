# dkwc
Simple unix tool for reading a file and returning words, characters and lines count.

## Examples
```
➜  wc git:(main) ✗ dkwc  -w -l test.txt                                 
test.txt 58164 7145 
```
```
➜  wc git:(main) dkwc test.txt 
test.txt 7145 58164 342190
```
```
➜  wc git:(main) ✗ dkwc -w test.txt
test.txt 58164 
```