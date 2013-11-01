42-toolkit	C Getopt
==========

## Function

	- init(t_getopt *v_this, int argc, const char **argv, const char *option)
	  /* This function init t_getopt */

	- option(t_getopt *v_this)
	  /* This function return true if a new argument exists */

	- check(t_getopt *v_this, const char *option)
	  /* This function return true if option match */

	- params(t_getopt *v_this);
	  /* This function return next argument */

	- destroy(t_getopt *v_this);
	  /* This function destroy t_getopt */



## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/getopt).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).