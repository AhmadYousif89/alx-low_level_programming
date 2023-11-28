#include "main.h"
#include <elf.h>

#define USAGE "Usage: Missing [ELF_PATH]\n"
#define ErrOnOpen "Error: Can't open file: %s\n"
#define ErrOnRead "Error: Can't read from file: %s\n"
#define ErrOnMatch "Error: Not an ELF file: %s\n"
#define ErrOnClose "Error: Closing file descriptor: %i\n"

void print_data(Elf64_Ehdr header);
void print_abiv(Elf64_Ehdr header);
void print_class(Elf64_Ehdr header);
void print_osabi(Elf64_Ehdr header);
void print_version(Elf64_Ehdr header);
void print_more_osabi(Elf64_Ehdr header);
void print_type(int e_type, unsigned char *e_ident);
void print_entry(long unsigned int e_entry, unsigned char *e_ident);

/**
 * main - Display the information contained in the ELF header
 * @argc: count of args
 * @argv: array of strings containing the command-line arguments.
 * Return: Always (0)
 */
int main(int argc, char *argv[])
{
	int i, fd;
	Elf64_Ehdr h;
	ssize_t bytes;
	char *filename;
	/* Second argument not specified */
	if (argc != 2)
		dprintf(STDERR_FILENO, USAGE), exit(98);

	filename = argv[1];
	/* Open the ELF file */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, ErrOnOpen, filename), exit(98);
	/* Read the ELF header */
	bytes = read(fd, &h, sizeof(h));
	if (bytes != sizeof(h) || bytes < 1)
		dprintf(STDERR_FILENO, ErrOnRead, filename), exit(98);
	/* Check if it's a valid ELF file */
	if (h.e_ident[EI_MAG0] != 0x7f ||
		strncmp((char *)&h.e_ident[EI_MAG1], "ELF", 3) != 0)
		dprintf(STDERR_FILENO, ErrOnMatch, filename), exit(98);
	/* Display ELF header information */
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", h.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
	print_data(h);
	print_abiv(h);
	print_class(h);
	print_osabi(h);
	print_version(h);
	print_type(h.e_type, h.e_ident);
	print_entry(h.e_entry, h.e_ident);

	if (close(fd))
		dprintf(STDERR_FILENO, ErrOnClose, fd), exit(98);

	return (0);
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
	default:
		printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
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
	default:
		printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
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
	case ELFOSABI_GNU:
		printf("%s", "GNU Hurd");
		break;
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
 * @e_type: The ELF type value obtained from the ELF header.
 * @e_ident: A pointer to an array containing the ELF identification bytes.
 */
void print_type(int e_type, unsigned char *e_ident)
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
 * print_entry - .
 * @e_entry: The entry point address obtained from the ELF header.
 * @e_ident: A pointer to an array containing the ELF identification bytes.
 */
void print_entry(long unsigned int e_entry, unsigned char *e_ident)
{
	int i;
	unsigned char *ptr = (unsigned char *)&e_entry;
	int size = (e_ident[EI_CLASS] == ELFCLASS32) ? 4 : 8;

	printf("  Entry point address:               0x");

	/* Determine the first non-zero byte index */
	for (i = size - 1; i >= 0 && !ptr[i]; i--)
		continue;

	/* Print the entry point address */
	for (; i >= 0; i--)
		printf(i == size - 1 ? "%x" : "%02x", ptr[i]);

	printf("\n");
}
