#include <stdio.h>
#include <pthread.h>

void *output(void *thread_name) {
    char *name = (char *)thread_name;
    for(int i = 0; i < 5; i++) {
        printf("%s: %d\n", name, i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    printf("Launching threads\n");

    pthread_create(&thread1, NULL, output, "thread 1");
    pthread_create(&thread2, NULL, output, "thread 2");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Threads complete!\n");
    return 0;
}
