# Assignment 4 

Not going to start much until the teacher clarifies the assignment in his lectures.
For now, I'll make a to-do list to divide and group up the work.

## To-do list (On-going)

#### HTML structure
~~~~~~
<input type="text" name="cmd"/>
<intput type="hidden" value="10,10"/>
~~~~~~~

#### The Boss/Challenge
- [ ] Decide on C/Python
- [ ] On Play command, removes N, E, S, W button.
- [ ] On Quit command, show N, E, S, W buttons.
- [ ] Interact with CSV to display hidden resources.
* Proposed format
~~~~~
printf("content...");
printf("<html><body><img src="someimg.png"/> 
  <form>
     <!-- html structure -->
     </form></body></html>");
~~~~~
#### Textbox processing
- [ ] C program called room.c and a.out
- [ ] Two arguments: Player's inventory and player's command.
* Supported commands
- [ ] Drop n
- [ ] Play
- [ ] Exit
- [ ] Refresh
* Teleporting
~~~~~~
<form action="transporter.py">
  <input type="hidden" name="inventory" value="10,10"/>
  <input type="hidden" name="url" value="ourserverurl"/>
  <input type="submit" value="Teleport to East"/>
 </form>
## CGI guide steps (Vybihal):  
> 1. ssh cgi64.cs.mcgill.ca
> 2. mkdir cgi-bin
>     chmod a+rx cgi-bin
> 3. vi program.c
> 4. gcc -o program.cgi program.c
> 5. mv program.cgi cgi-bin
> 6. chmod a+rx program.cgi
> 7. <form > action="www.cs.mcgill.ca/~username/cgi-bin/program.cgi" > method="post">
> 8. printf("Content-Type: text/html\n\n");
