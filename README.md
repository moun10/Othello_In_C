# Othello C
This is a game played by two players on the linux terminal. It will ask player 1 to pick color. 
When he does, it uses a dynamic function to determine the correct board locations 
on a 2d array. Then will tell the user if their choice is possible or
or not possible. This game automatically executes game over if either player wins. 

[![Trump2Cash](https://proxy.duckduckgo.com/iu/?u=https%3A%2F%2Fimg0.etsystatic.com%2F000%2F0%2F5976125%2Fil_fullxfull.209353316.jpg&f=1&nofb=1)](https://trump2cash.biz)

The code is written in C and is meant to run on a
Linux based machine.

The [`main`](main.c) file will execute the game itself, but placing the each piece occurs in board.c
While the headers reside in board.h

```C
// main driver of the game
int main(int argc, char *argv[])
{
	// exit if command-line arguments are not valid
	if (!isCmdLineArgsValid(argc,argv)) {
		exit(EXIT_FAILURE);
	}

	char board[SIZE][SIZE];
initializeBoard(board);
```

Follow these steps to run the code yourself:

### 1. Download GCC Compiler

```shell
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install build-essential
$ sudo apt-get install gcc
```

### 3. Check Version

```shell
$ whereis gcc make
$ gcc --version
$ make -v
```


### 3. Run the main file

```shell
$ gcc -Wall -std=c99 -o main *.c
```



## License

Copyright 2019 Harman Rai
Template GVSU
