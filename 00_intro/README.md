## Examples

See the subdirectories here for a few helpful intro examples:
- `makefiles/` - simple and advanced example of Makefiles
- `pba/` - simple code that helps you explore the compilation process
- `probe` - simple code to explore the address space of a running process

## Some Command Line Basics

```bash
cd
ls
pwd
mkdir
touch
mv
vim FILENAME
env
echo ($?, $$, $PATH)
make
gcc
```

## File Ops, Users, and Groups

- [Linux File Permissions Complete Guide](https://devconnected.com/linux-file-permissions-complete-guide/)
- [What is Umask and How To Setup Default umask Under Linux?](https://www.cyberciti.biz/tips/understanding-linux-unix-umask-value-usage.html)

```bash
# a basic example with files, permissions, and identity
mkdir ~/my_sandbox
cd my_sandbox
ls -al
touch myprecious.txt
ls -al
chmod 644 myprecious.txt
ls -al
chmod 600 myprecious.txt

whoami # find your user identity on the system
id [SOMEUSER] # to see details about the user (default is current user)
chown
chgrp

# a basic user/group demo
cat /etc/passwd
sudo useradd -c 'John from Accounts' -m -s /bin/bash john
sudo passwd john
(usermod)
su john #enter password
id
cd
touch johns_secrets.txt
chmod 600
su vagrant
cat /home/john/
sudo userdel --force --remove john

# group = a collection of users; groups make it easier to manage permissions.
cat /etc/group # see all system groups
groupadd
(groupmod)
groupdel

# misc
sudo chgroup root myid
cat /etc/passwd
umask # setting default permissions for creating new files/directories
```
