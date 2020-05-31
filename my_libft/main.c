/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:35:50 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/12 20:49:12 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
# include <signal.h>

# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <time.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <ctype.h>
#include <bsd/bsd.h>
 

 


 int main (void)
{
	 
/*
     int     intsrc[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int     intftsrc[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 12};
	

        char src[10] = "1234567890";
     	char ft_src[10] = "1234567890";

    ft_memset(NULL, 126, 5);
	memset(src, 200, 5);
	printf("src: %s\n", src);

	memset(intsrc, 5454, 45);
	ft_memset(NULL, 5454, 45);
        for (int i = 0; i < 10; i++){
        printf("src%d ", intsrc[i]);
	printf(" ; ftsrc%d ", intftsrc[i]);
        printf("\n");
	}


	//ft_bzero
	bzero(src, 1);
	ft_bzero(intftsrc, 16);
	for (int i = 0; i < 10; i++){
	        printf("src%d ", intftsrc[i]);
	}
	ft_bzero(ft_src, 5);
	printf("bzero%s\n", src);
	printf("ft_bzero%s\n", ft_src);

	//ft_memcpy

	printf("\n\nft_memcpy\n\n");

     	// Массив источник данных
   	unsigned char source[10]="123456";
 
   // Массив приемник данных
   	unsigned char dst[10]="";

   // Копируем 6 байт из массива src в массив dst
   	ft_memcpy (intsrc, intftsrc, 6);
//	memcpy (dst, source, 6);

   // Вывод массива dst на консоль
 
   	printf ("dst: %d\n", intsrc[0]);

}


		
 
         printf("\n\nft_memccpy\n\n");
	
	   // Массив источник данных
	   unsigned char src[15]="1234567890";

	   // Массив приемник данных
 	 unsigned char dst[15]="";

 	  // Копируем данные из массива src в массив dst
	 printf("%p\n", (memccpy (dst, src, '6', 6)));
	 void *ptr = ft_memccpy (dst, src, '6', 6);
	 printf("%p\n", ptr);
	 

  	 // Вывод массива dst на консоль
  	 printf ("dst: %s\n", dst);
   }





		 
   // Исходный массив данных
   unsigned char src[10]= "1234567890";

   int		size = 128 * 1028 * 1028;
			char	*dst = (char *)malloc(sizeof(char) * size);
			char	*data = (char *)malloc(sizeof(char) * size);
	

	ft_memset(data, 'A', size);
	memset(dst, 'B', size);

	clock_t t;

	t = clock();

   
	 memmove(data, dst, size);

	t = clock() - t;

	printf ("It took me %d clicks (%f seconds).\n", 
			(int)t, ((double)t)/CLOCKS_PER_SEC);
 	


	t = clock();

  
	ft_memmove(dst, data, size);
	 

	t = clock() - t;

	printf ("It took me %d clicks (%f seconds).\n", 
			(int)t, ((double)t)/CLOCKS_PER_SEC);
			printf ("src old: %s\n", data);
	



   printf ("src old: %s\n", src);

   // Копируем 3 байт
    ft_memmove(&src[4], &src[6], 3);

   // Вывод массива src на консоль
   printf ("src new: %s\n",src);



char *s1 = "\xff\xaa\xde\x12";
	char *s2 = "\xff\xaa\xde\x12MACOSAAAAA";
	size_t size = 4;
printf("%d\n", memcmp(s1, s2, size));
printf("%d\n", ft_memcmp(s1, s2, size));


//strlcat.c


//printf("%d\n", (int) strlcpy(s1, s2, size));
char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;

	strlcat(buff1, str, max);
	ft_strlcat(buff2, str, max);

	
	printf("%p\n",   strrchr(src, 'a'));
	printf("%p\n",  ft_strrchr(src, 'a'));
	 char *d1 = strrchr(src, 'a');
	 char *d2 = ft_strrchr(src, 'a');






 	//char *s1 = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
	//char *s2 = "Hello \t  Please\n Trim me !";

//	char *s1 = "123abcd456efg789";
//	char *s2 = "123456789";
//	char *s1 = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
//	char *s2 = "Hello \t  Please\n Trim me !";
//	s1 = ft_strtrim(s1, s2);
//	printf("%s\n", s1);


 

  //printf("%s\n", ft_itoa(2147483648));
	//itoa(-2147483647 -1);


	t_list *newlist;
	t_list *list;
	int i = 456;
	int j = 457;
	int k = 458;
	int l = 459;

	list = ft_lstnew(&i);
	printf("%d\n\n",	*((int *) list->content));

	ft_lstadd_back(&list, ft_lstnew(&j));
	while (list)
		{
			printf("%d\n",	*((int *) list->content));
			list = list->next;
		}
	printf(" \n\n");

	ft_lstadd_back(&list, ft_lstnew(&k));
	while (list)
	{
		printf("%d\n",	*((int *) list->content));
		list = list->next;
	}
	printf(" \n\n");

	ft_lstadd_back(&list,  ft_lstnew(&l));

	printf ("%d", ft_lstsize(list));
	
	while (list)
	{
		printf("%d\n",	*((int *) list->content));
		list = list->next;
	}
	
	const char *s = "a";
	char a = 'a';
	char *s1 = ft_strtrim(s, &a);
	printf("%s", s1);
	free(s1);
*/







	char *s = "a";
	char **s1 = ft_split(s, 'a');
	if (!s1){
		printf("pizda\n");
			return (0);
	}

	int i = 0;
	while(s1[i] != NULL)
	{
		printf("tytБлядь\n");
		printf("0%s0\n", s1[i]);
		//free(s1[i]);
		i++;
	}
	printf("%p\n", s1[i]);
	//free (s1[0]);
	i = 0;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free (s1);




/*
	char n[40] = "9223372036854";
	int i1 = atoi(n);
	int i2 = ft_atoi(n);
	printf("%d\n", i1);
	printf("%d\n", i2);
	

	char *s1 = ft_substr(s,  10, 1);
	if (!s1){
		printf("hui\v");
		return 0;
	}
	printf("%s\n", s1);
	while (s1[i] != NULL){
		printf("%s\n", s1[i]);
		i++;
	}
	//printf("%p\n", s1[1]);
	//printf("%d\n",*((int *)s1[0]));

char *ptr ;
	const char *s = "\0";
	const char *l = "jklj";
	size_t i = 7;
	ptr = strnstr(s, l, i);
	printf("%p\n", ptr);
	ptr = ft_strnstr(s, l, i);
	printf("%p\n", ptr);
	//	printf("%d\n",(int)s1[0][5]);
	//	printf("%s\n", s1[8]);
	//	printf("%p\n", (int *) s1[7]);
	//	printf("%s\n", s1[7]);

		//printf("%s\n", s1[1]);
		//printf("%s\n", s1[2]);
	
	return (0);*/
}


	