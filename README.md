# get-next-line-
another project in 1337 not finished still need more time
so first of all we will create a static variable because he will retain the rest value after the end of the program and after we'll protect the file we'll put a condition for fd < 0 or the BUFFER_SIZE < 0

it will return 0 .and other variable called line he's the one that we will return .

 

```c
char	*get_next_line(int fd)
{
	static char	*rest;
	char	*line;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	rest = read_buffer(fd,rest);
```

after we will create a function that will store into rest ,this function first should be protected so we'll handle it and after we ll create a while loop with the condition of : if strchr didn't find "\n" and the r exist .

so first of all r = read(fd,buff,BUFFER_SIZE); **what that mean ?**

it means that the function read will read the number of bits given by the buffer_size and it will return that number to r , and the buff will receive everything read has read it .so he's going to read  the fd till he find '\n' 

if an error happened we should free the buff so we will use free or if everything went good we will call strjoin to copy from the buff to str and put **'\0'** to determine the end of line finally return str the code will be like :

```c
char *read_buffer(int fd,char *str)
{
	char	*buff;
	int		r;
	
	if (!buff)
		return(NULL);
	r = 1;
	while (!ft_strchr(str,'\n') && r )
	{
		r = read(fd,buff,BUFFER_SIZE);
		if (r == -1)
		{
			free(buff);
			return(NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin(str,buff);
	}
		free(buff);
		return(str);
}
```

so after the return of str the rest will equal the str .

let's move to the next step 

so we'll create a function that'll take the line that we want .

first her prototype will be char   get_line(char *c)

we'll declare 3 variable first will be char* to store the line the other's will be int 

one of them gonna be the index and the other will store the len .

```c
	char  *get_line(char *c)
{
	char *line;
	int   i;
	int   len;
```

so now we want mesure the len of the line we 'll create a while that is going to increase till it find '\n' and after the len will equal how many time the i increase + 1 this one is for '\0' 
