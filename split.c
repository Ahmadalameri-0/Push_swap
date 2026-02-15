#include "push_swap.h"
#include <stddef.h>

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
			{
				s++;
			}
		}
		else
		{
			s++;
		}
	}
	return (count);
}

void	free_split(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

static char	*extract_word(const char **s, char c)
{
	const char	*start;
	char		*word;
	size_t		len;
	size_t		i;

	start = *s;
	len = 0;
	while (**s && **s != c)
	{
		len++;
		(*s)++;
	}
	word = (char *)malloc(len + 1);
	if (!word)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_allocate_words(char **ret, char const *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word = extract_word(&s, c);
			if (!word)
			{
				free_split(ret);
				return (NULL);
			}
			ret[i] = word;
			i++;
		}
		else
		{
			s++;
		}
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	word_count;

	if (!s)
	{
		return (NULL);
	}
	word_count = ft_count_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!ret)
	{
		return (NULL);
	}
	return (ft_allocate_words(ret, s, c));
}
