/*
* Kernel.c
*/
void kmain(void)
{
	const char *str = "My first kernel";
	char *vidptr = (char*)0xb8000; // video mem begins here.
	/* There are 25 lines each of 80 ascii characters; 
	each element takes 2 bytes. 
	Therefore, (25 * 80 x 2 = 4,000 (0xfa0) bytes per screen).
	0xb8000 + 0xfa0 = 0xb8fa0(our limit in this program) */
	const char *vidptr_end = (char*)0xb8fa0;

	//this loop clears the screen
	while(vidptr < vidptr_end)
	{
		// blank character
		*vidptr++ = ' ';
		// attribute-byte - light grey on black screen
		*vidptr++ = 0x07;
	}

	vidptr -= 0xfa0;

	// this loop writes the string to video memory
	while(*str != '\0')
	{
			// the character's ascii 
			*vidptr++ = *str++;
			// attribute-byte
			*vidptr++ = 0x07; 
	}

	return;
}