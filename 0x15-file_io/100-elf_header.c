#include "main.h"
#include <elf.h>

#define USAGE "Usage: elf_header elf_filename\n"
#define ErrOnOpen "Error: Can't open file: %s\n"
#define ErrOnRead "Error: Can't read from file: %s\n"
#define ErrOnMatch "Error: Not an ELF file: %s\n"
#define ErrOnClose "Error: Closing file descriptor: %i\n"

void handle_err(const char *message, const void *p_arg, int n_arg);
void print_class(Elf64_Ehdr header);
void print_data(Elf64_Ehdr header);
void print_version(Elf64_Ehdr header);
void print_osabi(Elf64_Ehdr header);
void print_more_osabi(Elf64_Ehdr header);
void print_abiv(Elf64_Ehdr header);
void print_type(Elf64_Ehdr header);
void print_entry(Elf64_Ehdr header);

/**
 * main - Display the information contained in the ELF header
 * @argc: count of args
 * @argv: array of strings containing the command-line arguments.
 * Return: Always (0)
 */
int main(int argc, char *argv[])
{
	int i, fd;
	ssize_t bytes;
	char *filename;
	Elf64_Ehdr header;
	/* Second argument not specified */
	if (argc != 2)
		handle_err(USAGE, NULL, 0);

	filename = argv[1];
	/* Open the ELF file */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_err(ErrOnOpen, filename, 0);
	/* Read the ELF header */
	bytes = read(fd, &header, sizeof(header));
	if (bytes != sizeof(header) || bytes < 1)
		handle_err(ErrOnRead, filename, 0);
	/* Check if it's a valid ELF file */
	if (header.e_ident[ELFMAG0] != 0x7f ||
		strncmp((char *)&header.e_ident[ELFMAG1], "ELF", 3) != 0)
		handle_err(ErrOnMatch, filename, 0);
	/* Display ELF header information */
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", header.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");

	print_class(header);
	print_data(header);
	print_version(header);
	print_osabi(header);
	print_abiv(header);
	print_type(header);
	print_entry(header);

	if (close(fd))
		handle_err(ErrOnClose, filename, fd);
	return (0);
}

/**
 * handle_err - Helper function to handle errors
 * @message: the error message to print upon exit
 * @p_arg: pointer to print optional argument
 * @n_arg: number to print optional argument
 */
void handle_err(const char *message, const void *p_arg, int n_arg)
{
	if (n_arg)
		dprintf(STDERR_FILENO, message, n_arg);
	else
		dprintf(STDERR_FILENO, message, p_arg);
	exit(98);
}

/**
 * print_class - .
 * @header: ELF header struct
 */
void print_class(Elf64_Ehdr header)
{
	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
	case ELFCLASS64:
		printf("ELF%d", 64);
		break;
	case ELFCLASS32:
		printf("ELF%d", 32);
		break;
	case ELFCLASSNONE:
		printf("none");
		break;
	}
	printf("\n");
}

/**
 * print_data - .
 * @header: ELF header struct
 */
void print_data(Elf64_Ehdr header)
{
	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("%s", "2's complement, little endian");
		break;
	case ELFDATA2MSB:
		printf("%s", "2's complement, big endian");
		break;
	case ELFDATANONE:
		printf("none");
		break;
	}
	printf("\n");
}

/**
 * print_version - .
 * @header: ELF header struct
 */
void print_version(Elf64_Ehdr header)
{
	printf("  Version:                           ");
	printf("%d", header.e_ident[EI_VERSION]);
	switch (header.e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf("%s", " (current)");
		break;
	case EV_NONE:
		printf("%s", "");
		break;
	}
	printf("\n");
}

/**
 * print_osabi - .
 * @header: ELF header struct
 */
void print_osabi(Elf64_Ehdr header)
{
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("%s", "UNIX - System V");
		break;
	case ELFOSABI_HPUX:
		printf("%s", "UNIX - HP-UX");
		break;
	case ELFOSABI_NETBSD:
		printf("%s", "UNIX - NetBSD");
		break;
	case ELFOSABI_LINUX:
		printf("%s", "UNIX - Linux");
		break;
	case ELFOSABI_SOLARIS:
		printf("%s", "UNIX - Solaris");
		break;
	case ELFOSABI_AIX:
		printf("%s", "UNIX - AIX");
		break;
	case ELFOSABI_IRIX:
		printf("%s", "UNIX - IRIX");
		break;
	case ELFOSABI_FREEBSD:
		printf("%s", "UNIX - FreeBSD");
		break;
	default:
		print_more_osabi(header);
		break;
	}
	printf("\n");
}

/**
 * print_more_osabi - .
 * @header: ELF header struct
 */
void print_more_osabi(Elf64_Ehdr header)
{
	switch (header.e_ident[EI_OSABI])
	{
	case ELFOSABI_ARM:
		printf("%s", "ARM");
		break;
	case ELFOSABI_TRU64:
		printf("%s", "UNIX - TRU64");
		break;
	case ELFOSABI_MODESTO:
		printf("%s", "Novall - Modesto");
		break;
	case ELFOSABI_OPENBSD:
		printf("%s", "UNIX - OpenBSD");
		break;
	case ELFOSABI_STANDALONE:
		printf("%s", "Standalone App");
		break;
	default:
		printf("<unknown: %x>", header.e_ident[EI_OSABI]);
		break;
	}
}

/**
 * print_abiv - .
 * @header: ELF header struct
 */
void print_abiv(Elf64_Ehdr header)
{
	printf("  ABI Version:                       ");
	printf("%d\n", header.e_ident[EI_ABIVERSION]);
}

/**
 * print_type - .
 * @header: ELF header struct
 */
void print_type(Elf64_Ehdr header)
{
	int t = 0;
	char *ptr = (char *)&header.e_type;

	printf("  Type:                              ");
	if (header.e_ident[EI_DATA] == ELFDATA2MSB)
		t = 1;

	switch (ptr[t])
	{
	case ET_NONE:
		printf("%s", "NONE (None)");
		break;
	case ET_EXEC:
		printf("%s", "EXEC (Executable file)");
		break;
	case ET_REL:
		printf("%s", "REL (Relocatable file)");
		break;
	case ET_CORE:
		printf("%s", "CORE (Core file)");
		break;
	case ET_DYN:
		printf("%s", "DYN (Shared Object file)");
		break;
	default:
		printf("<unknown: %x>", ptr[t]);
		break;
	}
	printf("\n");
}

/**
 * print_entry - .
 * @header: ELF header struct
 */
void print_entry(Elf64_Ehdr header)
{
	unsigned char *ptr = (unsigned char *)&header.e_entry;
	int size = (header.e_ident[EI_CLASS] == ELFCLASS32) ? 4 : 8;
	int i;

	printf("  Entry point address:               0x");

	/* Determine the first non-zero byte index */
	for (i = size - 1; i >= 0 && !ptr[i]; i--)
		continue;

	/* Print the entry point address */
	for (; i >= 0; i--)
		printf(i == size - 1 ? "%x" : "%02x", ptr[i]);

	printf("\n");
}
