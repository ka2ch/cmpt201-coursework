#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LEN 1024

int main(void) {
  pid_t pid;
  char input[MAX_LEN];

  printf("Enter programs to run.\n");

  while (1) {
    printf("> ");
    fflush(stdout);

    if (fgets(input, MAX_LEN, stdin) == NULL) {
      break;
    }

    input[strcspn(input, "\n")] = '\0';
    pid = fork();

    switch (pid) {
    case -1:
      perror("fork");
      exit(1);

    case 0:
      execl(input, input, (char *)NULL);
      perror("Exec failure");
      exit(1);

    default:
      waitpid(pid, NULL, 0);
    }
  }

  return 0;
}
