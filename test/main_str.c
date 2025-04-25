
#include "../libft/libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

#define TEST_MEMCMP(res1, res2, n, name)								\
	do {																\
		if (memcmp(res1, res2, n) == 0)									\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = ");										\
			memprint(res1, n);											\
			printf("CORR:  = ");										\
			memprint(res2, n);											\
		}																\
	} while (0);														\

void memprint(const void *mem, size_t n)
{
	const unsigned char *p;
	
	p = mem;
	for (size_t i = 0; i < n; i++) {
		printf("%02x ", p[i]);
	}
	printf("\n");
}

#define TEST_STRCMP(res1, res2, name)									\
	do {																\
		if (strcmp(res1, res2) == 0)									\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = \"%s\"\n", res1);							\
			printf("CORR:  = \"%s\"\n", res2);							\
		}																\
	} while (0);														\

#define TEST_PTRCMP(res1, res2, name)									\
	do {																\
		if ((uintptr_t)res1 == (uintptr_t)res2)							\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %p\n", res1);								\
			printf("CORR:  = %p\n", res2);								\
		}																\
	} while (0);														\

#define TEST_BYTECMP(res1, res2, name)									\
	do {																\
		if (res1 == res2)												\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %cu\n", res1);								\
			printf("CORR:  = %cu\n", res2);								\
		}																\
	} while (0);														\
	
#define TEST_INTCMP(res1, res2, name)									\
	do {																\
		if (res1 == res2)												\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %i\n", res1);								\
			printf("CORR:  = %i\n", res2);								\
		}																\
	} while (0);														\

#define TEST_SIZETCMP(res1, res2, name)									\
	do {																\
		if (res1 == res2)												\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %lu\n", res1);								\
			printf("CORR:  = %lu\n", res2);								\
		}																\
	} while (0);														\

int main(void)
{
	printf("++++++++++++ft_strlen++++++++++++\n");
	TEST_SIZETCMP(ft_strlen("helooooo"), strlen("helooooo"), "ft_strlen(\"helooooo\")");
	TEST_SIZETCMP(ft_strlen(""), strlen(""), "ft_strlen(\"\")");
	TEST_SIZETCMP(ft_strlen("a\0bcd"), strlen("a\0bcd"), "ft_strlen(\"a\\0bcd\")");
	
	printf("++++++++++++ft_strlcpy++++++++++++\n");
	char ft_buf[20] = {0};
	char buf[20] = {0};
	char src[] = "AAABB\0CCC";
	char src2[] = "";
	TEST_SIZETCMP(ft_strlcpy(ft_buf, src, 0), strlcpy(buf, src, 0), "ft_strlcpy(buf, src, 0): len");
	TEST_MEMCMP(ft_buf, buf, 10, "ft_strlcpy(ft_buf, buf, 0)");

	ft_bzero(ft_buf, 10);
	ft_bzero(buf, 10);
	TEST_SIZETCMP(ft_strlcpy(ft_buf, src, 1), strlcpy(buf, src, 1), "ft_strcpy(buf, src, 1): len");
	TEST_MEMCMP(ft_buf, buf, 10, "ft_strlcpy(ft_buf, buf, 1)");

	ft_bzero(ft_buf, 10);
	ft_bzero(buf, 10);
	TEST_SIZETCMP(ft_strlcpy(ft_buf, src, 10), strlcpy(buf, src, 10), "ft_strcpy(buf, src, 10): len");
	TEST_MEMCMP(ft_buf, buf, 10, "ft_strlcpy(ft_buf, buf, 10)");
	
	ft_bzero(ft_buf, 10);
	ft_bzero(buf, 10);
	TEST_SIZETCMP(ft_strlcpy(ft_buf, src, 3), strlcpy(buf, src, 3), "ft_strcpy(buf, src, 3): len");
	TEST_MEMCMP(ft_buf, buf, 3, "ft_strlcpy(ft_buf, buf, 3)");

	ft_bzero(ft_buf, 10);
	ft_bzero(buf, 10);
	TEST_SIZETCMP(ft_strlcpy(ft_buf, src2, 10), strlcpy(buf, src2, 10), "ft_strcpy(buf, src, 10): len");
	TEST_MEMCMP(ft_buf, buf, 10, "ft_strlcpy(ft_buf, buf-empty, 10)");
	
	printf("++++++++++++ft_strlcat++++++++++++\n");
	char src_cat[] = "AAABBBCCC";
	char dst[] = "hello\0                    ";
	char ft_dst[] = "hello\0                   ";
	TEST_SIZETCMP(ft_strlcat(ft_dst, src_cat, 10), strlcat(dst, src_cat, 10), "ft_strlcat(dst, src, 10): len");
	TEST_MEMCMP(ft_dst, dst, 10, "ft_strlcat(dst, src, 10)");

	ft_strlcpy(dst, "hello", 5);
	ft_strlcpy(ft_dst, "hello", 5);
	TEST_SIZETCMP(ft_strlcat(ft_dst, src_cat, 3), strlcat(dst, src_cat, 3), "ft_strlcat(dst, src, 3): len");
	TEST_MEMCMP(ft_dst, dst, 3, "ft_strlcat(dst, src, 3)");

	ft_strlcpy(dst, "hello", 0);
	ft_strlcpy(ft_dst, "hello", 0);
	TEST_SIZETCMP(ft_strlcat(ft_dst, src_cat, 0), strlcat(dst, src_cat, 0), "ft_strlcat(dst, src, 0): len");
	TEST_MEMCMP(ft_dst, dst, 0, "ft_strlcat(dst, src, 0)");
	
	ft_strlcpy(dst, "", 5);
	ft_strlcpy(ft_dst, "", 5);
	TEST_SIZETCMP(ft_strlcat(ft_dst, src_cat, 5), strlcat(dst, src_cat, 5), "ft_strlcat(dst, src, 5): len");
	TEST_MEMCMP(ft_dst, dst, 5, "ft_strlcat(dst, src, 5)");

	printf("++++++++++++ft_strchr++++++++++++\n");
	ft_strlcpy(dst, "ABCDEABCDE", 10);
	TEST_PTRCMP(ft_strchr(dst, 'A'), strchr(dst, 'A'), "ft_strchr(dst, 'A')");
	TEST_PTRCMP(ft_strchr(dst, 'Z'), strchr(dst, 'Z'), "ft_strchr(dst, 'Z')");
	TEST_PTRCMP(ft_strchr(dst, '\0'), strchr(dst, '\0'), "ft_strchr(dst, '\\0')");
	ft_strlcpy(dst, "\0", 1);
	TEST_PTRCMP(ft_strchr(dst, '\0'), strchr(dst, '\0'), "ft_strchr(dst, '\\0')");
	TEST_PTRCMP(ft_strchr(dst, 'A'), strchr(dst, 'A'), "ft_strchr(dst, 'A')");

	printf("++++++++++++ft_strrchr++++++++++++\n");
	ft_strlcpy(dst, "ABCDEABCDE", 10);
	TEST_PTRCMP(ft_strrchr(dst, 'A'), strrchr(dst, 'A'), "ft_strrchr(dst, 'A')");
	TEST_PTRCMP(ft_strrchr(dst, 'Z'), strrchr(dst, 'Z'), "ft_strrchr(dst, 'Z')");
	TEST_PTRCMP(ft_strrchr(dst, '\0'), strrchr(dst, '\0'), "ft_strrchr(dst, '\\0')");
	ft_strlcpy(dst, "\0", 1);
	TEST_PTRCMP(ft_strrchr(dst, '\0'), strrchr(dst, '\0'), "ft_strrchr(dst, '\\0')");
	TEST_PTRCMP(ft_strrchr(dst, 'A'), strrchr(dst, 'A'), "ft_strrchr(dst, 'A')");
	
	printf("++++++++++++ft_strncmp++++++++++++\n");
	TEST_INTCMP(ft_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3), "ft_strncmp(\"abc\", \"abc\", 3)");
	TEST_INTCMP(ft_strncmp("abc", "abd", 2), strncmp("abc", "abd", 2), "ft_strncmp(\"abc\", \"abd\", 2)");
	TEST_INTCMP(ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3), "ft_strncmp(\"abc\", \"abd\", 3)");
	TEST_INTCMP(ft_strncmp("ab", "abc", 3), strncmp("ab", "abc", 3), "ft_strncmp(\"ab\", \"abc\", 3)");
	TEST_INTCMP(ft_strncmp("abc", "ab", 3), strncmp("abc", "ab", 3), "ft_strncmp(\"abc\", \"ab\", 3)");
	TEST_INTCMP(ft_strncmp("abc", "abc", 0), strncmp("abc", "abc", 0), "ft_strncmp(\"abc\", \"abc\", 0)");
	TEST_INTCMP(ft_strncmp("abc", "ABC", 3), strncmp("abc", "ABC", 3), "ft_strncmp(\"abc\", \"ABC\", 3");
	TEST_INTCMP(ft_strncmp("abc\0xyz", "abc\0xyz", 7), strncmp("abc\0xyz", "abc\0xyz", 7), "ft_strncmp(\"abc\\0xyz\", \"abc\\0xyz\", 7)");

	printf("++++++++++++ft_strnstr++++++++++++\n");
	ft_strlcpy(dst, "hello world", 100);
	TEST_BYTECMP(*ft_strnstr(dst, "world", 11), 'w', "ft_strnstr(\"hello world\", \"world\", 11)");
	TEST_PTRCMP(ft_strnstr(dst, "world", 5), NULL, "ft_strnstr(\"hello world\", \"world\", 5)");
	TEST_BYTECMP(*ft_strnstr(dst, "", 50), 'h', "ft_strnstr(\"hello world\", \"\", 50)");
	ft_strlcpy(dst, "", 100);
	TEST_BYTECMP(*ft_strnstr(dst, "", 50), '\0', "ft_strnstr(\"\", \"\", 50)");
	TEST_PTRCMP(ft_strnstr(dst, "abc", 50), NULL, "ft_strnstr(\"\", \"abc\", 50)");
	ft_strlcpy(dst, "abcabcabc", 100);
	TEST_BYTECMP(*ft_strnstr(dst, "cab", 6), 'c', "ft_strnstr(\"\", \"cab\", 6)");
	
	printf("++++++++++++ft_strdup++++++++++++\n");
	char cpy[] = "hello";
	char *cpyofcpy = ft_strdup(cpy);
	TEST_MEMCMP(cpyofcpy, cpy, 6, "ft_strdup(\"hello\")");
	free(cpyofcpy);
	ft_strlcpy(cpy, "", 100);
	cpyofcpy = ft_strdup(cpy);
	TEST_MEMCMP(cpyofcpy, cpy, 1, "ft_strdup(\"\")");
	free(cpyofcpy);
	ft_strlcpy(cpy, "a\0bcd", 100);
	cpyofcpy = ft_strdup(cpy);
	TEST_MEMCMP(cpyofcpy, cpy, 1, "ft_strdup(\"\")");
	free(cpyofcpy);

	printf("++++++++++++ft_substr++++++++++++\n");
	// if failing, could mean not enough memory -> malloc fail NULL check include then
	TEST_STRCMP(ft_substr("hello world", 0, 5), "hello", "ft_substr(\"hello world\", 0, 5)");
	TEST_STRCMP(ft_substr("hello world", 6, 5), "world", "ft_substr(\"hello world\", 6, 5)");
	TEST_STRCMP(ft_substr("hello world", 1, 3), "ell", "ft_substr(\"hello world\", 1, 3)");
	TEST_STRCMP(ft_substr("hello world", 0, 0), "", "ft_substr(\"hello world\", 0, 0)");
	TEST_STRCMP(ft_substr("hello world", 0, 100), "hello world", "ft_substr(\"hello world\", 0, 100)");
	TEST_STRCMP(ft_substr("hello", 5, 10), "", "ft_substr(\"hello\", 5, 10)");
	TEST_STRCMP(ft_substr("hello", 6, 1), "", "ft_substr(\"hello\", 6, 1)");
	TEST_STRCMP(ft_substr("", 0, 0), "", "ft_substr(\"\", 0, 0)");
	TEST_STRCMP(ft_substr("abc\0def", 0, 7), "abc", "ft_substr(\"abc\\0def\", 0, 7)");
	
	printf("++++++++++++ft_strjoin++++++++++++\n");
	TEST_STRCMP(ft_strjoin("Hello", "World"), "HelloWorld", "ft_substr(\"Hello\", \"World\")");
	TEST_STRCMP(ft_strjoin("", "World"), "World", "ft_substr(\"\", \"World\")");
	TEST_STRCMP(ft_strjoin("", ""), "", "ft_substr(\"\", \"\")");
	TEST_STRCMP(ft_strjoin("A", "B"), "AB", "ft_substr(\"A\", \"B\")");

	printf("++++++++++++ft_strtrim++++++++++++\n");
	TEST_STRCMP(ft_strtrim(" hello ", " "), "hello", "ft_strtrim(\" Hello \", \" \")");
	TEST_STRCMP(ft_strtrim("$$$hello$$$", "$"), "hello", "ft_strtrim(\"$$$hello$$$\", \"$\")");
	TEST_STRCMP(ft_strtrim("..abc..", "."), "abc", "ft_strtrim(\"..abc..\", \".\")");
	TEST_STRCMP(ft_strtrim("xyzabcxyz", "xyz"), "abc", "ft_strtrim(\"xyzabcxyz\", \"abc\")");
	TEST_STRCMP(ft_strtrim("xyzabczyx", "zyx"), "abc", "ft_strtrim(\"xyzabczyx\", \"abc\")");
	TEST_STRCMP(ft_strtrim("xyzabczyxbb", "zyx"), "abczyxbb", "ft_strtrim(\"xyzabczyxbb\", \"abc\")");
	TEST_STRCMP(ft_strtrim("hello", "zyx"), "hello", "ft_strtrim(\"hello\", \"zyx\")");
	TEST_STRCMP(ft_strtrim(".....", "."), "", "ft_strtrim(\".....\", \".\")");
	TEST_STRCMP(ft_strtrim("", "abc"), "", "ft_strtrim(\"\", \"abc\")");
	TEST_STRCMP(ft_strtrim(" ", " "), "", "ft_strtrim(\" \", \" \")");
}
