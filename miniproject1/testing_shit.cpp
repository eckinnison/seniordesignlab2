#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/file.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

void lockUnLock() {
    FILE* foil;
    FILE* fnuts;
    FILE* fcoconut;
    FILE* fchocolate;
    FILE* fsugar;
    FILE* fcorn_syrup;
    int i;


    char oil[] = "/lab/bien4290/warehouse/oil";
    /* char nuts[] = "/lab/bien4290/warehouse/nuts";
    char coconut[] = "/lab/bien4290/warehouse/coconut.txt";
    char chocolate[] = "/lab/bien4290/warehouse/chocolate.txt";
    char sugar[] = "/lab/bien4290/warehouse/sugar.txt";
    char corn_syrup[] = "/lab/bien4290/warehouse/corn_syrup.txt";

*/ 
    foil = fopen(oil, "r+");
  /*   fnuts = fopen(nuts, "r+");
    fcoconut = fopen(coconut, "r+");
    fchocolate = fopen(chocolate, "r+");
    fsugar = fopen(sugar, "r+");
    fcorn_syrup = fopen(corn_syrup, "r+");

*/ 
    printf("Location: %s\n\n", oil); 
    printf("foil: %s\n\n", foil); 

    if (foil == NULL) //fix this bc NULL 
      perror("fopen() error for HFS file");
    else {
      printf("fileno() of the HFS file is %d\n", fileno(foil));
      fclose(foil);
    }

  //   if ((fd != -1)&&(fd2 != -1)&&(fd3 != -1)&&(fd4 != -1)&&(fd5 != -1)&&(fd6 != -1)) {
  //       std::cout << "open file " << oil << std::endl;
  //       std::cout << "Please input a number to lock the file" << oil << std::endl;
  //       //scanf("%d", &i);
  //   if ((flock(fd, LOCK_EX) == 0)&&(flock(fd2, LOCK_EX) == 0)&&(flock(fd3, LOCK_EX) == 0)&&(flock(fd4, LOCK_EX) == 0)&&(flock(fd5, LOCK_EX) == 0)&&(flock(fd6, LOCK_EX) == 0)) {
  //     std::cout << "The file was locked " << std::endl;
  //   } else {
  //     std::cout << "The file was not locked " << std::endl;
  //   }


  //   std::cout << "please input a number to unlock the file " << std::endl;
  //   //scanf("%d", &i);
  //   if ((flock(fd, LOCK_UN) == 0)&&(flock(fd2, LOCK_UN) == 0)&&(flock(fd3, LOCK_UN) == 0)&&(flock(fd4, LOCK_UN) == 0)&&(flock(fd5, LOCK_UN) == 0)&&(flock(fd6, LOCK_UN) == 0)) {
  //     std::cout << "The file was unlocked. " << std::endl;
  //   } else {
  //     std::cout << "The file was no unlocked. " << std::endl;
  //   }
  //   close(fd);
  //   close(fd2);

  // } else {
  //   std::cout << "Cannot open file " << oil << std::endl;
  // }

}

int main() {
    lockUnLock();
    return 0;
}