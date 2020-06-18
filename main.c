/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 15:25:24 by jbennink      #+#    #+#                 */
/*   Updated: 2020/06/18 13:15:16 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#define STR0 "string"
#define STR1 "strong"
#define STR2 "strang"
#define STR3 "stringa"
#define STR_EMPTY ""
#ifndef BUFFSIZE
# define BUFFSIZE 15
#endif
#define STR_LONG "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 153 154 155 156 157 158 159 160 161 162 163 164 165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 180 181 182 183 184 185 186 187 188 189 190 191 192 193 194 195 196 197 198 199 200 201 202 203 204 205 206 207 208 209 210 211 212 213 214 215 216 217 218 219 220 221 222 223 224 225 226 227 228 229 230 231 232 233 234 235 236 237 238 239 240 241 242 243 244 245 246 247 248 249 250"
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

static void	teststrlen(void)
{
	printf("\n\t==FT_STRLEN==\n\n");
	//=============================//
	char *s0 = strdup(STR_EMPTY);
	printf("string is =%s=\n", s0);
	printf("real: %lu\n", strlen(s0));
	printf("mine: %lu\n", ft_strlen(s0));
	free(s0);
	//=============================//
	char *s1 = strdup(STR_LONG);
	printf("string is =%s=\n", s1);
	printf("real: %lu\n", strlen(s1));
	printf("mine: %lu\n", ft_strlen(s1));
	free(s1);
	//=============================//
	char *s2 = strdup(STR0);
	printf("string is =%s=\n", s2);
	printf("real: %lu\n", strlen(s2));
	printf("mine: %lu\n", ft_strlen(s2));
	free(s2);
}

static void	teststrcpy(void)
{
	printf("\n\t==FT_STRCPY==\n\n");
	//=============================//
	char *src0 = strdup(STR0);
	char *rdst0 = malloc(strlen(src0) + 1);
	char *mdst0 = malloc(strlen(src0) + 1);
	printf("real:\nbefore:\tsrc  is =%s=\n\trdst is =%s=\n", src0, rdst0);
	printf("return: =%s=\n", strcpy(rdst0, src0));
	printf("after:\tsrc  is =%s=\n\trdst is =%s=\n", src0, rdst0);
	printf("mine:\nbefore:\tsrc  is =%s=\n\tmdst is =%s=\n", src0, mdst0);
	printf("return: =%s=\n", ft_strcpy(mdst0, src0));
	printf("after:\tsrc  is =%s=\n\tmdst is =%s=\n\n", src0, mdst0);
	free(src0);
	free(rdst0);
	free(mdst0);
	//=============================//
	char *src1 = strdup(STR_EMPTY);
	char *rdst1 = malloc(strlen(src1) + 1);
	char *mdst1 = malloc(strlen(src1) + 1);
	printf("real:\nbefore:\tsrc  is =%s=\n\trdst is =%s=\n", src1, rdst1);
	printf("return: =%s=\n", strcpy(rdst1, src1));
	printf("after:\tsrc  is =%s=\n\trdst is =%s=\n", src1, rdst1);
	printf("mine:\nbefore:\tsrc  is =%s=\n\tmdst is =%s=\n", src1, mdst1);
	printf("return: =%s=\n", ft_strcpy(mdst1, src1));
	printf("after:\tsrc  is =%s=\n\tmdst is =%s=\n\n", src1, mdst1);
	free(src1);
	free(rdst1);
	free(mdst1);
	//=============================//
	char *src2 = strdup(STR_LONG);
	char *rdst2 = malloc(strlen(src2) + 1);
	char *mdst2 = malloc(strlen(src2) + 1);
	printf("real:\nbefore:\tsrc  is =%s=\n\trdst is =%s=\n", src2, rdst2);
	printf("return: =%s=\n", strcpy(rdst2, src2));
	printf("after:\tsrc  is =%s=\n\trdst is =%s=\n", src2, rdst2);
	printf("mine:\nbefore:\tsrc  is =%s=\n\tmdst is =%s=\n", src2, mdst2);
	printf("return: =%s=\n", ft_strcpy(mdst2, src2));
	printf("after:\tsrc  is =%s=\n\tmdst is =%s=\n\n", src2, mdst2);
	free(src2);
	free(rdst2);
	free(mdst2);
}

static void	teststrcmp(void)
{
	printf("\n\t==FT_STRCMP==\n\n");
	//=============================//
	printf("str1 is =%s=\nstr2 is =%s=\n", STR0, STR0);
	printf("real: %i\n", strcmp(STR0, STR0));
	printf("mine: %i\n", ft_strcmp(STR0, STR0));
	//=============================//
	printf("str1 is =%s=\nstr2 is =%s=\n", STR_EMPTY, STR0);
	printf("real: %i\n", strcmp(STR_EMPTY, STR0));
	printf("mine: %i\n", ft_strcmp(STR_EMPTY, STR0));
	//=============================//
	printf("str1 is =%s=\nstr2 is =%s=\n", STR0, STR_EMPTY);
	printf("real: %i\n", strcmp(STR0, STR_EMPTY));
	printf("mine: %i\n", ft_strcmp(STR0, STR_EMPTY));
	//=============================//
	printf("str1 is =%s=\nstr2 is =%s=\n", STR_EMPTY, STR_EMPTY);
	printf("real: %i\n", strcmp(STR_EMPTY, STR_EMPTY));
	printf("mine: %i\n", ft_strcmp(STR_EMPTY, STR_EMPTY));
	//=============================//
	printf("str1 is =%s=\nstr2 is =%s=\n", STR0, STR3);
	printf("real: %i\n", strcmp(STR0, STR3));
	printf("mine: %i\n", ft_strcmp(STR0, STR3));
	//=============================//
	printf("str1 is =%s=\nstr2 is =%s=\n", STR0, STR1);
	printf("real: %i\n", strcmp(STR0, STR1));
	printf("mine: %i\n", ft_strcmp(STR0, STR1));
	//=============================//
	printf("str1 is =%s=\nstr2 is =%s=\n", STR0, STR2);
	printf("real: %i\n", strcmp(STR0, STR2));
	printf("mine: %i\n", ft_strcmp(STR0, STR2));
}

static void	testwrite(void)
{
	int fd = open("text0.txt", O_WRONLY);
	printf("\n\t==FT_WRITE==\n\n");
	//=============================//
	printf("errno is %i, fd is 1, string is =write\\n= bytes is 3\n", errno);
	printf("\nreal: %lu\n", write(1, "write\n", 3));
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	printf("\nmine: %lu\n", write(1, "write\n", 3));
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	//=============================//
	printf("errno is %i, fd is 1, string is =write\\n= bytes is 6\n", errno);
	printf("\nreal: %lu\n", write(1, "write\n", 6));
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	printf("\nmine: %lu\n", write(1, "write\n", 6));
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	//=============================//
	printf("errno is %i, fd is 1, string is =write\\n= bytes is 8\n", errno);
	printf("\nreal: %lu\n", write(1, "write\n", 8));
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	printf("\nmine: %lu\n", write(1, "write\n", 8));
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	//=============================//
	printf("errno is %i, fd is -1, string is =write\\n= bytes is 6\n", errno);
	printf("\nreal: %lu\n", write(-1, "write\n", 6));
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	printf("\nmine: %lu\n", write(-1, "write\n", 6));
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	//=============================//
	printf("errno is %i, fd is %i, string is =write\\n= bytes is 6\n", errno, fd);
	printf("\nreal: %lu\n", write(fd, "write\n", 6));
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	printf("\nmine: %lu\n", write(fd, "write\n", 6));
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	close(fd);
}

static void	testread(char *which, ssize_t (whichread)(int, void*, size_t))
{
	int fd = open("text1.txt", O_RDONLY);
	char buf[BUFFSIZE + 1];
	printf("\n\t ==%s==\n\t==FT_READ==\n\n", which);
	//=============================//
	bzero(buf, BUFFSIZE + 1);
	printf("errno is %i, fd is %i bytes is %i\n", fd, errno, BUFFSIZE);
	printf("return: %lu\n", whichread(fd, buf, BUFFSIZE));
	printf("buf is =%s=\n", buf);
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	//=============================//
	bzero(buf, BUFFSIZE + 1);
	printf("errno is %i, fd is -1 bytes is %i\n", errno, BUFFSIZE);
	printf("return: %lu\n", whichread(-1, buf, BUFFSIZE));
	printf("buf is =%s=\n", buf);
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	//=============================//
	bzero(buf, BUFFSIZE + 1);
	printf("errno is %i, fd is 0 bytes is %i\n(reading from stdin, type something)\n", errno, BUFFSIZE);
	printf("return: %lu\n", whichread(0, buf, BUFFSIZE));
	printf("buf is =%s=\n", buf);
	printf("errno is %i\n", errno);
	if (errno)
		perror("error msg is");
	errno = 0;
	close(fd);
}

static void	teststrdup(char *which, char* (whichdup)(const char*))
{
	printf("\n\t  ==%s==\n\t==FT_STRDUP==\n\n", which);
	//=============================//
	printf("string is =%s=\n", STR0);
	char *s0 = strdup(STR0);
	printf("result: =%s=\n", s0);
	free(s0);
	//=============================//
	printf("string is =%s=\n", STR_EMPTY);
	char *s1 = strdup(STR_EMPTY);
	printf("result: =%s=\n", s1);
	free(s1);
	//=============================//
	printf("string is =%s=\n", STR_LONG);
	char *s2 = strdup(STR_LONG);
	printf("result: =%s=\n", s2);
	free(s2);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
	{
		printf("run with argument for each function you would like to test\n");
		return (0);
	}
	i = 2;
	while (i <= ac)
	{
		if (!strcmp(av[i - 1], "strlen"))
			teststrlen();
		if (!strcmp(av[i - 1], "strcpy"))
			teststrcpy();
		if (!strcmp(av[i - 1], "strcmp"))
			teststrcmp();
		if (!strcmp(av[i - 1], "write"))
			testwrite();
		if (!strcmp(av[i - 1], "read"))
			{testread("REAL", read); testread("MINE", ft_read);}
		if (!strcmp(av[i - 1], "strdup"))
			{teststrdup("REAL", strdup); teststrdup("MINE", ft_strdup);}
		i++;
	}
	// ssize_t (int, const void *, size_t)
	// ssize_t (*)(int, void *, size_t)
	return (0);
}
