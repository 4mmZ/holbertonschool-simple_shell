# Project Simple Shell #

## Description ##

The way our shell works:

Receives an input that is tokenized. The beginning of the program stores memory for pointers of the type "char", arguments are passed that are reallocated in each iteration of the main function that is executed in a loop and in this way we make sure that we do not run out of memory.
$PATH is already connected to the path that contains each node, each tokenized argument in the main function.
We clone the execution syntax with "fork" where it is evaluated in which process the program is being executed.
## File Description ##

* functions.c - Functions that are used, get_env gets environment variable value, _path gets path, get_command gets assigned command, execute executes a thread.
* main.h - file that contains the standar libraries and prototypes.
* shell.c - function that initializes the command interpreter (shell).
* morefunction.c & prohibitedfunction.c - prohibited functions that are not accessible and some function that is used to facilitates the proccess.
* man_1_simple_shell - manual of out shell.

## Requirements ##

* Allowed editors: vi, vim, emacs.
* A README.md file, at the root of the folder of the project is mandatory.
* All files must be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All files must end with a new line.
* No more than 5 functions per file.
* All the code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

## Compilation ##
* Your shell will be compiled this way:
	`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Flowchart ##
	<div id="1E2D7B0DD9E993B8ECFA37DD4ACD23D478A_3164"><div id="1E2D7B0DD9E993B8ECFA37DD4ACD23D478A_3164_robot"><a href="https://cloud.smartdraw.com/share.aspx/?pubDocShare=1E2D7B0DD9E993B8ECFA37DD4ACD23D478A" target="_blank"><img src="https://cloud.smartdraw.com/cloudstorage/1E2D7B0DD9E993B8ECFA37DD4ACD23D478A/preview2.png"></a></div></div><script src="https://cloud.smartdraw.com/plugins/html/js/sdjswidget_html.js" type="text/javascript"></script><script type="text/javascript">SDJS_Widget("1E2D7B0DD9E993B8ECFA37DD4ACD23D478A",3164,1,"");</script><br/>

## Authors

* Andrés Maciel
[@4mmZ](https://github.com/4mmZ)
* Neo Dau
[@NeoDau](https://github.com/NeoDau)
