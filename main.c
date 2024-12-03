// main.c
#include "ui.h"
#include <unistd.h>
void usage(char* s)
{
	fprintf(stderr, "USAGE: %s [flags]\n\t-h\t-- help\n\t-m avl\t-- AVL mode\n\t-e\t-- echo input\n",s);
}
int main(int argc, char** argv)
{
	int opt;
  	bool echo = false;
	char mode;
	while ((opt = getopt(argc, argv, "hem:")) != -1) {
		switch (opt) {
		case 'e':
			echo = true;
			break;
		case 'm':
			mode = optarg[0];
			break;
		default:
			usage(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	run(mode,echo);
	exit(EXIT_SUCCESS);
}
