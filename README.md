# comp206a4


CGI guide steps:  
> 1. ssh cgi64.cs.mcgill.ca
> 2. mkdir cgi-bin
>     chmod a+rx cgi-bin
> 3. vi program.c
> 4. gcc -o program.cgi program.c
> 5. mv program.cgi cgi-bin
> 6. chmod a+rx program.cgi
> 7. <form > action="www.cs.mcgill.ca/~username/cgi-bin/program.cgi" > method="post">
> 8. printf("Content-Type: text/html\n\n");
