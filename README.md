# Assignment 4 

## Task division:
- [ ] **Jacky**: Command processing in C, Python transporter,  Game in C/Python, HTML
- [ ] **Henry**: Study for 273
- [ ] **Blair**: Study for 273

## Getting Started

1. ssh into your mimi.cs.mcgill.ca `ssh username@mimi.cs.mcgill.ca`
2. Make a public_html folder in your home folder and `chmod a+rx public_html`
3. `cd public_html`
4. `git clone https://github.com/jackymayo/comp206a4.git .`
5. make your changes then git add the files you changed, i.e. `git add transporter.py`, `git commit -m "changed this part of python script`, `git push origin master`

# To-do list (On-going)

 
#### The Boss/Challenge
- [ ] Decide on C/Python
- [ ] On Play command, removes N, E, S, W button.
- [ ] On Quit command, show N, E, S, W buttons.
- [ ] Interact with CSV to display hidden resources.


#### Textbox processing
- [ ] Two arguments: Player's inventory and player's command.
- [x] Read/Write Resource
- [x] Read/Change Player's inventory
* Supported commands
- [ ] Drop n
- [ ] Play
- [ ] Exit
- [ ] Refresh

# No longer need cgi, just use default mimi server.
## CGI guide steps (Vybihal):  
> 1. ssh mimi.cs.mcgill.ca
> 2. mkdir cgi-bin
>     chmod a+rx cgi-bin
> 3. vim room.c
> 4. gcc -o room.cgi room.c
> 5. mv room.cgi cgi-bin
> 6. chmod a+rx room.cgi
