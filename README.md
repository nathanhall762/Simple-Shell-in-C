# [<center>0x17. C - Simple Shell - 1142</center>](https://intranet.hbtn.io/projects/1142)
 ---
 ### <center>Description</center>
 ##### &emsp; The purpose of this project is to better understand the functionality of a shell and create our own simple shell program. The simple shell can execute linux commands from the environment and built-in functions within the program in both interactive and non-interactive modes.
### Compilation:
The repository is designed to be compiled into one program with the following command:
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
### Interactive Mode:
The simple shell can be initiated in interactive mode:
```sh
./hsh
$
```
Users can enter commands with arguments in the command line following the "$" prompt:
```sh
$ ls /usr/
bin games include lib lib32 lib64 libexec libx32 local sbin share src
```
### Non-Interactive Mode
The simple shell can also be initiated in non-interactive mode:
```sh
echo "ls /usr/" | ./hsh
$ bin games include lib lib32 lib64 libexec libx32 local sbin share src
```

 ---
 [<center>Nathan Hall & Buzz Kleine</center>](github.com/conkobar)
