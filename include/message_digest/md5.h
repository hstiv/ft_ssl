# define F_FUNC(X, Y, Z) ((X & Y) | (~X & Z))
# define G_FUNC(X, Y, Z) ((X & Z) | (Y & ~Z))
# define H_FUNC(X, Y, Z) (X ^ Y ^ Z)
# define I_FUNC(X, Y, Z) (Y ^ (X | ~Z))

# define A0 0
# define B0 1
# define C0 2
# define D0 3

typedef struct	s_md5
{
	uint32_t	a[4];
	uint32_t	aa[4];
	int			f;
	char		*bytes;
	uint32_t	*m;
	uint32_t	length;
	int			m_cycle;
	int			tmp;
}				t_md5;

char			*md5(char *s);
char			*md5_formatter(t_md5 *data);