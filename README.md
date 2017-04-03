# Assignment 4 

## To-do list (On-going)

####
#### The Boss/Challenge
- [ ] Decide on C/Python
- [ ] On Play command, removes N, E, S, W button.
- [ ] On Quit command, show N, E, S, W buttons.
- [ ] Interact with CSV to display hidden resources.

#### Textbox processing
- [ ] C program called room.c and a.out
- [ ] Two arguments: Player's inventory and player's command.
* Supported commands
- [ ] Drop n
- [ ] Play
- [ ] Exit
- [ ] Refresh
 
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
