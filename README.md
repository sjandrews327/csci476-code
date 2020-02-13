# Source code for CSCI 476 @ MSU - Computer Security

Includes some code examples from class.

Mostly adopted from **"Computer & Internet Security: A Hands-on Approach" (2nd Edition)** by Wenliang (Kevin) Du.

[https://www.handsonsecurity.net](https://www.handsonsecurity.net)

# Tips & Tricks

### Configure `gdb` to ensure it uses att syntax
```bash
# make sure default assembly syntax is att syntax. ONLY NEED TO RUN THIS ONCE!
echo 'set disassembly-flavor att' >> ~/.gdbinit
```

### Updating the Shell

On the SEED VM, `/bin/sh` is actually an alias for `/bin/dash`.
```bash
# sh is actually an alias
$ which sh
/bin/sh
$ ls -l /bin/sh
lrwxrwxrwx 1 root root 8 Jan 23 03:32 /bin/sh -> /bin/dash
```
`/bin/dash` has countermeasures against some of our exercises.
So, at times we may need to use another shell, such as `/bin/zsh`.
Here are examples of how to set/reset the shell symlinks:

```bash
$ sudo ln -sf /bin/zsh /bin/sh   # make sh symlink to zsh
$ sudo ln -sf /bin/dash /bin/sh  # sh is symlink to dash (default)
```
