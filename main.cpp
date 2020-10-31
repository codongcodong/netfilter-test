#include <cstdio>
#include <string>
#include <stdlib.h>
#include <signal.h>
#include "simpleNetfilter.h"

using namespace std;

const string* target;

void usage(void){
    puts("syntax : netfilter-test <host>");
    puts("sample : netfilter-test test.gilgil.net");
}

void sigintHandler(int sig){
	puts("Restoring Iptable rules");
	system("sudo netfilter-persistent reload");
	puts("Terminating Firewall\n");
	exit(0);
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        usage();
        return -1;
    }

    target = new string(argv[1]);               //target host
    struct sigaction sigintAction;		//signal handler for program termination
    
    sigemptyset(&sigintAction.sa_mask);
	sigintAction.sa_flags = 0;
	sigintAction.sa_handler = sigintHandler;
	sigaction(SIGINT,&sigintAction,0);
    
    system("./setRules.sh");                     //setting up iptable rules to use NFQUEUE

    filterPackets();
}
