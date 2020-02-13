# The Return-to-libc Attack & Return-Oriented Programming

This directory contains source code and notes for the return-to-libc attack & return-oriented programming chapter.

### Required Files for the Return-to-libc Attack Lab:

These are the files that you absolutely need to complete the lab related to this chapter.

- `retlib.c` : The vulnerable program for the return-to-libc attack lab.
- `libc_exploit.py`: Create malicious `badfile`  (to attack the `retlib.c` program)

### Overview of other files in this repo::

**Small Examples**
- `shellcode.c`: A condensed version of the shellcode program _(we saw this previously)_
- `envaddr.c`: Show address of user-added environment variable
- `func_prologue_epilogue.c`: a small program for looking at function prologues/epilogues

**Return-to-libc Attack Example**

_These files are similar to the files used in the lab, **but they are different**._
_These files are primarily used for in-class demos._

- `stack.c` : The vulnerable program _(used in return-to-libc attack example)_
- `libc_exploit_stack.py`: Create malicious `badfile` (to attack the `stack.c` program)

**ROP Example**
- `stack_rop.c` : Another vulnerable program _(similar to `stack.c` with minor changes for a ROP example)_
- `chain_noarg.py` : (Example 1) Build payload that causes the vuln. program to execute a function (`bar`) multiple times _(bar takes NO ARGUMENTS)_
- `chain_witharg.py` : (Example 2) Build payload that causes the vuln. program to execute a function (`baz`) multiple times _(baz takes ONE ARGUMENT)_
- `chain_printf.py` : (Example 3) Build payload that can chain libc function calls
- `chain_attack.py` : (Example 4) Final example that builds payload to call `setuid(0)` followed by `system("/bin/sh")`.

## Non-Executable Stack (`shellcode.c`)

**Executable stack:**
```bash
gcc -o shellcode -z execstack shellcode.c
./shellcode
```
**Non-executable stack:**
```bash
gcc -o shellcode -z noexecstack shellcode.c
./shellcode
```

# Return-to-libc (`stack.c`)

**Setup**
```bash
# DISABLE ASLR!
sudo sysctl -w kernel.randomize_va_space=0
# LINK TO SHELL THAT DOESN'T DROP PRIVILEGES FOR SETUID PROGRAMS
sudo ln -sf /bin/zsh /bin/sh
# ENABLE NON-EXECUTABLE STACK
gcc -fno-stack-protector -z noexecstack -o stack stack.c
# ROOT-OWNED SETUID PROGRAM
sudo chown root stack
sudo chmod 4755 stack
```

**Task A: Find address of system()**

```bash
gdb -q stack  # -q starts gdb in quiet mode
#Reading symbols from stack...(no debugging symbols found)…done.
gdb-peda$ b main  # run the program to get libc loaded into memory
gdb-peda$ run  # run the program to get libc loaded into memory
gdb-peda$ p system
gdb-peda$ p exit
gdb-peda$ quit
```

**Task B: Find the address of the “/bin/sh” string**

```bash
export MYSHELL="/bin/sh"
gcc -o myenv envaddr.c # truncate program name to 5 letters, like "stack"
$ ./myenv
  Value:   /bin/sh
  Address: bffffef8
```

**Task C: Construct arguments for system()**

Update addresses in `libc_exploit.py` based on Tasks A and B,
and what we know about about function prologues and epilogues.
_(i.e., we need to know where on the stack we should put the argument to `system`,
  so that when we return to `system`, it will run our desired command.)_

When you think you've got the addresses/offset correct, run:

```bash
chmod +x libc_exploit.py # only need to run this if this file isn't already executable.
libc_exploit.py
./stack
```
