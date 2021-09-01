#include "ft_ssl.h"

static char	base_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};

static size_t	mod_table[] = {0, 2, 1};

static uint32_t	encode_triple(size_t input_length,
					const char *data, size_t *i)
{
	uint32_t	octet_a;
	uint32_t	octet_b;
	uint32_t	octet_c;
	uint32_t	triple;

	octet_a = 0;
	octet_b = 0;
	octet_c = 0;
	if ((*i) < input_length)
		octet_a = (unsigned char)data[(*i)++];
	if ((*i) < input_length)
		octet_a = (unsigned char)data[(*i)++];
	if ((*i) < input_length)
		octet_a = (unsigned char)data[(*i)++];
	triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;
	return(triple);
}

char	*base64_encode(const char *data,
			size_t input_length, size_t *output_length)
{
	uint32_t	triple;
	char		*encoded_data;
	size_t		i;
	int			j;

	i = 0;
	j = 0;
    *output_length = 4 * ((input_length + 2) / 3);
    encoded_data = ft_strnew(*output_length);
	if (encoded_data == NULL)
		return NULL;
    while (i < input_length)
	{
		triple = encode_triple(input_length, data, &i);
        encoded_data[j++] = base_table[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = base_table[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = base_table[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = base_table[(triple >> 0 * 6) & 0x3F];
    }
	i = -1;
    while (++i < mod_table[input_length % 3])
		encoded_data[(*output_length) - 1 - i] = '=';
    return encoded_data;
}

static int32_t	decode_triple(const char *data, size_t *i)
{
	uint32_t	sextet_a;
	uint32_t	sextet_b;
	uint32_t	sextet_c;
	uint32_t	sextet_d;

	if (data[*i] == '=')
		sextet_a = 0 & (*i)++;
	else
		sextet_a = base_table[(int)data[(*i)++]];
	if (data[*i] == '=')
		sextet_b = 0 & (*i)++;
	else
		sextet_b = base_table[(int)data[(*i)++]];
	if (data[*i] == '=')
		sextet_c = 0 & (*i)++;
	else
		sextet_c = base_table[(int)data[(*i)++]];
	if (data[*i] == '=')
		sextet_d = 0 & (*i)++;
	else
		sextet_d = base_table[(int)data[(*i)++]];
	return((sextet_a << 3 * 6) + (sextet_b << 2 * 6)
        + (sextet_c << 1 * 6) + (sextet_d << 0 * 6));
}

char	*base64_decode(const char *data,
			size_t input_length, size_t *output_length)
{
	char			*decoded_data;
	uint32_t		triple;
	size_t			i;
	size_t			j;

    if (input_length % 4 != 0)
		return NULL;
    *output_length = input_length / 4 * 3;
    if (data[input_length - 1] == '=') (*output_length)--;
    if (data[input_length - 2] == '=') (*output_length)--;
    decoded_data = ft_strnew(*output_length);
    if (decoded_data == NULL)
		return NULL;
	i = 0;
	j = 0;
    while (i < input_length)
	{
        triple = decode_triple(data, &i);
        if (j < *output_length) decoded_data[j++] = (triple >> 2 * 8) & 0xFF;
        if (j < *output_length) decoded_data[j++] = (triple >> 1 * 8) & 0xFF;
        if (j < *output_length) decoded_data[j++] = (triple >> 0 * 8) & 0xFF;
    }
    return decoded_data;
}

int				base64()
{
	size_t		output_length;
	char		*output;

	if (g_ssl->params[E])
		output = base64_encode(g_ssl->input_text,
			ft_strlen(g_ssl->input_text), &output_length);
	else if (g_ssl->params[D])
		output = base64_decode(g_ssl->input_text,
			ft_strlen(g_ssl->input_text), &output_length);
	output[output_length] = '\0';
	printf("%s -> %s\n", "Cg==", base64_decode("Cg==", 4, &output_length));
	return (EXIT_SUCCESS);
}