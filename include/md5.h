# define F(X, Y, Z) ((X & Y) | (~X & Z))
# define G(X, Y, Z) ((X & Z) | (~Z & Y))
# define H(X, Y, Z) (X ^ Y ^ Z)
# define I(X, Y, Z) ( Y ^ (~Z & X))

typedef struct	s_md5
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	aa;
	uint32_t	bb;
	uint32_t	cc;
	uint32_t	dd;
	int			f;
	int			g;
	char		*bytes;
	char		*m;
	size_t		length;
}				t_md5;

char			*md5_formatter(t_md5 *data);