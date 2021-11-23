#include <global.hh>
#include <unistd.h> 
void signal_handler( int signal_num ) {	
    switch (signal_num){
    case  SIGINT: //ctrl+c
        std::cout << "Detención no permitida" << std::endl;
        break;
    case SIGTSTP://ctrl+z
        std::cout << "Detención no permitida" << std::endl;
        break;
    case SIGQUIT://ctrl+"\"
        std::cout << "Detención no permitida" << std::endl;
        break;
    case SIGUSR1://kill fibonacci
        exit(EXIT_SUCCESS);
        break;
    case SIGUSR2://kill impar
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
int main(int argc, char *argv[]){
int count = 0;
pid_t pid = fork();
std::signal(SIGTSTP, signal_handler);
std::signal(SIGINT, signal_handler);
std::signal(SIGQUIT, signal_handler);
std::signal(SIGUSR1, signal_handler);
std::signal(SIGUSR2, signal_handler);
	   
while(++count) { 
    if (pid == 0){
		int n=1;
        int a=1;
        while (n<=50){
            if(a%2 != 0){
                cout<<"Valor impar:"<<a<<"- PID:"<<getpid()<<endl;
                n++;
                std::this_thread::sleep_for(500ms);
        }
        a++;
        }
	}
	else if (pid != 0){
		long int a=1, b=0, c=0;
        c = a + b;
        a = b;
        b = c;
        cout<<"Valor Fibonacci:"<<c<<" - PPIDE = "<<getpid()<<endl;
        std::this_thread::sleep_for(500ms);
        }

	if (count == 50){
			std::raise(SIGTERM);
		}
	}
return EXIT_SUCCESS;
}
