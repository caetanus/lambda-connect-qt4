Project and example of use of c++lambda (*c++11*/*c++0x*) as a slot receiver of connect in qt4

to use it, include lambda-connect/lambdaconnect.h
example:
```cpp
#include "lambdaconnect.h"

...

connect(&myButton, SIGNAL(clicked()),
                          [](){
                              QMessageBox::information(NULL, "", "button was clicked");
                          });
...

```

there is an example code into the repository.
