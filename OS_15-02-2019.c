/*
<<<<<<< HEAD
Usando il servizio inotify(7) scrivere il programma doandelete.
Questo programma viene attivato con un unico parametro che deve essere una directory vuota(controllare la coerenza del parametro!).
=======
Usando il servizio inotify(7) scrivere il programma do and elete.
Questo programma viene attivato con un unico parametro che deve essere una directory vuota (controllare la coerenza del parametro!).
>>>>>>> 4058184c7057c5cdd87737a4049ec4001ab35880
Quando viene aggiunto un file alla directory questo viene eseguito e cancellato.
*/
#include <sys/inotify.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

<<<<<<< HEAD
int isDirectoryEmpty(char *dirname) {
=======
int isDirectoryEmpty(char *dirname)
{
>>>>>>> 4058184c7057c5cdd87737a4049ec4001ab35880
  int n = 0;
  struct dirent *d;
  DIR *dir = opendir(dirname);
  if (dir == NULL) //Not a directory or doesn't exist
    return 1;
<<<<<<< HEAD
  while ((d = readdir(dir)) != NULL) {
    if(++n > 2)
=======
  while ((d = readdir(dir)) != NULL)
  {
    if (++n > 2)
>>>>>>> 4058184c7057c5cdd87737a4049ec4001ab35880
      break;
  }
  closedir(dir);
  if (n <= 2) //Directory Empty
    return 1;
  else
    return 0;
}

<<<<<<< HEAD
int main(int argc, char * argv[]){


    if(!isDirectoryEmpty(argv[1])){
        printf("directory not empty!\n");
        return 1;
    }
    const int event_size = sizeof(struct inotify_event);
    const int buf_len = 1024 * (event_size + FILENAME_MAX);
    int eventcount, count = 0;
    char buff[buf_len];
    char command[100];
    char commandbase[20];
    strcpy(commandbase, argv[1]);
    strcat(commandbase, "/");
    int Inotify = inotify_init();
    inotify_add_watch(Inotify, argv[1], IN_CREATE);
    struct inotify_event *event;
    while(1){
        eventcount = read( Inotify, buff, buf_len);
        event = (struct inotify_event *)&buff[count];
        if(event ->mask & IN_CREATE){
            printf("executing new file %s!\n", event->name);
            strcpy(command, commandbase);
            strcat(command, event->name);
            system(command);
            if(remove(command))
                return 1;
 
        }
    }

    return 0;
}

=======
int main(int argc, char *argv[])
{

  if (!isDirectoryEmpty(argv[1]))
  {
    printf("directory not empty!\n");
    return 1;
  }
  const int event_size = sizeof(struct inotify_event);
  const int buf_len = 1024 * (event_size + FILENAME_MAX);
  int eventcount, count = 0;
  struct inotify_event *event;
  char buff[buf_len];

  char command[100];
  char commandbase[20];

  strcpy(commandbase, argv[1]);
  strcat(commandbase, "/");

  int Inotify = inotify_init();
  inotify_add_watch(Inotify, argv[1], IN_CREATE);
  while (1)
  {
    eventcount = read(Inotify, buff, buf_len);
    event = (struct inotify_event *)&buff[count];
    if (event->mask & IN_CREATE)
    {
      printf("executing new file %s!\n", event->name);
      strcpy(command, commandbase);
      strcat(command, event->name);
      system(command);
      if (remove(command))
        return 1;
    }
  }

  return 0;
}
>>>>>>> 4058184c7057c5cdd87737a4049ec4001ab35880
