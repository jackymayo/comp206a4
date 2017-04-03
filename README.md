# Assignment 4 

Not going to start much until the teacher clarifies the assignment in his lectures.
For now, I'll make a to-do list to divide and group up the work.

## Getting Started

1. ssh into your cgi64.cs.mcgill.ca `ssh username@cgi64.cs.mcgill.ca`
2. Go to a folder where you want your git repo to be.
3. git clone this repo: `git clone https://github.com/jackymayo/comp206a4.git`
4. make your changes then git add the files you changed `git add transporter.py`, `git commit -m "changed this part of python script`, `git push origin master`

## To-do list (On-going)

#### HTML structure
* room.cgi textbox processing:
~~~~~
<form action="room.cgi">
    <input type="hidden" name="inventory" value="10,10">
    <input type="text" name="command"/>
</form>
~~~~~
* Teleporting proposed by Vybihal:
~~~~~~
<form action="~northStudent/transporter.py">
  <input type="hidden" name="inventory" value="10,10"/>
  <input type="hidden" name="URL" value="ourserverurl"/>
  <input type="submit" value="North"/>
 </form>
 
<form action="~eastStudent/transporter.py">
  <input type="hidden" name="inventory" value="10,10"/>
  <input type="hidden" name="URL" value="ourserverurl"/>
  <input type="submit" value="East"/>
 </form>
 
 <form action="~westStudent/transporter.py">
  <input type="hidden" name="inventory" value="10,10"/>
  <input type="hidden" name="URL" value="ourserverurl"/>
  <input type="submit" value="West"/>
 </form>
 
 <form action="~southStudent/transporter.py">
  <input type="hidden" name="inventory" value="10,10"/>
  <input type="hidden" name="URL" value="ourserverurl"/>
  <input type="submit" value="South"/>
 </form>
 ~~~~~~~
 
#### The Boss/Challenge
- [ ] Decide on C/Python
- [ ] On Play command, removes N, E, S, W button.
- [ ] On Quit command, show N, E, S, W buttons.
- [ ] Interact with CSV to display hidden resources.
* Proposed format by Vybihal: 
~~~~~
printf("content...");
printf("<html><body><img src="someimg.png"/> 
  <form>
     <!-- html structure -->
     </form></body></html>");
~~~~~
#### Textbox processing
- [ ] C program called room.c and room.cgi
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
