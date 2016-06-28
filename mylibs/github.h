#include <stdlib.h>

void push() {

  system("git add /home/edluise/.atom/srcs/cplusplus/*.cpp /home/edluise/.atom/srcs/cplusplus/mylibs/*.h");
  system("git commit -m 'Commited by github.h'");
  system("git push origin master");
  
}
