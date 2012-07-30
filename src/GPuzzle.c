/*
 ============================================================================
 Name        : GPuzzle.c
 Author      : Tiangang Liu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void remove_a_double_b(char *s) {

    int read_ptr=0;

    int length=strlen(s);
    int b_cnt=0;
    int write_ptr=0;


    printf("Input:%s\n", s);

    while (read_ptr<length)
    {
        while (s[read_ptr]=='A')
            read_ptr++;

        if (write_ptr!=read_ptr)
            s[write_ptr]=s[read_ptr];
        if (s[write_ptr]=='B')
            b_cnt++;

        read_ptr++;
        write_ptr++;
    }

    s[write_ptr]='\0';

    printf("phase 1: %s\,  b counter:%d \n", s,b_cnt);

    if (b_cnt==0)
        return;

    read_ptr=write_ptr;
    write_ptr+=b_cnt;

    while (read_ptr>=0 && b_cnt>0)
    {
        s[write_ptr]=s[read_ptr];

        if (s[write_ptr]=='B')
        {
            write_ptr--;
            s[write_ptr]='B';
            b_cnt--;
        }

        write_ptr--;
        read_ptr--;

    }
    printf("phase 2: %s\n", s);


}
int main(void) {
	puts(""); /* prints  */
	return EXIT_SUCCESS;
}
