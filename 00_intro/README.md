## Some Basics...

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

- https://linuxacademy.com/guide/12659-understanding-linux-users-and-groups/
- https://www.cyberciti.biz/tips/understanding-linux-unix-umask-value-usage.html
- https://devconnected.com/linux-file-permissions-complete-guide/ 

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