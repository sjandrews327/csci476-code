# Source code for CSCI 476 @ MSU - Computer Security 

Includes some code examples from class. 

Mostly adopted from **"Computer & Internet Security: A Hands-on Approach" (2nd Edition)** by Wenliang (Kevin) Du.

[https://www.handsonsecurity.net](https://www.handsonsecurity.net)

## A Note About Updating the Shell

```bash
# sh is actually an alias
$ which sh
/bin/sh
$ ls -l /bin/sh
lrwxrwxrwx 1 root root 8 Jan 23 03:32 /bin/sh -> /bin/dash

# /bin/dash has countermeasures against some of our exercises. 
# we can instead link to /bin/zsh. 
# here are examples of how to set/reset the symlinks:

$ sudo ln -sf /bin/zsh /bin/sh   # make sh symlink to zsh
$ sudo ln -sf /bin/dash /bin/sh  # sh is symlink to dash (default)
```
