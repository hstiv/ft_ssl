# define F(X, Y, Z) ((X & Y) | (~X & Z))
# define G(X, Y, Z) ((X & Z) | (~Z & Y))
# define H(X, Y, Z) (X ^ Y ^ Z)
# define I(X, Y, Z) ( Y ^ (~Z & X))

typedef struct	s_md5
{
	uint32_t	a[4];
	uint32_t	aa[4];
	int			f;
	int			g;
	char		*bytes;
	uint32_t	*m;
	size_t		length;
	int			m_cycle;
}				t_md5;

char			*md5_formatter(t_md5 *data);