#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
  pid_t pid;
  char input[1024];

  while (1) {
    printf("Enter programs to run.\n");
    printf("> ");
    fflush(stdout);

    if (fgets(input, 1024, stdin) == NULL) {
      break;
    }

    input[strcspn(input, "\n")] = '\0';
    pid = fork();
    switch (pid) {
    case -1:
      perror("fork");
      exit(1);
      break;
    case 0:
      if (execl(input, input, (char *)NULL) == -1) {
        perror("Exec failure");
        exit(1);
      }
      break;

    default:
      waitpid(pid, NULL, 0);
      printf("\n");
      break;
    }
  }
  return 0;
}
