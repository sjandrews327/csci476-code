# Shellshock Attack

There is no source code in this chapter. 

Some snippets below:

```
#!/bin/bash_shellshock

echo "Content-type: text/plain"
echo 
echo "*** Environment Variables ***"
strings /proc/$$/environ
```
