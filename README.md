This project has been created as part of the 42 curriculum by iazaitce.

Description:
The goal of the project is to create a simple client-to-server communication program. 



Instructions:
Open two separate terminal windows and navigate to the project repository.
In one of the windows run _make_ in the root of the repository to complile the program.
After the project is compiled:
 - First run _./server_ in one of the terminal tabs. The output should display _PID:_ followed by a number.

 - In the second terminal window run _./client_ followed by the number recieved from the server and a string of characters in quotation marks. Example:
  
    >  <code>./client 82362 "Ph'nglui mglw'nafh Cthulhu R'lyeh wgah'nagl fhtagn"</code>

The string given to the client should then be displayed by the server without the delay. The server should be able to handle multiple inputs without needing to restart.


Resourses: 
- Linux manual on related topics. For example _sigaction()_ system call, _kill_, _sleep_ commands, etc.

- https://www.systutorials.com/catching-the-signal-sent-by-kill-in-c-on-linux/ - general tutorial on signal handling

The project was complete without the usage of AI.