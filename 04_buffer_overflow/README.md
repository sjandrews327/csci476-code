# Source code and notes for the buffer overflow attack chapter

**Overview**
* `stack.c` : The vulnerable program
* `exploit.py`: Create malicious badfile
* `defeat_rand.sh`: Defeat the address randomization countermeasure
* `revised_shellcode.py`: The revised shellcode that defeats the countermeasure in bash and dash.

## ...

Disable Address Randomization.
(We discuss how to defeat this countermeasures later.)
```bash
$ sudo sysctl -w kernel.randomize_va_space=0
```

Compile `stack.c` with compiler-based countermeasures.
(We discuss how to defeat these countermeasures later.)
```bash
$ gcc -o stack -z execstack -fno-stack-protector stack.c
$ sudo chown root stack
$ sudo chmod 4755 stack
# NOTE: must "chown" then "chmod" (chown resets the setuid bit)
```

**Create a _Dummy_ "Bad File"** _(to verify that this program has a buffer overflow vulnerability.)_

... with less than 100 characters:
```bash
$ echo "aaaa" > badfile
$ ./stack
Returned Properly
```
... with more than 100 characters:
```bash
$ echo "aaaa ...(100+ characters omitted)... aaa" > badfile
$ ./stack
Segmentation fault (core dumped)
```
**Create a _Real_ "Bad File"...** _(to demonstrate how we can exploit this buffer overflow vulnerability.)_

See `exploit.py` & Section 4.5 (pgs. 73-79), which offers a helpful narrative around what we need and why.

In short, this file generates a bad file that...
- Crafts and injects shellcode
- Injects a return address that jumps to the shellcode
- Injects a series of No-Op (`NOP`) instructions (i.e., adds many potential entry points to our injected shellcode)
