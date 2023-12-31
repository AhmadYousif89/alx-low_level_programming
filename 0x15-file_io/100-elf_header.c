#include "main.h"
#include <elf.h>

#define USAGE "Usage: Missing [ELF_PATH]\n"
#define ErrOnOpen "Error: Can't open file: %s\n"
#define ErrOnRead "Error: Can't read from file: %s\n"
#define ErrOnMatch "Error: Not an ELF file: %s\n"
#define ErrOnClose "Error: Closing file descriptor: %i\n"
#define ErrOnMalloc "Error: Memory allocation failed for ELF header in file: %s\n"

void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abiv(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_more_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void handle_err(const char *message, const void *p_arg, int n_arg);

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
	Elf64_Ehdr *header;
	/* Second argument not specified */
	if (argc != 2)
		handle_err(USAGE, NULL, 0);

	filename = argv[1];
	/* Open the ELF file */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_err(ErrOnOpen, filename, 0);
	/* Allocate memory for the ELF header */
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
		handle_err(ErrOnMalloc, filename, 0);
	/* Read the ELF header */
	bytes = read(fd, header, sizeof(Elf64_Ehdr));
	if (bytes < 1 || bytes != sizeof(Elf64_Ehdr))
	{
		free(header);
		handle_err(ErrOnRead, filename, 0);
	}
	/* Check if it's a valid ELF file */
	if (header->e_ident[EI_MAG0] != 0x7f ||
		strncmp((char *)&header->e_ident[EI_MAG1], "ELF", 3) != 0)
	{
		free(header);
		handle_err(ErrOnMatch, filename, 0);
	}
	/* Display ELF header information */
	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", header->e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abiv(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	if (close(fd) == -1)
		handle_err(ErrOnClose, filename, fd);

	return (0);
}

/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
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
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
	printf("\n");
}

/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
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
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
	printf("\n");
}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           ");
	printf("%d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf("%s", " (current)");
		break;
	}
	printf("\n");
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
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
		print_more_osabi(e_ident);
		break;
	}
	printf("\n");
}

/**
 * print_more_osabi - .
 * @e_ident: A pointer to an array containing the ELF identification bytes.
 */
void print_more_osabi(unsigned char *e_ident)
{
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_ARM:
		printf("%s", "ARM");
		break;
	case ELFOSABI_TRU64:
		printf("%s", "UNIX - TRU64");
		break;
	case ELFOSABI_MODESTO:
		printf("%s", "Novell - Modesto");
		break;
	case ELFOSABI_OPENBSD:
		printf("%s", "UNIX - OpenBSD");
		break;
	case ELFOSABI_STANDALONE:
		printf("%s", "Standalone App");
		break;
	default:
		printf("<unknown: %x>", e_ident[EI_OSABI]);
		break;
	}
}

/**
 * print_abiv - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abiv(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
		   e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	printf("  Type:                              ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	switch (e_type)
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
		printf("<unknown: %x>", e_type);
		break;
	}
	printf("\n");
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               0x");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("%lx\n", e_entry);
	else
		printf("%x\n", (unsigned int)e_entry);
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
