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

so to avoid leak we gonna add onther case if we find '\n' if we didn't we're going to allocated the len that we did find + 1 after we gonna copy from the string C  to line till the '\n' 

so here that could be a little be confusing cause when he will find a new line he will put a '\n' 

and after it '\0' and finally will return the line so the code will be like :

```c
char	*get_line(char *c)
{
	char	*line;
	int		i;
	int		len;
	
	if (!c)
		return(NULL);
	while (c[i] != '\n' && c[i])
		i++;
	len = i + 1;
	if (c[i] == '\n')
		len++;
	line = (char *)malloc(len);
	if (!line)
		return(NULL);
	while (c[i] && c[i] != '\n')
		{
			line[i] = c[i];
			i++;
		}
	if (c[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return(line);
}
```

so now we will move to the final version of code we want keep the rest that we found so .

we're going to create a function that found that rest and store it and in final return it .

**her prototype will be like** : char   *get_new_rest(char *rest)

first we gonna create 4 variables one will be char we gonna store in the rest and return him the other 3 will be int two index and one will store the len so it will be like : 

```c
char   *get_new_rest(char *rest)
{
	char *new_rest;
	int   i;
	int   j;
	int   len;
```

after that first thing we gonna initialize i&j by 0 and so now while the rest dos not equal '\n' or didn't finish it we 'll increase till he find it    . so if there is nth after the new line we'll free the rest and return NULL

if not we'll mesure he's len but ft_strlen from **&rest[ i+1]** that mean from the last index + 1 we add this one for the newline ,so after that we're going to alloc the new_rest by the len + 1 this 1 for '\0'

if he didn't get allocated we'll return NULL,and we will increase one more time to passed the new line after we gonna copy the rest in the new_rest and put in his end '\0 and finnaly free the rest .

 

```c
char	*get_new_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	len = ft_strlen(&rest[i + 1]);
	new_rest = (char *)malloc(sizeof(char) * len + 1);
	if (!new_rest)
		return (NULL);
	i++;
	while (rest[i])
		new_rest[j++] = rest[i++];
	new_rest[j] = '\0';
	free (rest);
	return (new_rest);
}
```

and after that we'll return the line, so now we did now how get_next_line work's 

for the bonus part we're not going to have some big changes 

it's just going to work with different fd in same time so the rest wil be a 2D table for storing value of every fd and we'll have same code